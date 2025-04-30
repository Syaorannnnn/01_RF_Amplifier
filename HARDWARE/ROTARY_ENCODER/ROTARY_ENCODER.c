/**
 * @file ROTARY_ENCODER.c
 * @author Aiden (aiden.tang0817@outlook.com)
 * @brief 旋转解码器功能模块
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "ROTARY_ENCODER.h"

int B_Current_State;

 void get_rotate_dir(void)
 {
    /* A上升沿触发时检测B，B为低电平则判定为顺时针转 */
    if(A)
    {
        if(!B)  rotate_dir = true;
    }
    /* B上升沿触发时检测A，A为低电平则判定为逆时针转 */
    if(B)
    {
        if(!A)  rotate_dir = false;
    }
 }