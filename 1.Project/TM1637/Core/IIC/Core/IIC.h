#ifndef _IIC_H
#define _IIC_H

#include "IIC_Cfg.h"

/* Extern interface */
extern void IIC_Start(void);
extern void IIC_Stop(void);
extern void IIC_ACK(void);
extern void IIC_WriteByte(unsigned char Byte);
#endif /* _IIC_H */
