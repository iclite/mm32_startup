////////////////////////////////////////////////////////////////////////////////
/// @file    MM32_SYSTEM.H
/// @author  Nanjing AE Team
/// @version V2.0.0
/// @date    2021-02-25
/// @brief   THIS FILE PROVIDES ALL THE SYSTEM FIRMWARE FUNCTIONS.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT 2018-2021 MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion  --------------------------------------
#ifndef __MM32_SYSTEM_H
#define __MM32_SYSTEM_H

// Files includes  -------------------------------------------------------------
#include "mm32_types.h"

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Startup_Layer
/// @brief MM32 Startup Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_System
/// @brief MM32 System Resource
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Constants
/// @{

#define IDCODE_DEVID_MASK               (0x00000FFFU)
#define COREID_MASK                     (0x00000070U)
#define CORTEX_M0_PARTNO                (0x0000C200U)   // Cortex-M0 r0p0
#define CORTEX_M3_PARTNO                (0x0000C230U)   // Cortex-M3 r1p1/r2p0/r2p1
#define CORTEX_M4_PARTNO                (0x0000C240U)   // Cortex-M4 r0p1
#define CORTEX_M7_PARTNO                (0x0000C270U)   // Cortex-M7 r0p2/r1p0/r1p1/r1p2
#define CORTEX_M23_PARTNO               (0x0000D200U)   // Cortex-M23 r1p0
#define MCUID_MM3M1                     (0xCC888045U)
#define MCUID_MM0M1                     (0xCC567071U)
#define MCUID_MM3N1                     (0xCC888047U)
#define MCUID_MM0N1                     (0xCC568091U)
#define MCUID_MM3O1                     (0xCC9AA0A1U)
#define MCUID_MM0P1                     (0xCC56A091U)
#define MCUID_MM0P2                     (0xCC56A097U)
#define MCUID_MM0Q1                     (0xCC4460B1U)
#define MCUID_MM0S1                     (0xCC5680C7U)
#define MCUID_MM0T1                     (0xCC4350D1U)
#define MCUID_MM3U1                     (0xCC9AA0E7U)

#ifndef CLOCK
    #warning "\"CLOCK\" macro is undefined!"
    #define CLOCK                       (8000000U)
#endif

#define HSE_VALUE                       CLOCK

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Enumeration
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief MCU ID enumerate definition.
/// @anchor EM_MCUID
////////////////////////////////////////////////////////////////////////////////
typedef enum {
    emMCUID_Unknown,
    emMCUID_MM32L073,
    emMCUID_MM32SPIN27,
    emMCUID_MM32F031,
    emMCUID_MM32F031_OLD,
    emMCUID_MM32L395,
    emMCUID_MM32F103_OLD,
    emMCUID_MM32L373,
    emMCUID_MM32F0130,
    emMCUID_MM32F0010,
    emMCUID_MM32F3270
}EM_MCUID;

////////////////////////////////////////////////////////////////////////////////
/// @brief Systick enable enumerate definition.
/// @anchor EM_SYSTICK
////////////////////////////////////////////////////////////////////////////////
typedef enum {
    emSYSTICK_Off,
    emSYSTICK_On = !emSYSTICK_Off
} EM_SYSTICK;

////////////////////////////////////////////////////////////////////////////////
/// @brief  System clock configuration
////////////////////////////////////////////////////////////////////////////////
typedef enum {
                                        //  Flash_Latency   Mul Div Sw  Src
    SYSCLK_HSI_6d       = 0x00000,      //              0   0   0   0   0
#if defined(__MM3N1) || defined(__MM0N1) || defined(__MM0P1) || defined(__MM0S1)
    SYSCLK_HSI_12MHz    = 0x00020,      //              0   0   0   2   0
    SYSCLK_HSI_24MHz    = 0x01020,      //              0   1   0   2   0
    SYSCLK_HSI_48MHz    = 0x13020,      //              1   3   0   2   0
    SYSCLK_HSI_72MHz    = 0x25020,      //              2   5   0   2   0
    SYSCLK_HSI_96MHz    = 0x37020,      //              3   7   0   2   0
    SYSCLK_HSE_1x       = 0x00011,      //              0   0   0   1   1
    SYSCLK_HSE_3x       = 0x02021,      //              0   2   0   2   1
    SYSCLK_HSE_4x       = 0x13021,      //              1   3   0   2   1
    SYSCLK_HSE_6x       = 0x15021,      //              1   5   0   2   1
    SYSCLK_HSE_7x       = 0x26021,      //              2   6   0   2   1
    SYSCLK_HSE_9x       = 0x28021,      //              2   8   0   2   1
    SYSCLK_HSE_12x      = 0x3B021,      //              3   1   0   2   1
#endif
#if defined(__MM0Q1) || defined(__MM0T1)
    SYSCLK_HSE_1x       = 0x00011,      //              0   0   0   1   1
    SYSCLK_HSI_48MHz    = 0x10020,      //              1   0   0   2   0
    SYSCLK_HSI_72MHz    = 0x20020,      //              2   0   0   2   0
    SYSCLK_LSI_40KHz    = 0x00032,      //              0   0   0   3   2
#endif
#if defined(__MM3U1)
    SYSCLK_HSI_8MHz     = 0x00020,      //              0   0   0   2   0
    SYSCLK_HSI_16MHz    = 0x01020,      //              0   1   0   2   0
    SYSCLK_HSI_24MHz    = 0x02020,      //              0   2   0   2   0
    SYSCLK_HSI_32MHz    = 0x13020,      //              1   3   0   2   0
    SYSCLK_HSI_40MHz    = 0x14020,      //              1   4   0   2   0
    SYSCLK_HSI_48MHz    = 0x15020,      //              1   5   0   2   0
    SYSCLK_HSI_56MHz    = 0x26020,      //              2   6   0   2   0
    SYSCLK_HSI_64MHz    = 0x27020,      //              2   7   0   2   0
    SYSCLK_HSI_72MHz    = 0x38020,      //              3   8   0   2   0
    SYSCLK_HSI_80MHz    = 0x39020,      //              3   9   0   2   0
    SYSCLK_HSI_88MHz    = 0x3A020,      //              3   9   0   2   0
    SYSCLK_HSI_96MHz    = 0x3B020,      //              3   9   0   2   0
    SYSCLK_HSI_104MHz   = 0x4C020,      //              4   9   0   2   0
    SYSCLK_HSI_112MHz   = 0x4D020,      //              4   9   0   2   0
    SYSCLK_HSI_120MHz   = 0x4E020,      //              4   9   0   2   0
    SYSCLK_HSE_1x       = 0x00011,      //              0   0   0   1   1
    SYSCLK_HSE_2x       = 0x01011,      //              0   1   0   1   1
    SYSCLK_HSE_3x       = 0x02021,      //              0   2   0   2   1
    SYSCLK_HSE_4x       = 0x13021,      //              1   3   0   2   1
    SYSCLK_HSE_5x       = 0x14021,      //              1   4   0   2   1
    SYSCLK_HSE_6x       = 0x15021,      //              1   5   0   2   1
    SYSCLK_HSE_7x       = 0x26021,      //              2   6   0   2   1
    SYSCLK_HSE_8x       = 0x27021,      //              2   7   0   2   1
    SYSCLK_HSE_9x       = 0x28021,      //              2   8   0   2   1
    SYSCLK_HSE_10x      = 0x39021,      //              3   9   0   2   1
    SYSCLK_HSE_11x      = 0x3A021,      //              3   A   0   2   1
    SYSCLK_HSE_12x      = 0x3B021,      //              3   B   0   2   1
    SYSCLK_HSE_13x      = 0x4C021,      //              4   C   0   2   1
    SYSCLK_HSE_14x      = 0x4D021,      //              4   D   0   2   1
    SYSCLK_HSE_15x      = 0x4E021,      //              4   E   0   2   1
#endif
} EM_SystemClock;

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_TypeDef
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  SysTick Callback Type Definition
////////////////////////////////////////////////////////////////////////////////
typedef void (*AppTick_fun)(void);

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Variables
/// @{

#ifdef _MM32_SYSTEM_C_
#define GLOBAL

GLOBAL int nTimeOutCnt = 0;

GLOBAL bool sysTickFlag1mS  = false;
GLOBAL bool sysTickFlag     = false;
GLOBAL u32  sysTickCnt      = 0;

GLOBAL bool tickFlag = false;

#else
#define GLOBAL extern

GLOBAL bool sysTickFlag1mS;
GLOBAL int nTimeOutCnt;
GLOBAL bool sysTickFlag;
GLOBAL u32 sysTickCnt;
GLOBAL bool tickFlag;

#endif

GLOBAL bool sysTickFlag;
GLOBAL u32 sysTickCnt;
GLOBAL EM_MCUID MCUID;

GLOBAL AppTick_fun AppTickPtr;

#undef GLOBAL

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Functions
/// @{

EM_MCUID DBG_GetDEVID(void);
EM_MCUID SystemInit(EM_SystemClock clockConfig, EM_SYSTICK tickEn , AppTick_fun callback);
EM_MCUID SetSystemClock(EM_SYSTICK enable , AppTick_fun callback);

/// @}

/// @}

/// @}

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
