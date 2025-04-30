/*

*/

#include "data_presentation.h"

int counter = 0;

char str[BUFFER_LEN_MAX_1];
/**
 * @brief 接收单片机发送来的数据，并将其打印在串口屏波形模块上
 * 
 * @param databuff 
 * @param select 
 */
void data_print(uint8_t* databuff, int select)
{
    /*  循环打印数据至串口屏波形模块    */
    for(int i = 0; i < DATA_LEN_MAX; i++)
    {
        switch(select)
        {
            case AMPLITUDE : {sprintf(str,"add s0.id,0,%d",databuff[i]); tjc_send_string(str); break;}
            case PHASE     : {sprintf(str,"add s1.id,0,%d",databuff[i]); tjc_send_string(str); break;}
        }
        
    }

}
/*****  游标模块    *****/
/*
    ref s0
    add s0.id,0,rand
    doevents
 */

void Cursor_refresh(void)
{
    sprintf(str,"ref s0");
    tjc_send_string(str); 
    
    sprintf(str,"doevents");
    tjc_send_string(str); 
}
/*  旋钮调整游标    */
void Cursor_move(bool dir)
{
    if(dir)
    {
        //Cursor_refresh();
        sprintf(str,"line %d,%d,%d,%d,BLACK",SCOPE_X_STANDARD + counter,SCOPE_Y_STANDARD,SCOPE_X_STANDARD + counter,SCOPE_Y_STANDARD + SCOPE_HEIGHT);
        tjc_send_string(str);
        //counter++;
        counter = (counter + 1) % (SCOPE_WIDTH + 1);
        sprintf(str,"line %d,%d,%d,%d,YELLOW",SCOPE_X_STANDARD + counter,SCOPE_Y_STANDARD,SCOPE_X_STANDARD + counter,SCOPE_Y_STANDARD + SCOPE_HEIGHT);
        tjc_send_string(str);
    }
    else 
    {
        //Cursor_refresh();
        sprintf(str,"line %d,%d,%d,%d,BLACK",SCOPE_X_STANDARD + counter,SCOPE_Y_STANDARD,SCOPE_X_STANDARD + counter,SCOPE_Y_STANDARD + SCOPE_HEIGHT);
        tjc_send_string(str);
        //counter = (counter + 1) % (WIDTH + 1);
        counter--;
        if(counter < 0) counter = 0;
        sprintf(str,"line %d,%d,%d,%d,YELLOW",SCOPE_X_STANDARD + counter,SCOPE_Y_STANDARD,SCOPE_X_STANDARD + counter,SCOPE_Y_STANDARD + SCOPE_HEIGHT);
        tjc_send_string(str);
    }
}
/*  在固定位置显示游标  */
void Cursor_present(int offset)
{
    sprintf(str,"line %d,%d,%d,%d,YELLOW",SCOPE_X_STANDARD + offset,SCOPE_Y_STANDARD,SCOPE_X_STANDARD + offset,SCOPE_Y_STANDARD + SCOPE_HEIGHT);
    tjc_send_string(str);
}
