////////////////////////////////////////////////////////////////////////////////
/// @file    MM32_STARTUP.C
/// @author  Nanjing AE Team
/// @version 1.0.0
/// @date    2021-04-21
/// @brief   THIS FILE PROVIDES ALL THE STARTUP FUNCTIONS.
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
/// <H2><CENTER>&COPY; COPYRIGHT 2021 MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion  --------------------------------------
#define _MM32_STARTUP_C_

// Files includes  -------------------------------------------------------------
#include <stdint.h>

#include "mm32_startup.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_RESOURCE
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Exported_Constants
/// @{

#if defined ( __ICCARM__ )
    #pragma segment  = "CSTACK"                                                 // IAR
    #define __initial_sp __sfe("CSTACK")
    extern void __iar_program_start(void);
#elif defined ( __CC_ARM ) || (defined ( __ARMCC_VERSION ) && ( __ARMCC_VERSION >= 6010050 ))
    extern uint32_t         Image$$ARM_LIB_STACK$$ZI$$Limit;                    // KEIL
    #define __initial_sp    &Image$$ARM_LIB_STACK$$ZI$$Limit
    extern void __main      (void) __attribute__((noreturn));
#elif defined ( __GNUC__ )
    extern uint32_t         _estack;                                            // GNU
    #define __initial_sp    &_estack
    extern void _start      (void);
#else
    #error ("Error: Unknown Compiler!")                                         // UNKNOWN
#endif

////////////////////////////////////////////////////////////////////////////////
///  @brief  Interrupt Vector Table
////////////////////////////////////////////////////////////////////////////////
const intvec_elem __vector_table[] __attribute__((section(".vector_table"))) = {
    { .__ptr = __initial_sp },

#if defined( __CORTEX_M_CORE_HANDLERS__ )
    __CORTEX_M_CORE_HANDLERS__
#endif

#if defined( __MM32_IRQ_HANDLERS__ )
    __MM32_IRQ_HANDLERS__
#endif
};

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Exported_Functions
/// @{

////////////////////////////////////////////////////////////////////////////////
///  @brief  System Reset Function.
///  @param  None.
///  @retval None.
////////////////////////////////////////////////////////////////////////////////
void Reset_Handler(void)
{
#if defined ( __ICCARM__ )
    __iar_program_start();
#elif defined ( __CC_ARM ) || (defined ( __ARMCC_VERSION ) && ( __ARMCC_VERSION >= 6010050 ))
    __main();
#elif defined ( __GNUC__ )
    _start();
#else
    #error Unknown compiler.
#endif

    while (1) {}
}
