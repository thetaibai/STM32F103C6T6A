/*!
 **********************************************************
 *@file 7SEG.c
 *@brief 7SEG mode core file
 **********************************************************
 *@author LHL
 *@version 1.0.0
 *@data 2023.8.1
 *
 *
 **********************************************************
 **/

#include "7SEG.h"

/* Four SEG state */
unsigned char SEG_Value[SEG_Num] =
{
		SEG_ZERO_POINT,
		SEG_ONE_POINT,
		SEG_TWO_POINT,
		SEG_THREE_POINT
};

/*  */
static void SEG_Function_1(void);
static void SEG_Function_2(void);
static void SEG_Function_3(void);
static void SEG_Function_4(void);
static void SEG_Set_Value(unsigned char Value);

/*!
 ***********************************************************
 *@brief SEG Main Function
 *
 *The function need be ported to OS Task endless loop.
 *
 ***********************************************************
 **/
void SEG_MainFunction(void)
{
	static unsigned char Count = 1;

	if (SEG_Num >= Count)
	{
		Count++;
	}
	else
	{
		Count = 1;
	}

	switch(Count)
	{
		case 1:SEG_Function_1();break;
		case 2:SEG_Function_2();break;
		case 3:SEG_Function_3();break;
		case 4:SEG_Function_4();break;
	}

}

/*!
 ***********************************************************
 *@brief SEG Function
 *
 * Set SEG State For First SEG.
 *
 ***********************************************************
 **/
static void SEG_Function_1(void)
{

	SEG_1_Clear();
	SEG_2_Set();
	SEG_3_Set();
	SEG_4_Set();

	SEG_Set_Value(SEG_Value[SEG_Index1]);

}

/*!
 ***********************************************************
 *@brief SEG Function
 *
 * Set SEG State For Second SEG.
 *
 ***********************************************************
 **/
static void SEG_Function_2(void)
{

	SEG_1_Set();
	SEG_2_Clear();
	SEG_3_Set();
	SEG_4_Set();

	SEG_Set_Value(SEG_Value[SEG_Index2]);

}

/*!
 ***********************************************************
 *@brief SEG Function
 *
 * Set SEG State For Third SEG.
 *
 ***********************************************************
 **/
static void SEG_Function_3(void)
{

	SEG_1_Set();
	SEG_2_Set();
	SEG_3_Clear();
	SEG_4_Set();

	SEG_Set_Value(SEG_Value[SEG_Index3]);

}

/*!
 ***********************************************************
 *@brief SEG Function
 *
 * Set SEG State For Fourth SEG.
 *
 ***********************************************************
 **/
static void SEG_Function_4(void)
{

	SEG_1_Set();
	SEG_2_Set();
	SEG_3_Set();
	SEG_4_Clear();

	SEG_Set_Value(SEG_Value[SEG_Index4]);

}

/*!
 ***********************************************************
 *@brief SEG Read Set Function
 *
 * Set SEG State For  A、B、C、D、E、F、G、DP.
 *
 ***********************************************************
 **/
static void SEG_Set_Value(unsigned char Value)
{
	if (1 == (Value & 0x01))
	{
		SEG_A_Set(SEG_Set);
	}
	else
	{
		SEG_A_Set(SEG_Clear);
	}

	if (1 == ((Value & 0x02) >> 1))
	{
		SEG_B_Set(SEG_Set);
	}
	else
	{
		SEG_B_Set(SEG_Clear);
	}

	if (1 == ((Value & 0x04) >> 2))
	{
		SEG_C_Set(SEG_Set);
	}
	else
	{
		SEG_C_Set(SEG_Clear);
	}

	if (1 == ((Value & 0x08) >> 3))
	{
		SEG_D_Set(SEG_Set);
	}
	else
	{
		SEG_D_Set(SEG_Clear);
	}

	if (1 == ((Value & 0x10) >> 4))
	{
		SEG_E_Set(SEG_Set);
	}
	else
	{
		SEG_E_Set(SEG_Clear);
	}

	if (1 == ((Value & 0x20) >> 5))
	{
		SEG_F_Set(SEG_Set);
	}
	else
	{
		SEG_F_Set(SEG_Clear);
	}

	if (1 == ((Value & 0x40) >> 6))
	{
		SEG_G_Set(SEG_Set);
	}
	else
	{
		SEG_G_Set(SEG_Clear);
	}

	if (1 == ((Value & 0x80) >> 7))
	{
		SEG_DP_Set(SEG_Set);
	}
	else
	{
		SEG_DP_Set(SEG_Clear);
	}
}
