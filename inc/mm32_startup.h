////////////////////////////////////////////////////////////////////////////////
/// @file     MM32_STARTUP.H
/// @author   Nanjing AE Team
/// @version  1.0.0
/// @date     2021-04-21
/// @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE ADC
///           FIRMWARE LIBRARY.
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
#ifndef __MM32_STARTUP_H__
#define __MM32_STARTUP_H__

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
// Cortex-M0 core handlers
#if defined(__MM0N1) || defined(__MM0P1) || defined(__MM0Q1) || defined(__MM0S1) || defined(__MM0T1)
__WEAK void NMI_Handler                 (void)  { while(1) {} }
__WEAK void HardFault_Handler           (void)  { while(1) {} }
__WEAK void SVC_Handler                 (void)  { while(1) {} }
__WEAK void PendSV_Handler              (void)  { while(1) {} }
#endif

// Cortex-M3 core handlers
#if defined(__MM3N1) || defined(__MM3O1) || defined(__MM3U1)
__WEAK void NMI_Handler                 (void)  { while(1) {} }
__WEAK void HardFault_Handler           (void)  { while(1) {} }
__WEAK void MemManage_Handler           (void)  { while(1) {} }
__WEAK void BusFault_Handler            (void)  { while(1) {} }
__WEAK void UsageFault_Handler          (void)  { while(1) {} }
__WEAK void SVC_Handler                 (void)  { while(1) {} }
__WEAK void DebugMon_Handler            (void)  { while(1) {} }
__WEAK void PendSV_Handler              (void)  { while(1) {} }
#endif

// Peripherals handlers
#if defined(__MM3N1)
__WEAK void WDG_IRQHandler              (void)  { while(1) {} }
__WEAK void PVD_IRQHandler              (void)  { while(1) {} }
__WEAK void TAMPER_IRQHandler           (void)  { while(1) {} }
__WEAK void RTC_IRQHandler              (void)  { while(1) {} }
__WEAK void FLASH_IRQHandler            (void)  { while(1) {} }
__WEAK void RCC_IRQHandler              (void)  { while(1) {} }
__WEAK void EXTI0_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI1_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI2_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI3_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI4_IRQHandler            (void)  { while(1) {} }
__WEAK void DMA1_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel2_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel3_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel4_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel5_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel6_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel7_IRQHandler    (void)  { while(1) {} }
__WEAK void ADC1_2_IRQHandler           (void)  { while(1) {} }
__WEAK void USB_HP_CAN1_TX_IRQHandler   (void)  { while(1) {} }
__WEAK void CAN1_RX1_IRQHandler         (void)  { while(1) {} }
__WEAK void EXTI9_5_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM1_BRK_IRQHandler         (void)  { while(1) {} }
__WEAK void TIM1_UP_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM1_TRG_COM_IRQHandler     (void)  { while(1) {} }
__WEAK void TIM1_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM2_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM3_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM4_IRQHandler             (void)  { while(1) {} }
__WEAK void I2C1_EV_IRQHandler          (void)  { while(1) {} }
__WEAK void I2C2_EV_IRQHandler          (void)  { while(1) {} }
__WEAK void SPI1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI2_IRQHandler             (void)  { while(1) {} }
__WEAK void UART1_IRQHandler            (void)  { while(1) {} }
__WEAK void UART2_IRQHandler            (void)  { while(1) {} }
__WEAK void UART3_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI15_10_IRQHandler        (void)  { while(1) {} }
__WEAK void RTCAlarm_IRQHandler         (void)  { while(1) {} }
__WEAK void USBWakeUp_IRQHandler        (void)  { while(1) {} }
__WEAK void AES_IRQHandler              (void)  { while(1) {} }
#endif

#if defined(__MM0N1)
__WEAK void WDG_IRQHandler              (void)  { while(1) {} }
__WEAK void PVD_IRQHandler              (void)  { while(1) {} }
__WEAK void FLASH_IRQHandler            (void)  { while(1) {} }
__WEAK void RCC_CRS_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI0_1_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI2_3_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI4_15_IRQHandler         (void)  { while(1) {} }
__WEAK void DMA1_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel2_3_IRQHandler  (void)  { while(1) {} }
__WEAK void DMA1_Channel4_5_IRQHandler  (void)  { while(1) {} }
__WEAK void ADC1_COMP_IRQHandler        (void)  { while(1) {} }
__WEAK void TIM1_BRK_UP_TRG_COM_IRQHandler(void)  { while(1) {} }
__WEAK void TIM1_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM2_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM3_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM14_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM16_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM17_IRQHandler            (void)  { while(1) {} }
__WEAK void I2C1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI2_IRQHandler             (void)  { while(1) {} }
__WEAK void UART1_IRQHandler            (void)  { while(1) {} }
__WEAK void UART2_IRQHandler            (void)  { while(1) {} }
__WEAK void AES_IRQHandler              (void)  { while(1) {} }
__WEAK void CAN_IRQHandler              (void)  { while(1) {} }
__WEAK void USB_IRQHandler              (void)  { while(1) {} }
#endif

#if defined(__MM3O1)
__WEAK void WDG_IRQHandler              (void)  { while(1) {} }
__WEAK void PVD_IRQHandler              (void)  { while(1) {} }
__WEAK void TAMPER_IRQHandler           (void)  { while(1) {} }
__WEAK void RTC_IRQHandler              (void)  { while(1) {} }
__WEAK void FLASH_IRQHandler            (void)  { while(1) {} }
__WEAK void RCC_CRS_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI0_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI1_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI2_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI3_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI4_IRQHandler            (void)  { while(1) {} }
__WEAK void DMA1_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel2_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel3_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel4_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel5_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel6_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel7_IRQHandler    (void)  { while(1) {} }
__WEAK void ADC1_IRQHandler             (void)  { while(1) {} }
__WEAK void FlashCache_IRQHandler       (void)  { while(1) {} }
__WEAK void CAN1_RX_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI9_5_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM1_BRK_IRQHandler         (void)  { while(1) {} }
__WEAK void TIM1_UP_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM1_TRG_COM_IRQHandler     (void)  { while(1) {} }
__WEAK void TIM1_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM2_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM3_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM4_IRQHandler             (void)  { while(1) {} }
__WEAK void I2C1_IRQHandler             (void)  { while(1) {} }
__WEAK void I2C2_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI2_IRQHandler             (void)  { while(1) {} }
__WEAK void UART1_IRQHandler            (void)  { while(1) {} }
__WEAK void UART2_IRQHandler            (void)  { while(1) {} }
__WEAK void UART3_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI15_10_IRQHandler        (void)  { while(1) {} }
__WEAK void RTCAlarm_IRQHandler         (void)  { while(1) {} }
__WEAK void USB_WKUP_IRQHandler         (void)  { while(1) {} }
__WEAK void TIM8_BRK_IRQHandler         (void)  { while(1) {} }
__WEAK void TIM8_UP_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM8_TRG_COM_IRQHandler     (void)  { while(1) {} }
__WEAK void TIM8_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void SDIO_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM5_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI3_IRQHandler             (void)  { while(1) {} }
__WEAK void UART4_IRQHandler            (void)  { while(1) {} }
__WEAK void UART5_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM6_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM7_IRQHandler             (void)  { while(1) {} }
__WEAK void DMA2_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA2_Channel2_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA2_Channel3_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA2_Channel4_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA2_Channel5_IRQHandler    (void)  { while(1) {} }
__WEAK void ETH_IRQHandler              (void)  { while(1) {} }
__WEAK void COMP1_2_IRQHandler          (void)  { while(1) {} }
__WEAK void USB_OTG_FS_IRQHandler       (void)  { while(1) {} }
__WEAK void UART6_IRQHandler            (void)  { while(1) {} }
__WEAK void AES_IRQHandler              (void)  { while(1) {} }
__WEAK void TRNG_IRQHandler             (void)  { while(1) {} }
__WEAK void UART7_IRQHandler            (void)  { while(1) {} }
__WEAK void UART8_IRQHandler            (void)  { while(1) {} }
#endif

#if defined(__MM0P1)
__WEAK void WDG_IRQHandler              (void)  { while(1) {} }
__WEAK void PVD_IRQHandler              (void)  { while(1) {} }
__WEAK void PWM_IRQHandler              (void)  { while(1) {} }
__WEAK void FLASH_IRQHandler            (void)  { while(1) {} }
__WEAK void RCC_IRQHandler              (void)  { while(1) {} }
__WEAK void EXTI0_1_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI2_3_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI4_15_IRQHandler         (void)  { while(1) {} }
__WEAK void HWDIV_IRQHandler            (void)  { while(1) {} }
__WEAK void DMA1_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel2_3_IRQHandler  (void)  { while(1) {} }
__WEAK void DMA1_Channel4_5_IRQHandler  (void)  { while(1) {} }
__WEAK void ADC1_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM1_BRK_UP_TRG_COM_IRQHandler(void)  { while(1) {} }
__WEAK void TIM1_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM2_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM3_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM8_BRK_UP_TRG_COM_IRQHandler(void)  { while(1) {} }
__WEAK void TIM8_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM14_IRQHandler            (void)  { while(1) {} }
__WEAK void ADC2_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM16_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM17_IRQHandler            (void)  { while(1) {} }
__WEAK void I2C1_IRQHandler             (void)  { while(1) {} }
__WEAK void COMP_1_2_3_4_5_IRQHandler   (void)  { while(1) {} }
__WEAK void SPI1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI2_IRQHandler             (void)  { while(1) {} }
__WEAK void UART1_IRQHandler            (void)  { while(1) {} }
__WEAK void UART2_IRQHandler            (void)  { while(1) {} }
__WEAK void Cache_IRQHandler            (void)  { while(1) {} }
#endif

// Peripherals handlers
#if defined(__MM0Q1)
__WEAK void WDG_IRQHandler              (void)  { while(1) {} }
__WEAK void PVD_IRQHandler              (void)  { while(1) {} }
__WEAK void PWM_IRQHandler              (void)  { while(1) {} }
__WEAK void FLASH_IRQHandler            (void)  { while(1) {} }
__WEAK void RCC_IRQHandler              (void)  { while(1) {} }
__WEAK void EXTI0_1_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI2_3_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI4_15_IRQHandler         (void)  { while(1) {} }
__WEAK void HWDIV_IRQHandler            (void)  { while(1) {} }
__WEAK void DMA1_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel2_3_IRQHandler  (void)  { while(1) {} }
__WEAK void DMA1_Channel4_5_IRQHandler  (void)  { while(1) {} }
__WEAK void ADC_COMP_IRQHandler         (void)  { while(1) {} }
__WEAK void TIM1_BRK_UP_TRG_COM_IRQHandler(void)  { while(1) {} }
__WEAK void TIM1_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM2_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM3_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM14_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM16_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM17_IRQHandler            (void)  { while(1) {} }
__WEAK void I2C1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI2_IRQHandler             (void)  { while(1) {} }
__WEAK void UART1_IRQHandler            (void)  { while(1) {} }
__WEAK void UART2_IRQHandler            (void)  { while(1) {} }
#endif

#if defined(__MM0S1)
__WEAK void WDG_IRQHandler              (void)  { while(1) {} }
__WEAK void PVD_IRQHandler              (void)  { while(1) {} }
__WEAK void RTC_BKP_IRQHandler          (void)  { while(1) {} }
__WEAK void FLASH_IRQHandler            (void)  { while(1) {} }
__WEAK void RCC_CRS_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI0_1_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI2_3_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI4_15_IRQHandler         (void)  { while(1) {} }
__WEAK void HWDIV_IRQHandler            (void)  { while(1) {} }
__WEAK void DMA1_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel2_3_IRQHandler  (void)  { while(1) {} }
__WEAK void DMA1_Channel4_5_IRQHandler  (void)  { while(1) {} }
__WEAK void ADC1_COMP_IRQHandler        (void)  { while(1) {} }
__WEAK void TIM1_BRK_UP_TRG_COM_IRQHandler(void)  { while(1) {} }
__WEAK void TIM1_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM2_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM3_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM14_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM16_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM17_IRQHandler            (void)  { while(1) {} }
__WEAK void I2C1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI2_IRQHandler             (void)  { while(1) {} }
__WEAK void UART1_IRQHandler            (void)  { while(1) {} }
__WEAK void UART2_IRQHandler            (void)  { while(1) {} }
__WEAK void CSM_IRQHandler              (void)  { while(1) {} }
__WEAK void CAN_IRQHandler              (void)  { while(1) {} }
__WEAK void USB_IRQHandler              (void)  { while(1) {} }
#endif

#if defined(__MM0T1)
__WEAK void WDG_IRQHandler              (void)  { while(1) {} }
__WEAK void PVD_IRQHandler              (void)  { while(1) {} }
__WEAK void FLASH_IRQHandler            (void)  { while(1) {} }
__WEAK void RCC_IRQHandler              (void)  { while(1) {} }
__WEAK void EXTI0_1_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI2_3_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI4_15_IRQHandler         (void)  { while(1) {} }
__WEAK void ADC1_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM1_BRK_UP_TRG_COM_IRQHandler(void)  { while(1) {} }
__WEAK void TIM1_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM3_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM14_IRQHandler            (void)  { while(1) {} }
__WEAK void I2C1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI1_IRQHandler             (void)  { while(1) {} }
__WEAK void UART1_IRQHandler            (void)  { while(1) {} }
__WEAK void UART2_IRQHandler            (void)  { while(1) {} }
#endif

#if defined(__MM3U1)
__WEAK void WDG_IRQHandler              (void)  { while(1) {} }
__WEAK void PVD_IRQHandler              (void)  { while(1) {} }
__WEAK void TAMPER_IRQHandler           (void)  { while(1) {} }
__WEAK void RTC_IRQHandler              (void)  { while(1) {} }
__WEAK void FLASH_IRQHandler            (void)  { while(1) {} }
__WEAK void RCC_CRS_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI0_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI1_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI2_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI3_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI4_IRQHandler            (void)  { while(1) {} }
__WEAK void DMA1_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel2_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel3_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel4_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel5_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel6_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA1_Channel7_IRQHandler    (void)  { while(1) {} }
__WEAK void ADC1_2_IRQHandler           (void)  { while(1) {} }
__WEAK void FLASH_CACHE_IRQHandler      (void)  { while(1) {} }
__WEAK void CAN1_RX_IRQHandler          (void)  { while(1) {} }
__WEAK void EXTI9_5_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM1_BRK_IRQHandler         (void)  { while(1) {} }
__WEAK void TIM1_UP_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM1_TRG_COM_IRQHandler     (void)  { while(1) {} }
__WEAK void TIM1_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM2_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM3_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM4_IRQHandler             (void)  { while(1) {} }
__WEAK void I2C1_IRQHandler             (void)  { while(1) {} }
__WEAK void I2C2_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI1_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI2_IRQHandler             (void)  { while(1) {} }
__WEAK void UART1_IRQHandler            (void)  { while(1) {} }
__WEAK void UART2_IRQHandler            (void)  { while(1) {} }
__WEAK void UART3_IRQHandler            (void)  { while(1) {} }
__WEAK void EXTI15_10_IRQHandler        (void)  { while(1) {} }
__WEAK void RTC_ALARM_IRQHandler        (void)  { while(1) {} }
__WEAK void USB_WKUP_IRQHandler         (void)  { while(1) {} }
__WEAK void TIM8_BRK_IRQHandler         (void)  { while(1) {} }
__WEAK void TIM8_UP_IRQHandler          (void)  { while(1) {} }
__WEAK void TIM8_TRG_COM_IRQHandler     (void)  { while(1) {} }
__WEAK void TIM8_CC_IRQHandler          (void)  { while(1) {} }
__WEAK void ADC3_IRQHandler             (void)  { while(1) {} }
__WEAK void SDIO_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM5_IRQHandler             (void)  { while(1) {} }
__WEAK void SPI3_IRQHandler             (void)  { while(1) {} }
__WEAK void UART4_IRQHandler            (void)  { while(1) {} }
__WEAK void UART5_IRQHandler            (void)  { while(1) {} }
__WEAK void TIM6_IRQHandler             (void)  { while(1) {} }
__WEAK void TIM7_IRQHandler             (void)  { while(1) {} }
__WEAK void DMA2_Channel1_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA2_Channel2_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA2_Channel3_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA2_Channel4_IRQHandler    (void)  { while(1) {} }
__WEAK void DMA2_Channel5_IRQHandler    (void)  { while(1) {} }
__WEAK void ETH_IRQHandler              (void)  { while(1) {} }
__WEAK void COMP1_2_IRQHandler          (void)  { while(1) {} }
__WEAK void USB_OTG_FS_IRQHandler       (void)  { while(1) {} }
__WEAK void UART6_IRQHandler            (void)  { while(1) {} }
__WEAK void UART7_IRQHandler            (void)  { while(1) {} }
__WEAK void UART8_IRQHandler            (void)  { while(1) {} }
#endif

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                              DECLARE HANDLERS                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
// Cortex-M0 core handlers
#if defined(__MM0N1) || defined(__MM0P1) || defined(__MM0Q1) || defined(__MM0S1) || defined(__MM0T1)
void Reset_Handler                      (void);
void NMI_Handler                        (void);
void HardFault_Handler                  (void);
void SVC_Handler                        (void);
void PendSV_Handler                     (void);
void SysTick_Handler                    (void);
#endif

// Cortex-M3 core handlers
#if defined(__MM3N1) || defined(__MM3O1) || defined(__MM3U1)
void Reset_Handler                      (void);
void NMI_Handler                        (void);
void HardFault_Handler                  (void);
void MemManage_Handler                  (void);
void BusFault_Handler                   (void);
void UsageFault_Handler                 (void);
void SVC_Handler                        (void);
void DebugMon_Handler                   (void);
void PendSV_Handler                     (void);
void SysTick_Handler                    (void);
#endif

// Peripherals handlers
#if defined(__MM3N1)
void WDG_IRQHandler                     (void);                                 ///< Window Watchdog
void PVD_IRQHandler                     (void);                                 ///< PVD through EXTI Line detect
void TAMPER_IRQHandler                  (void);                                 ///< Tamper
void RTC_IRQHandler                     (void);                                 ///< RTC
void FLASH_IRQHandler                   (void);                                 ///< Flash
void RCC_IRQHandler                     (void);                                 ///< RCC
void EXTI0_IRQHandler                   (void);                                 ///< EXTI Line 0
void EXTI1_IRQHandler                   (void);                                 ///< EXTI Line 1
void EXTI2_IRQHandler                   (void);                                 ///< EXTI Line 2
void EXTI3_IRQHandler                   (void);                                 ///< EXTI Line 3
void EXTI4_IRQHandler                   (void);                                 ///< EXTI Line 4
void DMA1_Channel1_IRQHandler           (void);                                 ///< DMA1 Channel 1
void DMA1_Channel2_IRQHandler           (void);                                 ///< DMA1 Channel 2
void DMA1_Channel3_IRQHandler           (void);                                 ///< DMA1 Channel 3
void DMA1_Channel4_IRQHandler           (void);                                 ///< DMA1 Channel 4
void DMA1_Channel5_IRQHandler           (void);                                 ///< DMA1 Channel 5
void DMA1_Channel6_IRQHandler           (void);                                 ///< DMA1 Channel 6
void DMA1_Channel7_IRQHandler           (void);                                 ///< DMA1 Channel 7
void ADC1_2_IRQHandler                  (void);                                 ///< ADC1 & ADC2
void USB_HP_CAN1_TX_IRQHandler          (void);                                 ///< USB High Priority or CAN1 TX
void CAN1_RX1_IRQHandler                (void);                                 ///< CAN1 RX1
void EXTI9_5_IRQHandler                 (void);                                 ///< EXTI Line 9..5
void TIM1_BRK_IRQHandler                (void);                                 ///< TIM1 Break
void TIM1_UP_IRQHandler                 (void);                                 ///< TIM1 Update
void TIM1_TRG_COM_IRQHandler            (void);                                 ///< TIM1 Trigger and Commutation
void TIM1_CC_IRQHandler                 (void);                                 ///< TIM1 Capture Compare
void TIM2_IRQHandler                    (void);                                 ///< TIM2
void TIM3_IRQHandler                    (void);                                 ///< TIM3
void TIM4_IRQHandler                    (void);                                 ///< TIM4
void I2C1_EV_IRQHandler                 (void);                                 ///< I2C1 Event
void I2C2_EV_IRQHandler                 (void);                                 ///< I2C2 Event
void SPI1_IRQHandler                    (void);                                 ///< SPI1
void SPI2_IRQHandler                    (void);                                 ///< SPI2
void UART1_IRQHandler                   (void);                                 ///< UART1
void UART2_IRQHandler                   (void);                                 ///< UART2
void UART3_IRQHandler                   (void);                                 ///< UART3
void EXTI15_10_IRQHandler               (void);                                 ///< EXTI Line 15..10
void RTCAlarm_IRQHandler                (void);                                 ///< RTC Alarm through EXTI Line
void USBWakeUp_IRQHandler               (void);                                 ///< USB Wakeup from suspend
void AES_IRQHandler                     (void);                                 ///< USB Wakeup from suspend
#endif

#if defined(__MM0N1)
void WDG_IRQHandler                     (void);                                 ///< Window Watchdog
void PVD_IRQHandler                     (void);                                 ///< PVD through EXTI Line detect
void FLASH_IRQHandler                   (void);                                 ///< FLASH
void RCC_CRS_IRQHandler                 (void);                                 ///< RCC & CRS
void EXTI0_1_IRQHandler                 (void);                                 ///< EXTI Line 0 and 1
void EXTI2_3_IRQHandler                 (void);                                 ///< EXTI Line 2 and 3
void EXTI4_15_IRQHandler                (void);                                 ///< EXTI Line 4 to 15
void DMA1_Channel1_IRQHandler           (void);                                 ///< DMA1 Channel 1
void DMA1_Channel2_3_IRQHandler         (void);                                 ///< DMA1 Channel 2 and Channel 3
void DMA1_Channel4_5_IRQHandler         (void);                                 ///< DMA1 Channel 4 and Channel 5
void ADC1_COMP_IRQHandler               (void);                                 ///< ADC1 & COMP
void TIM1_BRK_UP_TRG_COM_IRQHandler     (void);                                 ///< TIM1 Break, Update, Trigger and Commutation
void TIM1_CC_IRQHandler                 (void);                                 ///< TIM1 Capture Compare
void TIM2_IRQHandler                    (void);                                 ///< TIM2
void TIM3_IRQHandler                    (void);                                 ///< TIM3
void TIM14_IRQHandler                   (void);                                 ///< TIM14
void TIM16_IRQHandler                   (void);                                 ///< TIM16
void TIM17_IRQHandler                   (void);                                 ///< TIM17
void I2C1_IRQHandler                    (void);                                 ///< I2C1
void SPI1_IRQHandler                    (void);                                 ///< SPI1
void SPI2_IRQHandler                    (void);                                 ///< SPI2
void UART1_IRQHandler                   (void);                                 ///< UART1
void UART2_IRQHandler                   (void);                                 ///< UART2
void AES_IRQHandler                     (void);                                 ///< AES
void CAN_IRQHandler                     (void);                                 ///< CAN
void USB_IRQHandler                     (void);                                 ///< USB
#endif

#if defined(__MM3O1)
void WDG_IRQHandler                     (void);                                 ///< Window WatchDog Interrupt
void PVD_IRQHandler                     (void);                                 ///< PVD through EXTI Line detection Interrupt
void TAMPER_IRQHandler                  (void);                                 ///< Tamper Interrupt
void RTC_IRQHandler                     (void);                                 ///< RTC global Interrupt
void FLASH_IRQHandler                   (void);                                 ///< FLASH global Interrupt
void RCC_CRS_IRQHandler                 (void);                                 ///< RCC global Interrupt
void EXTI0_IRQHandler                   (void);                                 ///< EXTI Line0 Interrupt
void EXTI1_IRQHandler                   (void);                                 ///< EXTI Line1 Interrupt
void EXTI2_IRQHandler                   (void);                                 ///< EXTI Line2 Interrupt
void EXTI3_IRQHandler                   (void);                                 ///< EXTI Line3 Interrupt
void EXTI4_IRQHandler                   (void);                                 ///< EXTI Line4 Interrupt
void DMA1_Channel1_IRQHandler           (void);                                 ///< DMA1 Channel 1 global Interrupt
void DMA1_Channel2_IRQHandler           (void);                                 ///< DMA1 Channel 2 global Interrupt
void DMA1_Channel3_IRQHandler           (void);                                 ///< DMA1 Channel 3 global Interrupt
void DMA1_Channel4_IRQHandler           (void);                                 ///< DMA1 Channel 4 global Interrupt
void DMA1_Channel5_IRQHandler           (void);                                 ///< DMA1 Channel 5 global Interrupt
void DMA1_Channel6_IRQHandler           (void);                                 ///< DMA1 Channel 6 global Interrupt
void DMA1_Channel7_IRQHandler           (void);                                 ///< DMA1 Channel 7 global Interrupt
void ADC1_IRQHandler                    (void);                                 ///< ADC1 et ADC2 global Interrupt
void CAN1_RX_IRQHandler                 (void);                                 ///< CAN1 RX1 Interrupt
void EXTI9_5_IRQHandler                 (void);                                 ///< External Line[9:5] Interrupts
void TIM1_BRK_IRQHandler                (void);                                 ///< TIM1 Break Interrupt
void TIM1_UP_IRQHandler                 (void);                                 ///< TIM1 Update Interrupt
void TIM1_TRG_COM_IRQHandler            (void);                                 ///< TIM1 Trigger and Commutation Interrupt
void TIM1_CC_IRQHandler                 (void);                                 ///< TIM1 Capture Compare Interrupt
void TIM2_IRQHandler                    (void);                                 ///< TIM2 global Interrupt
void TIM3_IRQHandler                    (void);                                 ///< TIM3 global Interrupt
void TIM4_IRQHandler                    (void);                                 ///< TIM4 global Interrupt
void I2C1_IRQHandler                    (void);                                 ///< I2C1 Event Interrupt
void I2C2_IRQHandler                    (void);                                 ///< I2C2 Event Interrupt
void SPI1_IRQHandler                    (void);                                 ///< SPI1 global Interrupt
void SPI2_IRQHandler                    (void);                                 ///< SPI2 global Interrupt
void UART1_IRQHandler                   (void);                                 ///< UART1 global Interrupt
void UART2_IRQHandler                   (void);                                 ///< UART2 global Interrupt
void UART3_IRQHandler                   (void);                                 ///< UART3 global Interrupt
void EXTI15_10_IRQHandler               (void);                                 ///< External Line[15:10] Interrupts
void RTCAlarm_IRQHandler                (void);                                 ///< RTC Alarm through EXTI Line Interrupt
void USB_WKUP_IRQHandler                (void);                                 ///< USB WakeUp from suspend through EXTI Line Interrupt
void TIM8_BRK_IRQHandler                (void);                                 ///< TIM8 Break Interrupt
void TIM8_UP_IRQHandler                 (void);                                 ///< TIM8 Update Interrupt
void TIM8_TRG_COM_IRQHandler            (void);                                 ///< TIM8 Trigger and Commutation Interrupt
void TIM8_CC_IRQHandler                 (void);                                 ///< TIM8 Capture Compare Interrupt
void SDIO_IRQHandler                    (void);                                 ///< SDIO
void TIM5_IRQHandler                    (void);                                 ///< TIM5
void SPI3_IRQHandler                    (void);                                 ///< SPI3
void UART4_IRQHandler                   (void);                                 ///< UART4
void UART5_IRQHandler                   (void);                                 ///< UART5
void TIM6_IRQHandler                    (void);                                 ///< TIM6
void TIM7_IRQHandler                    (void);                                 ///< TIM7
void DMA2_Channel1_IRQHandler           (void);                                 ///< DMA2 Channel 1
void DMA2_Channel2_IRQHandler           (void);                                 ///< DMA2 Channel 2
void DMA2_Channel3_IRQHandler           (void);                                 ///< DMA2 Channel 3
void DMA2_Channel4_IRQHandler           (void);                                 ///< DMA2 Channel 4
void DMA2_Channel5_IRQHandler           (void);                                 ///< DMA2 Channel 5
void ETH_IRQHandler                     (void);                                 ///< Ethernet
void COMP1_2_IRQHandler                 (void);                                 ///< COMP1,COMP2
void USB_OTG_FS_IRQHandler              (void);                                 ///< USB_FS
void UART6_IRQHandler                   (void);                                 ///< UART6
void AES_IRQHandler                     (void);                                 ///< AES
void TRNG_IRQHandler                    (void);                                 ///< TRNG
void UART7_IRQHandler                   (void);                                 ///< UART7
void UART8_IRQHandler                   (void);                                 ///< UART8
#endif

#if defined(__MM0P1)
void WDG_IRQHandler                     (void);                                 ///< Window Watchdog and Independent Watchdog
void PVD_IRQHandler                     (void);                                 ///< PVD through EXTI Line detect
void PWM_IRQHandler                     (void);                                 ///< PWM Control interrupt
void FLASH_IRQHandler                   (void);                                 ///< FLASH
void RCC_IRQHandler                     (void);                                 ///< RCC  interrupt
void EXTI0_1_IRQHandler                 (void);                                 ///< EXTI Line 0 and 1
void EXTI2_3_IRQHandler                 (void);                                 ///< EXTI Line 2 and 3
void EXTI4_15_IRQHandler                (void);                                 ///< EXTI Line 4 to 15
void HWDIV_IRQHandler                   (void);                                 ///< HWDIV
void DMA1_Channel1_IRQHandler           (void);                                 ///< DMA1 Channel 1
void DMA1_Channel2_3_IRQHandler         (void);                                 ///< DMA1 Channel 2 and Channel 3
void DMA1_Channel4_5_IRQHandler         (void);                                 ///< DMA1 Channel 4 and Channel 5
void ADC1_IRQHandler                    (void);                                 ///< ADC1 interrupt
void TIM1_BRK_UP_TRG_COM_IRQHandler     (void);                                 ///< TIM1 Break, Update, Trigger and Commutation
void TIM1_CC_IRQHandler                 (void);                                 ///< TIM1 Capture Compare
void TIM2_IRQHandler                    (void);                                 ///< TIM2
void TIM3_IRQHandler                    (void);                                 ///< TIM3
void TIM8_BRK_UP_TRG_COM_IRQHandler     (void);                                 ///< TIM8 Break, Update, Trigger and Commutation
void TIM8_CC_IRQHandler                 (void);                                 ///< TIM8 Capture Compare
void TIM14_IRQHandler                   (void);                                 ///< TIM14
void ADC2_IRQHandler                    (void);                                 ///< ADC2
void TIM16_IRQHandler                   (void);                                 ///< TIM16
void TIM17_IRQHandler                   (void);                                 ///< TIM17
void I2C1_IRQHandler                    (void);                                 ///< I2C1
void COMP_1_2_3_4_5_IRQHandler          (void);                                 ///< COMP
void SPI1_IRQHandler                    (void);                                 ///< SPI1
void SPI2_IRQHandler                    (void);                                 ///< SPI2
void UART1_IRQHandler                   (void);                                 ///< UART1
void UART2_IRQHandler                   (void);                                 ///< UART2
void FlashCache_IRQHandler              (void);                                 ///< Cache
#endif

// Peripherals handlers
#if defined(__MM0Q1)
void WDG_IRQHandler                     (void);
void PVD_IRQHandler                     (void);
void PWM_IRQHandler                     (void);
void FLASH_IRQHandler                   (void);
void RCC_IRQHandler                     (void);
void EXTI0_1_IRQHandler                 (void);
void EXTI2_3_IRQHandler                 (void);
void EXTI4_15_IRQHandler                (void);
void HWDIV_IRQHandler                   (void);
void DMA1_Channel1_IRQHandler           (void);
void DMA1_Channel2_3_IRQHandler         (void);
void DMA1_Channel4_5_IRQHandler         (void);
void ADC_COMP_IRQHandler                (void);
void TIM1_BRK_UP_TRG_COM_IRQHandler     (void);
void TIM1_CC_IRQHandler                 (void);
void TIM2_IRQHandler                    (void);
void TIM3_IRQHandler                    (void);
void TIM14_IRQHandler                   (void);
void TIM16_IRQHandler                   (void);
void TIM17_IRQHandler                   (void);
void I2C1_IRQHandler                    (void);
void SPI1_IRQHandler                    (void);
void SPI2_IRQHandler                    (void);
void UART1_IRQHandler                   (void);
void UART2_IRQHandler                   (void);
#endif

#if defined(__MM0S1)
void WDG_IRQHandler                     (void);                                 ///< Window Watchdog
void PVD_IRQHandler                     (void);                                 ///< PVD through EXTI Line detect
void RTC_BKP_IRQHandler                 (void);                                 ///< RTC & BKP Handler
void FLASH_IRQHandler                   (void);                                 ///< FLASH
void RCC_CRS_IRQHandler                 (void);                                 ///< RCC & CRS
void EXTI0_1_IRQHandler                 (void);                                 ///< EXTI Line 0 and 1
void EXTI2_3_IRQHandler                 (void);                                 ///< EXTI Line 2 and 3
void EXTI4_15_IRQHandler                (void);                                 ///< EXTI Line 4 to 15
void HWDIV_IRQHandler                   (void);                                 ///< HWDIV
void DMA1_Channel1_IRQHandler           (void);                                 ///< DMA1 Channel 1
void DMA1_Channel2_3_IRQHandler         (void);                                 ///< DMA1 Channel 2 and Channel 3
void DMA1_Channel4_5_IRQHandler         (void);                                 ///< DMA1 Channel 4 and Channel 5
void ADC1_COMP_IRQHandler               (void);                                 ///< ADC1 & COMP
void TIM1_BRK_UP_TRG_COM_IRQHandler     (void);                                 ///< TIM1 Break, Update, Trigger and Commutation
void TIM1_CC_IRQHandler                 (void);                                 ///< TIM1 Capture Compare
void TIM2_IRQHandler                    (void);                                 ///< TIM2
void TIM3_IRQHandler                    (void);                                 ///< TIM3
void TIM14_IRQHandler                   (void);                                 ///< TIM14
void TIM16_IRQHandler                   (void);                                 ///< TIM16
void TIM17_IRQHandler                   (void);                                 ///< TIM17
void I2C1_IRQHandler                    (void);                                 ///< I2C1
void SPI1_IRQHandler                    (void);                                 ///< SPI1
void SPI2_IRQHandler                    (void);                                 ///< SPI2
void UART1_IRQHandler                   (void);                                 ///< UART1
void UART2_IRQHandler                   (void);                                 ///< UART2
void CAN_IRQHandler                     (void);                                 ///< CAN
void USB_IRQHandler                     (void);                                 ///< USB
#endif

#if defined(__MM0T1)
void PVD_IRQHandler                     (void);                                 ///< PVD through EXTI Line detect
void FLASH_IRQHandler                   (void);                                 ///< FLASH
void RCC_IRQHandler                     (void);                                 ///< RCC & CRS
void EXTI0_1_IRQHandler                 (void);                                 ///< EXTI Line 0 and 1
void EXTI2_3_IRQHandler                 (void);                                 ///< EXTI Line 2 and 3
void EXTI4_15_IRQHandler                (void);                                 ///< EXTI Line 4 to 15
void ADC1_IRQHandler                    (void);                                 ///< ADC1 & COMP
void TIM1_BRK_UP_TRG_COM_IRQHandler     (void);                                 ///< TIM1 Break, Update, Trigger and Commutation
void TIM1_CC_IRQHandler                 (void);                                 ///< TIM1 Capture Compare
void TIM3_IRQHandler                    (void);                                 ///< TIM3
void TIM14_IRQHandler                   (void);                                 ///< TIM14
void I2C1_IRQHandler                    (void);                                 ///< I2C1
void SPI1_IRQHandler                    (void);                                 ///< SPI1
void UART1_IRQHandler                   (void);                                 ///< UART1
void UART2_IRQHandler                   (void);                                 ///< UART2
#endif

#if defined(__MM3U1)
void WDG_IRQHandler                     (void);                                 ///< Window WatchDog Interrupt
void PVD_IRQHandler                     (void);                                 ///< PVD through EXTI Line detection Interrupt
void TAMPER_IRQHandler                  (void);                                 ///< Tamper Interrupt
void RTC_IRQHandler                     (void);                                 ///< RTC global Interrupt
void FLASH_IRQHandler                   (void);                                 ///< FLASH global Interrupt
void RCC_CRS_IRQHandler                 (void);                                 ///< RCC and CRS global Interrupt
void EXTI0_IRQHandler                   (void);                                 ///< EXTI Line0 Interrupt
void EXTI1_IRQHandler                   (void);                                 ///< EXTI Line1 Interrupt
void EXTI2_IRQHandler                   (void);                                 ///< EXTI Line2 Interrupt
void EXTI3_IRQHandler                   (void);                                 ///< EXTI Line3 Interrupt
void EXTI4_IRQHandler                   (void);                                 ///< EXTI Line4 Interrupt
void DMA1_Channel1_IRQHandler           (void);                                 ///< DMA1 Channel 1 global Interrupt
void DMA1_Channel2_IRQHandler           (void);                                 ///< DMA1 Channel 2 global Interrupt
void DMA1_Channel3_IRQHandler           (void);                                 ///< DMA1 Channel 3 global Interrupt
void DMA1_Channel4_IRQHandler           (void);                                 ///< DMA1 Channel 4 global Interrupt
void DMA1_Channel5_IRQHandler           (void);                                 ///< DMA1 Channel 5 global Interrupt
void DMA1_Channel6_IRQHandler           (void);                                 ///< DMA1 Channel 6 global Interrupt
void DMA1_Channel7_IRQHandler           (void);                                 ///< DMA1 Channel 7 global Interrupt
void ADC1_2_IRQHandler                  (void);                                 ///< ADC1 et ADC2 global Interrupt
void FLASH_CACHE_IRQHandler             (void);                                 ///< Flash Cache global Interrupt
void CAN1_RX_IRQHandler                 (void);                                 ///< CAN1 RX1 Interrupt
void EXTI9_5_IRQHandler                 (void);                                 ///< External Line[9:5] Interrupts
void TIM1_BRK_IRQHandler                (void);                                 ///< TIM1 Break Interrupt
void TIM1_UP_IRQHandler                 (void);                                 ///< TIM1 Update Interrupt
void TIM1_TRG_COM_IRQHandler            (void);                                 ///< TIM1 Trigger and Commutation Interrupt
void TIM1_CC_IRQHandler                 (void);                                 ///< TIM1 Capture Compare Interrupt
void TIM2_IRQHandler                    (void);                                 ///< TIM2 global Interrupt
void TIM3_IRQHandler                    (void);                                 ///< TIM3 global Interrupt
void TIM4_IRQHandler                    (void);                                 ///< TIM4 global Interrupt
void I2C1_IRQHandler                    (void);                                 ///< I2C1 Event Interrupt
void I2C2_IRQHandler                    (void);                                 ///< I2C2 Event Interrupt
void SPI1_IRQHandler                    (void);                                 ///< SPI1 global Interrupt
void SPI2_IRQHandler                    (void);                                 ///< SPI2 global Interrupt
void UART1_IRQHandler                   (void);                                 ///< UART1 global Interrupt
void UART2_IRQHandler                   (void);                                 ///< UART2 global Interrupt
void UART3_IRQHandler                   (void);                                 ///< UART3 global Interrupt
void EXTI15_10_IRQHandler               (void);                                 ///< External Line[15:10] Interrupts
void RTC_ALARM_IRQHandler               (void);                                ///< RTC Alarm through EXTI Line Interrupt
void USB_WKUP_IRQHandler                (void);                                 ///< USB WakeUp from suspend through EXTI Line Interrupt
void TIM8_BRK_IRQHandler                (void);                                 ///< TIM8 Break Interrupt
void TIM8_UP_IRQHandler                 (void);                                 ///< TIM8 Update Interrupt
void TIM8_TRG_COM_IRQHandler            (void);                                 ///< TIM8 Trigger and Commutation Interrupt
void TIM8_CC_IRQHandler                 (void);                                 ///< TIM8 Capture Compare Interrupt
void ADC3_IRQHandler                    (void);                                 ///< ADC3 global Interrupt
void SDIO_IRQHandler                    (void);                                 ///< SDIO global Interrupt
void TIM5_IRQHandler                    (void);                                 ///< TIM5 global Interrupt
void SPI3_IRQHandler                    (void);                                 ///< SPI3 global Interrupt
void UART4_IRQHandler                   (void);                                 ///< UART4 global Interrupt
void UART5_IRQHandler                   (void);                                 ///< UART5 global Interrupt
void TIM6_IRQHandler                    (void);                                 ///< TIM6 global Interrupt
void TIM7_IRQHandler                    (void);                                 ///< TIM7 global Interrupt
void DMA2_Channel1_IRQHandler           (void);                                 ///< DMA2 Channel 1 global Interrupt
void DMA2_Channel2_IRQHandler           (void);                                 ///< DMA2 Channel 2 global Interrupt
void DMA2_Channel3_IRQHandler           (void);                                 ///< DMA2 Channel 3 global Interrupt
void DMA2_Channel4_IRQHandler           (void);                                 ///< DMA2 Channel 4 global Interrupt
void DMA2_Channel5_IRQHandler           (void);                                 ///< DMA2 Channel 5 global Interrupt
void ETH_IRQHandler                     (void);                                 ///< Ethernet global Interrupt
void COMP1_2_IRQHandler                 (void);                                 ///< COMP1 and COMP2 global Interrupt
void USB_OTG_FS_IRQHandler              (void);                                 ///< USB OTG FS global Interrupt
void UART6_IRQHandler                   (void);                                 ///< UART6 global Interrupt
void UART7_IRQHandler                   (void);                                 ///< UART7 global Interrupt
void UART8_IRQHandler                   (void);                                 ///< UART8 global Interrupt
#endif

////////////////////////////////////////////////////////////////////////////////
///
///                          CONSTRUCT VECTOR TABLE
///
////////////////////////////////////////////////////////////////////////////////
// Cortex-M0 core handlers
#if defined(__MM0N1) || defined(__MM0P1) || defined(__MM0Q1) || defined(__MM0S1) || defined(__MM0T1)
#define __CORTEX_M_CORE_HANDLERS__      { Reset_Handler },                      \
                                        { NMI_Handler },                        \
                                        { HardFault_Handler },                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { SVC_Handler },                        \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { PendSV_Handler },                     \
                                        { SysTick_Handler },
#endif

// Cortex-M3 core handlers
#if defined(__MM3N1) || defined(__MM3O1) || defined(__MM3U1)
#define __CORTEX_M_CORE_HANDLERS__      { Reset_Handler },                      \
                                        { NMI_Handler },                        \
                                        { HardFault_Handler },                  \
                                        { MemManage_Handler },                  \
                                        { BusFault_Handler },                   \
                                        { UsageFault_Handler },                 \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { SVC_Handler },                        \
                                        { DebugMon_Handler },                   \
                                        { 0 },                                  \
                                        { PendSV_Handler },                     \
                                        { SysTick_Handler },
#endif

// Peripherals handlers
#if defined(__MM3N1)
#define __MM32_IRQ_HANDLERS__           { WDG_IRQHandler },                     \
                                        { PVD_IRQHandler },                     \
                                        { TAMPER_IRQHandler },                  \
                                        { RTC_IRQHandler },                     \
                                        { FLASH_IRQHandler },                   \
                                        { RCC_IRQHandler },                     \
                                        { EXTI0_IRQHandler },                   \
                                        { EXTI1_IRQHandler },                   \
                                        { EXTI2_IRQHandler },                   \
                                        { EXTI3_IRQHandler },                   \
                                        { EXTI4_IRQHandler },                   \
                                        { DMA1_Channel1_IRQHandler },           \
                                        { DMA1_Channel2_IRQHandler },           \
                                        { DMA1_Channel3_IRQHandler },           \
                                        { DMA1_Channel4_IRQHandler },           \
                                        { DMA1_Channel5_IRQHandler },           \
                                        { DMA1_Channel6_IRQHandler },           \
                                        { DMA1_Channel7_IRQHandler },           \
                                        { ADC1_2_IRQHandler },                  \
                                        { USB_HP_CAN1_TX_IRQHandler },          \
                                        { 0 },                                  \
                                        { CAN1_RX1_IRQHandler },                \
                                        { 0 },                                  \
                                        { EXTI9_5_IRQHandler },                 \
                                        { TIM1_BRK_IRQHandler },                \
                                        { TIM1_UP_IRQHandler },                 \
                                        { TIM1_TRG_COM_IRQHandler },            \
                                        { TIM1_CC_IRQHandler },                 \
                                        { TIM2_IRQHandler },                    \
                                        { TIM3_IRQHandler },                    \
                                        { TIM4_IRQHandler },                    \
                                        { I2C1_EV_IRQHandler },                 \
                                        { 0 },                                  \
                                        { I2C2_EV_IRQHandler },                 \
                                        { 0 },                                  \
                                        { SPI1_IRQHandler },                    \
                                        { SPI2_IRQHandler },                    \
                                        { UART1_IRQHandler },                   \
                                        { UART2_IRQHandler },                   \
                                        { UART3_IRQHandler },                   \
                                        { EXTI15_10_IRQHandler },               \
                                        { RTCAlarm_IRQHandler },                \
                                        { USBWakeUp_IRQHandler },               \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { AES_IRQHandler }
#endif

#if defined(__MM0N1)
#define __MM32_IRQ_HANDLERS__           { WDG_IRQHandler },                     \
                                        { PVD_IRQHandler },                     \
                                        { 0 },                                  \
                                        { FLASH_IRQHandler },                   \
                                        { RCC_CRS_IRQHandler },                 \
                                        { EXTI0_1_IRQHandler },                 \
                                        { EXTI2_3_IRQHandler },                 \
                                        { EXTI4_15_IRQHandler },                \
                                        { 0 },                                  \
                                        { DMA1_Channel1_IRQHandler },           \
                                        { DMA1_Channel2_3_IRQHandler },         \
                                        { DMA1_Channel4_5_IRQHandler },         \
                                        { ADC1_COMP_IRQHandler },               \
                                        { TIM1_BRK_UP_TRG_COM_IRQHandler },     \
                                        { TIM1_CC_IRQHandler },                 \
                                        { TIM2_IRQHandler },                    \
                                        { TIM3_IRQHandler },                    \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { TIM14_IRQHandler },                   \
                                        { 0 },                                  \
                                        { TIM16_IRQHandler },                   \
                                        { TIM17_IRQHandler },                   \
                                        { I2C1_IRQHandler },                    \
                                        { 0 },                                  \
                                        { SPI1_IRQHandler },                    \
                                        { SPI2_IRQHandler },                    \
                                        { UART1_IRQHandler },                   \
                                        { UART2_IRQHandler },                   \
                                        { AES_IRQHandler },                     \
                                        { CAN_IRQHandler },                     \
                                        { USB_IRQHandler }
#endif

#if defined(__MM3O1)
#define __MM32_IRQ_HANDLERS__           { WDG_IRQHandler },                     \
                                        { PVD_IRQHandler },                     \
                                        { TAMPER_IRQHandler },                  \
                                        { RTC_IRQHandler },                     \
                                        { FLASH_IRQHandler },                   \
                                        { RCC_CRS_IRQHandler },                 \
                                        { EXTI0_IRQHandler },                   \
                                        { EXTI1_IRQHandler },                   \
                                        { EXTI2_IRQHandler },                   \
                                        { EXTI3_IRQHandler },                   \
                                        { EXTI4_IRQHandler },                   \
                                        { DMA1_Channel1_IRQHandler },           \
                                        { DMA1_Channel2_IRQHandler },           \
                                        { DMA1_Channel3_IRQHandler },           \
                                        { DMA1_Channel4_IRQHandler },           \
                                        { DMA1_Channel5_IRQHandler },           \
                                        { DMA1_Channel6_IRQHandler },           \
                                        { DMA1_Channel7_IRQHandler },           \
                                        { ADC1_IRQHandler },                    \
                                        { FlashCache_IRQHandler },              \
                                        { 0 },                                  \
                                        { CAN1_RX_IRQHandler },                 \
                                        { 0 },                                  \
                                        { EXTI9_5_IRQHandler },                 \
                                        { TIM1_BRK_IRQHandler },                \
                                        { TIM1_UP_IRQHandler },                 \
                                        { TIM1_TRG_COM_IRQHandler },            \
                                        { TIM1_CC_IRQHandler },                 \
                                        { TIM2_IRQHandler },                    \
                                        { TIM3_IRQHandler },                    \
                                        { TIM4_IRQHandler },                    \
                                        { I2C1_IRQHandler },                    \
                                        { 0 },                                  \
                                        { I2C2_IRQHandler },                    \
                                        { 0 },                                  \
                                        { SPI1_IRQHandler },                    \
                                        { SPI2_IRQHandler },                    \
                                        { UART1_IRQHandler },                   \
                                        { UART2_IRQHandler },                   \
                                        { UART3_IRQHandler },                   \
                                        { EXTI15_10_IRQHandler },               \
                                        { RTCAlarm_IRQHandler },                \
                                        { USB_WKUP_IRQHandler },                \
                                        { TIM8_BRK_IRQHandler },                \
                                        { TIM8_UP_IRQHandler },                 \
                                        { TIM8_TRG_COM_IRQHandler },            \
                                        { TIM8_CC_IRQHandler },                 \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { SDIO_IRQHandler },                    \
                                        { TIM5_IRQHandler },                    \
                                        { SPI3_IRQHandler },                    \
                                        { UART4_IRQHandler },                   \
                                        { UART5_IRQHandler },                   \
                                        { TIM6_IRQHandler },                    \
                                        { TIM7_IRQHandler },                    \
                                        { DMA2_Channel1_IRQHandler },           \
                                        { DMA2_Channel2_IRQHandler },           \
                                        { DMA2_Channel3_IRQHandler },           \
                                        { DMA2_Channel4_IRQHandler },           \
                                        { DMA2_Channel5_IRQHandler },           \
                                        { ETH_IRQHandler },                     \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { COMP1_2_IRQHandler },                 \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { USB_OTG_FS_IRQHandler },              \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { UART6_IRQHandler },                   \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { AES_IRQHandler },                     \
                                        { TRNG_IRQHandler },                    \
                                        { 0 },                                  \
                                        { UART7_IRQHandler },                   \
                                        { UART8_IRQHandler }
#endif

#if defined(__MM0P1)
#define __MM32_IRQ_HANDLERS__           { WDG_IRQHandler },                     \
                                        { PVD_IRQHandler },                     \
                                        { PWM_IRQHandler },                     \
                                        { FLASH_IRQHandler },                   \
                                        { RCC_IRQHandler },                     \
                                        { EXTI0_1_IRQHandler },                 \
                                        { EXTI2_3_IRQHandler },                 \
                                        { EXTI4_15_IRQHandler },                \
                                        { HWDIV_IRQHandler },                   \
                                        { DMA1_Channel1_IRQHandler },           \
                                        { DMA1_Channel2_3_IRQHandler },         \
                                        { DMA1_Channel4_5_IRQHandler },         \
                                        { ADC1_IRQHandler },                    \
                                        { TIM1_BRK_UP_TRG_COM_IRQHandler },     \
                                        { TIM1_CC_IRQHandler },                 \
                                        { TIM2_IRQHandler },                    \
                                        { TIM3_IRQHandler },                    \
                                        { TIM8_BRK_UP_TRG_COM_IRQHandler },     \
                                        { TIM8_CC_IRQHandler },                 \
                                        { TIM14_IRQHandler },                   \
                                        { ADC2_IRQHandler },                    \
                                        { TIM16_IRQHandler },                   \
                                        { TIM17_IRQHandler },                   \
                                        { I2C1_IRQHandler },                    \
                                        { COMP_1_2_3_4_5_IRQHandler },          \
                                        { SPI1_IRQHandler },                    \
                                        { SPI2_IRQHandler },                    \
                                        { UART1_IRQHandler },                   \
                                        { UART2_IRQHandler },                   \
                                        { FlashCache_IRQHandler }
#endif

// Peripherals handlers
#if defined(__MM0Q1)
#define __MM32_IRQ_HANDLERS__           { WDG_IRQHandler },                     \
                                        { PVD_IRQHandler },                     \
                                        { PWM_IRQHandler },                     \
                                        { FLASH_IRQHandler },                   \
                                        { RCC_IRQHandler },                     \
                                        { EXTI0_1_IRQHandler },                 \
                                        { EXTI2_3_IRQHandler },                 \
                                        { EXTI4_15_IRQHandler },                \
                                        { HWDIV_IRQHandler },                   \
                                        { DMA1_Channel1_IRQHandler },           \
                                        { DMA1_Channel2_3_IRQHandler },         \
                                        { DMA1_Channel4_5_IRQHandler },         \
                                        { ADC_COMP_IRQHandler },                \
                                        { TIM1_BRK_UP_TRG_COM_IRQHandler },     \
                                        { TIM1_CC_IRQHandler },                 \
                                        { TIM2_IRQHandler },                    \
                                        { TIM3_IRQHandler },                    \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { TIM14_IRQHandler },                   \
                                        { 0 },                                  \
                                        { TIM16_IRQHandler },                   \
                                        { TIM17_IRQHandler },                   \
                                        { I2C1_IRQHandler },                    \
                                        { 0 },                                  \
                                        { SPI1_IRQHandler },                    \
                                        { SPI2_IRQHandler },                    \
                                        { UART1_IRQHandler },                   \
                                        { UART2_IRQHandler }
#endif

#if defined(__MM0S1)
#define __MM32_IRQ_HANDLERS__           { WDG_IRQHandler },                     \
                                        { PVD_IRQHandler },                     \
                                        { RTC_BKP_IRQHandler },                 \
                                        { FLASH_IRQHandler },                   \
                                        { RCC_CRS_IRQHandler },                 \
                                        { EXTI0_1_IRQHandler },                 \
                                        { EXTI2_3_IRQHandler },                 \
                                        { EXTI4_15_IRQHandler },                \
                                        { HWDIV_IRQHandler },                   \
                                        { DMA1_Channel1_IRQHandler },           \
                                        { DMA1_Channel2_3_IRQHandler },         \
                                        { DMA1_Channel4_5_IRQHandler },         \
                                        { ADC1_COMP_IRQHandler },               \
                                        { TIM1_BRK_UP_TRG_COM_IRQHandler },     \
                                        { TIM1_CC_IRQHandler },                 \
                                        { TIM2_IRQHandler },                    \
                                        { TIM3_IRQHandler },                    \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { TIM14_IRQHandler },                   \
                                        { 0 },                                  \
                                        { TIM16_IRQHandler },                   \
                                        { TIM17_IRQHandler },                   \
                                        { I2C1_IRQHandler },                    \
                                        { 0 },                                  \
                                        { SPI1_IRQHandler },                    \
                                        { SPI2_IRQHandler },                    \
                                        { UART1_IRQHandler },                   \
                                        { UART2_IRQHandler },                   \
                                        { CSM_IRQHandler },                     \
                                        { CAN_IRQHandler },                     \
                                        { USB_IRQHandler }
#endif

#if defined(__MM0T1)
#define __MM32_IRQ_HANDLERS__           { WDG_IRQHandler },                     \
                                        { PVD_IRQHandler },                     \
                                        { 0 },                                  \
                                        { FLASH_IRQHandler },                   \
                                        { RCC_IRQHandler },                     \
                                        { EXTI0_1_IRQHandler },                 \
                                        { EXTI2_3_IRQHandler },                 \
                                        { EXTI4_15_IRQHandler },                \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { ADC1_IRQHandler },                    \
                                        { TIM1_BRK_UP_TRG_COM_IRQHandler },     \
                                        { TIM1_CC_IRQHandler },                 \
                                        { 0 },                                  \
                                        { TIM3_IRQHandler },                    \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { TIM14_IRQHandler },                   \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { I2C1_IRQHandler },                    \
                                        { 0 },                                  \
                                        { SPI1_IRQHandler },                    \
                                        { 0 },                                  \
                                        { UART1_IRQHandler },                   \
                                        { UART2_IRQHandler }
#endif

#if defined(__MM3U1)
#define __MM32_IRQ_HANDLERS__           { WDG_IRQHandler },                     \
                                        { PVD_IRQHandler },                     \
                                        { TAMPER_IRQHandler },                  \
                                        { RTC_IRQHandler },                     \
                                        { FLASH_IRQHandler },                   \
                                        { RCC_CRS_IRQHandler },                 \
                                        { EXTI0_IRQHandler },                   \
                                        { EXTI1_IRQHandler },                   \
                                        { EXTI2_IRQHandler },                   \
                                        { EXTI3_IRQHandler },                   \
                                        { EXTI4_IRQHandler },                   \
                                        { DMA1_Channel1_IRQHandler },           \
                                        { DMA1_Channel2_IRQHandler },           \
                                        { DMA1_Channel3_IRQHandler },           \
                                        { DMA1_Channel4_IRQHandler },           \
                                        { DMA1_Channel5_IRQHandler },           \
                                        { DMA1_Channel6_IRQHandler },           \
                                        { DMA1_Channel7_IRQHandler },           \
                                        { ADC1_2_IRQHandler },                  \
                                        { FLASH_CACHE_IRQHandler },             \
                                        { 0 },                                  \
                                        { CAN1_RX_IRQHandler },                 \
                                        { 0 },                                  \
                                        { EXTI9_5_IRQHandler },                 \
                                        { TIM1_BRK_IRQHandler },                \
                                        { TIM1_UP_IRQHandler },                 \
                                        { TIM1_TRG_COM_IRQHandler },            \
                                        { TIM1_CC_IRQHandler },                 \
                                        { TIM2_IRQHandler },                    \
                                        { TIM3_IRQHandler },                    \
                                        { TIM4_IRQHandler },                    \
                                        { I2C1_IRQHandler },                    \
                                        { 0 },                                  \
                                        { I2C2_IRQHandler },                    \
                                        { 0 },                                  \
                                        { SPI1_IRQHandler },                    \
                                        { SPI2_IRQHandler },                    \
                                        { UART1_IRQHandler },                   \
                                        { UART2_IRQHandler },                   \
                                        { UART3_IRQHandler },                   \
                                        { EXTI15_10_IRQHandler },               \
                                        { RTC_ALARM_IRQHandler },               \
                                        { USB_WKUP_IRQHandler },                \
                                        { TIM8_BRK_IRQHandler },                \
                                        { TIM8_UP_IRQHandler },                 \
                                        { TIM8_TRG_COM_IRQHandler },            \
                                        { TIM8_CC_IRQHandler },                 \
                                        { ADC3_IRQHandler },                    \
                                        { 0 },                                  \
                                        { SDIO_IRQHandler },                    \
                                        { TIM5_IRQHandler },                    \
                                        { SPI3_IRQHandler },                    \
                                        { UART4_IRQHandler },                   \
                                        { UART5_IRQHandler },                   \
                                        { TIM6_IRQHandler },                    \
                                        { TIM7_IRQHandler },                    \
                                        { DMA2_Channel1_IRQHandler },           \
                                        { DMA2_Channel2_IRQHandler },           \
                                        { DMA2_Channel3_IRQHandler },           \
                                        { DMA2_Channel4_IRQHandler },           \
                                        { DMA2_Channel5_IRQHandler },           \
                                        { ETH_IRQHandler },                     \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { COMP1_2_IRQHandler },                 \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { USB_OTG_FS_IRQHandler },              \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { UART6_IRQHandler },                   \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { 0 },                                  \
                                        { UART7_IRQHandler },                   \
                                        { UART8_IRQHandler }
#endif

#endif // __MM32_STARTUP_H__
