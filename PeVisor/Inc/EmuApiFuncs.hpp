#pragma once
#include "BlackBone/ManualMap/MMap.h"
#include "BlackBone/Process/Process.h"
#include "Encode.hpp"
#include "wsprintf.h"
#include "Crt.hpp"
#include "IEApiErrorCodes.hpp"
#include "Nativestructs.hpp"
#include "UCPE.hpp"
#include "unicorn/unicorn.h"
#include "Zydis/Zydis.h"
#include <iostream>
#include <sstream>

#define NtCurrentThread ((HANDLE)-2)
#define ALIGN_TO_4KB(size) (((size) + 4095) / 4096) * 4096

typedef enum class __PROCESSINFOCLASS {
	ProcessBasicInformation = 0,
	ProcessDebugPort = 7,
	ProcessWow64Information = 26,
	ProcessImageFileName = 27,
	ProcessBreakOnTermination = 29,
	ProcessDebugObjectHandle = 30,
	ProcessDebugFlags = 31,
	ProcessTelemetryIdInformation = 64,
	ProcessSubsystemInformation = 75
} PROCESSINFOCLASS_;

typedef struct __PROCESS_BASIC_INFORMATION {
	NTSTATUS ExitStatus;
	PPEB PebBaseAddress;
	ULONG_PTR AffinityMask;
	KPRIORITY BasePriority;
	ULONG_PTR UniqueProcessId;
	ULONG_PTR InheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION_;

typedef enum _SUBSYSTEM_INFORMATION_TYPE {
	SubsystemInformationTypeWin32,
	SubsystemInformationTypeWSL,
	MaxSubsystemInformationType
} SUBSYSTEM_INFORMATION_TYPE, * PSUBSYSTEM_INFORMATION_TYPE;

typedef struct _PROCESS_TELEMETRY_ID_INFORMATION {
	ULONG HeaderSize;
	ULONG ProcessId;
	ULONG64 ProcessStartKey;
	ULONG64 CreateTime;
	ULONG64 CreateInterruptTime;
	ULONG64 CreateUnbiasedInterruptTime;
	ULONG64 ProcessSequenceNumber;
	ULONG64 SessionCreateTime;
	ULONG SessionId;
	ULONG BootId;
	ULONG ImageChecksum;
	ULONG ImageTimeDateStamp;
	ULONG UserSidOffset;
	ULONG ImagePathOffset;
	ULONG PackageNameOffset;
	ULONG RelativeAppNameOffset;
	ULONG CommandLineOffset;
} PROCESS_TELEMETRY_ID_INFORMATION, * PPROCESS_TELEMETRY_ID_INFORMATION;

typedef struct _THREAD_BASIC_INFORMATION {
	NTSTATUS ExitStatus;
	PVOID TebBaseAddress;
	CLIENT_ID ClientId;
	KAFFINITY AffinityMask;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
} THREAD_BASIC_INFORMATION, * PTHREAD_BASIC_INFORMATION;

typedef enum class __THREADINFOCLASS {
	ThreadBasicInformation = 0x0,
	ThreadTimes = 0x01,
	ThreadPriority = 0x02,
	ThreadBasePriority = 0x03,
	ThreadAffinityMask = 0x04,
	ThreadImpersonationToken = 0x05,
	ThreadDescriptorTableEntry = 0x06,
	ThreadEnableAlignmentFaultFixup = 0x07,
	ThreadEventPair = 0x08,
	ThreadQuerySetWin32StartAddress = 0x09,
	ThreadZeroTlsCell = 0x0A,
	ThreadPerformanceCount = 0x0B,
	ThreadAmILastThread = 0x0C,
	ThreadIdealProcessor = 0x0D,
	ThreadPriorityBoost = 0x0E,
	ThreadSetTlsArrayAddress = 0x0F,
	ThreadIsIoPending = 0x10,
	ThreadHideFromDebugger = 0x11,
	ThreadBreakOnTermination = 0x12,
	ThreadSwitchLegacyState = 0x13,
	ThreadIsTerminated = 0x14,
	ThreadLastSystemCall = 0x15,
	ThreadIoPriority = 0x16,
	ThreadCycleTime = 0x17,
	ThreadPagePriority = 0x18,
	ThreadActualBasePriority = 0x19,
	ThreadTebInformation = 0x1A,
	ThreadCSwitchMon = 0x1B,
	ThreadCSwitchPmu = 0x1C,
	ThreadWow64Context = 0x1D,
	ThreadGroupInformation = 0x1E,
	ThreadUmsInformation = 0x1F,
	ThreadCounterProfiling = 0x20,
	ThreadIdealProcessorEx = 0x21,
	ThreadCpuAccountingInformation = 0x22,
	ThreadSuspendCount = 0x23,
	ThreadHeterogeneousCpuPolicy = 0x24,
	ThreadContainerId = 0x25,
	ThreadNameInformation = 0x26,
	ThreadSelectedCpuSets = 0x27,
	ThreadSystemThreadInformation = 0x28,
	ThreadActualGroupAffinity = 0x29
} THREADINFOCLASS__;

namespace InternalEmuApi {
	bool EmuWriteNullTermString(_In_ uc_engine* uc, _Inout_ DWORD_PTR address, _In_ const std::string& str);
	bool EmuWriteNullTermUnicodeString(_In_ uc_engine* uc, _Inout_ DWORD_PTR address, _In_ const std::wstring& str);
	bool EmuReadNullTermString(_In_ uc_engine* uc, _In_ DWORD_PTR address, _Inout_ std::string& str, _In_opt_ bool OnLengthLimit = false,
		_In_opt_ size_t Length = 0);
	bool EmuReadNullTermUnicodeString(_In_ uc_engine* uc, _In_ DWORD_PTR address, _Inout_ std::wstring& str, _In_opt_ bool OnLengthLimit = false,
		_In_opt_ size_t Length = 0);
	void EmuCopyASCIStrs(_In_ uc_engine* uc, _In_ LPSTR Dst, _In_ std::string Src);
	void EmuCopyUnicodeStrs(_In_ uc_engine* uc, _In_ LPWSTR EmuAddr, _In_ std::wstring Src);
	void EmuCopyBufferFromUc(_In_ uc_engine* uc, _In_ LPVOID MyAddr, _In_ LPVOID EmuAddr, _In_ size_t NumberOfBytes);
	void EmuCopyBufferToUc(_In_ uc_engine* uc, _In_ LPVOID EmuAddr, _In_ LPVOID MyAddr, _In_ size_t NumberOfBytes);
	DWORD_PTR EmuReadReturnAddress(_In_ uc_engine* uc);
}

using namespace InternalEmuApi;

typedef NTSTATUS(NTAPI* TNtQueryInformationProcess)(
	IN HANDLE           ProcessHandle,
	IN PROCESSINFOCLASS_ ProcessInformationClass,
	OUT PVOID           ProcessInformation,
	IN ULONG            ProcessInformationLength,
	OUT PULONG          ReturnLength
	);

typedef NTSTATUS(NTAPI* TNtOpenSection)(
	OUT PHANDLE             SectionHandle,
	IN ACCESS_MASK          DesiredAccess,
	IN POBJECT_ATTRIBUTES   ObjectAttributes
	);

namespace EmuApi
{
	void EmuGetSystemTimeAsFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	////////////////////////////////////////////////////////////////////////////////GUI
	void EmuMessageBoxA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuMessageBoxW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetProcessWindowStation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetUserObjectInformationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetUserObjectInformationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	////////////////////////////////////////////////////////////////////////////////GUI

	void EmuExitProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuGetCurrentThreadId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetCurrentProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuQueryPerformanceCounter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuLoadLibraryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuLoadLibraryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetProcAddress(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetModuleHandleA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetModuleHandleW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetModuleFileNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetModuleFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetModuleHandleExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetStartupInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetStartupInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetStdHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetFileType(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetProcessHeap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetCommandLineA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetCommandLineW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuCloseHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuVirtualProtect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuWvsprintfA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuWvsprintfW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuWriteFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuAreFileApisANSI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuIsValidCodePage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetACP(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetCPInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuWideCharToMultiByte(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuMultiByteToWideChar(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuGetStringTypeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuLCMapStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	///////////////////////////////////////////////////////////////////////////////ANTI-DEBUG
	void EmuIsDebuggerPresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuCheckRemoteDebuggerPresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuNtQueryInformationProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuNtSetInformationThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	///////////////////////////////////////////////////////////////////////////////ANTI-DEBUG

	void EmuGetLastError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuSetLastError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuInitializeCriticalSectionAndSpinCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuInitializeCriticalSectionEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuRtlEnterCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlLeaveCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuTlsAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuTlsSetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuTlsGetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuTlsFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuDeleteCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuLocalAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlAllocateHeap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuLocalFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlFreeHeap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlIsProcessorFeaturePresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuGetProcessAffinityMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuSetThreadAffinityMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuSleep(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuGetEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuFreeEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuSetUnhandledExceptionFilter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuRtlUnwindEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	
	void EmuRtlInitializeSListHead(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuHeapValidate(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuNtOpenFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuNtOpenSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

	void EmuExAllocatePool(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuNtProtectVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuNtQuerySystemInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuExFreePool(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuExFreePoolWithTag(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuIoAllocateMdl(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuMmProbeAndLockPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuMmMapLockedPagesSpecifyCache(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuKeQueryActiveProcessors(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuKeSetSystemAffinityThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuKeRevertToUserAffinityThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuMmUnlockPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuIoFreeMdl(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlGetVersion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuDbgPrint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuKeInitializeMutex(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlInitUnicodeString(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuKeWaitForSingleObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuKeReleaseMutex(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void Emusrand(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void Emurand(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlZeroMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlFillMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuRtlCopyMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void Emuwcsstr(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuMmIsAddressValid(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void EmuExGetPreviousMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void Emu__C_specific_handler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
}