
#include "bsp_hcsr501.h"

/**
 * @brief �ж��Ƿ�����
 * 
 * @return uint8_t 1:���ˣ�0:����
 */
uint8_t exist_people(void)
{
	return HAL_GPIO_ReadPin(SR_GPIO_Port, SR_Pin);
}