#ifndef _TM1637_CFG_H
#define _TM1637_CFG_H

#include "IIC.h"

#define TM1637_Start()    IIC_Start()
#define TM1637_Stop()     IIC_Stop()
#define TM1637_ACK()      IIC_ACK()
#define TM1637_WriteByte(x)    IIC_WriteByte(x)

#endif /* _TM1637_CFG_H */
