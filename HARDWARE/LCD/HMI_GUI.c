/**
 * @file HMI_GUI.c
 * @author Aiden
 * @brief 串口屏GUI绘制库
 * @version 0.1
 * @date 2025-04-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "HMI_GUI.h"

/*  采样点结构声明  */
// typedef struct
// {
// 	float freq;
// 	float gain_db;
// 	float phase_deg;
// }AmpPoint;

/*  绘图点  */
typedef struct Point
{
    int X;
    int Y;
}Point;

extern volatile AmpPoint SamplePoints[SAMPLE_SIZE];
extern uint16_t freq_index;
/*  幅度/相位数据缓冲区 */
int Amplitude[N];
int Phase[N];

Point amp_point[N] = {0};
Point pha_point[N] = {0};

char str[BUFFER_LEN_MAX];
uint8_t offset = 0;
bool receive_completed = false;

void clear_scr(void)
{
    sprintf(str,"clr WHITE");
    tjc_send_string(str);
    //sprintf(str,"fill %d,%d,%d,%d,%d",AMP_X_STANDARD,AMP_Y_STANDARD,WIDTH,HEIGHT,BACKGROUND);
    sprintf(str,"ref p0");
    tjc_send_string(str);
    //sprintf(str,"fill %d,%d,%d,%d,%d",PHA_X_STANDARD,PHA_Y_STANDARD,WIDTH,HEIGHT,BACKGROUND);
    sprintf(str,"ref p1");
    tjc_send_string(str);
     
}

void draw_dot(int x, int y,int color)
{
    sprintf(str,"cirs %d,%d,%d,%d",x,y,RADIUS,color);
    tjc_send_string(str);
}

void draw_line(int x1, int y1, int x2, int y2,int color)
{
    sprintf(str,"line %d,%d,%d,%d,%d",x1,y1,x2,y2,color);
    tjc_send_string(str);
}

void clr_line(int x1, int y1, int x2, int y2)
{
    sprintf(str,"line %d,%d,%d,%d,%d",x1,y1,x2,y2,BACKGROUND);
    tjc_send_string(str);
}

void cursor_init(void) 
{
    draw_line(AMP_X_STANDARD, AMP_Y_STANDARD, AMP_X_STANDARD, AMP_Y_STANDARD + HEIGHT,YELLOW);
}

void cursor_move(int select, bool dir)
{
    if(dir)
    {
        if(select == AMPLITUDE)
        {
            //clr_line(AMP_X_STANDARD + offset, AMP_Y_STANDARD, AMP_X_STANDARD + offset, AMP_Y_STANDARD + HEIGHT);
            offset = (offset + 1) % N;
            //draw_line(AMP_X_STANDARD + offset, AMP_Y_STANDARD, AMP_X_STANDARD + offset, AMP_Y_STANDARD + HEIGHT,GREEN);
        }
        else
        {
            //clr_line(PHA_X_STANDARD + offset, PHA_Y_STANDARD, PHA_X_STANDARD + offset, PHA_Y_STANDARD + HEIGHT);
            offset = (offset + 1) % N;
            //draw_line(PHA_X_STANDARD + offset, PHA_Y_STANDARD, PHA_X_STANDARD + offset, PHA_Y_STANDARD + HEIGHT,GREEN);
        }
    }
    else 
    {
        if(select == AMPLITUDE)
        {
            //clr_line(AMP_X_STANDARD + offset, AMP_Y_STANDARD, AMP_X_STANDARD + offset, AMP_Y_STANDARD + HEIGHT);
            offset--;
            if(offset < 0)  offset = 0;
            //draw_line(AMP_X_STANDARD + offset, AMP_Y_STANDARD, AMP_X_STANDARD + offset, AMP_Y_STANDARD + HEIGHT,GREEN);
        }
        else 
        {
            //clr_line(PHA_X_STANDARD + offset, PHA_Y_STANDARD, PHA_X_STANDARD + offset, PHA_Y_STANDARD + HEIGHT);
            offset--;
            if(offset < 0)  offset = 0;
            //draw_line(PHA_X_STANDARD + offset, PHA_Y_STANDARD, PHA_X_STANDARD + offset, PHA_Y_STANDARD + HEIGHT,GREEN);
        }
        
    }
}

/*  显示游标值  */
void cursor_value(int select)
{
    if(select == AMPLITUDE)
    {
        sprintf(str, "amp.txt=\"%.2f\"",SamplePoints[offset].gain_db);
        tjc_send_string(str);   
    }
    else 
    {
        sprintf(str, "pha.txt=\"%.2f\"",SamplePoints[offset].phase_deg);
        tjc_send_string(str);  
    }
     
}

/*  防止游标被刷新掉  */
void cursor_present(void)
{
    draw_line(AMP_X_STANDARD + offset * DIVISION, AMP_Y_STANDARD, AMP_X_STANDARD + offset * DIVISION, AMP_Y_STANDARD + HEIGHT,GREEN);
    draw_line(PHA_X_STANDARD + offset * DIVISION, PHA_Y_STANDARD, PHA_X_STANDARD + offset * DIVISION, PHA_Y_STANDARD + HEIGHT,GREEN);
}

/*  
    即时更新点
    并连成曲线        
 */
void show_curve(int select)
{
    switch (select) 
    {
        case AMPLITUDE : 
            draw_dot(amp_point[freq_index].X, amp_point[freq_index].Y,YELLOW); break;
        case PHASE : 
            draw_dot(pha_point[freq_index].X, pha_point[freq_index].Y,YELLOW); break;
            default : break;
    }

    for(int j = 1; j < N - 2 ; j++)
    {
        draw_line(amp_point[j - 1].X, amp_point[j - 1].Y, amp_point[j].X, amp_point[j].Y,YELLOW);
        draw_line(pha_point[j - 1].X, pha_point[j - 1].Y, pha_point[j].X, pha_point[j].Y,YELLOW);
    }
    // int dot_x[N];
    // int dot_y[N];
    
    // if(receive_completed)
    // {
    //     if(select == AMPLITUDE)
    //     {
    //         for(int i = 0; i < N - 2; i++) 
    //         {
    //             dot_x[i] = AMP_X_STANDARD + i * DIVISION;
    //             //dot_y[i] = 96 - (magnitude[i] * 4096 / 3.3) / 32;
    //             dot_y[i] = AMP_Y_STANDARD + HEIGHT - Amplitude[i];
    //             draw_dot(dot_x[i], dot_y[i],YELLOW);
    //         }

    //         for(int i = 1; i < N - 2; i++) 
    //         {
    //             draw_line(dot_x[i-1], dot_y[i-1], dot_x[i], dot_y[i],YELLOW);
    //         }
       
    //     }
    //     else 
    //     {
    //         for(int i = 0; i < N - 2; i++)
    //         {
    //             dot_x[i] = PHA_X_STANDARD + i * DIVISION;
    //             dot_y[i] = PHA_Y_STANDARD + HEIGHT - Phase[i];
    //             //dot_y[i] = 96 - (magnitude[i] * 4096 / 3.3) / 32;
    //             //printf("dot_x[%d]: %d, dot_y[%d]: %d \r\n", i, dot_x[i], i, dot_y[i]);
    //             draw_dot(dot_x[i], dot_y[i],YELLOW);
    //         }

    //         for(int i = 1; i < N - 2; i++) 
    //         {
    //             draw_line(dot_x[i-1], dot_y[i-1], dot_x[i], dot_y[i],YELLOW);
    //         }
    //     }
    // }
   
}

/*  示波器显示  */
void show_scope(void)
{
    show_curve(AMPLITUDE);
    show_curve(PHASE);

    clear_scr();
    delay_ms(50);

    cursor_present();
}

/*  把采样点里的数据映射成(x,y) */
void coordinate_conversion(void)
{   
    // /*  开始接收数据，数据缓冲区未满    */
    // receive_completed = false;
    // if(!receive_completed)
    // {
    //         for(int i = 0; i < N; i++)
    //         {
    //             Amplitude[i] = SamplePoints[i].gain_db;
    //             Phase[i] = SamplePoints[i].phase_deg;
    //         }
    //         /*  接收数据完，数据缓冲区满，可以打印    */
    //         receive_completed = true;          
    // }
    amp_point[freq_index].X = pha_point[freq_index].X = freq_index;
    amp_point[freq_index].Y = AMP_Y_STANDARD + HEIGHT - SamplePoints[freq_index].gain_db;
    pha_point[freq_index].Y = PHA_Y_STANDARD + HEIGHT - SamplePoints[freq_index].phase_deg;
    
}

void test(void)
{
    receive_completed = true;
    //cursor_init();
    double x = 0.0;
    for(int i = 0; i < N; i++)
    {
        Amplitude[i] = 100 * sin(2 * PI *x) + 100;
        Phase[i] = x;
        x++;
    }

    //show_scope(AMPLITUDE);
    //show_scope(PHASE);
    clear_scr();
    delay_ms(50);

    cursor_present();
}