
#include "delay.h"

void delay_us(uint32_t us)
{
    uint32_t delay = (HAL_RCC_GetHCLKFreq() / 4000000 * us);
    while (delay--);
}

void delay_ms(uint16_t ms)
{
	uint32_t i;
	for(i=0; i < ms; i++) delay_us(1000);
}

