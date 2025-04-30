/*

*/

#ifndef __ADC_H__
#define __ADC_H__

#include "ti_msp_dl_config.h"
#include "../FREQ_DECODER/FREQ_DECODER.h"
#include "../LCD/HMI_GUI.h"

extern volatile bool gCheckADC;
/*  数据-采样点转换 */
void data_samplepoints_conversion(void);

#endif