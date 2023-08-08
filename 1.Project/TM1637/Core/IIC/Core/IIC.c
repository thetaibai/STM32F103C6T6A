#include "IIC.h"

static void IIC_Delay_us(unsigned int Value);

static void IIC_Delay_us(unsigned int Value)
{
	Value = (unsigned int)(Value * 2);
	while(Value--)
	{
		__asm("nop");
	}
}

void IIC_Start(void)
{
	IIC_DIO_OUT();

	IIC_CLK_Set(1);
	IIC_DIO_Set(1);

	IIC_Delay_us(2);
	IIC_DIO_Set(0);
}

void IIC_Stop(void)
{
	IIC_DIO_OUT();

	IIC_CLK_Set(0);
	IIC_Delay_us(2);
	IIC_DIO_Set(0);

	IIC_Delay_us(2);

	IIC_CLK_Set(1);
	IIC_Delay_us(2);
	IIC_DIO_Set(1);
}

void IIC_ACK(void)
{
	IIC_DIO_IN();

	IIC_CLK_Set(0);
	IIC_Delay_us(5);

	//while(IIC_DIO_Read());

	IIC_CLK_Set(1);
	IIC_Delay_us(2);
	IIC_CLK_Set(0);

}

void IIC_WriteByte(unsigned char Byte)
{
	unsigned char i = 0;

	IIC_DIO_OUT();

	for(i = 0; i < 8; i++)
	{
		IIC_CLK_Set(0);

		if(Byte & 0x01)
		{
			IIC_DIO_Set(1);
		}
		else
		{
			IIC_DIO_Set(0);
		}

		IIC_Delay_us(3);
		Byte = Byte >> 0x01;
		IIC_CLK_Set(1);
		IIC_Delay_us(3);

	}
}
