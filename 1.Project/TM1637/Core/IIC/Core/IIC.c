#include "IIC.h"

void IIC_Delay_us(unsigned int Value)
{
	Value = Value * 13;
	while(Value--)
	{
		__asm("nop");
	}
}
