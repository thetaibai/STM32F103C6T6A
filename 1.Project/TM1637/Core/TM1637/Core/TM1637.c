#include "TM1637.h"

void TM1637_DisPlay_NoInc(unsigned char Addr, unsigned char Value)
{
	TM1637_Start();
	TM1637_WriteByte(0x44);
	TM1637_ACK();
	TM1637_Stop();

	TM1637_Start();
	TM1637_WriteByte(0x0C|Addr);
	TM1637_ACK();
	TM1637_Stop();

	TM1637_Start();
	TM1637_WriteByte(Value);
	TM1637_ACK();
	TM1637_Stop();

	TM1637_Start();
	TM1637_WriteByte(0x88|0x07);
	TM1637_ACK();
	TM1637_Stop();
}
