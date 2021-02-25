#define _MM32_STARTUP_C_

#include "stdint.h"
#include "mm32_startup.h"

////////////////////////////////////////////////////////////////////////////////
///
/// Compiler Configuration
///
////////////////////////////////////////////////////////////////////////////////
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
///
/// Interrupt Vector Table
///
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

////////////////////////////////////////////////////////////////////////////////
///
/// Reset Handler
///
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
    #error "Error: Unknown Compiler!"
#endif

    while (1) {}
}
