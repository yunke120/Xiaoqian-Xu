#ifndef __BSP_DS18B20_H__
#define __BSP_DS18B20_H__

#include "main.h"
#include "sys.h"

#define DS18B20_IO_IN()  {GPIOB->CRH &= 0xFFF0FFFF;	GPIOB->CRH |= 8 << 16;}	// PB12 IN  MODE
#define DS18B20_IO_OUT() {GPIOB->CRH &= 0xFFF0FFFF;	GPIOB->CRH |= 3 << 16;}	// PB12 OUT MODE 

// IO��������											   
#define	DS18B20_DQ_OUT PBout(12) 			// ���ݶ˿�	PA4
#define	DS18B20_DQ_IN  PBin(12)  			// ���ݶ˿�	PA4



// IO�������� PB12
//#define DS18B20_IO_IN()  {DQ_GPIO_Port->CRL &= 0xFFF0FFFF;	DQ_GPIO_Port->CRL |= 8 << 16;}	// PB12 IN  MODE
//#define DS18B20_IO_OUT() {DQ_GPIO_Port->CRL &= 0xFFF0FFFF;	DQ_GPIO_Port->CRL |= 3 << 16;}	// PB12 OUT MODE 

//// IO��������											   
//#define	DS18B20_DQ_OUT PAout(4) 			// ���ݶ˿�	PA4
//#define	DS18B20_DQ_IN  PAin(4)  			// ���ݶ˿�	PA4
   	
uint8_t DS18B20_Init(void);					// ��ʼ��DS18B20
short 	DS18B20_Get_Temp(void);				// ��ȡ�¶�
void 	DS18B20_Start(void);				// ��ʼ�¶�ת��
void 	DS18B20_Write_Byte(uint8_t dat);	// д��һ���ֽ�
uint8_t DS18B20_Read_Byte(void);			// ����һ���ֽ�
uint8_t DS18B20_Read_Bit(void);				// ����һ��λ
uint8_t DS18B20_Check(void);				// ����Ƿ����DS18B20
void 	DS18B20_Rst(void);					// ��λDS18B20    

#endif /* __BSP_DS18B20_H__ */

