/**
 * @file DAC.c
 * @author Kleeper & Aiden
 * @brief DAC输出模块
 * @version 0.1
 * @date 2025-04-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "DAC.h"

uint32_t dac_value = 0;
uint32_t step_sum = 0;
uint32_t dac_value0 = DAC_0 * DAC_MAX / DAC_VCC + CORRECTED_VALUE;    //初始电压1V

char str[100];
/*
 * 经过纠正加减输出的电压误差发生概率变小
 * 出现的误差大小仅有±1mV
 */
void DAC_OUTPUT0(void)
{
    DL_DAC12_output12(DAC0, dac_value0);
    /*这里的误差消除不了，固定4mV*/
	sprintf(str,"msg.txt=\"%d mV\"",DAC_0);
	tjc_send_string(str);

    sprintf(str,"t2.txt=\"%d dB\"",0);
	tjc_send_string(str);
}

void DAC_OUTPUT(void)
{
    if((step_sum + DAC_0) >= AD_MAX) count = 60;			
	step_sum = count * STEP;

	dac_value = step_sum * DAC_MAX / DAC_VCC + dac_value0;
	DL_DAC12_output12(DAC0, dac_value);
					
	sprintf(str,"msg.txt=\"%d mV\"",(step_sum + DAC_0));
	tjc_send_string(str);

    sprintf(str,"t2.txt=\"%.2f dB\"",(step_sum * 0.04));
	tjc_send_string(str);
}