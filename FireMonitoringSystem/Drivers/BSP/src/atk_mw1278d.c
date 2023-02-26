/**
 ****************************************************************************************************
 * @file        atk_mw1278d.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2022-06-21
 * @brief       ATK-MW1278Dģ����������
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� MiniSTM32 V4������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "atk_mw1278d.h"
#include "delay.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief       ATK-MW1278Dģ��Ӳ����ʼ��
 * @param       ��
 * @retval      ��
 */
static void atk_mw1278d_hw_init(void)
{
    GPIO_InitTypeDef gpio_init_struct = {0};
    
    /* ʹ��ʱ�� */
    ATK_MW1278D_AUX_GPIO_CLK_ENABLE();
    ATK_MW1278D_MD0_GPIO_CLK_ENABLE();
    
    /* AUX���� */
    gpio_init_struct.Pin = ATK_MW1278D_AUX_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pull = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(ATK_MW1278D_AUX_GPIO_PORT, &gpio_init_struct);
    
    /* MD0���� */
    gpio_init_struct.Pin = ATK_MW1278D_MD0_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Pull = GPIO_PULLDOWN;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(ATK_MW1278D_MD0_GPIO_PORT, &gpio_init_struct);
    
    ATK_MW1278D_MD0(0);
}

/**
 * @brief       ATK-MW1278Dģ���ʼ��
 * @param       baudrate: ATK-MW1278Dģ��UARTͨѶ������
 * @retval      ATK_MW1278D_EOK  : ATK-MW1278Dģ���ʼ���ɹ�������ִ�гɹ�
 *              ATK_MW1278D_ERROR: ATK-MW1278Dģ���ʼ��ʧ�ܣ�����ִ��ʧ��
 */
uint8_t atk_mw1278d_init(uint32_t baudrate)
{
    uint8_t ret;
    
    atk_mw1278d_hw_init();                          /* Ӳ����ʼ�� */
    atk_mw1278d_uart_init(baudrate);                /* UART��ʼ�� */
    atk_mw1278d_enter_config();                     /* ��������ģʽ */
    ret = atk_mw1278d_at_test();                    /* ATָ����� */
    atk_mw1278d_exit_config();                      /* �˳�����ģʽ */
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ���������ģʽ
 * @param       ��
 * @retval      ��
 */
void atk_mw1278d_enter_config(void)
{
    ATK_MW1278D_MD0(1);
}

/**
 * @brief       ATK-MW1278Dģ���˳�����ģʽ
 * @param       ��
 * @retval      ��
 */
void atk_mw1278d_exit_config(void)
{
    ATK_MW1278D_MD0(0);
}

/**
 * @brief       �ж�ATK-MW1278Dģ���Ƿ����
 * @note        ����ATK-MW1278Dģ����е�ʱ�򣬲��ܷ�������
 * @param       ��
 * @retval      ATK_MW1278D_EOK  : ATK-MW1278Dģ�����
 *              ATK_MW1278D_EBUSY: ATK-MW1278Dģ��æ
 */
uint8_t atk_mw1278d_free(void)
{
    if (ATK_MW1278D_AUX() != 0)
    {
        return ATK_MW1278D_EBUSY;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ��ATK-MW1278Dģ�鷢��ATָ��
 * @param       cmd    : �����͵�ATָ��
 *              ack    : �ȴ�����Ӧ
 *              timeout: �ȴ���ʱʱ��
 * @retval      ATK_MW1278D_EOK     : ����ִ�гɹ�
 *              ATK_MW1278D_ETIMEOUT: �ȴ�����Ӧ��ʱ������ִ��ʧ��
 */
uint8_t atk_mw1278d_send_at_cmd(char *cmd, char *ack, uint32_t timeout)
{
    uint8_t *ret = NULL;
    
    atk_mw1278d_uart_rx_restart();
    atk_mw1278d_uart_printf("%s\r\n", cmd);
    return ATK_MW1278D_EOK;
    if ((ack == NULL) || (timeout == 0))
    {
        return ATK_MW1278D_EOK;
    }
    else
    {
        while (timeout > 0)
        {
            ret = atk_mw1278d_uart_rx_get_frame();
            if (ret != NULL)
            {
				printf("%s", ret);
                if (strstr((const char *)ret, ack) != NULL)
                {
                    return ATK_MW1278D_EOK;
                }
                else
                {
                    atk_mw1278d_uart_rx_restart();
                }
            }
//			else{
//				printf("no ack\r\n");
//			}
            timeout--;
            delay_ms(1);
        }
        
        return ATK_MW1278D_ETIMEOUT;
    }
}

/**
 * @brief       ATK-MW1278Dģ��ATָ�����
 * @param       ��
 * @retval      ATK_MW1278D_EOK  : ATָ����Գɹ�
 *              ATK_MW1278D_ERROR: ATָ�����ʧ��
 */
uint8_t atk_mw1278d_at_test(void)
{
    uint8_t ret;
    uint8_t i;
    
    for (i=0; i<10; i++)
    {
        ret = atk_mw1278d_send_at_cmd("AT", "OK", ATK_MW1278D_AT_TIMEOUT);
        if (ret == ATK_MW1278D_EOK)
        {
            return ATK_MW1278D_EOK;
        }
    }
    
    return ATK_MW1278D_ERROR;
}

/**
 * @brief       ATK-MW1278Dģ��ָ���������
 * @param       enable: ATK_MW1278D_DISABLE: �ر�ָ�����
 *                      ATK_MW1278D_ENABLE : ����ָ�����
 * @retval      ATK_MW1278D_EOK   : ָ��������óɹ�
 *              ATK_MW1278D_ERROR : ָ���������ʧ��
 *              ATK_MW1278D_EINVAL: �����������
 */
uint8_t atk_mw1278d_echo_config(atk_mw1278d_enable_t enable)
{
    uint8_t ret;
    char cmd[5] = {0};
    
    switch (enable)
    {
        case ATK_MW1278D_ENABLE:
        {
            sprintf(cmd, "ATE1");
            break;
        }
        case ATK_MW1278D_DISABLE:
        {
            sprintf(cmd, "ATE0");
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ�������λ
 * @param       ��
 * @retval      ATK_MW1278D_EOK  : �����λ�ɹ�
 *              ATK_MW1278D_ERROR: �����λʧ��
 */
uint8_t atk_mw1278d_sw_reset(void)
{
    uint8_t ret;
    
    ret = atk_mw1278d_send_at_cmd("AT+RESET", "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ�������������
 * @param       enable: ATK_MW1278D_DISABLE: ���������
 *                      ATK_MW1278D_ENABLE : �������
 * @retval      ATK_MW1278D_EOK   : �����������óɹ�
 *              ATK_MW1278D_ERROR : ������������ʧ��
 *              ATK_MW1278D_EINVAL: �����������
 */
uint8_t atk_mw1278d_flash_config(atk_mw1278d_enable_t enable)
{
    uint8_t ret;
    char cmd[11] = {0};
    
    switch (enable)
    {
        case ATK_MW1278D_DISABLE:
        {
            sprintf(cmd, "AT+FLASH=0");
            break;
        }
        case ATK_MW1278D_ENABLE:
        {
            sprintf(cmd, "AT+FLASH=1");
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ��ָ���������
 * @param       ��
 * @retval      ATK_MW1278D_EOK   : �ָ��������óɹ�
 *              ATK_MW1278D_ERROR : �ָ���������ʧ��
 */
uint8_t atk_mw1278d_default(void)
{
    uint8_t ret;
    
    ret = atk_mw1278d_send_at_cmd("AT+DEFAULT", "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ���豸��ַ����
 * @param       addr: �豸��ַ
 * @retval      ATK_MW1278D_EOK   : �豸��ַ���óɹ�
 *              ATK_MW1278D_ERROR : �豸��ַ����ʧ��
 */
uint8_t atk_mw1278d_addr_config(uint16_t addr)
{
    uint8_t ret;
    char cmd[14] = {0};
    
    sprintf(cmd, "AT+ADDR=%02X,%02X", (uint8_t)(addr >> 8) & 0xFF, (uint8_t)addr & 0xFF);
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ�鷢�书������
 * @param       tpower: ATK_MW1278D_TPOWER_11DBM: 11dBm
 *                      ATK_MW1278D_TPOWER_14DBM: 14dBm
 *                      ATK_MW1278D_TPOWER_17DBM: 17dBm
 *                      ATK_MW1278D_TPOWER_20DBM: 20dBm��Ĭ�ϣ�
 * @retval      ATK_MW1278D_EOK   : ���书�����óɹ�
 *              ATK_MW1278D_ERROR : ���书������ʧ��
 *              ATK_MW1278D_EINVAL: �����������
 */
uint8_t atk_mw1278d_tpower_config(atk_mw1278d_tpower_t tpower)
{
    uint8_t ret;
    char cmd[12] = {0};
    
    switch (tpower)
    {
        case ATK_MW1278D_TPOWER_11DBM:
        case ATK_MW1278D_TPOWER_14DBM:
        case ATK_MW1278D_TPOWER_17DBM:
        case ATK_MW1278D_TPOWER_20DBM:
        {
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    sprintf(cmd, "AT+TPOWER=%d", tpower);
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ�鹤��ģʽ����
 * @param       workmode: ATK_MW1278D_WORKMODE_NORMAL  : һ��ģʽ��Ĭ�ϣ�
 *                        ATK_MW1278D_WORKMODE_WAKEUP  : ����ģʽ
 *                        ATK_MW1278D_WORKMODE_LOWPOWER: ʡ��ģʽ
 *                        ATK_MW1278D_WORKMODE_SIGNAL  : �ź�ǿ��ģʽ
 * @retval      ATK_MW1278D_EOK   : ����ģʽ���óɹ�
 *              ATK_MW1278D_ERROR : ����ģʽ����ʧ��
 *              ATK_MW1278D_EINVAL: �����������
 */
uint8_t atk_mw1278d_workmode_config(atk_mw1278d_workmode_t workmode)
{
    uint8_t ret;
    char cmd[12] = {0};
    
    switch (workmode)
    {
        case ATK_MW1278D_WORKMODE_NORMAL:
        case ATK_MW1278D_WORKMODE_WAKEUP:
        case ATK_MW1278D_WORKMODE_LOWPOWER:
        case ATK_MW1278D_WORKMODE_SIGNAL:
        {
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    sprintf(cmd, "AT+CWMODE=%d", workmode);
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ�鷢��ģʽ����
 * @param       tmode: ATK_MW1278D_TMODE_TT: ͸�����䣨Ĭ�ϣ�
 *                     ATK_MW1278D_TMODE_DT: ������
 * @retval      ATK_MW1278D_EOK   : ����ģʽ���óɹ�
 *              ATK_MW1278D_ERROR : ����ģʽ����ʧ��
 *              ATK_MW1278D_EINVAL: �����������
 */
uint8_t atk_mw1278d_tmode_config(atk_mw1278d_tmode_t tmode)
{
    uint8_t ret;
    char cmd[11] = {0};
    
    switch (tmode)
    {
        case ATK_MW1278D_TMODE_TT:
        case ATK_MW1278D_TMODE_DT:
        {
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    sprintf(cmd, "AT+TMODE=%d", tmode);
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ��������ʺ��ŵ�����
 * @param       wlrate : ATK_MW1278D_WLRATE_0K3 : 0.3Kbps
 *                       ATK_MW1278D_WLRATE_1K2 : 1.2Kbps
 *                       ATK_MW1278D_WLRATE_2K4 : 2.4Kbps
 *                       ATK_MW1278D_WLRATE_4K8 : 4.8Kbps
 *                       ATK_MW1278D_WLRATE_9K6 : 9.6Kbps
 *                       ATK_MW1278D_WLRATE_19K2: 19.2Kbps��Ĭ�ϣ�
 *              channel: �ŵ�����Χ0~83
 * @retval      ATK_MW1278D_EOK   : �������ʺ��ŵ����óɹ�
 *              ATK_MW1278D_ERROR : �������ʺ��ŵ�����ʧ��
 *              ATK_MW1278D_EINVAL: �����������
 */
uint8_t atk_mw1278d_wlrate_channel_config(atk_mw1278d_wlrate_t wlrate, uint8_t channel)
{
    uint8_t ret;
    char cmd[15] = {0};
    
    switch (wlrate)
    {
        case ATK_MW1278D_WLRATE_1K2:
        case ATK_MW1278D_WLRATE_2K4:
        case ATK_MW1278D_WLRATE_4K8:
        case ATK_MW1278D_WLRATE_9K6:
        case ATK_MW1278D_WLRATE_19K2:
        {
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    if (channel > 83)
    {
        return ATK_MW1278D_EINVAL;
    }
    
    sprintf(cmd, "AT+WLRATE=%d,%d", channel, wlrate);
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ������ʱ������
 * @param       wltime: ATK_MW1278D_WLTIME_1S: 1�루Ĭ�ϣ�
 *                      ATK_MW1278D_WLTIME_2S: 2��
 * @retval      ATK_MW1278D_EOK   : ����ʱ�����óɹ�
 *              ATK_MW1278D_ERROR : ����ʱ������ʧ��
 *              ATK_MW1278D_EINVAL: �����������
 */
uint8_t atk_mw1278d_wltime_config(atk_mw1278d_wltime_t wltime)
{
    uint8_t ret;
    char cmd[12] = {0};
    
    switch (wltime)
    {
        case ATK_MW1278D_WLTIME_1S:
        case ATK_MW1278D_WLTIME_2S:
        {
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    sprintf(cmd, "AT+WLTIME=%d", wltime);
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}

/**
 * @brief       ATK-MW1278Dģ�鴮������
 * @param       baudrate: ATK_MW1278D_UARTRATE_1200BPS  : 1200bps
 *                        ATK_MW1278D_UARTRATE_2400BPS  : 2400bps
 *                        ATK_MW1278D_UARTRATE_4800BPS  : 4800bps
 *                        ATK_MW1278D_UARTRATE_9600BPS  : 9600bps
 *                        ATK_MW1278D_UARTRATE_19200BPS : 19200bps
 *                        ATK_MW1278D_UARTRATE_38400BPS : 38400bps
 *                        ATK_MW1278D_UARTRATE_57600BPS : 57600bps
 *                        ATK_MW1278D_UARTRATE_115200BPS: 115200bps��Ĭ�ϣ�
 *              parity  : ATK_MW1278D_UARTPARI_NONE: ��У�飨Ĭ�ϣ�
 *                        ATK_MW1278D_UARTPARI_EVEN: żУ��
 *                        ATK_MW1278D_UARTPARI_ODD : ��У��
 * @retval      ATK_MW1278D_EOK   : �������óɹ�
 *              ATK_MW1278D_ERROR : ��������ʧ��
 *              ATK_MW1278D_EINVAL: �����������
 */
uint8_t atk_mw1278d_uart_config(atk_mw1278d_uartrate_t baudrate, atk_mw1278d_uartpari_t parity)
{
    uint8_t ret;
    char cmd[12] = {0};
    
    switch (baudrate)
    {
        case ATK_MW1278D_UARTRATE_1200BPS:
        case ATK_MW1278D_UARTRATE_2400BPS:
        case ATK_MW1278D_UARTRATE_4800BPS:
        case ATK_MW1278D_UARTRATE_9600BPS:
        case ATK_MW1278D_UARTRATE_19200BPS:
        case ATK_MW1278D_UARTRATE_38400BPS:
        case ATK_MW1278D_UARTRATE_57600BPS:
        case ATK_MW1278D_UARTRATE_115200BPS:
        {
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    switch (parity)
    {
        case ATK_MW1278D_UARTPARI_NONE:
        case ATK_MW1278D_UARTPARI_EVEN:
        case ATK_MW1278D_UARTPARI_ODD:
        {
            break;
        }
        default:
        {
            return ATK_MW1278D_EINVAL;
        }
    }
    
    sprintf(cmd, "AT+UART=%d,%d", baudrate, parity);
    
    ret = atk_mw1278d_send_at_cmd(cmd, "OK", ATK_MW1278D_AT_TIMEOUT);
    if (ret != ATK_MW1278D_EOK)
    {
        return ATK_MW1278D_ERROR;
    }
    
    return ATK_MW1278D_EOK;
}
