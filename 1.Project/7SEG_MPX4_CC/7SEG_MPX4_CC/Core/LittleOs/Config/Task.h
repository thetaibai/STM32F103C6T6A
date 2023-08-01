/*!
 **********************************************************
 *@file Task.h
 *@brief Task mode'head file
 **********************************************************
 *@author LHL
 *@version 1.0.0
 *@data 2023.7.17
 *
 *
 **********************************************************
 **/

#ifndef TASK_H
#define TASK_H

/* User include */
#include "7SEG.h"

enum TaskIdT
{
	TaskId_1ms,
	TaskId_2ms,
	TaskId_4ms1,
	TaskId_8ms3,
	TaskId_8ms7,

	TaskIdNumber
};

struct TaskTableT
{
	enum TaskIdT TaskId;	/* Task Id for loop */
	unsigned char Cycle;	/* Cycle for loop must be as exponent of 2 because Scheduler */
	unsigned char Shifting; /* Offset from start */
	void (*Task)(void);		/* Task Pointer */
};

extern void OS_1ms(void);
extern void OS_2ms(void);
extern void OS_4ms1(void);
extern void OS_8ms3(void);
extern void OS_8ms7(void);
extern void OS_Idle(void);

extern struct TaskTableT TaskTable[TaskIdNumber];

#endif
