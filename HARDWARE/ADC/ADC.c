/**
 * @file ADC.c
 * @author Aiden (aiden.tang0817@outlook.com) & Kleeper
 * @brief ADC模块
 * @version 0.1
 * @date 2025-04-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "ADC.h"

volatile bool gCheckADC = false;

volatile bool uart_rx_finish = false;
volatile bool uart_rx_start = false;
volatile unsigned char uart_rx_buffer[RX_BUFFER_SIZE];
volatile uint8_t uart_rx_index = 0;		        //串口缓冲区索引

extern volatile uint8_t stage;
extern volatile uint8_t LCD_Byte;
extern volatile unsigned char LCD_Data[30];
extern volatile unsigned char* LCD_Data_p;
extern volatile uint8_t decode_done;

uint16_t freq_index = 0;
extern uint8_t freq_count;
extern uint16_t sample_count;
extern uint8_t sample_end;

/**
 * @brief ADC中断请求处理
 * 
 */
void ADC12_0_INST_IRQHandler(void)
{
    switch (DL_ADC12_getPendingInterrupt(ADC12_0_INST)) 
    {
        case DL_ADC12_IIDX_MEM1_RESULT_LOADED:
			DL_GPIO_togglePins(GPIO_LEDS_PORT, GPIO_LEDS_G_PIN);
			//sendString("ADC Interrupt\r\n");
            gCheckADC = true;
            break;
        default:
            break;
    }
}
/**
 * @brief 数据-采样点转换
 * 
 */
 void data_samplepoints_conversion(void)
 {
    if(decode_done && (freq_count++ % 2 != 0)) 
    { //轮询等待读取频率完成
        NVIC_DisableIRQ(GPIO_FREQ_DECODER_INT_IRQN);   //关闭GPIOA Pin E输入中断
        decode_done = 0;
        //频率计读取完毕再开启ADC采样
        DL_ADC12_enableConversions(ADC12_0_INST);
        DL_ADC12_startConversion(ADC12_0_INST);
        while(gCheckADC == false);      //阻塞等待ADC采样完成
        //sendString("ADC Complete\r\n");
        gCheckADC = false;
        //存储该频率下相关的幅频和相频信息
        float frequency = getFreq();
        freq_index = freq2index(frequency);
        SamplePoints[freq_index].freq = frequency;
        sendString("Freq: ");
        char str[20];	
        sprintf(str, "%.2f", frequency);
        sendString(str);	
        sendString("\r\n");
        if(frequency > 42) 
        {
            sample_end = 1;
            NVIC_DisableIRQ(GPIO_FREQ_DECODER_INT_IRQN);
        }
        /*  数据处理，变成采样点    */
        uint16_t vol_db = DL_ADC12_getMemResult(ADC12_0_INST, DL_ADC12_MEM_IDX_0);
        uint16_t vol_deg = DL_ADC12_getMemResult(ADC12_0_INST, DL_ADC12_MEM_IDX_1);
        float gain_db = vol2gain((float)vol_db * 3300 / 4095);
        float gain_deg = vol2deg((float)vol_deg * 3300 / 4095);
        sendString("gain_db: "); sendNum(gain_db);
        sendString("gain_deg: "); sendNum(gain_deg);
        SamplePoints[freq_index].gain_db = gain_db + 20;
        SamplePoints[freq_index].phase_deg = gain_deg;

        /*  把采样的点映射到坐标系  */
        coordinate_conversion();
        //plot_dot();
        instant_show_scope_without_cursor();            

        NVIC_EnableIRQ(GPIO_FREQ_DECODER_INT_IRQN);    //开启GPIOA Pin E输入中断
    }
 }

 