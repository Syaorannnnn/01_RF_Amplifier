/*

*/
#ifndef __HMI_GUI_H__
#define __HMI_GUI_H__

#include "stdio.h"
#include "stdbool.h"
#include "tjc_usart_hmi.h"
#include "../TICK/Tick.h"
#include "../FREQ_DECODER/FREQ_DECODER.h"

/*********************************************/
/***    参数定义    ***/
#define     BUFFER_LEN_MAX      100     //发送指令缓冲区最大长度
/*********************************************/
/***  绘图参数    ***/
#define     RADIUS          3           //画点半径
#define     PI              3.14159265358979
#define     SCALE           3
/*  数据点数    */
#define     N               84         //图线绘制的点数，与SAMPLE_SIZE保持一致
/*  select参数  */
#define     AMPLITUDE       1           //代表选择幅度值
#define     PHASE           2           //代表选择相位值
/*  方向    */
#define     LEFT            false
#define     RIGHT           true
/*  颜色(十进制)    */
#define     RED             63488
#define     BLUE            31
#define     GRAY            33840
#define     BLACK           0
#define     WHITE           65535
#define     GREEN           2016
#define     BROWN           48192
#define     YELLOW          65504
/******************************************************/
/***     幅频/相频绘制      ***/
/*  背景色  */
#define     BACKGROUND          WHITE
/*  图谱宽高    */
#define     WIDTH               300     //绘图宽300px
#define     HEIGHT              255     //绘图高255px  
/*  图谱基准位置    */
#define     AMP_X_STANDARD      10
#define     AMP_Y_STANDARD      100
#define     PHA_X_STANDARD      490
#define     PHA_Y_STANDARD      100
/******************************************************/
/*
 * 新示波器窗口参数
 * x轴 400-700     一小格75
 * y轴 50-350		一小格60
 *
 */

#define     SCOPE_X         400
#define     SCOPE_Y         700
#define     SCOPE_WIDTH     300
#define     SCOPE_HEIGHT    300
/*
 * 一小格里面各对数刻度宽度(从左至右)
 * 20 15 10 8 5 5 5 4 3
 */
//uint8_t log_scale[9];
/******************************************************/

/*  绘图点(x,y)  */
typedef struct Point
{
    int X;
    int Y;
}Point_t;

/***********  绘图功能函数    **********/
void clr_scr(void);                                             //清屏
void draw_dot(int x,int y,int color);                           //画点
void draw_line(int x1,int y1,int x2,int y2,int color);          //画线
void clr_line(int x1,int y1,int x2,int y2);                     //擦除线

/*  游标    */
void cursor_init(void);                                         //初始化
void cursor_move(bool dir);                                     //移动游标
void cursor_value(int select);                                  //显示游标值
void show_cursor(void);                                         //刷新游标，防止被清屏函数刷走

/*  绘制图线    */
void show_curve(Point_t *point);                                    
void instant_show_curve(Point_t *point);

/*  示波器画面更新  */
void static_show_scope(void);                                          
void instant_show_scope_without_cursor(void);

/*  采样点映射成(x,y)  */
void coordinate_conversion(void);                               //坐标转换

/*  测试函数    */
//void test(void);

void Point_init();
void plot_dot();


#endif