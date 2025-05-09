/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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

#include "ti_msp_dl_config.h"
#include "./ADC/ADC.h"
#include "./ROTARY_ENCODER/ROTARY_ENCODER.h"
#include "./FREQ_DECODER/FREQ_DECODER.h"
#include "./UART/UART.h"
#include "./LCD/PAGE_HANDLE.h"

volatile uint8_t freq_count = 1;    //采样两个频率点再进入ADC采样，避免频率变化过快让lcd卡死
volatile uint16_t sample_count = 0; //总有效采样点，超过SAMPLE_SIZE则停止采样
volatile uint8_t sample_end = 0;

int main(void)
{
	SYSCFG_DL_init();
	//  清除串口中断标志
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    //  DAC使能
    DL_DAC12_enable(DAC0);

    /*  中断使能    */
	//  使能串口中断
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
    //  使能旋转编码器中断
    NVIC_EnableIRQ(GPIO_ENCODER_INT_IRQN);
    //  使能ADC中断
    NVIC_EnableIRQ(ADC12_0_INST_INT_IRQN);
    //  使能频率解码计中断
    NVIC_EnableIRQ(GPIO_FREQ_DECODER_INT_IRQN);
    /*********************/
    //  DAC输出默认值
	DAC_OUTPUT0();

    //Point_init();

	while (1)
	{
        if(!sample_end) 
        {
            data_samplepoints_conversion();
        }

        Page_Handler();
	}
}

// GPIO中断请求处理
void GROUP1_IRQHandler(void)    //Group1的中断触发
{
    switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) 
    {
        case GPIO_ENCODER_INT_IIDX : 
            get_rotate_dir();
            //Page_Handler();

            DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT, GPIO_ENCODER_A_PIN | GPIO_ENCODER_B_PIN);
            break;

        case GPIO_FREQ_DECODER_INT_IIDX : 
            DL_GPIO_togglePins(GPIO_LEDS_PORT, GPIO_LEDS_R_PIN);
            freq_fetch();

            DL_GPIO_clearInterruptStatus(GPIO_FREQ_DECODER_PORT, GPIO_FREQ_DECODER_E_PIN);
            break;
    }

}