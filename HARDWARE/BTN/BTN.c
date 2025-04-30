#include "BTN.h"

BTNTick_t BTNTick = {0};
BTNData_t BTNData = {0};

int count = 0;

void BTN_getData(BTNData_t* data) {
    if (BTN_LEFT_PRESS && !BTNTick.left) {
        BTNTick.left = BTN_DEBOUNCE_TIME;
        data->left = 1;
    }
    else {
        data->left = 0;
    }
    if (BTN_DOWN_PRESS && !BTNTick.down) {
        BTNTick.down = BTN_DEBOUNCE_TIME;
        data->down = 1;
    }
    else {
        data->down = 0;
    }
    if (BTN_RIGHT_PRESS && !BTNTick.right) {
        BTNTick.right = BTN_DEBOUNCE_TIME;
        data->right = 1;
    }
    else {
        data->right = 0;
    }
    if (BTN_UP_PRESS && !BTNTick.up) {
        BTNTick.up = BTN_DEBOUNCE_TIME;
        data->up = 1;
    }
    else {
        data->up = 0;
    }
    if (BTN_MID_PRESS && !BTNTick.mid) {
        BTNTick.mid = BTN_DEBOUNCE_TIME;
        data->mid = 1;
    }
    else {
        data->mid = 0;
    }
}

/*  按钮操作    */
void BTN_act(void)
{
    BTN_getData(&BTNData);
    if(BTNData.left)
	{
        DL_GPIO_togglePins(GPIO_LEDS_PORT, GPIO_LEDS_LED_PIN);
        count += 1;
        DAC_OUTPUT();
    }
	if(BTNData.right)
	{
        DL_GPIO_togglePins(GPIO_LEDS_PORT, GPIO_LEDS_LED_PIN);
        count -= 1;
		if(count < 0) count = 0;
        DAC_OUTPUT();				
	}				
}