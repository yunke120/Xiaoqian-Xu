
#include "bsp_hcsr501.h"

/**
 * @brief 判断是否有人
 * 
 * @return uint8_t 1:有人，0:无人
 */
uint8_t exist_people(void)
{
	return HAL_GPIO_ReadPin(SR_GPIO_Port, SR_Pin);
}