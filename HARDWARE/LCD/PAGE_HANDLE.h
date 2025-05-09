/*

*/

#ifndef __PAGE_HANDLE_H__
#define __PAGE_HANDLE_H__

#include <stdio.h>
#include "tjc_usart_hmi.h"
#include "HMI_GUI.h"
#include "./BTN/BTN.h"
#include "./UART/UART.h"

/*  以下代码只在上电时运行一次,一般用于全局变量定义和上电初始化数据
 *   int sys0=0,sys1=0,sys2=0     //全局变量定义目前仅支持4字节有符号整形(int),不支持其他类型的全局变量声明,
 *                                   如需使用字符串类型可以在页面中使用变量控件来实现
 *   baud=115200//配置波特率
 *   dim=100//配置屏幕背光
 *   recmod=0//串口协议模式:0-字符串指令协议;1-主动解析协议
 *   bkcmd=2
 *   printh 00 00 00 ff ff ff 88 ff ff ff//输出上电信息到串口
 *   page 0                       //上电刷新第0页    
 */

//页面索引
extern int page_index;
enum Pages
{
    main_page,scope,new_scope
};
/*  电路参数    */
typedef struct Circuit_Parameter
{
    float Ri;   //输入电阻
    float Ro;   //输出电阻
    float Av;   //1kHz增益
    float fh;   //上截止频率
}cir_param_t;

/*  数据处理 & 指令解析    */
void Data_Handler(void);

/*****  页面处理    ******/
void Page_Handler(void);                //页面综合处理函数
void Param_update(cir_param_t p);       //参数更新


#endif