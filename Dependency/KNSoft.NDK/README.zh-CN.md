| [English (en-US)](https://github.com/KNSoft/KNSoft.NDK/blob/main/README.md) | **简体中文 (zh-CN)** |
| --- | --- |

<br>

# KNSoft.NDK

[![NuGet Downloads](https://img.shields.io/nuget/dt/KNSoft.NDK)](https://www.nuget.org/packages/KNSoft.NDK) [![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/KNSoft/KNSoft.NDK/msbuild.yml)](https://github.com/KNSoft/KNSoft.NDK/actions/workflows/msbuild.yml) ![PR Welcome](https://img.shields.io/badge/PR-welcome-0688CB.svg) [![GitHub License](https://img.shields.io/github/license/KNSoft/KNSoft.NDK)](https://github.com/KNSoft/KNSoft.NDK/blob/main/LICENSE)

[KNSoft.NDK](https://github.com/KNSoft/KNSoft.NDK)提供了原始C/C++定义和引入库供Windows NT开发。

## 功能

- Windows NT
  - 未公开的API声明和类型定义，例如：`Nt/Zw*`、`Ldr*`、`PEB`、`TEB`、`LDR_*`……
  - Windows DLL导出项引入库，例如：`KERNEL32.dll!CreateProcessInternalW`、`ntdll.dll!LdrRegisterDllNotification`……
  - Windows SDK的补充
  - 扩展的宏和定义，例如：`NtCurrentPeb()`、`PEB(64/32)`、`TEB(64/32)`……
- 规范
  - SMBIOS
  - CPUID
  - MSVC
- 工具
  - 单元测试框架
  - StrSafe.h（与Windows SDK里的`strsafe.h`不同）

## 用法

[![NuGet Downloads](https://img.shields.io/nuget/dt/KNSoft.NDK)](https://www.nuget.org/packages/KNSoft.NDK)

### 提要

包含[NDK.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/NDK.h)代替（或先于）`Windows.h`即可。
```C
#include <KNSoft/NDK/NDK.h>
```

NuGet包[KNSoft.NDK](https://www.nuget.org/packages/KNSoft.NDK)包含所有头文件和引入库。

### 详细说明

下列功能**默认没有启用**，按需引用对应的头文件和库：

- 规范
  - CPUID: [CPUID.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/Extension/CPUID.h)
  - SMBIOS: [SMBIOS.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/Extension/SMBIOS.h)
- Ntdll Hash API (`(A_SHA/MD4/MD5)(Init/Update/Final)`)
  - [Ntdll.Hash.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/WinDef/API/Ntdll.Hash.h)
  - KNSoft.NDK.Ntdll.Hash.lib (由[KNSoft.NDK.Ntdll.Hash.xml](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/KNSoft.NDK/WinAPI/KNSoft.NDK.Ntdll.Hash.xml)生成)
- Windows API 引入库补充
  - KNSoft.NDK.WinAPI.lib (由[KNSoft.NDK.WinAPI.xml](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/KNSoft.NDK/WinAPI/KNSoft.NDK.WinAPI.xml)生成)
- 单元测试框架
  - [UnitTest.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/UnitTest/UnitTest.h)
  - [UnitTest.inl](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/UnitTest/UnitTest.inl)
- 安全字符串函数（与Windows SDK里的`strsafe.h`不同）
  - [StrSafe.h](https://github.com/KNSoft/KNSoft.NDK/blob/main/Source/Include/KNSoft/NDK/Extension/StrSafe.h)

下列功能**默认启用**，定义对应宏可进行排除：

| 宏 | 排除功能 |
| ---- | ---- |
| _KNSOFT_NDK_NO_EXTENSION | 补充或扩展的宏和定义 |
| _KNSOFT_NDK_NO_EXTENSION_MSTOOLCHAIN | Microsoft工具链专有扩展 |

## 兼容性

![PR Welcome](https://img.shields.io/badge/PR-welcome-0688CB.svg) [![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/KNSoft/KNSoft.NDK/msbuild.yml)](https://github.com/KNSoft/KNSoft.NDK/actions/workflows/msbuild.yml)

[KNSoft.NDK](https://github.com/KNSoft/KNSoft.NDK)始终跟进最新的Windows NT和规范，目标x86、x64和ARM64平台。

**仅支持最新的MSVC生成工具和SDK。**

> [!CAUTION]
> 处于beta阶段，应小心使用。

## 协议

[![GitHub License](https://img.shields.io/github/license/KNSoft/KNSoft.NDK)](https://github.com/KNSoft/KNSoft.NDK/blob/main/LICENSE)

[KNSoft.NDK](https://github.com/KNSoft/KNSoft.NDK)根据[MIT](https://github.com/KNSoft/KNSoft.NDK/blob/main/LICENSE)协议进行许可。

合法使用了来自下列公开源的内容：
- Microsoft WDK/DDK/SDK
- Microsoft Public Symbolic Data
- Microsoft Learning
- Microsoft Windows Protocols
- Windows Internals

和公开项目：
- [winsiderss/phnt](https://github.com/winsiderss/phnt) - [MIT](https://github.com/winsiderss/phnt/blob/master/LICENSE) ([RatinCN/phnt](https://github.com/RatinCN/phnt) fork is used)

[KNSoft.NDK](https://github.com/KNSoft/KNSoft.NDK)也使用了[KNSoft/Precomp4C](https://github.com/KNSoft/Precomp4C)来生成DLL引入库。
