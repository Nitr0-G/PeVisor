#pragma once
/// See: MEMORY-MANAGEMENT REGISTERS
#include <pshpack1.h>
struct Idtr {
	unsigned short limit;
	ULONG_PTR base;
};

struct Idtr32 {
	unsigned short limit;
	ULONG32 base;
};
static_assert(sizeof(Idtr32) == 6, "Size check");

/// @copydoc Idtr
using Gdtr = Idtr;
#if defined(_AMD64_)
static_assert(sizeof(Idtr) == 10, "Size check");
static_assert(sizeof(Gdtr) == 10, "Size check");
#else
static_assert(sizeof(Idtr) == 6, "Size check");
static_assert(sizeof(Gdtr) == 6, "Size check");
#endif
#include <poppack.h>

/// See: Segment Selectors
#include <pshpack1.h>
union SegmentSelector {
	unsigned short all;
	struct {
		unsigned short rpl : 2;  //!< Requested Privilege Level
		unsigned short ti : 1;   //!< Table Indicator
		unsigned short index : 13;
	} fields;
};
static_assert(sizeof(SegmentSelector) == 2, "Size check");
#include <poppack.h>

/// See: Segment Descriptor
union SegmentDescriptor {
	ULONG64 all;
	struct {
		ULONG64 limit_low : 16;
		ULONG64 base_low : 16;
		ULONG64 base_mid : 8;
		ULONG64 type : 4;
		ULONG64 system : 1;
		ULONG64 dpl : 2;
		ULONG64 present : 1;
		ULONG64 limit_high : 4;
		ULONG64 avl : 1;
		ULONG64 l : 1;  //!< 64-bit code segment (IA-32e mode only)
		ULONG64 db : 1;
		ULONG64 gran : 1;
		ULONG64 base_high : 8;
	} fields;
};
static_assert(sizeof(SegmentDescriptor) == 8, "Size check");

/// @copydoc SegmentDescriptor
struct SegmentDesctiptorX64 {
	SegmentDescriptor descriptor;
	ULONG32 base_upper32;
	ULONG32 reserved;
};
static_assert(sizeof(SegmentDesctiptorX64) == 16, "Size check");

/// See: MODEL-SPECIFIC REGISTERS (MSRS)
enum class Msr : unsigned int {
	kIa32ApicBase = 0x01B,

	kIa32FeatureControl = 0x03A,

	kIa32SysenterCs = 0x174,
	kIa32SysenterEsp = 0x175,
	kIa32SysenterEip = 0x176,

	kIa32Debugctl = 0x1D9,

	kIa32MtrrCap = 0xFE,
	kIa32MtrrDefType = 0x2FF,
	kIa32MtrrPhysBaseN = 0x200,
	kIa32MtrrPhysMaskN = 0x201,
	kIa32MtrrFix64k00000 = 0x250,
	kIa32MtrrFix16k80000 = 0x258,
	kIa32MtrrFix16kA0000 = 0x259,
	kIa32MtrrFix4kC0000 = 0x268,
	kIa32MtrrFix4kC8000 = 0x269,
	kIa32MtrrFix4kD0000 = 0x26A,
	kIa32MtrrFix4kD8000 = 0x26B,
	kIa32MtrrFix4kE0000 = 0x26C,
	kIa32MtrrFix4kE8000 = 0x26D,
	kIa32MtrrFix4kF0000 = 0x26E,
	kIa32MtrrFix4kF8000 = 0x26F,

	kIa32VmxBasic = 0x480,
	kIa32VmxPinbasedCtls = 0x481,
	kIa32VmxProcBasedCtls = 0x482,
	kIa32VmxExitCtls = 0x483,
	kIa32VmxEntryCtls = 0x484,
	kIa32VmxMisc = 0x485,
	kIa32VmxCr0Fixed0 = 0x486,
	kIa32VmxCr0Fixed1 = 0x487,
	kIa32VmxCr4Fixed0 = 0x488,
	kIa32VmxCr4Fixed1 = 0x489,
	kIa32VmxVmcsEnum = 0x48A,
	kIa32VmxProcBasedCtls2 = 0x48B,
	kIa32VmxEptVpidCap = 0x48C,
	kIa32VmxTruePinbasedCtls = 0x48D,
	kIa32VmxTrueProcBasedCtls = 0x48E,
	kIa32VmxTrueExitCtls = 0x48F,
	kIa32VmxTrueEntryCtls = 0x490,
	kIa32VmxVmfunc = 0x491,

	kIa32Efer = 0xC0000080,
	kIa32Star = 0xC0000081,
	kIa32Lstar = 0xC0000082,

	kIa32Fmask = 0xC0000084,

	kIa32FsBase = 0xC0000100,
	kIa32GsBase = 0xC0000101,
	kIa32KernelGsBase = 0xC0000102,
	kIa32TscAux = 0xC0000103,
};

union FlagRegister {
	ULONG_PTR all;
	struct {
		ULONG_PTR cf : 1;          //!< [0] Carry flag
		ULONG_PTR reserved1 : 1;   //!< [1] Always 1
		ULONG_PTR pf : 1;          //!< [2] Parity flag
		ULONG_PTR reserved2 : 1;   //!< [3] Always 0
		ULONG_PTR af : 1;          //!< [4] Borrow flag
		ULONG_PTR reserved3 : 1;   //!< [5] Always 0
		ULONG_PTR zf : 1;          //!< [6] Zero flag
		ULONG_PTR sf : 1;          //!< [7] Sign flag
		ULONG_PTR tf : 1;          //!< [8] Trap flag
		ULONG_PTR intf : 1;        //!< [9] Interrupt flag
		ULONG_PTR df : 1;          //!< [10] Direction flag
		ULONG_PTR of : 1;          //!< [11] Overflow flag
		ULONG_PTR iopl : 2;        //!< [12:13] I/O privilege level
		ULONG_PTR nt : 1;          //!< [14] Nested task flag
		ULONG_PTR reserved4 : 1;   //!< [15] Always 0
		ULONG_PTR rf : 1;          //!< [16] Resume flag
		ULONG_PTR vm : 1;          //!< [17] Virtual 8086 mode
		ULONG_PTR ac : 1;          //!< [18] Alignment check
		ULONG_PTR vif : 1;         //!< [19] Virtual interrupt flag
		ULONG_PTR vip : 1;         //!< [20] Virtual interrupt pending
		ULONG_PTR id : 1;          //!< [21] Identification flag
		ULONG_PTR reserved5 : 10;  //!< [22:31] Always 0
	} fields;
};
static_assert(sizeof(FlagRegister) == sizeof(void*), "Size check");

#define IRP_MJ_CREATE                   0x00
#define IRP_MJ_CREATE_NAMED_PIPE        0x01
#define IRP_MJ_CLOSE                    0x02
#define IRP_MJ_READ                     0x03
#define IRP_MJ_WRITE                    0x04
#define IRP_MJ_QUERY_INFORMATION        0x05
#define IRP_MJ_SET_INFORMATION          0x06
#define IRP_MJ_QUERY_EA                 0x07
#define IRP_MJ_SET_EA                   0x08
#define IRP_MJ_FLUSH_BUFFERS            0x09
#define IRP_MJ_QUERY_VOLUME_INFORMATION 0x0a
#define IRP_MJ_SET_VOLUME_INFORMATION   0x0b
#define IRP_MJ_DIRECTORY_CONTROL        0x0c
#define IRP_MJ_FILE_SYSTEM_CONTROL      0x0d
#define IRP_MJ_DEVICE_CONTROL           0x0e
#define IRP_MJ_INTERNAL_DEVICE_CONTROL  0x0f
#define IRP_MJ_SHUTDOWN                 0x10
#define IRP_MJ_LOCK_CONTROL             0x11
#define IRP_MJ_CLEANUP                  0x12
#define IRP_MJ_CREATE_MAILSLOT          0x13
#define IRP_MJ_QUERY_SECURITY           0x14
#define IRP_MJ_SET_SECURITY             0x15
#define IRP_MJ_POWER                    0x16
#define IRP_MJ_SYSTEM_CONTROL           0x17
#define IRP_MJ_DEVICE_CHANGE            0x18
#define IRP_MJ_QUERY_QUOTA              0x19
#define IRP_MJ_SET_QUOTA                0x1a
#define IRP_MJ_PNP                      0x1b
#define IRP_MJ_PNP_POWER                IRP_MJ_PNP      // Obsolete....
#define IRP_MJ_MAXIMUM_FUNCTION         0x1b

typedef struct _DRIVER_OBJECT {
	SHORT Type;
	SHORT Size;

	//
	// The following links all of the devices created by a single driver
	// together on a list, and the Flags word provides an extensible flag
	// location for driver objects.
	//

	PVOID DeviceObject;
	ULONG Flags;

	//
	// The following section describes where the driver is loaded.  The count
	// field is used to count the number of times the driver has had its
	// registered reinitialization routine invoked.
	//

	PVOID DriverStart;
	ULONG DriverSize;
	PVOID DriverSection;
	PVOID DriverExtension;

	//
	// The driver name field is used by the error log thread
	// determine the name of the driver that an I/O request is/was bound.
	//

	UNICODE_STRING DriverName;

	//
	// The following section is for registry support.  This is a pointer
	// to the path to the hardware information in the registry
	//

	PUNICODE_STRING HardwareDatabase;

	//
	// The following section contains the optional pointer to an array of
	// alternate entry points to a driver for "fast I/O" support.  Fast I/O
	// is performed by invoking the driver routine directly with separate
	// parameters, rather than using the standard IRP call mechanism.  Note
	// that these functions may only be used for synchronous I/O, and when
	// the file is cached.
	//

	PVOID FastIoDispatch;

	//
	// The following section describes the entry points to this particular
	// driver.  Note that the major function dispatch table must be the last
	// field in the object so that it remains extensible.
	//

	PVOID DriverInit;
	PVOID DriverStartIo;
	PVOID DriverUnload;
	PVOID MajorFunction[IRP_MJ_MAXIMUM_FUNCTION + 1];

} DRIVER_OBJECT;
typedef struct _DRIVER_OBJECT* PDRIVER_OBJECT;

typedef struct _MDL {
	struct _MDL* Next;
	SHORT Size;
	SHORT MdlFlags;

	PVOID Process;
	PVOID MappedSystemVa;   /* see creators for field size annotations. */
	PVOID StartVa;   /* see creators for validity; could be address 0.  */
	ULONG ByteCount;
	ULONG ByteOffset;
} MDL, * PMDL;

typedef struct _KLDR_DATA_TABLE_ENTRY {
	LIST_ENTRY InLoadOrderLinks;
	PVOID ExceptionTable;
	ULONG ExceptionTableSize;
	// ULONG padding on IA64
	PVOID GpValue;
	PVOID NonPagedDebugInfo;
	PVOID DllBase;
	PVOID EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	USHORT LoadCount;
	USHORT __Unused5;
	PVOID SectionPointer;
	ULONG CheckSum;
	// ULONG padding on IA64
	PVOID LoadedImports;
	PVOID PatchInformation;
} KLDR_DATA_TABLE_ENTRY, * PKLDR_DATA_TABLE_ENTRY;

#define UNWIND_HISTORY_TABLE_NONE 0
#define UNWIND_HISTORY_TABLE_GLOBAL 1
#define UNWIND_HISTORY_TABLE_LOCAL 2

#define MAXIMUM_INVERTED_FUNCTION_TABLE_SIZE 160

typedef struct _INVERTED_FUNCTION_TABLE_ENTRY {
	PRUNTIME_FUNCTION FunctionTable;
	PVOID ImageBase;
	ULONG SizeOfImage;
	ULONG SizeOfTable;
} INVERTED_FUNCTION_TABLE_ENTRY, * PINVERTED_FUNCTION_TABLE_ENTRY;

typedef struct _INVERTED_FUNCTION_TABLE {
	ULONG CurrentSize;
	ULONG MaximumSize;
	BOOLEAN Overflow;
	INVERTED_FUNCTION_TABLE_ENTRY TableEntry[MAXIMUM_INVERTED_FUNCTION_TABLE_SIZE];
} INVERTED_FUNCTION_TABLE, * PINVERTED_FUNCTION_TABLE;

typedef enum _UNWIND_OP_CODES {
	UWOP_PUSH_NONVOL = 0,
	UWOP_ALLOC_LARGE,
	UWOP_ALLOC_SMALL,
	UWOP_SET_FPREG,
	UWOP_SAVE_NONVOL,
	UWOP_SAVE_NONVOL_FAR,
	//UWOP_EPILOG,
	UWOP_SPARE_CODE1,
	UWOP_SPARE_CODE2,
	UWOP_SAVE_XMM128,
	UWOP_SAVE_XMM128_FAR,
	UWOP_PUSH_MACHFRAME
} UNWIND_OP_CODES, * PUNWIND_OP_CODES;


//Define unwind code structure.
typedef union _UNWIND_CODE {
	struct {
		UCHAR CodeOffset;
		UCHAR UnwindOp : 4;
		UCHAR OpInfo : 4;
	};

	struct {
		UCHAR OffsetLow;
		UCHAR UnwindOp : 4;
		UCHAR OffsetHigh : 4;
	} EpilogueCode;

	USHORT FrameOffset;
} UNWIND_CODE, * PUNWIND_CODE;


//Define unwind information flags.


#define UNW_FLAG_NHANDLER 0x0
#define UNW_FLAG_EHANDLER 0x1
#define UNW_FLAG_UHANDLER 0x2
#define UNW_FLAG_CHAININFO 0x4


//Define unwind information structure.


typedef struct _UNWIND_INFO {
	UCHAR Version : 3;
	UCHAR Flags : 5;
	UCHAR SizeOfProlog;
	UCHAR CountOfCodes;
	UCHAR FrameRegister : 4;
	UCHAR FrameOffset : 4;
	UNWIND_CODE UnwindCode[1];

	//
	// The unwind codes are followed by an optional DWORD aligned field that
	// contains the exception handler address or a function table entry if
	// chained unwind information is specified. If an exception handler address
	// is specified, then it is followed by the language specified exception
	// handler data.
	//
	//  union {
	//      struct {
	//          ULONG ExceptionHandler;
	//          ULONG ExceptionData[];
	//      };
	//
	//      RUNTIME_FUNCTION FunctionEntry;
	//  };
	//

} UNWIND_INFO, * PUNWIND_INFO;