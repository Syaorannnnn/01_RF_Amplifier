/*

*/

#ifndef __DATA_PRESENTATION_H__
#define __DATA_PRESENTATION_H__





#include <stdio.h>
#include "stdbool.h"
#include "tjc_usart_hmi.h"


/*  绘图参数    */
#define WIDTH               300     //绘图宽300px
#define HEIGHT              255     //绘图高255px
#define SCOPE_X_STANDARD    39
#define SCOPE_Y_STANDARD    116
#define SCOPE_WIDTH         300
#define SCOPE_HEIGHT        255  
/*  select参数  */
#define AMPLITUDE       1       //代表选择幅度值
#define PHASE           2       //代表选择相位值

#define DATA_LEN_MAX    1024    //采样的点数 or 波形控件加载的点数
#define BUFFER_LEN_MAX_1  1000    //串口缓冲区最大长度

#define LEFT            false
#define RIGHT           true

/*  接收单片机数据    */
void data_print(uint8_t *databuff, int select);
/*  坐标轴显示  */
void Axis_present(void);
/*  游标模块    */
void Cursor_refresh(void);
void Cursor_move(bool dir);
void Cursor_present(int offset);


#endif