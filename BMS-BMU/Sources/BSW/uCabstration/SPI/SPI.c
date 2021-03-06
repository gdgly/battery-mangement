/*=======================================================================
 *Subsystem:   裸机
 *File:        SPI.C
 *Author:      Wenming
 *Description: 通信：
               接口：
               波特率：
 ========================================================================
 * History:    修改历史记录列表
 * 1. Date:
      Author:
      Modification:
========================================================================*/

#include "SPI.h"

/*=======================================================================
 *函数名:      SPI1_Init(void) 
 *功能:        SPI1初始化
 *参数:        无       
 *返回：       无
 *说明：       通信波特率:1Mhz
               SPI初始化首先需要片选
========================================================================*/
uint8 SPI1_Init(void) 
{
   SPI1CR1=0b01011100;
   SPI1CR2=0x00;
   SPI1BR=0x71; //1MHz波特率
 
   return 0;
}
                           
/*=======================================================================
 *函数名:      SPI1_Write(uint8) 
 *功能:        SPI1写数据函数
 *参数:        data：要写的8位数据       
 *返回：       无
 *说明：       SPI1写数据函数
========================================================================*/
void SPI1_Write(uint8 data) 
{
  while(!SPI1SR_SPTEF);                // 每次只能发送一个字节的数据；
  SPI1DRL = data;
}

/*=======================================================================
 *函数名:      SPI1_read(void) 
 *功能:        SPI1读数据函数
 *参数:        无       
 *返回：       无
 *说明：       SPI1读数据函数
========================================================================*/
uint8 SPI1_read(void) 
{
  uint8 temp2,returndata;
 
  while(!SPI1SR_SPIF) 
  temp2 = SPI1SR;   
  
  returndata = SPI1DRL;           //读取数据
  return(returndata); 
}


    
 
