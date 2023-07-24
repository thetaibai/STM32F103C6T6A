#ifndef LED_IF_H
#define LED_IF_H

#include "main.h"
#include "Button.h"

#define SetLED() HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
#define ClearLED() HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
#define GetButtonState(x)    ButtonTable[x].State

#endif
