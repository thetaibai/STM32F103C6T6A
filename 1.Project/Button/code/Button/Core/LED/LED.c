#include "LED.h"


void LED_Task(void)
{
	unsigned char i;

	for(i = 0; i < 7; i++)
	{
		if (Press == GetButtonState(i))
		{
			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		}
	}
}
