#include "Button.h"

struct ButtonT ButtonTable[KeyNum] =
{
		{GPIO_PIN_RESET,NoPress, NoPress, 0},
		{GPIO_PIN_RESET,NoPress, NoPress, 0},
		{GPIO_PIN_RESET,NoPress, NoPress, 0},
		{GPIO_PIN_RESET,NoPress, NoPress, 0},
		{GPIO_PIN_RESET,NoPress, NoPress, 0},
		{GPIO_PIN_RESET,NoPress, NoPress, 0},
		{GPIO_PIN_RESET,NoPress, NoPress, 0}
};

void ButtonInit(void);
static void GetPinState(void);
void ButtonTask(void);

void ButtonInit(void)
{

}

/* runing Task_8ms */
void ButtonTask(void)
{
	unsigned char i;

	GetPinState();
	for(i = Key1; i < KeyNum ; i++)
	{
		if (GPIO_PIN_SET == ButtonTable[i].PinState)
		{
			if(ButtonTable[i].Cnt <= 3)
			{
				ButtonTable[i].Cnt++;
			}
		}
		else if (GPIO_PIN_RESET == ButtonTable[i].PinState)
		{
			ButtonTable[i].Cnt = 0;
		}

		if (3 < ButtonTable[i].Cnt)
		{
			ButtonTable[i].State = Press;
		}
		else
		{
			ButtonTable[i].State = NoPress;
		}
	}
}

static void GetPinState(void)
{
	ButtonTable[Key1].PinState = ReadKey1();
	ButtonTable[Key2].PinState = ReadKey1();
	ButtonTable[Key3].PinState = ReadKey1();
	ButtonTable[Key4].PinState = ReadKey1();
	ButtonTable[Key5].PinState = ReadKey1();
	ButtonTable[Key6].PinState = ReadKey1();
	ButtonTable[Key7].PinState = ReadKey1();
}
