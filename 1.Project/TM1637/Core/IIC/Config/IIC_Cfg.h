#ifndef _IIC_CFG_H
#define _IIC_CFG_H

#include "main.h"


/* Interface */
#define IIC_CLK_Set(x)    HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, x)
#define IIC_DIO_Set(x)    HAL_GPIO_WritePin(DIO_GPIO_Port, DIO_Pin, x)
#define IIC_DIO_Read()    HAL_GPIO_ReadPin(DIO_GPIO_Port, DIO_Pin)

#define   IIC_DIO_OUT()   GPIOB->CRL=(GPIOB->CRL&(~(0x0000000F)))|0x00000003 //推挽输出
#define   IIC_DIO_IN()    GPIOB->CRL=(GPIOB->CRL&(~(0x0000000F)))|0x00000004 //浮空输入

#endif /* _IIC_CFG_H */
