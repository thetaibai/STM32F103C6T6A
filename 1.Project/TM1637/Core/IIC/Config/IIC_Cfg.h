#ifndef _IIC_CFG_H
#define _IIC_CFG_H

#include "main.h"


/* Interface */
#define IIC_CLK_Set(x)    HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, x);
#define IIC_DIO_Set(x)    HAL_GPIO_WritePin(DIO_GPIO_Port, DIO_Pin, x);

#endif /* _IIC_CFG_H */
