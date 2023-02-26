#include "bsp_relay.h"


void open_relay(void)
{
	HAL_GPIO_WritePin(Relay_GPIO_Port,Relay_Pin, GPIO_PIN_SET);
}
void close_relay(void)
{
	HAL_GPIO_WritePin(Relay_GPIO_Port,Relay_Pin, GPIO_PIN_RESET);
}