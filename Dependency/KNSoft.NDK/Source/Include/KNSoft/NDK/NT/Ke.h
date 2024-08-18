#pragma once

#include "./MinDef.h"

EXTERN_C_START

/* wdm.h */

#define LOW_PRIORITY 0              // Lowest thread priority level
#define LOW_REALTIME_PRIORITY 16    // Lowest realtime priority level
#define HIGH_PRIORITY 31            // Highest thread priority level
#define MAXIMUM_PRIORITY 32         // Number of thread priority levels

#define MAXIMUM_WAIT_OBJECTS 64     // Maximum number of wait objects

#define MAXIMUM_SUSPEND_COUNT MAXCHAR // Maximum times thread can be suspended

/* wdm.h */
typedef enum _KINTERRUPT_MODE
{
    LevelSensitive,
    Latched
} KINTERRUPT_MODE;

EXTERN_C_END
