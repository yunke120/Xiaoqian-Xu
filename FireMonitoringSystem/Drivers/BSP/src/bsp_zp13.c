#include "bsp_zp13.h"

/**
 * @brief �ж��Ƿ�������
 * 
 * @return uint8_t 1:�У�0:��
 */
uint8_t exist_smoke(void)
{
	return HAL_GPIO_ReadPin(ZP_GPIO_Port, ZP_Pin);
}