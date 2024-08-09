#include "iic.h"


/*******************************************************************************
* 函 数 名       : iic_start
* 函数功能		 : 产生IIC起始信号
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void iic_start(void)
{
	IIC_SDA=1;//如果把该条语句放在SCL后面，第二次读写会出现问题
	delay_10us(1);
	IIC_SCL=1;
	delay_10us(1);
	IIC_SDA=0;	//当SCL为高电平时，SDA由高变为低
	delay_10us(1);
	IIC_SCL=0;//钳住I2C总线，准备发送或接收数据
	delay_10us(1);
}

/*******************************************************************************
* 函 数 名         : iic_stop
* 函数功能		   : 产生IIC停止信号   
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void iic_stop(void)
{	
	IIC_SDA=0;//如果把该条语句放在SCL后面，第二次读写会出现问题
	delay_10us(1);
	IIC_SCL=1;
	delay_10us(1);
	IIC_SDA=1;	//当SCL为高电平时，SDA由低变为高
	delay_10us(1);			
}

/*******************************************************************************
* 函 数 名         : iic_ack
* 函数功能		   : 产生ACK应答  
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void iic_ack(void)
{
	IIC_SCL=0;
	IIC_SDA=0;	//SDA为低电平
	delay_10us(1);
   	IIC_SCL=1;
	delay_10us(1);
	IIC_SCL=0;
}

/*******************************************************************************
* 函 数 名         : iic_nack
* 函数功能		   : 产生NACK非应答  
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void iic_nack(void)
{
	IIC_SCL=0;
	IIC_SDA=1;	//SDA为高电平
	delay_10us(1);
   	IIC_SCL=1;
	delay_10us(1);
	IIC_SCL=0;	
}

/*******************************************************************************
* 函 数 名         : iic_wait_ack
* 函数功能		   : 等待应答信号到来   
* 输    入         : 无
* 输    出         : 1，接收应答失败
        			 0，接收应答成功
*******************************************************************************/
u8 iic_wait_ack(void)
{
	u8 time_temp=0;
	
	IIC_SCL=1;
	delay_10us(1);
	while(IIC_SDA)	//等待SDA为低电平
	{
		time_temp++;
		if(time_temp>100)//超时则强制结束IIC通信
		{	
			iic_stop();
			return 1;	
		}			
	}
	IIC_SCL=0;
	return 0;	
}

/*******************************************************************************
* 函 数 名         : iic_write_byte
* 函数功能		   : IIC发送一个字节 
* 输    入         : dat：发送一个字节
* 输    出         : 无
*******************************************************************************/
void iic_write_byte(u8 dat)
{                        
    u8 i=0; 
	   	    
    IIC_SCL=0;
    for(i=0;i<8;i++)	//循环8次将一个字节传出，先传高再传低位
    {              
        if((dat&0x80)>0) 
			IIC_SDA=1;
		else
			IIC_SDA=0;
        dat<<=1; 	  
		delay_10us(1);  
		IIC_SCL=1;
		delay_10us(1); 
		IIC_SCL=0;	
		delay_10us(1);
    }	 
}

/*******************************************************************************
* 函 数 名         : iic_read_byte
* 函数功能		   : IIC读一个字节 
* 输    入         : ack=1时，发送ACK，ack=0，发送nACK 
* 输    出         : 应答或非应答
*******************************************************************************/
u8 iic_read_byte(u8 ack)
{
	u8 i=0,receive=0;
   	
    for(i=0;i<8;i++ )	//循环8次将一个字节读出，先读高再传低位
	{
        IIC_SCL=0; 
        delay_10us(1);
		IIC_SCL=1;
        receive<<=1;
        if(IIC_SDA)receive++;   
		delay_10us(1); 
    }					 
    if (!ack)
        iic_nack();
    else
        iic_ack();  
		  
    return receive;
}
