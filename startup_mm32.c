#define _STARTUP_MM32_C_

#include "stdint.h"
#include "startup_mm32.h"

////////////////////////////////////////////////////////////////////////////////
///
/// IAR Compiler
///
////////////////////////////////////////////////////////////////////////////////
#if defined ( __ICCARM__ )
    #pragma segment  = "CSTACK"
    #pragma section  = ".intvec"
    #pragma location = ".intvec"
    const intvec_elem __vector_table[]    = {
        { .__ptr = __sfe("CSTACK")},

////////////////////////////////////////////////////////////////////////////////
///
/// ARM Compiler 4/5 || ARM Compiler 6 (armclang)
///
////////////////////////////////////////////////////////////////////////////////
#elif defined ( __CC_ARM ) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
    extern uint32_t         Image$$ARM_LIB_STACK$$ZI$$Limit;
    #define __initial_sp    Image$$ARM_LIB_STACK$$ZI$$Limit
    extern void __main      (void) __attribute__((noreturn));
    const intvec_elem vector_table[] __attribute__((section("vector_table"))) = {
        { .__ptr = &__initial_sp},

////////////////////////////////////////////////////////////////////////////////
///
/// GNU Compiler
///
////////////////////////////////////////////////////////////////////////////////
#elif defined ( __GNUC__ )
    extern uint32_t         _estack;
    #define __initial_sp    _estack
    extern void _start      (void);
    void *vector_table[]    __attribute__((section(".vector_table"))) = {
        (void *)(&__initial_sp),

////////////////////////////////////////////////////////////////////////////////
///
/// Unknown Compiler
///
////////////////////////////////////////////////////////////////////////////////
#else
    #error ("Error: Unknown Compiler!")
#endif


////////////////////////////////////////////////////////////////////////////////
///
/// Chip Handlers
///
////////////////////////////////////////////////////////////////////////////////
#if defined(__CORTEX_M_CORE_HANDLERS__)
        __CORTEX_M_CORE_HANDLERS__
#endif

#if defined(__MM32_IRQ_HANDLERS__)
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
#elif defined ( __CC_ARM ) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
    __main();
#elif defined ( __GNUC__ )
    _start();
#else
    #error "Error: Unknown Compiler!"
#endif

    while (1) {}
}
