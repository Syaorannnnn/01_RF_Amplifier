/*

*/

#ifndef __ROTARY_ENCODER_H__
#define __ROTARY_ENCODER_H__

#include "ti_msp_dl_config.h"
#include "stdbool.h"

#define     A       (DL_GPIO_readPins(GPIO_ENCODER_PORT, GPIO_ENCODER_A_PIN) && 0x8000)        //读取A引脚的电平
#define     B       (DL_GPIO_readPins(GPIO_ENCODER_PORT, GPIO_ENCODER_B_PIN) && 0x10000)       //读取B引脚的电平

bool rotate_dir;            //旋转编码器旋转方向
void get_rotate_dir(void);  //旋转编码器方向检测

#endif