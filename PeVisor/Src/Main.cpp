#include "UCPE.hpp"
#include <EmuApiFuncs.hpp>
using namespace blackbone;

//#pragma comment(lib,"ntdll.lib")

std::ostream* outs;

extern "C"
{
	NTSYSAPI
		PIMAGE_NT_HEADERS
		NTAPI
		RtlImageNtHeader(IN PVOID BaseAddress);

	NTSYSAPI
		PVOID
		NTAPI
		RtlImageDirectoryEntryToData(
			PVOID BaseAddress,
			BOOLEAN MappedAsImage,
			USHORT Directory,
			PULONG Size
		);
}

static ULONG ExtractEntryPointRva(PVOID ModuleBase)
{
	return RtlImageNtHeader(ModuleBase)->OptionalHeader.AddressOfEntryPoint;
}

// TO DO: x86 support => InitDescriptor32 function support,
// DWORD Virtual addresses and etc..
namespace InitOfDescriptor
{
	// About: Function for initialization of 64 bit process descriptor
	// Mode: Usermode + Kernelmode
	static void InitDescriptor64(SegmentDesctiptorX64* desc, DWORD_PTR base, DWORD_PTR limit, bool is_code, bool is_long_mode)
	{
		desc->descriptor.all = 0;  //clear the descriptor
		desc->descriptor.fields.base_low = base;
		desc->descriptor.fields.base_mid = (base >> 16) & 0xff;
		desc->descriptor.fields.base_high = base >> 24;
		desc->base_upper32 = base >> 32;

		if (limit > 0xfffff) {
			limit >>= 12;
			desc->descriptor.fields.gran = 1;
		}

		desc->descriptor.fields.limit_low = limit & 0xffff;
		desc->descriptor.fields.limit_high = limit >> 16;

		desc->descriptor.fields.dpl = 0;
		desc->descriptor.fields.present = 1;
		desc->descriptor.fields.db = 1;   //64 bit
		desc->descriptor.fields.type = is_code ? 0xb : 3;
		desc->descriptor.fields.system = 1;  //code or data
		desc->descriptor.fields.l = is_long_mode ? 1 : 0;
	}
}

// About: Function for initialization of Processor State
// TO DO: x86 support => InitDescriptor32 function support,
// DWORD Virtual addresses and etc..
// Mode: Usermode + Kernelmode
void PeEmulation::InitProcessorState()
{
	uc_x86_mmr gdtr;

	DWORD_PTR kpcr_base = 0xfffff00000000000ull;

	KPCR kpcr;

	memset(&kpcr, 0, sizeof(KPCR));

	gdtr.base = kpcr_base + offsetof(KPCR, gdt);
	gdtr.limit = sizeof(kpcr.gdt) - 1;

	InitOfDescriptor::InitDescriptor64(&kpcr.gdt[1], 0, 0xffffffffffffffff, true, true);
	InitOfDescriptor::InitDescriptor64(&kpcr.gdt[2], 0, 0xffffffffffffffff, false, true);

	auto err = uc_mem_map(m_uc, kpcr_base, PAGE_SIZE, UC_PROT_READ);
	err = uc_mem_write(m_uc, kpcr_base, &kpcr, sizeof(KPCR));
	err = uc_reg_write(m_uc, UC_X86_REG_GDTR, &gdtr);

	SegmentSelector cs = { 0 };
	cs.fields.index = 1;
	uc_reg_write(m_uc, UC_X86_REG_CS, &cs.all);

	SegmentSelector ds = { 0 };
	ds.fields.index = 2;
	uc_reg_write(m_uc, UC_X86_REG_DS, &ds.all);

	SegmentSelector ss = { 0 };
	ss.fields.index = 2;
	uc_reg_write(m_uc, UC_X86_REG_SS, &ss.all);

	SegmentSelector es = { 0 };
	es.fields.index = 2;
	uc_reg_write(m_uc, UC_X86_REG_ES, &es.all);

	SegmentSelector gs = { 0 };
	gs.fields.index = 2;
	uc_reg_write(m_uc, UC_X86_REG_GS, &gs.all);

	FlagRegister eflags = { 0 };
	eflags.fields.id = 1;
	eflags.fields.intf = 1;
	eflags.fields.reserved1 = 1;

	uc_reg_write(m_uc, UC_X86_REG_EFLAGS, &eflags.all);

	DWORD_PTR cr8 = 0;
	uc_reg_write(m_uc, UC_X86_REG_CR8, &cr8);
}

// About: Function for insertion of something in tail list
// Mode: Usermode + Kernelmode
void PeEmulation::InsertTailList(_In_ DWORD_PTR ListHeadAddress, _In_ DWORD_PTR EntryAddress)
{
	PLIST_ENTRY Blink;

	//Blink = ListHead->Blink;
	uc_mem_read(m_uc, ListHeadAddress + offsetof(LIST_ENTRY, Blink), &Blink, sizeof(Blink));

	//Entry->Flink = (PLIST_ENTRY)ListHeadAddress;

	uc_mem_write(m_uc, EntryAddress + offsetof(LIST_ENTRY, Flink), &ListHeadAddress, sizeof(ListHeadAddress));

	//Entry->Blink = Blink;

	uc_mem_write(m_uc, EntryAddress + offsetof(LIST_ENTRY, Blink), &Blink, sizeof(Blink));

	//Blink->Flink = (PLIST_ENTRY)EntryAddress;

	uc_mem_write(m_uc, (uint64_t)Blink + offsetof(LIST_ENTRY, Flink), &EntryAddress, sizeof(EntryAddress));

	//ListHead->Blink = (PLIST_ENTRY)EntryAddress;

	uc_mem_write(m_uc, ListHeadAddress + offsetof(LIST_ENTRY, Blink), &EntryAddress, sizeof(EntryAddress));
}

// About: Function for initialization of KSharedUserData
// TO DO: Normal initialization of KSharedUserData without zeroes or making of reading redirection to my own KSharedUserData in process.
// Mode: Usermode + Kernelmode
void PeEmulation::InitKSharedUserData()
{
	if (m_IsKernel)
	{
		m_KSharedUserDataBase = 0xfffff78000000000ull;
		m_KSharedUserDataEnd = 0xfffff78000001000ull;
	}
	else
	{
		m_KSharedUserDataBase = 0x7FFE0000;
		m_KSharedUserDataEnd = 0x7FFF0000;
	}

	uc_mem_map(m_uc, m_KSharedUserDataBase, PAGE_SIZE, UC_PROT_READ);
	uc_mem_write(m_uc, m_KSharedUserDataBase, (void*)0x7FFE0000, PAGE_SIZE);
}

// About: Function for intialization of TebPeb
// TO DO: Normal initialization of peb and teb without zeroes.
// Mode: Usermode
void PeEmulation::InitTebPeb()
{
	PEB peb = { 0 };

	m_PebBase = 0x90000ull;
	m_PebEnd = m_PebBase + AlignSize(sizeof(PEB), PAGE_SIZE);

	uc_mem_map(m_uc, m_PebBase, m_PebEnd - m_PebBase, UC_PROT_READ);
	uc_mem_write(m_uc, m_PebBase, &peb, sizeof(PEB));

	m_TebBase = 0x80000ull;
	m_TebEnd = m_TebBase + AlignSize(sizeof(TEB), PAGE_SIZE);

	TEB teb = { 0 };

	teb.ProcessEnvironmentBlock = (PPEB)m_PebBase;

	uc_mem_map(m_uc, m_TebBase, m_TebEnd - m_TebBase, UC_PROT_READ);
	uc_mem_write(m_uc, m_TebBase, &teb, sizeof(TEB));

	uc_x86_msr msr;
	msr.rid = (uint32_t)Msr::kIa32GsBase;
	msr.value = m_TebBase;

	uc_reg_write(m_uc, UC_X86_REG_MSR, &msr);
}

// About: Function for intialization of PsLoadedModuleList in driver
// Mode: Kernelmode
void PeEmulation::InitPsLoadedModuleList()
{
	m_PsLoadedModuleListBase = HeapAlloc(sizeof(LIST_ENTRY));

	LIST_ENTRY PsLoadedModuleList = { 0 };
	PsLoadedModuleList.Blink = PsLoadedModuleList.Flink = (PLIST_ENTRY)m_PsLoadedModuleListBase;

	uc_mem_write(m_uc, m_PsLoadedModuleListBase, &PsLoadedModuleList, sizeof(PsLoadedModuleList));

	for (size_t i = 0; i < m_FakeModules.size(); ++i)
	{
		auto LdrEntryBase = HeapAlloc(sizeof(KLDR_DATA_TABLE_ENTRY));

		KLDR_DATA_TABLE_ENTRY LdrEntry = { 0 };
		LdrEntry.DllBase = (PVOID)m_FakeModules[i]->ImageBase;
		LdrEntry.LoadCount = 1;
		LdrEntry.EntryPoint = (PVOID)m_FakeModules[i]->ImageEntry;
		LdrEntry.SizeOfImage = m_FakeModules[i]->ImageSize;

		auto fullname = L"\\SystemRoot\\system32\\drivers\\" + m_FakeModules[i]->DllName;
		LdrEntry.FullDllName.Length = (USHORT)fullname.length() * sizeof(WCHAR);
		LdrEntry.FullDllName.MaximumLength = ((USHORT)fullname.length() + 1) * sizeof(WCHAR);
		auto FullDllNameBase = HeapAlloc(LdrEntry.FullDllName.MaximumLength);
		LdrEntry.FullDllName.Buffer = (PWSTR)FullDllNameBase;

		LdrEntry.BaseDllName.Length = (USHORT)fullname.length() - (_countof(L"\\SystemRoot\\system32\\drivers\\") - 1) * sizeof(WCHAR);
		LdrEntry.BaseDllName.MaximumLength = ((USHORT)fullname.length() + 1 - (_countof(L"\\SystemRoot\\system32\\drivers\\") - 1)) * sizeof(WCHAR);
		auto BaseDllNameBase = FullDllNameBase + (_countof(L"\\SystemRoot\\system32\\drivers\\") - 1) * sizeof(WCHAR);
		LdrEntry.BaseDllName.Buffer = (PWSTR)BaseDllNameBase;

		LdrEntry.ExceptionTable = (PVOID)m_FakeModules[i]->ExceptionTable;
		LdrEntry.ExceptionTableSize = m_FakeModules[i]->ExceptionTableSize;

		uc_mem_write(m_uc, FullDllNameBase, fullname.data(), LdrEntry.FullDllName.MaximumLength);

		uc_mem_write(m_uc, LdrEntryBase, &LdrEntry, sizeof(LdrEntry));

		if (m_FakeModules[i]->ImageBase == m_ImageBase)
		{
			m_DriverLdrEntry = LdrEntryBase;
			m_MainModuleIndex = (int)i;
		}

		InsertTailList(m_PsLoadedModuleListBase, LdrEntryBase);
	}

	return;
}

// About: Function for intialization of DriverObject
// Mode: Kernelmode
void PeEmulation::InitDriverObject()
{
	m_DriverObjectBase = HeapAlloc(sizeof(DRIVER_OBJECT));

	DRIVER_OBJECT DriverObject = { 0 };
	DriverObject.DriverSize = (ULONG)(m_ImageEnd - m_ImageBase);
	DriverObject.DriverStart = (PVOID)m_ImageBase;
	DriverObject.DriverInit = (PVOID)m_ImageEntry;
	DriverObject.Size = sizeof(DRIVER_OBJECT);
	DriverObject.DriverSection = (PVOID)m_DriverLdrEntry;

	uc_mem_write(m_uc, m_DriverObjectBase, &DriverObject, sizeof(DriverObject));

	return;
}

// About: Function for sorting of module list by Priority, i.e. value1->Priority > value2->Priority
// Mode: Kernelmode
void PeEmulation::SortModuleList()
{
	std::sort(m_FakeModules.begin(), m_FakeModules.end(),
		[](const FakeModule* value1, const FakeModule* value2)
		{
			return value1->Priority > value2->Priority;
		});
}

int main(int argc, char** argv)
{
	using namespace blackbone;

	PeEmulation ctx;

	if (argc < 2)
	{
		printf("usage: unicorn_pe (filename) [-k] [-disasm]\n");
		return -1;
	}

	outs = &std::cout;

	std::string filename = argv[1];
	std::wstring wfilename;
	ANSIToUnicode(filename, wfilename);

	bool bKernel = true;

	{
		for (int i = 2; i < argc; ++i)
		{
			if (!strcmp(argv[i], "-k"))
			{
				ctx.m_IsKernel = true;
			}
			if (!strcmp(argv[i], "-disasm"))
			{
				ctx.m_DisplayDisasm = true;
			}
			if (!strcmp(argv[i], "-packed"))
			{
				ctx.m_IsPacked = true;
			}
			if (!strcmp(argv[i], "-boundcheck"))
			{
				ctx.m_BoundCheck = true;
			}
			if (!strcmp(argv[i], "-dump"))
			{
				ctx.m_Dump = true;
			}
		}
	}

	uc_engine* uc = NULL;
	auto err = uc_open(UC_ARCH_X86, UC_MODE_64, &uc);
	if (err)
	{
		printf("failed to uc_open %d\n", err);
		return -1;
	}

	ctx.m_uc = uc;
	ctx.thisProc.Attach(GetCurrentProcessId());

	uc_hook ucHookInvalidRwx = 0, ucHookRwx = 0, ucHookCode = 0, ucHookIntr = 0;

	DWORD_PTR Stack = (!ctx.m_IsKernel) ? 0x40000 : 0xFFFFFC0000000000ull;
	size_t StackSize = 0x10000;

	virtual_buffer_t StackBuf;
	if (!StackBuf.GetSpace(StackSize))
	{
		printf("failed to allocate virtual stack\n");
		return 0;
	}

	//allocate virtual stack for execution
	memset(StackBuf.GetBuffer(), 0, StackBuf.GetLength());
	uc_mem_map(uc, Stack, StackSize, UC_PROT_READ | UC_PROT_WRITE);
	uc_mem_write(uc, Stack, StackBuf.GetBuffer(), StackSize);

	ctx.m_StackBase = Stack;
	ctx.m_StackEnd = Stack + StackSize;
	ctx.m_LoadModuleBase = (!ctx.m_IsKernel) ? 0x180000000ull : 0xFFFFF80000000000ull;
	ctx.m_HeapBase = (!ctx.m_IsKernel) ? 0x10000000ull : 0xFFFFFA0000000000ull;
	ctx.m_HeapEnd = ctx.m_HeapBase + 0x1000000ull;

	uc_mem_map(uc, ctx.m_HeapBase, ctx.m_HeapEnd - ctx.m_HeapBase, (ctx.m_IsKernel) ? UC_PROT_READ | UC_PROT_WRITE | UC_PROT_EXEC : UC_PROT_READ | UC_PROT_WRITE);

	auto MapResult = ctx.thisProc.mmap().MapImage(wfilename,
		ManualImports | NoSxS | NoExceptions | NoDelayLoad | NoTLS | NoExceptions | NoExec,
		ManualMapCallback, &ctx, 0);

	if (!MapResult.success())
	{
		printf("failed to MapImage\n");
		return 0;
	}

	auto res = MapResult.result();
	// LDR_DATA_TABLE_ENTRY_BASE_T* p = res->
	ctx.m_PathExe = wfilename;
	ctx.m_ImageBase = res->baseAddress;
	ctx.m_ImageEnd = res->baseAddress + res->size;
	ctx.m_ImageEntry = ctx.m_ImageBase + ExtractEntryPointRva((PVOID)res->imgPtr);
	ctx.m_LastRipModule = ctx.m_ImageBase;
	ctx.m_ExecuteFromRip = ctx.m_ImageEntry;

	if (!ctx.m_IsKernel)
	{
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemTimeAsFileTime", EmuApi::EmuGetSystemTimeAsFileTime);

		///////////////////////////////////////////////////////////////////////////////ANTI-DEBUG
		ctx.RegisterAPIEmulation(L"kernel32.dll", "IsDebuggerPresent", EmuApi::EmuIsDebuggerPresent);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "CheckRemoteDebuggerPresent", EmuApi::EmuCheckRemoteDebuggerPresent);
		///////////////////////////////////////////////////////////////////////////////ANTI-DEBUG

		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentThreadId", EmuApi::EmuGetCurrentThreadId);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentProcessId", EmuApi::EmuGetCurrentProcessId);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "QueryPerformanceCounter", EmuApi::EmuQueryPerformanceCounter);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "LoadLibraryExW", EmuApi::EmuLoadLibraryExW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "LoadLibraryA", EmuApi::EmuLoadLibraryA);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcAddress", EmuApi::EmuGetProcAddress);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleHandleA", EmuApi::EmuGetModuleHandleA);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleHandleW", EmuApi::EmuGetModuleHandleW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLastError", EmuApi::EmuGetLastError);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeCriticalSectionAndSpinCount", EmuApi::EmuInitializeCriticalSectionAndSpinCount);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleFileNameA", EmuApi::EmuGetModuleFileNameA);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleFileNameW", EmuApi::EmuGetModuleFileNameW);

		////////////////////////////////////////////////////////////////////////////////GUI
		ctx.RegisterAPIEmulation(L"user32.dll", "MessageBoxA", EmuApi::EmuMessageBoxA);
		ctx.RegisterAPIEmulation(L"user32.dll", "MessageBoxW", EmuApi::EmuMessageBoxW);
		ctx.RegisterAPIEmulation(L"user32.dll", "GetProcessWindowStation", EmuApi::EmuGetProcessWindowStation);
		ctx.RegisterAPIEmulation(L"user32.dll", "GetUserObjectInformationW", EmuApi::EmuGetUserObjectInformationW);
		ctx.RegisterAPIEmulation(L"user32.dll", "GetUserObjectInformationA", EmuApi::EmuGetUserObjectInformationA);
		////////////////////////////////////////////////////////////////////////////////GUI

		if (!ctx.RegisterAPIEmulation(L"kernelbase.dll", "InitializeCriticalSectionEx", EmuApi::EmuInitializeCriticalSectionEx))
			ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeCriticalSectionEx", EmuApi::EmuInitializeCriticalSectionEx);

		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlDeleteCriticalSection", EmuApi::EmuDeleteCriticalSection);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlIsProcessorFeaturePresent", EmuApi::EmuRtlIsProcessorFeaturePresent);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessAffinityMask", EmuApi::EmuGetProcessAffinityMask);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsAlloc", EmuApi::EmuTlsAlloc);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsSetValue", EmuApi::EmuTlsSetValue);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsFree", EmuApi::EmuTlsFree);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "LocalAlloc", EmuApi::EmuLocalAlloc);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "LocalFree", EmuApi::EmuLocalFree);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "CloseHandle", EmuApi::EmuCloseHandle);

		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtProtectVirtualMemory", EmuApi::EmuNtProtectVirtualMemory);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtQueryInformationProcess", EmuApi::EmuNtQueryInformationProcess);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtSetInformationThread", EmuApi::EmuNtSetInformationThread);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtQuerySystemInformation", EmuApi::EmuNtQuerySystemInformation);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtOpenFile", EmuApi::EmuNtOpenFile);

		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlAllocateHeap", EmuApi::EmuRtlAllocateHeap);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlFreeHeap", EmuApi::EmuRtlFreeHeap);
	}
	else
	{
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "ExAllocatePool", EmuApi::EmuExAllocatePool);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "ExAllocatePoolWithTag", EmuApi::EmuExAllocatePool);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "NtQuerySystemInformation", EmuApi::EmuNtQuerySystemInformation);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "ZwQuerySystemInformation", EmuApi::EmuNtQuerySystemInformation);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "ExFreePool", EmuApi::EmuExFreePool);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "ExFreePoolWithTag", EmuApi::EmuExFreePoolWithTag);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "IoAllocateMdl", EmuApi::EmuIoAllocateMdl);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "MmProbeAndLockPages", EmuApi::EmuMmProbeAndLockPages);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "MmMapLockedPagesSpecifyCache", EmuApi::EmuMmMapLockedPagesSpecifyCache);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "KeQueryActiveProcessors", EmuApi::EmuKeQueryActiveProcessors);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "KeSetSystemAffinityThread", EmuApi::EmuKeSetSystemAffinityThread);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "KeRevertToUserAffinityThread", EmuApi::EmuKeRevertToUserAffinityThread);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "MmUnlockPages", EmuApi::EmuMmUnlockPages);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "IoFreeMdl", EmuApi::EmuIoFreeMdl);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "RtlGetVersion", EmuApi::EmuRtlGetVersion);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "DbgPrint", EmuApi::EmuDbgPrint);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "KeInitializeMutex", EmuApi::EmuKeInitializeMutex);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "RtlInitUnicodeString", EmuApi::EmuRtlInitUnicodeString);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "KeWaitForSingleObject", EmuApi::EmuKeWaitForSingleObject);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "KeWaitForMutexObject", EmuApi::EmuKeWaitForSingleObject);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "KeReleaseMutex", EmuApi::EmuKeReleaseMutex);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "srand", EmuApi::Emusrand);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "rand", EmuApi::Emurand);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "RtlZeroMemory", EmuApi::EmuRtlZeroMemory);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "RtlCopyMemory", EmuApi::EmuRtlCopyMemory);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "RtlFillMemory", EmuApi::EmuRtlFillMemory);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "wcsstr", EmuApi::Emuwcsstr);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "MmIsAddressValid", EmuApi::EmuMmIsAddressValid);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "ExGetPreviousMode", EmuApi::EmuExGetPreviousMode);
		ctx.RegisterAPIEmulation(L"ntoskrnl.exe", "__C_specific_handler", EmuApi::Emu__C_specific_handler);
	}

	memset(&ctx.m_InitReg, 0, sizeof(ctx.m_InitReg));
	ctx.m_InitReg.Rsp = ctx.m_StackEnd - 64;

	ctx.InitProcessorState();

	if (!ctx.m_IsKernel)
	{
		ctx.InitTebPeb();

		ctx.m_InitReg.Rcx = ctx.m_ImageBase;
		ctx.m_InitReg.Rdx = DLL_PROCESS_ATTACH;
		ctx.m_InitReg.R8 = 0;
	}
	else
	{
		ctx.SortModuleList();
		ctx.InitPsLoadedModuleList();
		ctx.InitDriverObject();

		ctx.m_InitReg.Rcx = ctx.m_DriverObjectBase;
		ctx.m_InitReg.Rdx = 0;
	}

	ctx.InitKSharedUserData();

	//return to image end when entrypoint is executed
	uc_mem_write(uc, ctx.m_InitReg.Rsp, &ctx.m_ImageEnd, sizeof(ctx.m_ImageEnd));
	uc_mem_map(uc, ctx.m_ImageEnd, 0x1000, UC_PROT_EXEC | UC_PROT_READ);

	uc_reg_write(uc, UC_X86_REG_RAX, &ctx.m_InitReg.Rax);
	uc_reg_write(uc, UC_X86_REG_RBX, &ctx.m_InitReg.Rbx);
	uc_reg_write(uc, UC_X86_REG_RCX, &ctx.m_InitReg.Rcx);
	uc_reg_write(uc, UC_X86_REG_RDX, &ctx.m_InitReg.Rdx);
	uc_reg_write(uc, UC_X86_REG_RSI, &ctx.m_InitReg.Rsi);
	uc_reg_write(uc, UC_X86_REG_RDI, &ctx.m_InitReg.Rdi);
	uc_reg_write(uc, UC_X86_REG_R8, &ctx.m_InitReg.R8);
	uc_reg_write(uc, UC_X86_REG_R9, &ctx.m_InitReg.R9);
	uc_reg_write(uc, UC_X86_REG_R10, &ctx.m_InitReg.R10);
	uc_reg_write(uc, UC_X86_REG_R11, &ctx.m_InitReg.R11);
	uc_reg_write(uc, UC_X86_REG_R12, &ctx.m_InitReg.R12);
	uc_reg_write(uc, UC_X86_REG_R13, &ctx.m_InitReg.R13);
	uc_reg_write(uc, UC_X86_REG_R14, &ctx.m_InitReg.R14);
	uc_reg_write(uc, UC_X86_REG_R15, &ctx.m_InitReg.R15);
	uc_reg_write(uc, UC_X86_REG_RBP, &ctx.m_InitReg.Rbp);
	uc_reg_write(uc, UC_X86_REG_RSP, &ctx.m_InitReg.Rsp);

	//////////////////////////////////////////////////////////////// HOOKS_SPACE
	{
		uc_hook_add(uc, &ucHookInvalidRwx, UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED |
			UC_HOOK_MEM_FETCH_UNMAPPED | UC_HOOK_MEM_FETCH_PROT | UC_HOOK_MEM_WRITE_PROT,
			ucHooks::HookInvalidRwx, &ctx, 1, 0);

		uc_hook_add(uc, &ucHookRwx, UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE | UC_HOOK_MEM_FETCH,
			ucHooks::HookRwx, &ctx, 1, 0);

		uc_hook_add(uc, &ucHookCode, UC_HOOK_CODE,
			ucHooks::HookCode, &ctx, 1, 0);

		uc_hook_add(uc, &ucHookIntr, UC_HOOK_INTR,
			ucHooks::HookIntr, &ctx, 1, 0);
	}
	//////////////////////////////////////////////////////////////// HOOKS_SPACE

	//Infinity while loop and start of emulation
	while (true)
	{
		err = uc_emu_start(uc, ctx.m_ExecuteFromRip, ctx.m_ImageEnd, 0, 0);

		if (ctx.m_LastException != STATUS_SUCCESS)
		{
			auto except = ctx.m_LastException;
			ctx.m_LastException = STATUS_SUCCESS;
			ctx.RtlRaiseStatus(except);
		}
		else { break; }
	}

	//////////////////////////////////////////////////////////////// HOOKS_SPACE
	{
		uc_hook_del(uc, ucHookInvalidRwx);
		uc_hook_del(uc, ucHookRwx);
		uc_hook_del(uc, ucHookCode);
		uc_hook_del(uc, ucHookIntr);
	}
	//////////////////////////////////////////////////////////////// HOOKS_SPACE

	DWORD_PTR result_rax = 0;
	uc_reg_read(uc, UC_X86_REG_RAX, &result_rax);

	//deumping of our image if we selected -dump flag
	if (ctx.m_Dump)
	{
		//virtual_buffer_t imagebuf(ctx.m_ImageEnd - ctx.m_ImageBase);
		//virtual_buffer_t RebuildSectionBuffer;
		//
		//uc_mem_read(uc, ctx.m_ImageBase, imagebuf.GetBuffer(), ctx.m_ImageEnd - ctx.m_ImageBase);
		//
		//auto ntheader = RtlImageNtHeader(imagebuf.GetBuffer());
		//
		//auto SectionHeader = (PIMAGE_SECTION_HEADER)((PUCHAR)ntheader + sizeof(ntheader->Signature) + \
		//	sizeof(ntheader->FileHeader) + ntheader->FileHeader.SizeOfOptionalHeader);
		//
		//auto SectionCount = ntheader->FileHeader.NumberOfSections;
		//for (USHORT i = 0; i < SectionCount; ++i)
		//{
		//	SectionHeader[i].PointerToRawData = SectionHeader[i].VirtualAddress;
		//	SectionHeader[i].SizeOfRawData = SectionHeader[i].Misc.VirtualSize;
		//}
		//
		//ctx.RebuildSection(imagebuf.GetBuffer(), (DWORD)(ctx.m_ImageEnd - ctx.m_ImageBase), RebuildSectionBuffer);
		//
		//if (ctx.m_ImageRealEntry)
		//{
		//	ntheader->OptionalHeader.AddressOfEntryPoint = (DWORD)(ctx.m_ImageRealEntry - ctx.m_ImageBase);
		//}
		//
		//auto dumpfile = filename + ".dump";
		//
		//FILE* fp = nullptr;
		//fopen_s(&fp, dumpfile.c_str(), "wb");
		//
		//fwrite(imagebuf.GetBuffer(), ctx.m_ImageEnd - ctx.m_ImageBase, 1, fp);
		//
		//if (RebuildSectionBuffer.GetBuffer())
		//{
		//	fwrite(RebuildSectionBuffer.GetBuffer(), RebuildSectionBuffer.GetLength(), 1, fp);
		//}
		//
		//fclose(fp);
	}

	uc_close(uc);

	ctx.thisProc.mmap().UnmapAllModules();

	*outs << "uc_emu_start return: " << std::dec << err << "\n";

	*outs << "entrypoint return: " << std::hex << result_rax << "\n";
	*outs << "last rip: " << std::hex << ctx.m_LastRip;

	std::stringstream RipRegion, RealentryRegion;
	if (ctx.FindAddressInRegion(ctx.m_LastRip, RipRegion))
		*outs << " (" << RipRegion.str() << ")\n";

	if (ctx.m_ImageRealEntry)
	{
		if (ctx.FindAddressInRegion(ctx.m_ImageRealEntry, RealentryRegion))
			*outs << "real entrypoint: " << RealentryRegion.str() << "\n";
	}

	outs->flush();

	return 0;
}