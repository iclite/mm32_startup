////////////////////////////////////////////////////////////////////////////////
/// @file    MM32_SYSTEM.C
/// @author  AE TEAM
/// @version 2.0.0
/// @date    2018-08-01
/// @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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
/// <H2><CENTER>&COPY; COPYRIGHT 2018 MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion  --------------------------------------
#define _MM32_SYSTEM_C_

// Files includes  -------------------------------------------------------------
#include <string.h>
#include "mm32_types.h"
#include "mm32.h"

#include "mm32_system.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_RESOURCE
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Exported_Constants
/// @{

#if defined(__CORTEX_M) && (__CORTEX_M == 3U)
//  #define VECT_TAB_SRAM
    #define VECT_TAB_OFFSET  0x0000
#endif

#ifndef __WEAK
    #define __WEAK __attribute__((weak))
#endif

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Exported_Functions
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function handles SysTick Handler.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
__WEAK void SysTick_Handler (void)
{
    nTimeOutCnt++;
    sysTickFlag1mS = true;

    if (sysTickCnt++ >= 20) {
        sysTickCnt  = 0;
        sysTickFlag = true;
    }

    if (AppTickPtr != NULL) {
        AppTickPtr();
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function get the MCU ID.
/// @param  None.
/// @retval  MCU ID.
////////////////////////////////////////////////////////////////////////////////
EM_MCUID DBGMCU_GetDEVID()
{
    if ((SCB->CPUID & SCB_CPUID_PARTNO_Msk) == CORTEX_M3_PARTNO) {
        RCC->APB1ENR &= ~RCC_APB1ENR_PWR;
        RCC->APB1ENR |= RCC_APB1ENR_PWR;
    }

    switch (DBG->IDCODE) {
    case MCUID_MM0N1:
        return emMCUID_MM32L073;        // emMCUID_MM0N1;
    case MCUID_MM0P1:
    case MCUID_MM0P2:
        return emMCUID_MM32SPIN27;      // emMCUID_MM0P1;
    case MCUID_MM0Q1:
        return emMCUID_MM32F031;        // emMCUID_MM0Q1;
    case MCUID_MM0M1:
        return emMCUID_MM32F031_OLD;    // emMCUID_MM0M1;
    case MCUID_MM3O1:
        return emMCUID_MM32L395;        // emMCUID_MM3O1;
    case MCUID_MM3N1:
        return emMCUID_MM32L373;        // emMCUID_MM3N1;
    case MCUID_MM3M1:
        return emMCUID_MM32F103_OLD;    // emMCUID_MM3M1;
    default:
        return Unknown;
    }
}

////////////////////////////////////////////////////////////////////////////////
// @brief  Setup the microcontroller system
//         Initialize the Embedded Flash Interface, the PLL and update the
//         SystemCoreClock variable.
// @note   This function should be used only after reset.
// @param  ClockSoucre : Select system clock source.
// @param  tickEn : Enable or disable the systick.
// @param  pCallback : The pointer point to the systick callback function.
// @retval  MCU ID.
////////////////////////////////////////////////////////////////////////////////
EM_MCUID SystemInit(EM_SystemClock ClockSource, EM_SYSTICK tickEn , AppTick_fun pCallback)
{
    // Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers
    // Configure the Flash Latency cycles and enable prefetch buffer

    // Flash
    if ((ClockSource >> 16) <= 4) {
        FLASH->ACR |= FLASH_ACR_PRFTBE;
        FLASH->ACR &=~FLASH_ACR_LATENCY;
        FLASH->ACR |= ClockSource >> 16;
    } else {
        while(1);                                                               // Flash Latency not in range.
    }

    // Set Oscillator
    if ((ClockSource & 0x0000F) == 0) {                                         // HSI
#if defined(RCC_CR_HSI_72M)
        (((ClockSource & 0xF0000) >> 16) == 1) ? (RCC->CR &= ~RCC_CR_HSI_72M) :
                                                 (RCC->CR |=  RCC_CR_HSI_72M);
#endif
        RCC->CR |= RCC_CR_HSION;
        while (!(RCC->CR & RCC_CR_HSIRDY));                                     // Wait for HSI clock ready!
#if defined(RCC_CFGR_PLLSRC)
        RCC->CFGR &= ~RCC_CFGR_PLLSRC;
#elif defined(RCC_PLLCFGR_PLLSRC)
        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC;
#endif
    } else if ((ClockSource & 0x0000F) == 1) {                                  // HSE
        RCC->CR |= RCC_CR_HSEON;
        while (!(RCC->CR & RCC_CR_HSERDY));                                     // Wait for PLL ready!
#if defined(RCC_CFGR_PLLSRC)
        RCC->CFGR |= RCC_CFGR_PLLSRC;
#elif defined(RCC_PLLCFGR_PLLSRC)
        RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;
#endif
    } else if ((ClockSource & 0x0000F) == 2) {                                  // LSE
        RCC->CSR |= RCC_CSR_LSION;
        while (!(RCC->CR & RCC_CSR_LSIRDY));                                    // Wait for PLL ready!
    } else {
        while (1);                                                              // Clock Source not in range
    }

#if defined(RCC_CR_PLLON)
    // PLL on
    if ((ClockSource & 0x000F0) >> 4 == 2) {
#if defined(RCC_PLLCFGR_PLLSRC)
        RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLMUL | RCC_PLLCFGR_PLLDIV);
        RCC->PLLCFGR |= (((ClockSource & 0x0F000) >> 12) << RCC_PLLCFGR_PLLMUL_Pos);
        RCC->PLLCFGR |= ((ClockSource & 0x00F00) << RCC_PLLCFGR_PLLDIV_Pos);
#else
        RCC->CR |= ((ClockSource & 0x0F000) << 14);
        RCC->CR |= ((ClockSource & 0x00F00) << 12);
#endif
        RCC->CR |= RCC_CR_PLLON;
        while (!(RCC->CR & RCC_CR_PLLRDY)); // Wait for PLL ready!
    }
#endif

#if defined(USB)
    RCC->CFGR |= (1 << RCC_CFGR_USBPRE_Pos) & RCC_CFGR_USBPRE;
#endif

    // AHB, APB1, APB2
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;
#if !defined(__MM0T1)
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
#endif
    // Clock Switch to
    RCC->CFGR |= (((ClockSource & 0x000F0) >> 4) << RCC_CFGR_SW_Pos) & RCC_CFGR_SW;
    while (((RCC->CFGR & RCC_CFGR_SWS) >> 2) != ((ClockSource & 0x000F0) >> 4));

    if (tickEn && pCallback != NULL)
        AppTickPtr = pCallback;

    if (tickEn) {
        u32 clock = 8000000;
        u32 pre   = 1000000;
        if (((ClockSource & 0x000F0) >> 4) == 2) {
            clock =  ((ClockSource & 0x0000F) == 0) ? 12000000 : HSE_VALUE;
            if (!(ClockSource & 0x0F000) && (ClockSource & 0xF0000)) {
                clock = ((ClockSource & 0xF0000) == 0x10000) ? 48000000 : 72000000;
            } else {
                clock *= ((ClockSource & 0x0F000) >> 12) + 1;
                clock /= ((ClockSource & 0x00F00) >> 8)  + 1;
            }
        } else if (((ClockSource & 0x000F0) >> 4) == 3) {
            clock = 40000;
            pre   = 10000;
        }
        SysTick_Config(clock / pre * 1000);
    } else {
        SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

#if (__CORTEX_M == 3U)
    #ifdef VECT_TAB_SRAM
        SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM. */
    #else
        SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH. */
    #endif
#endif

    return DBGMCU_GetDEVID();
}


////////////////////////////////////////////////////////////////////////////////
//  @brief  System clock configuration
//  @param  enable: Enable or disable the systick.
//  @param  callbackPtr: The pointer point to the systick callback function.
//  @retval None.
////////////////////////////////////////////////////////////////////////////////
EM_MCUID SetSystemClock(EM_SYSTICK enable , AppTick_fun callbackPtr)
{
    return SystemInit(SYSCLK_HSI_72MHz, enable, callbackPtr);
}

/// @}


/// @}

/// @}


