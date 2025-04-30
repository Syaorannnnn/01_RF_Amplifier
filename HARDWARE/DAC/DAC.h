/*

*/

#ifndef __DAC_H__
#define __DAC_H__

#include "stdio.h"
#include "ti_msp_dl_config.h"
#include "../LCD/tjc_usart_hmi.h"

#define     DAC_0                               (0)                          //初始电压
#define     DAC_MAX 	                        (4095)
#define     DAC_VCC		                        (3300)
#define     STEP	                            (10)		                    //步进10mV
#define     AD_MAX		                        (1600)
#define     CORRECTED_VALUE                     (5 * DAC_MAX / DAC_VCC)         //修正值

extern int count;

void DAC_OUTPUT0(void);
void DAC_OUTPUT(void);
#endif