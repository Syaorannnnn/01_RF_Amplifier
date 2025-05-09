/**
 * @file PAGE_HANDLE.c
 * @author Aiden 
 * @brief 页面功能处理
 * @version 0.1
 * @date 2025-05-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "PAGE_HANDLE.h"

enum Pages pages;
extern uint8_t sample_end;
int page_index = 0;

cir_param_t cp = {0};

/**
 * @brief 串口屏发送的数据解析函数
 * 指令类型暂时分为两类：
 * 串口屏内部的控件（比如按钮）执行功能后，通过printh指令向单片机返回数据，指令末尾格式为0xff 0xff 0xff
 * 单片机向串口屏输送的指令因初始化设置bkcmd = 2，串口屏不再返回任何数据作为执行成功的应答
 * 
 */
void Data_Handler()
{
    uint16_t data_len = getRingBuffLength();
    if(u(data_len-1) == 0xff && u(data_len-2) == 0xff && u(data_len-3) == 0xff) 
    {
        //数据有效
        sendString("The command is legal!");
        //
        if(u(0) == u(1) == u(2) == 0x00)    {   }
        //上电成功的信息
        else if (u(0) == 0x88)              {sendString("Screen opens successfully.");}
        /*  按钮事件返回数据
         *  0xaa : 主页
         *  0xbb : 示波器页面
         */
        else if(u(0) == 0xaa)
        {
            sendString("Turn to the main page.");
            page_index = main_page;
        }
        else if(u(0) == 0xbb)
        {
            sendString("Turn to the scope page."); 
            page_index = scope;
        }
        else if(u(0) == 0xcc)
        {
            sendString("Turn to the new scope page."); 
            page_index = new_scope;
        }
    }
    
    else
    {
        //数据无效
        sendString("The command is illegal!");       
    }
    //删除解析过的数据
    udelete(data_len);    
}

/**
 * @brief 页面综合处理函数
 * 
 */
void Page_Handler()
{
    Data_Handler();
    switch(page_index)
    {
        case main_page : 
            BTN_act(); 
            break;                         
        case scope : 
            if(!sample_end) 
            {
                //show_scope_without_cursor();
                break;
            } 
            else 
            {
                static_show_scope();
                break;
            }
        case new_scope :
            break;           
    }
}

void Param_update(cir_param_t p)
{
    char str[15];
    sprintf(str, "Ri.txt=\"%.2f\"",p.Ri);
    tjc_send_string(str);
    sprintf(str, "Ro.txt=\"%.2f\"",p.Ro);
    tjc_send_string(str);
    sprintf(str, "Av.txt=\"%.2f\"",p.Av);
    tjc_send_string(str);
    sprintf(str, "fh.txt=\"%.2f\"",p.fh);
    tjc_send_string(str);   
}
