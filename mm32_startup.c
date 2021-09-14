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

#include "mm32.h"
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

extern uint32_t __INITIAL_SP;
extern void __PROGRAM_START(void);
#define __initial_sp &__INITIAL_SP

////////////////////////////////////////////////////////////////////////////////
///  @brief  Interrupt Vector Table
////////////////////////////////////////////////////////////////////////////////
#if defined(__ICCARM__)
    #ifndef __VECTOR_TABLE_ATTRIBUTE
    #define __VECTOR_TABLE_ATTRIBUTE __attribute__((used, section(".intvec")))
    #endif
#endif

const intvec_elem __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
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
    __PROGRAM_START();

    while (1) {}
}
