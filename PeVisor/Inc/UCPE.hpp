#pragma once
#include "CPUID.hpp"
#include "BlackBone/ManualMap/MMap.h"
#include "BlackBone/Process/Process.h"
#include "Buffer.hpp"
#include "Encode.hpp"
#include "Nativestructs.hpp"
#include "unicorn/unicorn.h"
#include <functional>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <intrin.h>
using api_emu_callback = std::function<bool(uc_engine* uc)>;

enum IntelEnc : unsigned int { IEbx = 'uneG', IEdx = 'Ieni', IEcx = 'letn' };
enum AmdEnc : unsigned int { AEbx = 'htuA', AEdx = 'itne', AEcx = 'DMAc' };

enum class CpuVendor { CpuUnknown, CpuIntel, CpuAmd };

typedef struct _KPCR
{
	SegmentDesctiptorX64 gdt[8];
} KPCR;

typedef struct _UCPE_CacheFile
{
	size_t ImageSize = 0;
	size_t HeapSize = 0;
	size_t StackSize = 0;
	DWORD RealEntryPoint = 0;

	CONTEXT ContextAtRealEntryPoint;
} UCPE_CacheFile, *PUCPE_CacheFile;

typedef struct _FakeAPI
{
	_FakeAPI(const char* n, uint64_t va) : ProcedureName(n), VirtualAddress(va) {}

	DWORD_PTR VirtualAddress = 0;

	PVOID EmuCallback = nullptr;

	std::string ProcedureName;
} FakeAPI, *PFakeAPI;

typedef struct _FakeSection
{
	_FakeSection(ULONG a, ULONG b, char* c, bool u) : SectionBase(a), SectionSize(b), IsUnknownSection(u) {}

	DWORD SectionBase = 0;

	size_t SectionSize = 0;

	CHAR SectionName[9]{};

	bool IsUnknownSection = false;
} FakeSection, *PFakeSection;

typedef struct _FakeModule
{
	_FakeModule(DWORD_PTR b, ULONG s, DWORD_PTR e, const std::wstring& n, const std::filesystem::path& p) : 
		ImageBase(b), ImageSize(s), ImageEntry(e), DllName(n), FullPath(p) {}

	PVOID ImgPtr = nullptr;

	DWORD_PTR ImageBase = 0;
	DWORD_PTR ImageEntry = 0;
	DWORD_PTR ExceptionTable = 0;

	ULONG ImageSize = 0;
	ULONG ExceptionTableSize = 0;

	int Priority = 0;

	std::wstring DllName;
	std::filesystem::path FullPath;
	std::vector<FakeAPI> FakeAPIs;
	std::vector<FakeSection> FakeSections;
} FakeModule, *PFakeModule;

typedef struct _AllocBlock
{
	_AllocBlock(DWORD_PTR b, size_t s) : base(b), size(s) {}

	DWORD_PTR base = 0;

	size_t size = 0;

	bool free = false;
} AllocBlock, *PAllocBlock;

typedef struct _MemMappingBlock
{
	_MemMappingBlock(DWORD_PTR v, DWORD_PTR val, size_t s) : va(v), value(val), size(s) {}

	DWORD_PTR va = 0;
	DWORD_PTR value = 0;
	
	size_t size = 0;
} MemMappingBlock, *PMemMappingBlock;

typedef struct _MemMapping
{
	_MemMapping(DWORD_PTR b, DWORD_PTR v, size_t s) : baseva(b), mappedva(v), size(s) {}

	DWORD_PTR baseva = 0;
	DWORD_PTR mappedva = 0;

	size_t size = 0;

	std::vector<MemMappingBlock> blocks;
} MemMapping, *PMemMapping;

namespace ucHooks {
	void HookCpuid(uc_engine* uc, void* user_data);
	void HookSySCall(uc_engine* uc, void* user_data);
	void HookCode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void HookIntr(uc_engine* uc, int exception, void* user_data);
	void HookRwx(uc_engine* uc, uc_mem_type type,
		DWORD_PTR address, int size, INT_PTR value, void* user_data);
	bool HookInvalidRwx(uc_engine* uc, uc_mem_type type,
		DWORD_PTR address, int size, INT_PTR value, void* user_data);
	void EmuUnknownAPI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
}

blackbone::LoadData ManualMapCallback(blackbone::CallbackType type, void* context, blackbone::Process& /*process*/, const blackbone::ModuleData& modInfo);

class PeEmulation
{
public: //Basis emu api
	void AddAPIEmulation(_Inout_ PFakeAPI FApi, _Out_ PVOID callback);
	bool RegisterAPIEmulation(
		_In_ const std::wstring& DllName,
		_In_ const char* ProcedureName,
		_In_ PVOID callback);
public:
	void GetModuleHandleAInternalEmulation(_Out_ DWORD_PTR* ImageBase, _In_ std::wstring& wModuleName);
	NTSTATUS LdrFindDllByNameInternalEmualtion(_In_ const std::wstring& DllName, _Out_ DWORD_PTR* ImageBase, _Out_ size_t* ImageSize, _In_ bool LoadIfNotExist);
	std::filesystem::path GetModuleFileInternalEmulation(_In_ PVOID hModule);
public:
	//Usermode only
	void InitProcessorState();
	void InitLdrModuleList();
	void InitTebPeb();

	//Kernelmode only
	void SortModuleList();
	void InitPsLoadedModuleList();
	void InitDriverObject();

	//Usermode + Kernelmode
	void InsertTailList(_In_ DWORD_PTR ListHeadAddress, _In_ DWORD_PTR EntryAddress);
	void InitKSharedUserData();

public:	//Finders
	bool FindAddressInRegion(
		_In_ DWORD_PTR address, 
		_Inout_ std::stringstream& RegionName,
		_In_opt_ bool FindInModules = true, 
		_In_opt_ bool FindInStack = true,
		_In_opt_ bool FindInHeap = true);
	bool FindAPIByAddress(_In_ DWORD_PTR address, _Inout_ std::wstring& DllName, _Inout_ FakeAPI** api);
	bool FindSectionByAddress(_In_ DWORD_PTR address, _Inout_ FakeSection** section);
	bool FindModuleByAddress(_In_ DWORD_PTR address, _Inout_ DWORD_PTR& DllBase);

public: //Memory block
	//Stack
	DWORD_PTR StackAlloc(_In_ size_t AllocBytes);
	void StackFree(_In_ size_t AllocBytes);

	//Heap
	DWORD_PTR HeapAlloc(_In_ size_t AllocBytes, _In_opt_ bool IsPageAlign = false);
	bool HeapFree(_In_ DWORD_PTR FreeAddress);

	//Mem mapping
	bool CreateMemMapping(_In_ DWORD_PTR BaseAddress, _In_ DWORD_PTR MapAddress, _In_ size_t Bytes);
	bool WriteMemMapping(_In_ DWORD_PTR baseaddress, _In_ DWORD_PTR value, _In_ size_t size);
	void DeleteMemMapping(_In_ DWORD_PTR MapAddress);
	void FlushMemMapping(_In_ void);

public: //Ldrs
	DWORD_PTR LdrGetProcAddress(_In_ DWORD_PTR ImageBase, _In_ const char* ProcedureName);
	void LdrResolveExportTable(_Inout_ FakeModule* module, _In_ PVOID ImageBase, _In_ DWORD_PTR MappedBase);
	NTSTATUS LdrFindDllByName(_In_ const std::wstring& DllName, _Out_ DWORD_PTR* ImageBase, _Out_ size_t* ImageSize, _In_ bool LoadIfNotExist);
	NTSTATUS LdrLoadDllByName(_In_ const std::wstring& DllName);

public: //ManualMap
	void MapImageToEngine(
		_In_ const std::filesystem::path& FullPath,
		_In_ const std::wstring& ImageName,
		_In_ PVOID ImageBase,
		_In_ ULONG ImageSize,
		_In_ DWORD_PTR MappedBase,
		_In_ DWORD_PTR EntryPoint);
public: //RTLs
	void RtlpGetStackLimits(_Out_ PDWORD_PTR LowLimit, _Out_ PDWORD_PTR HighLimit);
	void RtlpCaptureContext(_In_ PCONTEXT ContextRecord);
	void RtlpRestoreContext(_In_ PCONTEXT ContextRecord, _In_ PEXCEPTION_RECORD ExceptionRecord OPTIONAL);
	BOOLEAN RtlpDispatchException(_In_ PEXCEPTION_RECORD ExceptionRecord, _In_ PCONTEXT ContextRecord);
	void RtlRaiseStatus(_In_ NTSTATUS Status);
	NTSTATUS RaiseException(
		_In_ PEXCEPTION_RECORD ExceptionRecord, 
		_In_ PCONTEXT ContextRecord, 
		_In_ BOOLEAN FirstChance);
	void RtlInsertInvertedFunctionTable(
		_Inout_ PINVERTED_FUNCTION_TABLE InvertedTable,
		_In_ DWORD_PTR MappedBase,
		_In_ PVOID ImageBase,
		_In_ ULONG SizeOfImage);
	EXCEPTION_DISPOSITION RtlpExecuteHandlerForException(
		_Inout_ struct _EXCEPTION_RECORD* ExceptionRecord, 
		_In_ PVOID EstablisherFrame,
		_Inout_ struct _CONTEXT* ContextRecord, 
		_In_ PDISPATCHER_CONTEXT DispatcherContext);
	PRUNTIME_FUNCTION RtlpLookupFunctionTable(_In_ PVOID ControlPc, _Out_ PVOID* ImageBase, _Out_ PULONG SizeOfTable);
	PRUNTIME_FUNCTION RtlpLookupFunctionEntry(
		_In_ DWORD_PTR ControlPc,
		_Out_ PDWORD_PTR ImageBase,
		_Inout_ PUNWIND_HISTORY_TABLE HistoryTable OPTIONAL);
	PRUNTIME_FUNCTION RtlpConvertFunctionEntry(_In_ PRUNTIME_FUNCTION FunctionEntry, _In_ DWORD_PTR ImageBase);
	PEXCEPTION_ROUTINE RtlpVirtualUnwind(
		_In_ ULONG HandlerType,
		_In_ DWORD_PTR ImageBase,
		_In_ DWORD_PTR ControlPc,
		_In_ PRUNTIME_FUNCTION FunctionEntry,
		_Inout_ PCONTEXT ContextRecord,
		_Out_ PVOID* HandlerData,
		_Out_ PDWORD_PTR EstablisherFrame,
		_Inout_ PKNONVOLATILE_CONTEXT_POINTERS ContextPointers OPTIONAL
	);
	PRUNTIME_FUNCTION RtlpSameFunction(_In_ PRUNTIME_FUNCTION FunctionEntry, _In_ DWORD_PTR ImageBase, _In_ DWORD_PTR ControlPc);
	PUNWIND_INFO RtlpLookupPrimaryUnwindInfo(
		_In_ PRUNTIME_FUNCTION FunctionEntry,
		_In_ DWORD_PTR ImageBase,
		_Out_ PRUNTIME_FUNCTION* PrimaryEntry);
	PRUNTIME_FUNCTION RtlpUnwindPrologue(
		_In_ DWORD_PTR ImageBase,
		_In_ DWORD_PTR ControlPc,
		_In_ DWORD_PTR FrameBase,
		_In_ PRUNTIME_FUNCTION FunctionEntry,
		_Inout_ PCONTEXT ContextRecord,
		_Inout_ PKNONVOLATILE_CONTEXT_POINTERS ContextPointers OPTIONAL
	);
	EXCEPTION_DISPOSITION C_specific_handler(void);
	void RtlpUnwindEx(
		_In_ PVOID TargetFrame OPTIONAL,
		_In_ PVOID TargetIp OPTIONAL,
		_In_ PEXCEPTION_RECORD ExceptionRecord OPTIONAL,
		_In_ PVOID ReturnValue,
		_In_ PCONTEXT OriginalContext,
		_In_ PUNWIND_HISTORY_TABLE HistoryTable OPTIONAL
	);
public:
	blackbone::Process thisProc;

	uc_engine* m_uc = nullptr;

	bool m_IsWin64 = false;
	//-k flag
	bool m_IsKernel = false;
	//-disasm flag
	bool m_DisplayDisasm = false;
	//-packed flag
	bool m_IsPacked = false;
	//-boundcheck flag
	bool m_BoundCheck = false;
	//-dump flag
	bool m_Dump = false;
	bool m_Cache = false;
	bool m_HasCache = false;

	std::filesystem::path m_PathExe;

	DWORD_PTR m_KSharedUserDataBase = 0;
	DWORD_PTR m_KSharedUserDataEnd = 0;
	DWORD_PTR m_StackBase = 0;
	DWORD_PTR m_StackEnd = 0;
	DWORD_PTR m_ImageBase = 0;
	DWORD_PTR m_ImageEnd = 0;
	DWORD_PTR m_ImageEntry = 0;
	DWORD_PTR m_ImageRealEntry = 0;
	DWORD_PTR m_HeapBase = 0;
	DWORD_PTR m_HeapEnd = 0;
	DWORD_PTR m_LoadModuleBase = 0;

	//Usermode only
	DWORD_PTR m_PebBase = 0;
	DWORD_PTR m_PebEnd = 0;
	DWORD_PTR m_LdrBase = 0;
	DWORD_PTR m_LdrEnd = 0;
	DWORD_PTR m_TebBase = 0;
	DWORD_PTR m_TebEnd = 0;
	DWORD m_Win32LastError = 0;
	DWORD_PTR m_CommandLineABase = 0;
	DWORD_PTR m_CommandLineWBase = 0;


	//Kernelmode only
	DWORD_PTR m_DriverObjectBase = 0;
	DWORD_PTR m_RegistryPathBase = 0;
	DWORD_PTR m_KThreadBase = 0;
	DWORD_PTR m_PsLoadedModuleListBase = 0;
	DWORD_PTR m_LdrModuleListBase = 0;
	DWORD_PTR m_DriverLdrEntry = 0;
	DWORD_PTR m_LastRip = 0;
	DWORD_PTR m_LastRipModule = 0;
	DWORD_PTR m_ExecCodeCount = 0;
	DWORD_PTR m_ExecuteFromRip = 0;
	DWORD_PTR m_LastFakeAPICallReturnAddress = 0;

	NTSTATUS m_LastException = 0;

	int m_MainModuleIndex = 0;
	size_t m_LastHeapAllocBytes = 0;
	int m_ExecuteExceptionHandler = 0;

	UCHAR m_RtlpUnwindOpSlotTable[11]{};

	bool m_FakeAPICallEnabled = false;

	PFakeAPI m_LastFakeAPICall;
	CONTEXT m_InitReg;
	INVERTED_FUNCTION_TABLE m_PsInvertedFunctionTable;

	std::vector<PFakeModule> m_FakeModules;
	std::vector<AllocBlock> m_HeapAllocs;
	std::vector<MemMapping> m_MemMappings;
	std::vector<DWORD_PTR> m_TlsValue;

	std::string filename;
};

#define API_FUNCTION_SIZE 8
#define PAGE_SIZE 0x1000
#define PAGE_ALIGN(Va) (ULONG_PTR)(Va) & ~(PAGE_SIZE - 1)
#define PAGE_ALIGN_64(Va) (Va) & ~(0x1000ull - 1)
#define PAGE_ALIGN_64k(Va) ((Va)) & ~(0x10000ull - 1)

#define AlignSize(Size, Align) (Size+Align-1)/Align*Align

#define EXCP00_DIVZ	0
#define EXCP01_DB	1
#define EXCP02_NMI	2
#define EXCP03_INT3	3
#define EXCP04_INTO	4
#define EXCP05_BOUND	5
#define EXCP06_ILLOP	6
#define EXCP07_PREX	7
#define EXCP08_DBLE	8
#define EXCP09_XERR	9
#define EXCP0A_TSS	10
#define EXCP0B_NOSEG	11
#define EXCP0C_STACK	12
#define EXCP0D_GPF	13
#define EXCP0E_PAGE	14
#define EXCP10_COPR	16
#define EXCP11_ALGN	17
#define EXCP12_MCHK	18

#define EXCP_SYSCALL    0x100 /* only happens in user only emulation
								 for syscall instruction */