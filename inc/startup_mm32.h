#ifndef __STARTUP_MM32_H__
#define __STARTUP_MM32_H__

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

#ifndef __WEAK
    #define __WEAK __attribute__((weak))
#endif

////////////////////////////////////////////////////////////////////////////////
///
///                         DECLARE WEAK HANDLERS
///
////////////////////////////////////////////////////////////////////////////////
// Cortex-M core handlers
__WEAK void HardFault_Handler               (void) { while(1) {} }
__WEAK void NMI_Handler                     (void) { while(1) {} }
__WEAK void MemManage_Handler               (void) { while(1) {} }
__WEAK void BusFault_Handler                (void) { while(1) {} }
__WEAK void UsageFault_Handler              (void) { while(1) {} }
__WEAK void SVC_Handler                     (void) { while(1) {} }
__WEAK void DebugMon_Handler                (void) { while(1) {} }
__WEAK void PendSV_Handler                  (void) { while(1) {} }
__WEAK void SysTick_Handler                 (void) { while(1) {} }

// Peripherals handlers
__WEAK void WDG_IRQHandler                  (void) { while(1) {} }
__WEAK void PVD_IRQHandler                  (void) { while(1) {} }
__WEAK void PWM_IRQHandler                  (void) { while(1) {} }
__WEAK void FLASH_IRQHandler                (void) { while(1) {} }
__WEAK void RCC_IRQHandler                  (void) { while(1) {} }
__WEAK void EXTI0_1_IRQHandler              (void) { while(1) {} }
__WEAK void EXTI2_3_IRQHandler              (void) { while(1) {} }
__WEAK void EXTI4_15_IRQHandler             (void) { while(1) {} }
__WEAK void HWDIV_IRQHandler                (void) { while(1) {} }
__WEAK void DMA1_Channel1_IRQHandler        (void) { while(1) {} }
__WEAK void DMA1_Channel2_3_IRQHandler      (void) { while(1) {} }
__WEAK void DMA1_Channel4_5_IRQHandler      (void) { while(1) {} }
__WEAK void ADC_COMP_IRQHandler             (void) { while(1) {} }
__WEAK void TIM1_BRK_UP_TRG_COM_IRQHandler  (void) { while(1) {} }
__WEAK void TIM1_CC_IRQHandler              (void) { while(1) {} }
__WEAK void TIM2_IRQHandler                 (void) { while(1) {} }
__WEAK void TIM3_IRQHandler                 (void) { while(1) {} }
__WEAK void TIM14_IRQHandler                (void) { while(1) {} }
__WEAK void TIM16_IRQHandler                (void) { while(1) {} }
__WEAK void TIM17_IRQHandler                (void) { while(1) {} }
__WEAK void I2C1_IRQHandler                 (void) { while(1) {} }
__WEAK void SPI1_IRQHandler                 (void) { while(1) {} }
__WEAK void SPI2_IRQHandler                 (void) { while(1) {} }
__WEAK void UART1_IRQHandler                (void) { while(1) {} }
__WEAK void UART2_IRQHandler                (void) { while(1) {} }

////////////////////////////////////////////////////////////////////////////////
///
///                             DECLARE HANDLERS
///
////////////////////////////////////////////////////////////////////////////////
// Cortex-M core handlers
void Reset_Handler                          (void);
void NMI_Handler                            (void);
void HardFault_Handler                      (void);
void MemManage_Handler                      (void);
void BusFault_Handler                       (void);
void UsageFault_Handler                     (void);
void SVC_Handler                            (void);
void DebugMon_Handler                       (void);
void PendSV_Handler                         (void);
void SysTick_Handler                        (void);

// Peripherals handlers
void WDG_IRQHandler                         (void);
void PVD_IRQHandler                         (void);
void PWM_IRQHandler                         (void);
void FLASH_IRQHandler                       (void);
void RCC_IRQHandler                         (void);
void EXTI0_1_IRQHandler                     (void);
void EXTI2_3_IRQHandler                     (void);
void EXTI4_15_IRQHandler                    (void);
void HWDIV_IRQHandler                       (void);
void DMA1_Channel1_IRQHandler               (void);
void DMA1_Channel2_3_IRQHandler             (void);
void DMA1_Channel4_5_IRQHandler             (void);
void ADC_COMP_IRQHandler                    (void);
void TIM1_BRK_UP_TRG_COM_IRQHandler         (void);
void TIM1_CC_IRQHandler                     (void);
void TIM2_IRQHandler                        (void);
void TIM3_IRQHandler                        (void);
void TIM14_IRQHandler                       (void);
void TIM16_IRQHandler                       (void);
void TIM17_IRQHandler                       (void);
void I2C1_IRQHandler                        (void);
void SPI1_IRQHandler                        (void);
void SPI2_IRQHandler                        (void);
void UART1_IRQHandler                       (void);
void UART2_IRQHandler                       (void);

////////////////////////////////////////////////////////////////////////////////
///
///                          CONSTRUCT VECTOR TABLE
///
////////////////////////////////////////////////////////////////////////////////
#define __CORTEX_M_CORE_HANDLERS__          Reset_Handler,                  \
                                            NMI_Handler,                    \
                                            HardFault_Handler,              \
                                            MemManage_Handler,              \
                                            BusFault_Handler,               \
                                            UsageFault_Handler,             \
                                            0,                              \
                                            0,                              \
                                            0,                              \
                                            0,                              \
                                            SVC_Handler,                    \
                                            DebugMon_Handler,               \
                                            0,                              \
                                            PendSV_Handler,                 \
                                            SysTick_Handler,

#define __MM32_IRQ_HANDLERS__               WDG_IRQHandler,                 \
                                            PVD_IRQHandler,                 \
                                            PWM_IRQHandler,                 \
                                            FLASH_IRQHandler,               \
                                            RCC_IRQHandler,                 \
                                            EXTI0_1_IRQHandler,             \
                                            EXTI2_3_IRQHandler,             \
                                            EXTI4_15_IRQHandler,            \
                                            HWDIV_IRQHandler,               \
                                            DMA1_Channel1_IRQHandler,       \
                                            DMA1_Channel2_3_IRQHandler,     \
                                            DMA1_Channel4_5_IRQHandler,     \
                                            ADC_COMP_IRQHandler,            \
                                            TIM1_BRK_UP_TRG_COM_IRQHandler, \
                                            TIM1_CC_IRQHandler,             \
                                            TIM2_IRQHandler,                \
                                            TIM3_IRQHandler,                \
                                            0,                              \
                                            0,                              \
                                            TIM14_IRQHandler,               \
                                            0,                              \
                                            TIM16_IRQHandler,               \
                                            TIM17_IRQHandler,               \
                                            I2C1_IRQHandler,                \
                                            0,                              \
                                            SPI1_IRQHandler,                \
                                            SPI2_IRQHandler,                \
                                            UART1_IRQHandler,               \
                                            UART2_IRQHandler

#endif // __STARTUP_MM32_H__