#include "bsp_zp13.h"

/**
 * @brief 判断是否有烟雾
 * 
 * @return uint8_t 1:有，0:无
 */
uint8_t exist_smoke(void)
{
	return HAL_GPIO_ReadPin(ZP_GPIO_Port, ZP_Pin);
}