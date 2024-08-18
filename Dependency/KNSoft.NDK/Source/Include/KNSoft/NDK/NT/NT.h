#pragma once

#define _DEFINED__WNF_STATE_NAME

#include "./MinDef.h"
#include "./Macro.h"
#include "./Addendum.h"

#include <WinBase.h>
#include <evntrace.h>
#include <winioctl.h>
#include <dpfilter.h>

#pragma region phnt

#ifndef PHNT_MODE
#if defined(_KERNEL_MODE)
#define PHNT_MODE PHNT_MODE_KERNEL
#else
#define PHNT_MODE PHNT_MODE_USER
#endif
#endif

#ifndef PHNT_VERSION
#if (NTDDI_VERSION < NTDDI_WINXP)
#define PHNT_VERSION PHNT_WIN2K
#elif (NTDDI_VERSION < NTDDI_WS03)
#define PHNT_VERSION PHNT_WINXP
#elif (NTDDI_VERSION < NTDDI_WIN6)
#define PHNT_VERSION PHNT_WS03
#elif (NTDDI_VERSION < NTDDI_WIN7)
#define PHNT_VERSION PHNT_VISTA
#elif (NTDDI_VERSION < NTDDI_WIN8)
#define PHNT_VERSION PHNT_WIN7
#elif (NTDDI_VERSION < NTDDI_WINBLUE)
#define PHNT_VERSION PHNT_WIN8
#elif (NTDDI_VERSION < NTDDI_WINTHRESHOLD)
#define PHNT_VERSION PHNT_WINBLUE
#elif (NTDDI_VERSION < NTDDI_WIN10_TH2)
#define PHNT_VERSION PHNT_THRESHOLD
#elif (NTDDI_VERSION < NTDDI_WIN10_RS1)
#define PHNT_VERSION PHNT_THRESHOLD2
#elif (NTDDI_VERSION < NTDDI_WIN10_RS2)
#define PHNT_VERSION PHNT_REDSTONE
#elif (NTDDI_VERSION < NTDDI_WIN10_RS3)
#define PHNT_VERSION PHNT_REDSTONE2
#elif (NTDDI_VERSION < NTDDI_WIN10_RS4)
#define PHNT_VERSION PHNT_REDSTONE3
#elif (NTDDI_VERSION < NTDDI_WIN10_RS5)
#define PHNT_VERSION PHNT_REDSTONE4
#elif (NTDDI_VERSION < NTDDI_WIN10_19H1)
#define PHNT_VERSION PHNT_REDSTONE5
#elif (NTDDI_VERSION < NTDDI_WIN10_VB)
#define PHNT_VERSION PHNT_19H1
#elif (NTDDI_VERSION < NTDDI_WIN10_MN)
#define PHNT_VERSION PHNT_19H2
#elif (NTDDI_VERSION < NTDDI_WIN10_FE)
#define PHNT_VERSION PHNT_20H1
#elif (NTDDI_VERSION < NTDDI_WIN10_CO)
#define PHNT_VERSION PHNT_20H2
#elif (NTDDI_VERSION < NTDDI_WIN10_NI)
#define PHNT_VERSION PHNT_21H1
#elif (NTDDI_VERSION < NTDDI_WIN10_CU)
#define PHNT_VERSION PHNT_WIN10_21H2
#elif (NTDDI_VERSION < NTDDI_WIN11_ZN)
#define PHNT_VERSION PHNT_WIN10_22H2
#elif (NTDDI_VERSION < NTDDI_WIN11_GA)
#define PHNT_VERSION PHNT_WIN11_22H2
#elif (NTDDI_VERSION < NTDDI_WIN11_GE)
#define PHNT_VERSION PHNT_WIN11_23H2
#else
#define PHNT_VERSION PHNT_WIN11_24H2
#endif
#endif

#include "../3rdParty/phnt/phnt.h"

#undef RTL_SOFT_ASSERT
#undef RTL_SOFT_ASSERTMSG

#pragma endregion

#pragma region KNSoft.NDK

#include "./Dbg.h"
#include "./Ex.h"
#include "./Io.h"
#include "./Ke.h"
#include "./Mm.h"
#include "./Ob.h"
#include "./Se.h"
#include "./Rtl/Rtl.h"
#include "./Wow/Wow.h"

#ifndef _KNSOFT_NDK_NO_EXTENSION
#include "./Extension/Runtime.h"
#include "./Extension/Security.h"
#endif

#pragma endregion
