| **English (en-US)** | [简体中文 (zh-CN)](https://github.com/KNSoft/KNSoft.NDK/blob/main/README.zh-CN.md) |
| --- | --- |

<br>

# KNSoft.NDK

[![NuGet Downloads](https://img.shields.io/nuget/dt/KNSoft.NDK)](https://www.nuget.org/packages/KNSoft.NDK) [![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/KNSoft/KNSoft.NDK/msbuild.yml)](https://github.com/KNSoft/KNSoft.NDK/actions/workflows/msbuild.yml) ![PR Welcome](https://img.shields.io/badge/PR-welcome-0688CB.svg) [![GitHub License](https://img.shields.io/github/license/KNSoft/KNSoft.NDK)](https://github.com/KNSoft/KNSoft.NDK/blob/main/LICENSE)

[KNSoft.NDK](https://github.com/KNSoft/KNSoft.NDK) provides native C/C++ definitions and import libraries for Windows NT development.

## Feature

- Windows NT
  - Undocumented API declarations and type definitions, e.g. `Nt/Zw*`, `Ldr*`, `PEB`, `TEB`, `LDR_*`, ...
  - Import library for Windows DLL exports, e.g. `KERNEL32.dll!CreateProcessInternalW`, `ntdll.dll!LdrRegisterDllNotification`, ...
  - Addendum to Windows SDK
  - Extension macros and definitions, e.g. `NtCurrentPeb()`, `PEB(64/32)`, `TEB(64/32)`, ...
- Specifications
  - SMBIOS
  - CPUID
  - MSVC
- Kits
  - Unit Test Framework
  - StrSafe.h (different from `strsafe.h` in Windows SDK)

## Usage

[![NuGet Downloads](https://img.shields.io/nuget/dt/KNSoft.NDK)](https://www.nuget.org/packages/KNSoft.NDK)

### TL;DR

Include [NDK.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/NDK.h) instead of (or **BEFORE**) `Windows.h` will do.
```C
#include <KNSoft/NDK/NDK.h>
```

NuGet package [KNSoft.NDK](https://www.nuget.org/packages/KNSoft.NDK) includes all the headers and import libraries.

### Details

The following features **are not enabled by default**, reference corresponding headers and libraries on demand:

- Specifications
  - CPUID: [CPUID.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/Extension/CPUID.h)
  - SMBIOS: [SMBIOS.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/Extension/SMBIOS.h)
- Ntdll Hash API (`(A_SHA/MD4/MD5)(Init/Update/Final)`)
  - [Ntdll.Hash.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/WinDef/API/Ntdll.Hash.h)
  - KNSoft.NDK.Ntdll.Hash.lib (Generated from [KNSoft.NDK.Ntdll.Hash.xml](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/KNSoft.NDK/WinAPI/KNSoft.NDK.Ntdll.Hash.xml))
- Windows API import library addendum
  - KNSoft.NDK.WinAPI.lib (Generated from [KNSoft.NDK.WinAPI.xml](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/KNSoft.NDK/WinAPI/KNSoft.NDK.WinAPI.xml))
- Unit Test Framework
  - [UnitTest.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/UnitTest/UnitTest.h)
  - [UnitTest.inl](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/UnitTest/UnitTest.inl)
- Safe string functions (different from `strsafe.h` in Windows SDK)
  - [StrSafe.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/Extension/StrSafe.h)

The following features **are enabled by default**, can be excluded by defining corresponding macro:

| Macro | Exclude feature |
| ---- | ---- |
| _KNSOFT_NDK_NO_EXTENSION | Addendum or extension macros and definitions |
| _KNSOFT_NDK_NO_EXTENSION_MSTOOLCHAIN | Microsoft Tool Chain specific extension |

## Compatibility

![PR Welcome](https://img.shields.io/badge/PR-welcome-0688CB.svg) [![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/KNSoft/KNSoft.NDK/msbuild.yml)](https://github.com/KNSoft/KNSoft.NDK/actions/workflows/msbuild.yml)

[KNSoft.NDK](https://github.com/KNSoft/KNSoft.NDK) always follow up the latest Windows NT and specifications, targets to x86, x64 and ARM64 platforms.

**Only support the latest MSVC generation tools and SDKs.**

> [!CAUTION]
> In beta stage, should be used with caution.

## License

[![GitHub License](https://img.shields.io/github/license/KNSoft/KNSoft.NDK)](https://github.com/KNSoft/KNSoft.NDK/blob/main/LICENSE)

[KNSoft.NDK](https://github.com/KNSoft/KNSoft.NDK) is licensed under the [MIT](https://github.com/KNSoft/KNSoft.NDK/blob/main/LICENSE) license.

The content from the following public sources were lawfully used:
- Microsoft WDK/DDK/SDK
- Microsoft Public Symbolic Data
- Microsoft Learning
- Microsoft Windows Protocols
- Windows Internals

And public projects:
- [winsiderss/phnt](https://github.com/winsiderss/phnt) - [MIT](https://github.com/winsiderss/phnt/blob/master/LICENSE) ([RatinCN/phnt](https://github.com/RatinCN/phnt) fork is used)

[KNSoft.NDK](https://github.com/KNSoft/KNSoft.NDK) also uses [KNSoft/Precomp4C](https://github.com/KNSoft/Precomp4C) to generate DLL import libraries.
