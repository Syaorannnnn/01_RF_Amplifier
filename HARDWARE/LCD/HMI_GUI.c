/**
 * @file HMI_GUI.c
 * @author Aiden
 * @brief 串口屏GUI绘制
 * @version 0.1
 * @date 2025-04-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "HMI_GUI.h"

extern bool rotate_dir;
extern volatile AmpPoint SamplePoints[SAMPLE_SIZE];
extern uint16_t freq_index;

uint8_t log_scale[9] = {20,15,10,8,5,5,5,4,3};
/*  幅度/相位数据缓冲区 */
Point_t amp_point[N + 1] = {0};
Point_t pha_point[N + 1] = {0};

char str[BUFFER_LEN_MAX];
uint8_t offset = 0;

void Point_init() 
{
    for(int i = 0; i <= N; i++) {
        amp_point[i].X = i * 3 + 50;
        amp_point[i].Y = AMP_Y_STANDARD + HEIGHT;
        pha_point[i].X = i * 3 + 500;
        pha_point[i].Y = PHA_Y_STANDARD + HEIGHT;
    }
}

/**
 * @brief 清屏
 * 
 */
void clr_scr(void)
{
    sprintf(str,"clr WHITE");
    tjc_send_string(str);
    sprintf(str,"ref p0");
    tjc_send_string(str);    
}

/**
 * @brief 画点
 * 
 * @param x 
 * @param y 
 * @param color 
 */
void draw_dot(int x, int y,int color)
{
    sprintf(str,"cirs %d,%d,%d,%d",x,y,RADIUS,color);
    tjc_send_string(str);
    //delay_cycles(1000);
}

/**
 * @brief 画线
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2 
 * @param color 
 */
void draw_line(int x1, int y1, int x2, int y2,int color)
{
    sprintf(str,"line %d,%d,%d,%d,%d",x1,y1,x2,y2,color);
    tjc_send_string(str);
    //delay_cycles(1000);
}

/**
 * @brief 清除线
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2 
 */
void clr_line(int x1, int y1, int x2, int y2)
{
    sprintf(str,"line %d,%d,%d,%d,%d",x1,y1,x2,y2,BACKGROUND);
    tjc_send_string(str);
    delay_cycles(1000);
}

void cursor_init(void) 
{
    draw_line(AMP_X_STANDARD, AMP_Y_STANDARD, AMP_X_STANDARD, AMP_Y_STANDARD + HEIGHT,YELLOW);
}

/**
 * @brief 游标移动
 *  
 * @param dir 
 */
void cursor_move(bool dir)
{
    if(dir)
    {
            //clr_line(AMP_X_STANDARD + offset, AMP_Y_STANDARD, AMP_X_STANDARD + offset, AMP_Y_STANDARD + HEIGHT);
            offset = (offset + 1 * SCALE) % (N * SCALE + 50);
            //draw_line(AMP_X_STANDARD + offset, AMP_Y_STANDARD, AMP_X_STANDARD + offset, AMP_Y_STANDARD + HEIGHT,GREEN);
    }
    else 
    {
            offset -= 1 * SCALE;
            if(offset < 0)  offset = 0;
    }
}

/**
 * @brief 显示游标值
 * 
 * @param select 
 */
void cursor_value(int select)
{
    if(select == AMPLITUDE)
    {
        //sprintf(str, "amp.txt=\"%.2f\"",SamplePoints[(offset - 50) / 3].gain_db);
        sprintf(str, "amp.txt=\"%.2f\"",SamplePoints[offset].gain_db);
        tjc_send_string(str);   
    }
    else 
    {
        //sprintf(str, "pha.txt=\"%.2f\"",SamplePoints[(offset - 50) / 3].phase_deg);
        sprintf(str, "pha.txt=\"%.2f\"",SamplePoints[offset].phase_deg);
        tjc_send_string(str);  
    }
     
}

/**
 * @brief 显示游标与其对应的值
 * 
 */
void show_cursor(void)
{
    draw_line(AMP_X_STANDARD + offset * SCALE, AMP_Y_STANDARD, AMP_X_STANDARD + offset * SCALE, AMP_Y_STANDARD + HEIGHT,GREEN);
    draw_line(PHA_X_STANDARD + offset * SCALE, PHA_Y_STANDARD, PHA_X_STANDARD + offset * SCALE, PHA_Y_STANDARD + HEIGHT,GREEN);

    cursor_value(AMPLITUDE);
    cursor_value(PHASE);
}

/**
 * @brief for循环打印点与线，在ADC完毕时使用
 * 
 * @param point 
 */
void show_curve(Point_t *point)
{
    for(int i = 0; i < N; i++)
    { 
        draw_dot(point[freq_index].X, point[freq_index].Y,YELLOW); 
    }

    for(int j = 1; j < N ; j++)
    {
        draw_line(point[j - 1].X, point[j - 1].Y, point[j].X, point[j].Y, YELLOW);
    }
}

/**
 * @brief 即时打印点,并连成曲线
 * 
 * @param point 
 */
void instant_show_curve(Point_t *point)
{ 
    draw_dot(point[freq_index].X, point[freq_index].Y,YELLOW); 

    for(int j = 1; j < N ; j++)
    {
        draw_line(point[j - 1].X, point[j - 1].Y, point[j].X, point[j].Y, YELLOW);
    }
   
}

/**
 * @brief 静态更新图线与游标
 * 
 */
void static_show_scope()
{
    clr_scr();
    //delay_ms(50);

    show_curve(amp_point);
    show_curve(pha_point);

    cursor_move(rotate_dir);
    cursor_move(rotate_dir);
    
    show_cursor(); 
  
}

/**
 * @brief 示波器动态显示,此时不带游标更新
 * 
 */
void instant_show_scope_without_cursor(void)
{
    clr_scr();
    //delay_ms(50);

    instant_show_curve(amp_point);
    instant_show_curve(pha_point);

}

/**
 * @brief 把采样点里的数据映射成(x,y)
 * 
 */
void coordinate_conversion(void)
{   
    amp_point[freq_index].X = freq_index * 3 + 50;
    pha_point[freq_index].X = freq_index * 3 + 500;
    amp_point[freq_index].Y = AMP_Y_STANDARD + HEIGHT - SamplePoints[freq_index].gain_db * 3;
    pha_point[freq_index].Y = PHA_Y_STANDARD + HEIGHT - SamplePoints[freq_index].phase_deg;
    
}

void plot_dot()
 {
    if(freq_index == 0) return;
    draw_dot(amp_point[freq_index].X, amp_point[freq_index].Y,YELLOW);
    draw_dot(pha_point[freq_index].X, pha_point[freq_index].Y,YELLOW);
    draw_line(amp_point[freq_index - 1].X, amp_point[freq_index - 1].Y, amp_point[freq_index].X, amp_point[freq_index].Y, YELLOW);
    draw_line(pha_point[freq_index - 1].X, pha_point[freq_index - 1].Y, pha_point[freq_index].X, pha_point[freq_index].Y, YELLOW);

    //cursor_present();
}