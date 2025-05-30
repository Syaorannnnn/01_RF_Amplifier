/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for UART_0 */
#define UART_0_INST                                                        UART2
#define UART_0_INST_FREQUENCY                                           32000000
#define UART_0_INST_IRQHandler                                  UART2_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART2_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOB
#define GPIO_UART_0_TX_PORT                                                GPIOB
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_18
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_17
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM44)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM43)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM44_PF_UART2_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM43_PF_UART2_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_0_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART0
#define UART_1_INST_FREQUENCY                                           32000000
#define UART_1_INST_IRQHandler                                  UART0_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_1_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_1_FBRD_32_MHZ_115200_BAUD                                      (23)





/* Defines for ADC12_0 */
#define ADC12_0_INST                                                        ADC0
#define ADC12_0_INST_IRQHandler                                  ADC0_IRQHandler
#define ADC12_0_INST_INT_IRQN                                    (ADC0_INT_IRQn)
#define ADC12_0_ADCMEM_0                                      DL_ADC12_MEM_IDX_0
#define ADC12_0_ADCMEM_0_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_0_ADCMEM_0_REF_VOLTAGE_V                                       3.3
#define ADC12_0_ADCMEM_1                                      DL_ADC12_MEM_IDX_1
#define ADC12_0_ADCMEM_1_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_0_ADCMEM_1_REF_VOLTAGE_V                                       3.3
#define GPIO_ADC12_0_C0_PORT                                               GPIOA
#define GPIO_ADC12_0_C0_PIN                                       DL_GPIO_PIN_27
#define GPIO_ADC12_0_C1_PORT                                               GPIOA
#define GPIO_ADC12_0_C1_PIN                                       DL_GPIO_PIN_26



/* Port definition for Pin Group GPIO_LEDS */
#define GPIO_LEDS_PORT                                                   (GPIOA)

/* Defines for LED: GPIOA.3 with pinCMx 8 on package pin 9 */
#define GPIO_LEDS_LED_PIN                                        (DL_GPIO_PIN_3)
#define GPIO_LEDS_LED_IOMUX                                       (IOMUX_PINCM8)
/* Defines for G: GPIOA.4 with pinCMx 9 on package pin 10 */
#define GPIO_LEDS_G_PIN                                          (DL_GPIO_PIN_4)
#define GPIO_LEDS_G_IOMUX                                         (IOMUX_PINCM9)
/* Defines for R: GPIOA.2 with pinCMx 7 on package pin 8 */
#define GPIO_LEDS_R_PIN                                          (DL_GPIO_PIN_2)
#define GPIO_LEDS_R_IOMUX                                         (IOMUX_PINCM7)
/* Port definition for Pin Group GPIO_BTN */
#define GPIO_BTN_PORT                                                    (GPIOB)

/* Defines for LEFT: GPIOB.6 with pinCMx 23 on package pin 20 */
#define GPIO_BTN_LEFT_PIN                                        (DL_GPIO_PIN_6)
#define GPIO_BTN_LEFT_IOMUX                                      (IOMUX_PINCM23)
/* Defines for DOWN: GPIOB.7 with pinCMx 24 on package pin 21 */
#define GPIO_BTN_DOWN_PIN                                        (DL_GPIO_PIN_7)
#define GPIO_BTN_DOWN_IOMUX                                      (IOMUX_PINCM24)
/* Defines for RIGHT: GPIOB.8 with pinCMx 25 on package pin 22 */
#define GPIO_BTN_RIGHT_PIN                                       (DL_GPIO_PIN_8)
#define GPIO_BTN_RIGHT_IOMUX                                     (IOMUX_PINCM25)
/* Defines for UP: GPIOB.9 with pinCMx 26 on package pin 23 */
#define GPIO_BTN_UP_PIN                                          (DL_GPIO_PIN_9)
#define GPIO_BTN_UP_IOMUX                                        (IOMUX_PINCM26)
/* Defines for MID: GPIOB.14 with pinCMx 31 on package pin 24 */
#define GPIO_BTN_MID_PIN                                        (DL_GPIO_PIN_14)
#define GPIO_BTN_MID_IOMUX                                       (IOMUX_PINCM31)
/* Port definition for Pin Group GPIO_ENCODER */
#define GPIO_ENCODER_PORT                                                (GPIOB)

/* Defines for A: GPIOB.15 with pinCMx 32 on package pin 25 */
// pins affected by this interrupt request:["A","B"]
#define GPIO_ENCODER_INT_IRQN                                   (GPIOB_INT_IRQn)
#define GPIO_ENCODER_INT_IIDX                   (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_ENCODER_A_IIDX                                 (DL_GPIO_IIDX_DIO15)
#define GPIO_ENCODER_A_PIN                                      (DL_GPIO_PIN_15)
#define GPIO_ENCODER_A_IOMUX                                     (IOMUX_PINCM32)
/* Defines for B: GPIOB.16 with pinCMx 33 on package pin 26 */
#define GPIO_ENCODER_B_IIDX                                 (DL_GPIO_IIDX_DIO16)
#define GPIO_ENCODER_B_PIN                                      (DL_GPIO_PIN_16)
#define GPIO_ENCODER_B_IOMUX                                     (IOMUX_PINCM33)
/* Port definition for Pin Group GPIO_FREQ_DECODER */
#define GPIO_FREQ_DECODER_PORT                                           (GPIOA)

/* Defines for E: GPIOA.0 with pinCMx 1 on package pin 1 */
// pins affected by this interrupt request:["E"]
#define GPIO_FREQ_DECODER_INT_IRQN                              (GPIOA_INT_IRQn)
#define GPIO_FREQ_DECODER_INT_IIDX              (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_FREQ_DECODER_E_IIDX                             (DL_GPIO_IIDX_DIO0)
#define GPIO_FREQ_DECODER_E_PIN                                  (DL_GPIO_PIN_0)
#define GPIO_FREQ_DECODER_E_IOMUX                                 (IOMUX_PINCM1)
/* Defines for DB4: GPIOA.1 with pinCMx 2 on package pin 2 */
#define GPIO_FREQ_DECODER_DB4_PIN                                (DL_GPIO_PIN_1)
#define GPIO_FREQ_DECODER_DB4_IOMUX                               (IOMUX_PINCM2)
/* Defines for DB5: GPIOA.28 with pinCMx 3 on package pin 3 */
#define GPIO_FREQ_DECODER_DB5_PIN                               (DL_GPIO_PIN_28)
#define GPIO_FREQ_DECODER_DB5_IOMUX                               (IOMUX_PINCM3)
/* Defines for DB6: GPIOA.31 with pinCMx 6 on package pin 5 */
#define GPIO_FREQ_DECODER_DB6_PIN                               (DL_GPIO_PIN_31)
#define GPIO_FREQ_DECODER_DB6_IOMUX                               (IOMUX_PINCM6)
/* Defines for DB7: GPIOA.5 with pinCMx 10 on package pin 11 */
#define GPIO_FREQ_DECODER_DB7_PIN                                (DL_GPIO_PIN_5)
#define GPIO_FREQ_DECODER_DB7_IOMUX                              (IOMUX_PINCM10)





/* Defines for DAC12 */
#define DAC12_IRQHandler                                         DAC0_IRQHandler
#define DAC12_INT_IRQN                                           (DAC0_INT_IRQn)
#define GPIO_DAC12_OUT_PORT                                                GPIOA
#define GPIO_DAC12_OUT_PIN                                        DL_GPIO_PIN_15
#define GPIO_DAC12_IOMUX_OUT                                     (IOMUX_PINCM37)
#define GPIO_DAC12_IOMUX_OUT_FUNC                   IOMUX_PINCM37_PF_UNCONNECTED

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_ADC12_0_init(void);

void SYSCFG_DL_SYSTICK_init(void);
void SYSCFG_DL_DAC12_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
