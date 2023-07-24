/*!
 **********************************************************
 *@file Button.h
 *@brief Button' head file
 **********************************************************
 *@author LHL
 *@version 1.0.0
 *@data 2023.7.24
 *
 *
 **********************************************************
 **/

#ifndef BUTTON_H
#define BUTTON_H

#include "main.h"
#include "Button_if.h"


struct ButtonT
{
	unsigned char PinState;	/* 按键当前状态 */
	unsigned char State;	/* 按键当前状态 */
	unsigned char PreState;	/* 按键前周期状态 */
	unsigned char Cnt;	/* 按键前周期状态 */
};

enum KEY_enum
{
	Key1 = 0,
	Key2 = 1,
	Key3 = 2,
	Key4 = 3,
	Key5 = 4,
	Key6 = 5,
	Key7 = 6,

	KeyNum = 7
};

enum
{
	NoPress = 0,
	Press = 1
};

extern void ButtonTask(void);
extern struct ButtonT ButtonTable[KeyNum];

#endif
