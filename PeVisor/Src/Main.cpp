#include "UCPE.hpp"
#include <EmuApiFuncs.hpp>

std::ostream* outs;

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
	RTL_USER_PROCESS_PARAMETERS LocalProcessParameters{};
	PRTL_USER_PROCESS_PARAMETERS EmuProcessParameters = (PRTL_USER_PROCESS_PARAMETERS)HeapAlloc(sizeof(RTL_USER_PROCESS_PARAMETERS));

	std::wstring MyEnvironment = GetEnvironmentStringsW();
	LPWCH EmuEnvironment = (LPWCH)HeapAlloc(MyEnvironment.size() * sizeof(wchar_t));

	InternalEmuApi::EmuCopyUnicodeStrs(m_uc, EmuEnvironment, MyEnvironment);

	LocalProcessParameters.Environment = (PVOID)EmuEnvironment;

	uc_mem_write(m_uc, (DWORD_PTR)EmuProcessParameters, &LocalProcessParameters, sizeof(RTL_USER_PROCESS_PARAMETERS));

	

	m_PebBase = 0x90000ull;
	m_PebEnd = m_PebBase + AlignSize(sizeof(PEB), PAGE_SIZE);
	m_LdrBase = 0x70000ull;
	m_LdrEnd = m_LdrBase + AlignSize(sizeof(PEB_LDR_DATA), PAGE_SIZE);

	peb.Ldr = (PPEB_LDR_DATA)m_LdrBase;
	peb.ProcessParameters = EmuProcessParameters;
	peb.InheritedAddressSpace = NtCurrentPeb()->InheritedAddressSpace; // apparently this is always getting initialized with 0
	peb.ReadImageFileExecOptions = NtCurrentPeb()->ReadImageFileExecOptions;
	peb.BeingDebugged = NtCurrentPeb()->BeingDebugged;
	peb.BitField = NtCurrentPeb()->BitField;
	peb.Mutant = NtCurrentPeb()->Mutant;
	InitLdrModuleList(); // need to initialize this structure inside that method
	peb.ImageBaseAddress = NtCurrentPeb()->ImageBaseAddress;
	peb.ProcessParameters = NtCurrentPeb()->ProcessParameters; // this should be implemented something like peb.ProcessParameters = getProcessParameters()?
	peb.SubSystemData = NtCurrentPeb()->SubSystemData;
	peb.ProcessHeap = NtCurrentPeb()->ProcessHeap; // // this is intialized to 0x000002413f480000. Which one to keep?
	peb.FastPebLock = NtCurrentPeb()->FastPebLock; 
	peb.AtlThunkSListPtr = NtCurrentPeb()->AtlThunkSListPtr;
	peb.IFEOKey = NtCurrentPeb()->IFEOKey;
	peb.CrossProcessFlags = NtCurrentPeb()->CrossProcessFlags;
	peb.KernelCallbackTable = NtCurrentPeb()->KernelCallbackTable;
	peb.UserSharedInfoPtr = NtCurrentPeb()->UserSharedInfoPtr;
	peb.SystemReserved = NtCurrentPeb()->SystemReserved;
	peb.AtlThunkSListPtr32 = NtCurrentPeb()->AtlThunkSListPtr32;
	peb.ApiSetMap = NtCurrentPeb()->ApiSetMap;
	peb.TlsExpansionCounter = NtCurrentPeb()->TlsExpansionCounter;
	peb.TlsBitmap = NtCurrentPeb()->TlsBitmap;
	peb.TlsBitmapBits[1] = TLS_MINIMUM_AVAILABLE;
	peb.ReadOnlySharedMemoryBase = NtCurrentPeb()->ReadOnlySharedMemoryBase;
	peb.SharedData = NtCurrentPeb()->SharedData;
	peb.ReadOnlyStaticServerData = NtCurrentPeb()->ReadOnlyStaticServerData;
	peb.AnsiCodePageData = NtCurrentPeb()->AnsiCodePageData;
	peb.OemCodePageData = NtCurrentPeb()->OemCodePageData;
	peb.UnicodeCaseTableData = NtCurrentPeb()->UnicodeCaseTableData;
	peb.NumberOfProcessors = NtCurrentPeb()->NumberOfProcessors;
	peb.NtGlobalFlag = NtCurrentPeb()->NtGlobalFlag;
	peb.CriticalSectionTimeout = NtCurrentPeb()->CriticalSectionTimeout;
	peb.HeapSegmentReserve = NtCurrentPeb()->HeapSegmentReserve;
	peb.HeapSegmentCommit = NtCurrentPeb()->HeapSegmentCommit;
	peb.HeapDeCommitTotalFreeThreshold = NtCurrentPeb()->HeapDeCommitTotalFreeThreshold;
	peb.HeapDeCommitFreeBlockThreshold = NtCurrentPeb()->HeapDeCommitFreeBlockThreshold;
	peb.NumberOfHeaps = NtCurrentPeb()->NumberOfHeaps;
	peb.MaximumNumberOfHeaps = NtCurrentPeb()->MaximumNumberOfHeaps;
	peb.ProcessHeaps = NtCurrentPeb()->ProcessHeaps; // is a pointer to an array of heap pointers, their count is NumberOfHeaps.
	peb.GdiSharedHandleTable = NtCurrentPeb()->GdiSharedHandleTable;
	peb.ProcessStarterHelper = NtCurrentPeb()->ProcessStarterHelper;
	peb.GdiDCAttributeList = NtCurrentPeb()->GdiDCAttributeList;
	peb.LoaderLock = NtCurrentPeb()->LoaderLock;
	peb.OSMajorVersion = NtCurrentPeb()->OSMajorVersion;
	peb.OSMinorVersion = NtCurrentPeb()->OSMinorVersion;
	peb.OSBuildNumber = NtCurrentPeb()->OSBuildNumber;
	peb.OSCSDVersion = NtCurrentPeb()->OSCSDVersion;
	peb.OSPlatformId = NtCurrentPeb()->OSPlatformId;
	peb.ImageSubsystem = NtCurrentPeb()->ImageSubsystem;
	peb.ImageSubsystemMajorVersion = NtCurrentPeb()->ImageSubsystemMajorVersion;
	peb.ImageSubsystemMinorVersion = NtCurrentPeb()->ImageSubsystemMinorVersion;
	peb.ActiveProcessAffinityMask = NtCurrentPeb()->ActiveProcessAffinityMask;
	peb.GdiHandleBuffer[59] = NtCurrentPeb()->GdiHandleBuffer[59]; 
	peb.PostProcessInitRoutine = NtCurrentPeb()->PostProcessInitRoutine;
	peb.TlsExpansionBitmap = NtCurrentPeb()->TlsExpansionBitmap;
	peb.TlsExpansionBitmapBits[31] = NtCurrentPeb()->TlsExpansionBitmapBits[31];
	peb.SessionId = NtCurrentPeb()->SessionId;
	peb.AppCompatFlags = NtCurrentPeb()->AppCompatFlags;
	peb.AppCompatFlagsUser = NtCurrentPeb()->AppCompatFlagsUser;
	peb.pShimData = NtCurrentPeb()->pShimData;
	peb.AppCompatInfo = NtCurrentPeb()->AppCompatInfo;
	peb.CSDVersion = NtCurrentPeb()->CSDVersion;
	peb.ActivationContextData = NtCurrentPeb()->ActivationContextData;
	peb.ProcessAssemblyStorageMap = NtCurrentPeb()->ProcessAssemblyStorageMap;
	peb.SystemDefaultActivationContextData = NtCurrentPeb()->SystemDefaultActivationContextData;
	peb.SystemAssemblyStorageMap = NtCurrentPeb()->SystemAssemblyStorageMap;
	peb.MinimumStackCommit = NtCurrentPeb()->MinimumStackCommit;
	peb.SparePointers[1] = NtCurrentPeb()->SparePointers[1];
	peb.PatchLoaderData = NtCurrentPeb()->PatchLoaderData;
	peb.ChpeV2ProcessInfo = NtCurrentPeb()->ChpeV2ProcessInfo;
	peb.AppModelFeatureState = NtCurrentPeb()->AppModelFeatureState;
	peb.SpareUlongs[1] = NtCurrentPeb()->SpareUlongs[1];
	peb.ActiveCodePage = NtCurrentPeb()->ActiveCodePage;
	peb.OemCodePage = NtCurrentPeb()->OemCodePage;
	peb.UseCaseMapping = NtCurrentPeb()->UseCaseMapping;
	peb.UnusedNlsField = NtCurrentPeb()->UnusedNlsField;
	peb.WerRegistrationData = NtCurrentPeb()->WerRegistrationData;
	peb.WerShipAssertPtr = NtCurrentPeb()->WerShipAssertPtr;
	peb.EcCodeBitMap = NtCurrentPeb()->EcCodeBitMap;
	peb.pImageHeaderHash = NtCurrentPeb()->pImageHeaderHash;
	peb.TracingFlags = NtCurrentPeb()->TracingFlags;
	peb.CsrServerReadOnlySharedMemoryBase = NtCurrentPeb()->CsrServerReadOnlySharedMemoryBase;
	peb.TppWorkerpListLock = NtCurrentPeb()->TppWorkerpListLock;
	peb.TppWorkerpList = NtCurrentPeb()->TppWorkerpList;
	peb.WaitOnAddressHashTable[127] = NtCurrentPeb()->WaitOnAddressHashTable[127];
	peb.TelemetryCoverageHeader = NtCurrentPeb()->TelemetryCoverageHeader;
	peb.CloudFileFlags = NtCurrentPeb()->CloudFileFlags;
	peb.CloudFileDiagFlags = NtCurrentPeb()->CloudFileDiagFlags;
	peb.PlaceholderCompatibilityMode = NtCurrentPeb()->PlaceholderCompatibilityMode;
	peb.PlaceholderCompatibilityModeReserved[6] = NtCurrentPeb()->PlaceholderCompatibilityModeReserved[6];
	peb.LeapSecondData = NtCurrentPeb()->LeapSecondData;
	peb.LeapSecondFlags = NtCurrentPeb()->LeapSecondFlags;
	peb.NtGlobalFlag2 = NtCurrentPeb()->NtGlobalFlag2;
	peb.ExtendedFeatureDisableMask = NtCurrentPeb()->ExtendedFeatureDisableMask;
	uc_mem_map(m_uc, m_PebBase, m_PebEnd - m_PebBase, UC_PROT_READ);
	uc_mem_write(m_uc, m_PebBase, &peb, sizeof(PEB));

	m_TebBase = 0x80000ull;
	m_TebEnd = m_TebBase + AlignSize(sizeof(TEB), PAGE_SIZE);

	TEB teb = { 0 };

	teb.ProcessEnvironmentBlock = (PPEB)m_PebBase;

	uc_mem_map(m_uc, m_TebBase, m_TebEnd - m_TebBase, UC_PROT_READ);
	uc_mem_write(m_uc, m_TebBase, &teb, sizeof(TEB));

	int StackBase = 0x8;
	int StackLimit = 0x10;
	uc_mem_write(m_uc, m_TebBase + StackBase, &m_StackBase, sizeof(m_StackBase));
	uc_mem_write(m_uc, m_TebBase + StackLimit, &m_StackEnd, sizeof(m_StackEnd));

	uc_x86_msr MsrIa32GsBase;
	MsrIa32GsBase.rid = (uint32_t)Msr::kIa32GsBase;
	MsrIa32GsBase.value = m_TebBase;

	uc_reg_write(m_uc, UC_X86_REG_MSR, &MsrIa32GsBase);

	CR4 cr4{};
	cr4.x64.Bitmap.VME = true;
	cr4.x64.Bitmap.PVI = true;
	cr4.x64.Bitmap.TSD = false;
	cr4.x64.Bitmap.DE = false;
	cr4.x64.Bitmap.PSE = false;
	cr4.x64.Bitmap.PAE = false;
	cr4.x64.Bitmap.MCE = true;
	cr4.x64.Bitmap.PGE = false;
	cr4.x64.Bitmap.PCE = true;
	cr4.x64.Bitmap.OSFXSR = true;
	cr4.x64.Bitmap.OSXMMEXCPT = true;
	cr4.x64.Bitmap.UMIP = true;
	cr4.x64.Bitmap.LA57 = false;
	cr4.x64.Bitmap.VMXE = false;
	cr4.x64.Bitmap.SMXE = true;
	cr4.x64.Bitmap.FSGSBASE = true;
	cr4.x64.Bitmap.PCIDE = false;
	cr4.x64.Bitmap.OSXSAVE = true;
	cr4.x64.Bitmap.KL = true;
	cr4.x64.Bitmap.SMEP = false;
	cr4.x64.Bitmap.SMAP = false;
	cr4.x64.Bitmap.PKE = false;
	cr4.x64.Bitmap.CET = true;
	cr4.x64.Bitmap.PKS = false;
	cr4.x64.Bitmap.UINTR = false;

	uc_reg_write(m_uc, UC_X86_REG_CR4, &cr4.Value);
}

// About: Function for intialization of PsLoadedModuleList in usermode app
// Mode: Usermode
void PeEmulation::InitLdrModuleList()
{
	PEB_LDR_DATA Ldr{};

	Ldr.InInitializationOrderModuleList.Flink = (_LIST_ENTRY*)HeapAlloc(sizeof(LIST_ENTRY));
	Ldr.InMemoryOrderModuleList.Flink = (_LIST_ENTRY*)HeapAlloc(sizeof(LIST_ENTRY));
	Ldr.InLoadOrderModuleList.Flink = (_LIST_ENTRY*)HeapAlloc(sizeof(LIST_ENTRY));

	Ldr.Length = m_FakeModules.size() - 1;
	Ldr.Initialized = true;
	

	LIST_ENTRY PsLoadedModuleList = { 0 };
	PsLoadedModuleList.Blink = PsLoadedModuleList.Flink = (PLIST_ENTRY)Ldr.InInitializationOrderModuleList.Flink;

	LIST_ENTRY PsLoadedModuleList1 = { 0 };
	PsLoadedModuleList1.Blink = PsLoadedModuleList1.Flink = (PLIST_ENTRY)Ldr.InMemoryOrderModuleList.Flink;

	LIST_ENTRY PsLoadedModuleList2 = { 0 };
	PsLoadedModuleList2.Blink = PsLoadedModuleList2.Flink = (PLIST_ENTRY)Ldr.InLoadOrderModuleList.Flink;

	uc_mem_write(m_uc, (DWORD_PTR)Ldr.InInitializationOrderModuleList.Flink, &PsLoadedModuleList, sizeof(PsLoadedModuleList));
	uc_mem_write(m_uc, (DWORD_PTR)Ldr.InMemoryOrderModuleList.Flink, &PsLoadedModuleList1, sizeof(PsLoadedModuleList));
	uc_mem_write(m_uc, (DWORD_PTR)Ldr.InLoadOrderModuleList.Flink, &PsLoadedModuleList2, sizeof(PsLoadedModuleList));

	for (size_t i = 0; i < m_FakeModules.size(); ++i)
	{
		auto LdrEntryBase = HeapAlloc(sizeof(LDR_DATA_TABLE_ENTRY));

		LDR_DATA_TABLE_ENTRY LdrEntry = { 0 };
		LdrEntry.DllBase = (PVOID)m_FakeModules[i]->ImageBase;
		LdrEntry.ReferenceCount = 1;
		LdrEntry.EntryPoint = (PLDR_INIT_ROUTINE)m_FakeModules[i]->ImageEntry;
		LdrEntry.SizeOfImage = m_FakeModules[i]->ImageSize;

		LdrEntry.FullDllName.Length = (USHORT)m_FakeModules[i]->FullPath.wstring().length() * sizeof(WCHAR);
		LdrEntry.FullDllName.MaximumLength = ((USHORT)(m_FakeModules[i]->FullPath.wstring().length() + 1) * sizeof(WCHAR));
		PWSTR FullDllNameBase = (PWSTR)HeapAlloc(LdrEntry.FullDllName.MaximumLength);
		LdrEntry.FullDllName.Buffer = FullDllNameBase;

		LdrEntry.BaseDllName.Length = (USHORT)m_FakeModules[i]->DllName.length() * sizeof(WCHAR);
		LdrEntry.BaseDllName.MaximumLength = ((USHORT)(m_FakeModules[i]->DllName.length() + 1) * sizeof(WCHAR));
		PWSTR BaseDllNameBase = (PWSTR)HeapAlloc(LdrEntry.BaseDllName.MaximumLength);
		LdrEntry.BaseDllName.Buffer = BaseDllNameBase;

		//printf("%p\n", BaseDllNameBase);
		//printf("%p\n", LdrEntryBase);

		InternalEmuApi::EmuCopyUnicodeStrs(m_uc, FullDllNameBase, m_FakeModules[i]->FullPath);
		InternalEmuApi::EmuCopyUnicodeStrs(m_uc, BaseDllNameBase, m_FakeModules[i]->DllName);

		uc_mem_write(m_uc, LdrEntryBase, &LdrEntry, sizeof(LdrEntry));

		InsertTailList((DWORD_PTR)Ldr.InInitializationOrderModuleList.Flink, LdrEntryBase);
		InsertTailList((DWORD_PTR)Ldr.InMemoryOrderModuleList.Flink, LdrEntryBase);
		InsertTailList((DWORD_PTR)Ldr.InLoadOrderModuleList.Flink, LdrEntryBase);
	}

	m_LdrBase = 0x70000ull;
	m_LdrEnd = m_LdrBase + AlignSize(sizeof(PEB_LDR_DATA), PAGE_SIZE);
	uc_mem_map(m_uc, m_LdrBase, m_LdrEnd - m_LdrBase, UC_PROT_READ);
	uc_mem_write(m_uc, m_LdrBase, &Ldr, sizeof(PEB_LDR_DATA));

	return;
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

		auto fullname = m_FakeModules[i]->FullPath.wstring();
		LdrEntry.FullDllName.Length = (USHORT)fullname.length() * sizeof(WCHAR);
		LdrEntry.FullDllName.MaximumLength = ((USHORT)fullname.length() + 1) * sizeof(WCHAR);
		auto FullDllNameBase = HeapAlloc(LdrEntry.FullDllName.MaximumLength);
		LdrEntry.FullDllName.Buffer = (PWSTR)FullDllNameBase;

		auto BaseDllName = m_FakeModules[i]->DllName;
		LdrEntry.BaseDllName.Length = (USHORT)m_FakeModules[i]->DllName.length() * sizeof(WCHAR);
		LdrEntry.BaseDllName.MaximumLength = ((USHORT)m_FakeModules[i]->DllName.length() + 1) * sizeof(WCHAR);
		auto BaseDllNameBase = HeapAlloc(LdrEntry.BaseDllName.MaximumLength);
		LdrEntry.BaseDllName.Buffer = (PWSTR)BaseDllNameBase;

		LdrEntry.ExceptionTable = (PVOID)m_FakeModules[i]->ExceptionTable;
		LdrEntry.ExceptionTableSize = m_FakeModules[i]->ExceptionTableSize;

		uc_mem_write(m_uc, FullDllNameBase, fullname.data(), LdrEntry.FullDllName.MaximumLength);
		uc_mem_write(m_uc, BaseDllNameBase, BaseDllName.data(), LdrEntry.BaseDllName.MaximumLength);

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
		printf("usage: PeVisor (filename) [-k] [-disasm]\n");
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
	uc_ctl_set_cpu_model(uc, UC_CPU_X86_EPYC);
	if (err)
	{
		printf("failed to uc_open %d\n", err);
		return -1;
	}

	ctx.m_uc = uc;
	ctx.thisProc.Attach(GetCurrentProcessId());

	uc_hook ucHookInvalidRwx = 0, 
		ucHookRwx = 0, 
		ucHookCode = 0,
		ucHookIntr = 0,
		ucHookCpuid = 0, 
		ucHookSySCall = 0;

	DWORD_PTR Stack = (!ctx.m_IsKernel) ? 0x40000 : 0xFFFFFC0000000000ull;

	virtual_buffer_t StackBuf;
	if (!StackBuf.GetSpace(ctx.m_StackSize))
	{
		printf("failed to allocate virtual stack\n");
		return 0;
	}

	//allocate virtual stack for execution
	memset(StackBuf.GetBuffer(), 0, StackBuf.GetLength());
	uc_mem_map(uc, Stack, ctx.m_StackSize, UC_PROT_READ | UC_PROT_WRITE);
	uc_mem_write(uc, Stack, StackBuf.GetBuffer(), ctx.m_StackSize);

	ctx.m_StackBase = Stack;
	ctx.m_StackEnd = Stack + ctx.m_StackSize;
	ctx.m_LoadModuleBase = (!ctx.m_IsKernel) ? 0x180000000ull : 0xFFFFF80000000000ull;
	ctx.m_HeapBase = (!ctx.m_IsKernel) ? 0x10000000ull : 0xFFFFFA0000000000ull;
	ctx.m_HeapBase = (!ctx.m_IsKernel) ? (DWORD_PTR)ctx.getProcessHeap() : 0xFFFFFA0000000000ull; // my code
	ctx.m_HeapEnd = ctx.m_HeapBase + 0x1000000ull;

	DWORD_PTR Zero = 0;
	uc_mem_map(uc, ctx.m_HeapBase, ctx.m_HeapEnd - ctx.m_HeapBase, (ctx.m_IsKernel) ? UC_PROT_READ | UC_PROT_WRITE | UC_PROT_EXEC : UC_PROT_READ | UC_PROT_WRITE);
	for (size_t Index = 0; Index <= ctx.m_HeapEnd - ctx.m_HeapBase; Index += sizeof(Zero))
	{
		uc_mem_write(uc, ctx.m_HeapBase + Index, &Zero, sizeof(Zero));
	}

	auto MapResult = ctx.thisProc.mmap().MapImage(wfilename,
		ManualImports | NoSxS | NoExceptions | NoDelayLoad | NoTLS | NoExceptions | NoExec,
		ManualMapCallback, &ctx, 0);

	if (!MapResult.success())
	{
		printf("failed to MapImage\n");
		return 0;
	}

	auto res = MapResult.result();
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
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleHandleExW", EmuApi::EmuGetModuleHandleExW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLastError", EmuApi::EmuGetLastError);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "SetLastError", EmuApi::EmuSetLastError);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeCriticalSectionAndSpinCount", EmuApi::EmuInitializeCriticalSectionAndSpinCount);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleFileNameA", EmuApi::EmuGetModuleFileNameA);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleFileNameW", EmuApi::EmuGetModuleFileNameW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCommandLineA", EmuApi::EmuGetCommandLineA);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCommandLineW", EmuApi::EmuGetCommandLineW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetStdHandle", EmuApi::EmuGetStdHandle);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileType", EmuApi::EmuGetFileType);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileSize", EmuApi::EmuGetFileSize);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileSizeEx", EmuApi::EmuGetFileSizeEx);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "ExitProcess", EmuApi::EmuExitProcess);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualProtect", EmuApi::EmuVirtualProtect);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "WriteFile", EmuApi::EmuWriteFile);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFileW", EmuApi::EmuCreateFileW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFileA", EmuApi::EmuCreateFileA);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFileMappingW", EmuApi::EmuCreateFileMappingW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFileMappingA", EmuApi::EmuCreateFileMappingA);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "MapViewOfFile", EmuApi::EmuMapViewOfFile);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "UnmapViewOfFile", EmuApi::EmuUnmapViewOfFile);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetEnvironmentStringsW", EmuApi::EmuGetEnvironmentStringsW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "FreeEnvironmentStringsW", EmuApi::EmuFreeEnvironmentStringsW);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "IsProcessorFeaturePresent", EmuApi::EmuRtlIsProcessorFeaturePresent);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "HeapValidate", EmuApi::EmuHeapValidate);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "RtlUnwindEx", EmuApi::EmuRtlUnwindEx);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "SetUnhandledExceptionFilter", EmuApi::EmuSetUnhandledExceptionFilter);

		////////////////////////////////////////////////////////////////////////////////GUI
		ctx.RegisterAPIEmulation(L"user32.dll", "wvsprintfW", EmuApi::EmuWvsprintfW);
		ctx.RegisterAPIEmulation(L"user32.dll", "wvsprintfA", EmuApi::EmuWvsprintfA);
		ctx.RegisterAPIEmulation(L"user32.dll", "MessageBoxA", EmuApi::EmuMessageBoxA);
		ctx.RegisterAPIEmulation(L"user32.dll", "MessageBoxW", EmuApi::EmuMessageBoxW);
		ctx.RegisterAPIEmulation(L"user32.dll", "GetProcessWindowStation", EmuApi::EmuGetProcessWindowStation);
		ctx.RegisterAPIEmulation(L"user32.dll", "GetUserObjectInformationW", EmuApi::EmuGetUserObjectInformationW);
		ctx.RegisterAPIEmulation(L"user32.dll", "GetUserObjectInformationA", EmuApi::EmuGetUserObjectInformationA);
		////////////////////////////////////////////////////////////////////////////////GUI

		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetStartupInfoW", EmuApi::EmuGetStartupInfoW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetStartupInfoA", EmuApi::EmuGetStartupInfoA);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetStringTypeW", EmuApi::EmuGetStringTypeW);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "LCMapStringW", EmuApi::EmuLCMapStringW);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "WideCharToMultiByte", EmuApi::EmuWideCharToMultiByte);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "MultiByteToWideChar", EmuApi::EmuMultiByteToWideChar);

		ctx.RegisterAPIEmulation(L"kernelbase.dll", "InitializeCriticalSectionEx", EmuApi::EmuInitializeCriticalSectionEx);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeCriticalSectionEx", EmuApi::EmuInitializeCriticalSectionEx);

		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlDeleteCriticalSection", EmuApi::EmuDeleteCriticalSection);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlIsProcessorFeaturePresent", EmuApi::EmuRtlIsProcessorFeaturePresent);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessHeap", EmuApi::EmuGetProcessHeap);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "HeapFree", EmuApi::EmuRtlFreeHeap);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessAffinityMask", EmuApi::EmuGetProcessAffinityMask);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadAffinityMask", EmuApi::EmuSetThreadAffinityMask);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "Sleep", EmuApi::EmuSleep);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualProtect", EmuApi::EmuVirtualProtect);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCPInfo", EmuApi::EmuGetCPInfo);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "GetACP", EmuApi::EmuGetACP);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "AreFileApisANSI", EmuApi::EmuAreFileApisANSI);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "IsValidCodePage", EmuApi::EmuIsValidCodePage);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsAlloc", EmuApi::EmuTlsAlloc);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsSetValue", EmuApi::EmuTlsSetValue);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsGetValue", EmuApi::EmuTlsGetValue);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsFree", EmuApi::EmuTlsFree);

		ctx.RegisterAPIEmulation(L"kernelbase.dll", "FlsAlloc", EmuApi::EmuTlsAlloc);
		ctx.RegisterAPIEmulation(L"kernelbase.dll", "FlsSetValue", EmuApi::EmuTlsSetValue);
		ctx.RegisterAPIEmulation(L"kernelbase.dll", "FlsGetValue", EmuApi::EmuTlsGetValue);
		ctx.RegisterAPIEmulation(L"kernelbase.dll", "FlsFree", EmuApi::EmuTlsFree);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "FlsAlloc", EmuApi::EmuTlsAlloc);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "FlsSetValue", EmuApi::EmuTlsSetValue);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "FlsGetValue", EmuApi::EmuTlsGetValue);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "FlsFree", EmuApi::EmuTlsFree);

		ctx.RegisterAPIEmulation(L"kernel32.dll", "LocalAlloc", EmuApi::EmuLocalAlloc);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "LocalFree", EmuApi::EmuLocalFree);
		ctx.RegisterAPIEmulation(L"kernel32.dll", "CloseHandle", EmuApi::EmuCloseHandle);

		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtProtectVirtualMemory", EmuApi::EmuNtProtectVirtualMemory);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtQueryInformationProcess", EmuApi::EmuNtQueryInformationProcess);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtSetInformationThread", EmuApi::EmuNtSetInformationThread);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtQuerySystemInformation", EmuApi::EmuNtQuerySystemInformation);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "NtOpenFile", EmuApi::EmuNtOpenFile);
		//ctx.RegisterAPIEmulation(L"ntdll.dll", "NtOpenSection", EmuApi::EmuNtOpenSection);
		//ctx.RegisterAPIEmulation(L"ntdll.dll", "ZwOpenSection", EmuApi::EmuNtOpenSection);

		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlAllocateHeap", EmuApi::EmuRtlAllocateHeap);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlFreeHeap", EmuApi::EmuRtlFreeHeap);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlEnterCriticalSection", EmuApi::EmuRtlEnterCriticalSection);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlLeaveCriticalSection", EmuApi::EmuRtlLeaveCriticalSection);
		ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlInitializeSListHead", EmuApi::EmuRtlInitializeSListHead);
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

	ctx.szCommandLineA = "D:\\Programs\\Soft\\Coding\\C\\VisualStudio\\Coders\\PeVisor\\x64\\Debug\\Peb.exe";
	ctx.EmuCommandLineA = (LPSTR)ctx.HeapAlloc(ctx.szCommandLineA.size());
	InternalEmuApi::EmuCopyASCIStrs(ctx.m_uc, ctx.EmuCommandLineA, ctx.szCommandLineA);

	ctx.szCommandLineW = L"D:\\Programs\\Soft\\Coding\\C\\VisualStudio\\Coders\\PeVisor\\x64\\Debug\\Peb.exe";
	ctx.EmuCommandLineW = (LPWSTR)ctx.HeapAlloc(ctx.szCommandLineW.size() * sizeof(wchar_t));
	InternalEmuApi::EmuCopyUnicodeStrs(ctx.m_uc, ctx.EmuCommandLineW, ctx.szCommandLineW);

	if (!ctx.m_IsKernel)
	{
		ctx.SortModuleList();
		ctx.InitPsLoadedModuleList();
		ctx.InitLdrModuleList();
		ctx.InitTebPeb();

		//Dll
		//ctx.m_InitReg.Rcx = ctx.m_ImageBase;
		//ctx.m_InitReg.Rdx = DLL_PROCESS_ATTACH;
		//ctx.m_InitReg.R8 = 0;
		//ctx.m_InitReg.Dr0 = 0;
		//ctx.m_InitReg.Dr1 = 0;
		//ctx.m_InitReg.Dr2 = 0;
		//ctx.m_InitReg.Dr3 = 0;
		//ctx.m_InitReg.Dr6 = 0;
		//ctx.m_InitReg.Dr7 = 0;

		ctx.m_InitReg.Rax = ctx.m_ExecuteFromRip;
		ctx.m_InitReg.Rcx = ctx.m_PebBase;
		ctx.m_InitReg.Rdx = ctx.m_ExecuteFromRip;
		ctx.m_InitReg.R8 = ctx.m_PebBase;
		ctx.m_InitReg.R9 = ctx.m_ExecuteFromRip;
		ctx.m_InitReg.Dr0 = 0;
		ctx.m_InitReg.Dr1 = 0;
		ctx.m_InitReg.Dr2 = 0;
		ctx.m_InitReg.Dr3 = 0;
		ctx.m_InitReg.Dr6 = 0;
		ctx.m_InitReg.Dr7 = 0;
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

		uc_hook_add(uc, &ucHookCpuid, UC_HOOK_INSN,
			ucHooks::HookCpuid, &ctx, 1, 0, UC_X86_INS_CPUID);

		uc_hook_add(uc, &ucHookSySCall, UC_HOOK_INSN,
			ucHooks::HookSySCall, &ctx, 1, 0, UC_X86_INS_SYSCALL);
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
		uc_hook_del(uc, ucHookCpuid);
		uc_hook_del(uc, ucHookSySCall);
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