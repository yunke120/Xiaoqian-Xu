#ifndef __BSP_DS18B20_H__
#define __BSP_DS18B20_H__

#include "main.h"
#include "sys.h"

#define DS18B20_IO_IN()  {GPIOB->CRH &= 0xFFF0FFFF;	GPIOB->CRH |= 8 << 16;}	// PB12 IN  MODE
#define DS18B20_IO_OUT() {GPIOB->CRH &= 0xFFF0FFFF;	GPIOB->CRH |= 3 << 16;}	// PB12 OUT MODE 

// IO操作函数											   
#define	DS18B20_DQ_OUT PBout(12) 			// 数据端口	PA4
#define	DS18B20_DQ_IN  PBin(12)  			// 数据端口	PA4



// IO方向设置 PB12
//#define DS18B20_IO_IN()  {DQ_GPIO_Port->CRL &= 0xFFF0FFFF;	DQ_GPIO_Port->CRL |= 8 << 16;}	// PB12 IN  MODE
//#define DS18B20_IO_OUT() {DQ_GPIO_Port->CRL &= 0xFFF0FFFF;	DQ_GPIO_Port->CRL |= 3 << 16;}	// PB12 OUT MODE 

//// IO操作函数											   
//#define	DS18B20_DQ_OUT PAout(4) 			// 数据端口	PA4
//#define	DS18B20_DQ_IN  PAin(4)  			// 数据端口	PA4
   	
uint8_t DS18B20_Init(void);					// 初始化DS18B20
short 	DS18B20_Get_Temp(void);				// 获取温度
void 	DS18B20_Start(void);				// 开始温度转换
void 	DS18B20_Write_Byte(uint8_t dat);	// 写入一个字节
uint8_t DS18B20_Read_Byte(void);			// 读出一个字节
uint8_t DS18B20_Read_Bit(void);				// 读出一个位
uint8_t DS18B20_Check(void);				// 检测是否存在DS18B20
void 	DS18B20_Rst(void);					// 复位DS18B20    

#endif /* __BSP_DS18B20_H__ */

