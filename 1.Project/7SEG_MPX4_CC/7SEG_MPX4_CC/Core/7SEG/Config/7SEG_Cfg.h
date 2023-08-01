/*!
 **********************************************************
 *@file 7SEG_Cfg.h
 *@brief 7SEG mode's Interface file
 **********************************************************
 *@author LHL
 *@version 1.0.0
 *@data 2023.8.1
 *
 *
 **********************************************************
 **/

#ifndef _7SEG_CFG_H
#define _7SEG_CFG_H

#include "main.h"



/* Interface */

#define SEG_4_Set()    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET)
#define SEG_4_Clear()    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET)
#define SEG_3_Set()    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET)
#define SEG_3_Clear()    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET)
#define SEG_2_Set()    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_SET)
#define SEG_2_Clear()    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET)
#define SEG_1_Set()    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET)
#define SEG_1_Clear()    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET)

#define SEG_DP_Set(x)    HAL_GPIO_WritePin(SEG_DP_GPIO_Port, SEG_DP_Pin, x)

#define SEG_A_Set(x)    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, x)
#define SEG_B_Set(x)    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, x)
#define SEG_C_Set(x)    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, x)
#define SEG_D_Set(x)    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, x)
#define SEG_E_Set(x)    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, x)
#define SEG_F_Set(x)    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, x)
#define SEG_G_Set(x)    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, x)

#endif    /* 7SEG_CFG_H */
