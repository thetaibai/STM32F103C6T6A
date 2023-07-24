#include "LED.h"


void LED_Task(void)
{
	unsigned char i;

	for(i = 0; i < 7; i++)
	{
		if (Press == GetButtonState(0))
		{
			SetLED();
		}
		else
		{
			ClearLED();
		}
	}
}
