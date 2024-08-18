/*
 * KNSoft.NDK (https://github.com/KNSoft/KNSoft.NDK)
 * Copyright (c) KNSoft.org (https://github.com/KNSoft). All rights reserved.
 * Licensed under the MIT license.
 */

#pragma once

#include "./NT/NT.h"

/* Windows.h */

#include <Windows.h>
#include "./Win32/Def/WinUser.h"
#include "./3rdParty/phnt/winsta.h"

/* APIs */

#include "./Win32/API/Ntdll.h"
#include "./Win32/API/Kernel32.h"
#include "./Win32/API/User32.h"

/* Additional headers */

#include <intrin.h>
#include <suppress.h>

/* Enable extensions */

#ifndef _KNSOFT_NDK_NO_EXTENSION
#include "Extension/Extension.h"
#endif

#ifndef _KNSOFT_NDK_NO_EXTENSION_MSTOOLCHAIN
#include "Extension/MSToolChain.h"
#endif
