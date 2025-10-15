#ifndef _I2C_H_
#define _I2C_H_

#include"RM.h"
#include"I2c.h"


void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(uint8_t data);
uint8_t I2C_ReceiveAck(void);
void I2C_SendData(uint8_t data);

#endif

