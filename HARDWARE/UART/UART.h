/*
*/
#ifndef __UART_H__
#define __UART_H__

#include "ti_msp_dl_config.h"
#include <stdio.h>
#include "./LCD/tjc_usart_hmi.h"

volatile uint8_t uart_data;

void sendData(uint8_t data);
void sendString(char* p);

#endif