#include"I2C.h"
#include<stdint.h>

//延时函数，满足I2C时序要求
static void I2C_Delay(void)
{
    unit8_t i;
    for(i=0;i<10;i++0);
}

//设置I2C起始条件:SCL为高电平时，SDA由高电平转向低电平
void I2C_Start(void)
{
    SDA_High();
    SCL_High();
    I2C_Delay();

    SDA_Low();
    I2C_Delay();

    SCL_Low();
    I2C_Delay();
}

//设置I2C终止条件：SCL为高电平时，SDA由低电平转向高电平
void I2C_Stop(void)
{
    SCL_Low();
    SDA_LOW();
    I2C_Delay();

    SCL_High();
    I2C_Delay();

    SDA_High();
    I2C_Delay();
}

//发送一个字节数据
void I2C_SendByte(Uint8_t date)
{
    uint8_t i;

    //逐位发送数据
    for ( i = 0; i < 8; i++)
    {
        if(date & 0x80)
        {
            SDA_High();
        }
        else
        {
            SDA_Low();
        }

        I2C_Delay();
        
        //时钟线置高，从机读取数据
        SCL_High();
        I2C_Delay();

        //时钟线置低，准备下一位数据
        SCL_Low();
        data <<= 1;
    }
    //调高SDA线，准备接收应答
    SDA_High();
    I2C_Delay();
}

//接收应答信号，0表示收到应答，1表示未收到
uint8_t I2C_ReceiveAck(void)
{
    uint8_t ack;

    //时钟线置高，读取应答信号
    SCL_High();
    I2C_Delay();

    //读取SDA线状态
    ack = SDA_Read();

    //时钟线置低
    SCL_Low();
    I2C_Delay();

    //返回应答状态
    return ack;
}

//完整发送数据流程
void I2C_SendDate(uint8_t data)
{
    I2C_Start();
    I2C_SendByte(date);
    I2C_ReceiveAck();
    I2C_Stop();
}