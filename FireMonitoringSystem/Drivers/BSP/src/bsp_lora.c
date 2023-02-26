#include "bsp_lora.h"
#include "usart.h"
#include "atk_mw1278d.h"

/**
 * @brief loraģ���ʼ��
 * 
 * @return int 0:��ʼ���ɹ�������:ʧ��
 */
int lora_init()
{
	uint8_t ret;
	
	/* ��ʼ��ATK-MW1278Dģ�� */
    ret = atk_mw1278d_init(115200);
    if (ret != 0)
    {
        printf("ATK-MW1278D init failed!\r\n");
		return 1;
    }
    
    /* ����ATK-MW1278Dģ�� */
    atk_mw1278d_enter_config();
    ret  = atk_mw1278d_addr_config(SLAVE_ADDR);
    ret += atk_mw1278d_wlrate_channel_config(SLAVE_WLRATE, SLAVE_CHANNEL);
    ret += atk_mw1278d_tpower_config(SLAVE_TPOWER);
    ret += atk_mw1278d_workmode_config(SLAVE_WORKMODE);
    ret += atk_mw1278d_tmode_config(SLAVE_TMODE);
    ret += atk_mw1278d_wltime_config(SLAVE_WLTIME);
    ret += atk_mw1278d_uart_config(SLAVE_UARTRATE, SLAVE_UARTPARI);
    atk_mw1278d_exit_config();
    if (ret != 0)
    {
        printf("ATK-MW1278D config failed!\r\n");
		return 2;
    }
    
    printf("ATK-MW1278D config succedded!\r\n");
    atk_mw1278d_uart_rx_restart();
	return 0;
}

/**
 * @brief ͨ��loraģ�鷢����Ϣ
 * 
 * @param buf ������Ϣ������
 * @param len ������Ϣ�ֽڳ���
 */
void lora_send(uint8_t *buf, uint8_t len)
{
	if (atk_mw1278d_free() != ATK_MW1278D_EBUSY)
	{
		HAL_UART_Transmit(&huart2, buf, len, HAL_MAX_DELAY);
	}
}

