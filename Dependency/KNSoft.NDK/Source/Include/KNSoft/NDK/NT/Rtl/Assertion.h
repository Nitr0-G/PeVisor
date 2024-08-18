#pragma once

#include "../NT.h"

EXTERN_C_START

#pragma region Assert

#if DBG

#define ASSERT( exp ) \
    ((!(exp)) ? \
        (RtlAssert( (PVOID)#exp, (PVOID)__FILE__, __LINE__, NULL ),FALSE) : \
        TRUE)
#define ASSERTMSG( msg, exp ) \
    ((!(exp)) ? \
        (RtlAssert( (PVOID)#exp, (PVOID)__FILE__, __LINE__, (PSTR)msg ),FALSE) : \
        TRUE)
#define RTL_SOFT_ASSERT(_exp) \
    ((!(_exp)) ? \
        (DbgPrint("%s(%d): Soft assertion failed\n   Expression: %s\n", __FILE__, __LINE__, #_exp),FALSE) : \
        TRUE)
#define RTL_SOFT_ASSERTMSG(_msg, _exp) \
    ((!(_exp)) ? \
        (DbgPrint("%s(%d): Soft assertion failed\n   Expression: %s\n   Message: %s\n", __FILE__, __LINE__, #_exp, (_msg)),FALSE) : \
        TRUE)
#define RTL_VERIFY         ASSERT
#define RTL_VERIFYMSG      ASSERTMSG
#define RTL_SOFT_VERIFY    RTL_SOFT_ASSERT
#define RTL_SOFT_VERIFYMSG RTL_SOFT_ASSERTMSG

#else

#define ASSERT(exp)         ((void) 0)
#define ASSERTMSG(msg, exp) ((void) 0)
#define RTL_SOFT_ASSERT(_exp)           ((void) 0)
#define RTL_SOFT_ASSERTMSG(_msg, _exp)  ((void) 0)
#define RTL_VERIFY(exp)         ((exp) ? TRUE : FALSE)
#define RTL_VERIFYMSG(msg, exp) ((exp) ? TRUE : FALSE)
#define RTL_SOFT_VERIFY(_exp)           ((_exp) ? TRUE : FALSE)
#define RTL_SOFT_VERIFYMSG(msg, _exp)   ((_exp) ? TRUE : FALSE)

#endif // DBG

#pragma endregion wdm.h

EXTERN_C_END
