/**
 * @file FREQ_DECODER.c
 * @author Kleeper
 * @brief 频率计解码
 * @version 0.1
 * @date 2025-04-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "FREQ_DECODER.h"

volatile uint8_t stage = 0;
volatile uint8_t LCD_Byte = '\0';
volatile unsigned char LCD_Data[30] = {[0]='\0'};
volatile unsigned char* LCD_Data_p = LCD_Data;
volatile uint8_t decode_done = 0;


uint16_t freq2index(float freq) {
		if(freq < 1.0 || freq >= 43.0) {
			return 0;
		}
		uint16_t temp = (freq - 1.0) / 0.5f;
		return temp;
}

float vol2gain(float voltage) {
		return voltage / 30 - 30;
}

float vol2deg(float voltage) {
		return -voltage / 10 + 180;
}

float getFreq() {
		return findFloat(LCD_Data_p);
}

float findFloat(unsigned char* str) {
    double num = 0;
    int divisor = 1;
    unsigned char inPart = 1;
    while(*str != '\0') {
        if(*str == '.') {
            inPart = 0;
            str++;
        }
        if(*str >= '0' && *str <= '9') {
            if(inPart == 0) {
                divisor *= 10;
                num += (double)(*str - '0') / divisor;
            }
            else {
                num = num * 10 + *str - '0';
            }
        }
        str++;
    }
    return num;
}

/**
 * @brief 频率计解码
 * 
 */
void freq_fetch(void)
{
    if (E == GPIO_FREQ_DECODER_E_PIN) 
    {
        if(stage == 0)
        {
            uint8_t db4 = (DB4 >> 1);
            uint8_t db5 = (DB5 >> 28); 
            uint8_t db6 = (DB6 >> 31); 
            uint8_t db7 = DB7 >> 5; 

            LCD_Byte = '\0';
            LCD_Byte += (db4 << 4);
            LCD_Byte += (db5 << 5);
            LCD_Byte += (db6 << 6);
            LCD_Byte += (db7 << 7);
            if(LCD_Byte == 128)
            {
                stage = 1;
            }
            
        }
        else if(stage == 1)
        {
            uint8_t db4 = DB4 >> 1;
            uint8_t db5 = DB5 >> 28; 
            uint8_t db6 = DB6 >> 31; 
            uint8_t db7 = DB7 >> 5; 

            //sendStr("try to syn");
            LCD_Byte += db4;
            LCD_Byte += (db5 << 1);
            LCD_Byte += (db6 << 2);
            LCD_Byte += (db7 << 3);
            if(LCD_Byte == 128)
            {
                stage = 2;
                //sendString("LCD Start\r\n");
            }
            else
            {
                stage = 0;
            }
        }
        else if(stage == 2)
        {
            uint8_t db4 = DB4 >> 1;
            uint8_t db5 = DB5 >> 28; 
            uint8_t db6 = DB6 >> 31; 
            uint8_t db7 = DB7 >> 5; 

            LCD_Byte = '\0';
            LCD_Byte += (db4 << 4);
            LCD_Byte += (db5 << 5);
            LCD_Byte += (db6 << 6);
            LCD_Byte += (db7 << 7);
            //LCD_Data_p = LCD_Data;
            stage = 3;
            
        }
        else if(stage == 3)
        {
            uint8_t db4 = DB4 >> 1;
            uint8_t db5 = DB5 >> 28; 
            uint8_t db6 = DB6 >> 31; 
            uint8_t db7 = DB7 >> 5; 

            LCD_Byte += db4;
            LCD_Byte += (db5 << 1);
            LCD_Byte += (db6 << 2);
            LCD_Byte += (db7 << 3);
            //sendData('\r');
            //sendData('\r');sendData('\n');
            //sendStr("the end");
            if(LCD_Byte == 192)
            {
                stage = 0;
                *LCD_Data_p = '\0';
                LCD_Data_p = LCD_Data;
                decode_done = 1;
                //sendString("LCD Done\r\n");
            }
            else
            {
                stage = 2;
                *LCD_Data_p = LCD_Byte;
                LCD_Data_p++;
            }
        }
    }
}