/**
 * @file UART.c
 * @author Aiden 
 * @brief 串口功能模块
 * @version 0.1
 * @date 2025-05-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "UART.h"

void sendData(uint8_t data) {
    while(DL_UART_isBusy(UART_1_INST));
    DL_UART_Main_transmitData(UART_1_INST, data);
}

void sendString(char* p) {
		while(*p != '\0') {
			sendData(*p);
			p++;
		}
}

void sendNum(float num) {
	char str[30];
    sprintf(str, "%5.2f\r\n", num);
    sendString(str);
}

/**
 * @brief 串口中断请求处理函数
 * 
 */
void UART_0_INST_IRQHandler(void)
{
	// 如果产生了串口中断
	switch (DL_UART_Main_getPendingInterrupt(UART_0_INST))
	{
	case DL_UART_MAIN_IIDX_RX: // 如果是接收中断
		// 接发送过来的数据保存在变量中
		uart_data = DL_UART_Main_receiveData(UART_0_INST);
		writeRingBuff(uart_data);

		break;

	default: // 其他的串口中断
		break;
	}
}