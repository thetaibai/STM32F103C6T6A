/*!
 **********************************************************
 *@file Os.c
 *@brief Os mode' heart code
 **********************************************************
 *@author LHL
 *@version 1.0.0
 *@data 2023.7.17
 *
 *
 **********************************************************
 **/

#include "OS.h"

volatile unsigned char LittleHeart = OS_FALSE;

/*!
 **********************************************************
 *@brief OS's Heart Function
 *
 *The function need be ported to timer for 1ms .
 *
 **********************************************************
 **/
void LittleHeartFunc(void)
{
	LittleHeart = 1;
}

/*!
 ***********************************************************
 *@brief OS dispatch Function
 *
 *The function need be ported to main function endless loop.
 *
 ***********************************************************
 **/
void OS(void)
{
	static unsigned char HeartCnt = 0;

	if(LittleHeart == OS_TRUE)
	{
		HeartCnt++;
		LittleHeart = OS_FALSE;

		/* Scheduler % --> & */
		for (enum TaskIdT i = TaskId_1ms; i < TaskIdNumber; i++)
		{
			if (TaskTable[i].Shifting == (HeartCnt & (TaskTable[i].Cycle - 1)))
			{
				TaskTable[i].Task();
			}
		}
	}
	else
	{
		OS_Idle();
	}
}

