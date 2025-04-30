/*

*/

#ifndef __FREQ_DECODER_H__
#define __FREQ_DECODER_H__


#include "ti_msp_dl_config.h"
#include "stdio.h"

#define SAMPLE_SIZE	 210		//1-43MHz，每隔0.2MHz采样一次
#define RX_BUFFER_SIZE	30	    //串口接收缓冲区大小

#define E     DL_GPIO_readPins(GPIO_FREQ_DECODER_PORT, GPIO_FREQ_DECODER_E_PIN)
#define DB4   DL_GPIO_readPins(GPIO_FREQ_DECODER_PORT, GPIO_FREQ_DECODER_DB4_PIN)
#define DB5   DL_GPIO_readPins(GPIO_FREQ_DECODER_PORT, GPIO_FREQ_DECODER_DB5_PIN)
#define DB6   DL_GPIO_readPins(GPIO_FREQ_DECODER_PORT, GPIO_FREQ_DECODER_DB6_PIN)
#define DB7   DL_GPIO_readPins(GPIO_FREQ_DECODER_PORT, GPIO_FREQ_DECODER_DB7_PIN)

typedef struct{
	float freq;
	float gain_db;
	float phase_deg;
}AmpPoint;

volatile AmpPoint SamplePoints[SAMPLE_SIZE];	//放大器对应频率的幅频相频信息

uint16_t freq2index(float freq);
void sendNum(float freq);
void sendString(char* p);
void sendData(uint8_t data);
float getFreq();
float vol2gain(float voltage);
float vol2deg(float voltage);
float findFloat(unsigned char* str);

void freq_fetch(void);

#endif