/*!
 **********************************************************
 *@file Task.c
 *@brief all Task in this file
 **********************************************************
 *@author LHL
 *@version 1.0.0
 *@data 2023.7.17
 *
 *
 **********************************************************
 **/

#include "Task.h"


void OS_1ms(void);
void OS_2ms(void);
void OS_4ms1(void);
void OS_8ms3(void);
void OS_8ms7(void);

struct TaskTableT TaskTable[TaskIdNumber] =
{
	{TaskId_1ms,    1,    0,    OS_1ms},
	{TaskId_2ms, 	2, 	  0, 	OS_2ms},
	{TaskId_4ms1, 	4, 	  1, 	OS_4ms1},
	{TaskId_8ms3, 	8, 	  3, 	OS_8ms3},
	{TaskId_8ms7, 	8, 	  7, 	OS_8ms7}
};

/*!
 **********************************************************
 *@brief Loop in 1ms
 *
 *The function will be call 1ms loop .
 *
 **********************************************************
 **/
void OS_1ms(void)
{
	HAL_GPIO_TogglePin(OS_1ms_GPIO_Port, OS_1ms_Pin);

}

/*!
 **********************************************************
 *@brief Loop in 2ms
 *
 *The function will be call 2ms loop .
 *
 **********************************************************
 **/
void OS_2ms(void)
{
	HAL_GPIO_TogglePin(OS_2ms_GPIO_Port, OS_2ms_Pin);
}

/*!
 **********************************************************
 *@brief Loop in 4ms
 *
 *The function will be call 4ms loop .
 *
 **********************************************************
 **/
void OS_4ms1(void)
{
	HAL_GPIO_TogglePin(OS_4ms1_GPIO_Port, OS_4ms1_Pin);
}

/*!
 **********************************************************
 *@brief Loop in 8ms
 *
 *The function will be call 8ms loop .
 *
 **********************************************************
 **/
void OS_8ms3(void)
{
	HAL_GPIO_TogglePin(OS_8ms3_GPIO_Port, OS_8ms3_Pin);
}

/*!
 **********************************************************
 *@brief Loop in 8ms
 *
 *The function will be call 8ms loop .
 *
 **********************************************************
 **/
void OS_8ms7(void)
{
	HAL_GPIO_TogglePin(OS_8ms7_GPIO_Port, OS_8ms7_Pin);
}

/*!
 **********************************************************
 *@brief Loop in idle
 *
 *The function will be call when idle .
 *
 **********************************************************
 **/
void OS_Idle(void)
{
	//HAL_GPIO_TogglePin(Led5_GPIO_Port, Led5_Pin);
}
