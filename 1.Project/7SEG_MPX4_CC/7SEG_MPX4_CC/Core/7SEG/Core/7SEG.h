/*!
 **********************************************************
 *@file 7SEG.h
 *@brief 7SEG mode's head file
 **********************************************************
 *@author LHL
 *@version 1.0.0
 *@data 2023.8.1
 *
 *
 **********************************************************
 **/

#ifndef _7SEG_H
#define _7SEG_H

#include "7SEG_Cfg.h"     /* For IO Interface */

/* define */
#define SEG_ONE     (unsigned char)0x06U
#define SEG_TWO     (unsigned char)0x5BU
#define SEG_THREE   (unsigned char)0x4FU
#define SEG_FOUR    (unsigned char)0x66U
#define SEG_FIVE    (unsigned char)0x6DU
#define SEG_SIX     (unsigned char)0x7DU
#define SEG_SEVEN   (unsigned char)0x07U
#define SEG_EIGHT   (unsigned char)0x7FU
#define SEG_NINE    (unsigned char)0x6FU
#define SEG_ZERO    (unsigned char)0x3FU

#define SEG_ONE_POINT     (unsigned char)0x86U
#define SEG_TWO_POINT     (unsigned char)0xDBU
#define SEG_THREE_POINT   (unsigned char)0xCFU
#define SEG_FOUR_POINT    (unsigned char)0xE6U
#define SEG_FIVE_POINT    (unsigned char)0xEDU
#define SEG_SIX_POINT     (unsigned char)0xFDU
#define SEG_SEVEN_POINT   (unsigned char)0x87U
#define SEG_EIGHT_POINT   (unsigned char)0xFFU
#define SEG_NINE_POINT    (unsigned char)0xEFU
#define SEG_ZERO_POINT    (unsigned char)0xBFU

#define SEG_Index1    0u
#define SEG_Index2    1u
#define SEG_Index3    2u
#define SEG_Index4    3u

#define SEG_Num     4u

#define SEG_Set    0u
#define SEG_Clear    1u

/* Extern interface */
extern void SEG_MainFunction(void);
extern unsigned char SEG_Value[SEG_Num];

#endif  /*_7SEG_H */
