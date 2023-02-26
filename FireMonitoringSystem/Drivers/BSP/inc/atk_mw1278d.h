/**
 ****************************************************************************************************
 * @file        atk_mw1278d.h
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

#ifndef __ATK_MW1278D_H
#define __ATK_MW1278D_H

#include "sys.h"
#include "atk_mw1278d_uart.h"
#include "main.h"

/* AT��Ӧ�ȴ���ʱʱ�䣨���룩 */
#define ATK_MW1278D_AT_TIMEOUT  1000

/* ���Ŷ��� */
#define ATK_MW1278D_AUX_GPIO_PORT           GPIOA
#define ATK_MW1278D_AUX_GPIO_PIN            GPIO_PIN_1
#define ATK_MW1278D_AUX_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)
#define ATK_MW1278D_MD0_GPIO_PORT           GPIOA
#define ATK_MW1278D_MD0_GPIO_PIN            GPIO_PIN_0
#define ATK_MW1278D_MD0_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

/* IO���� */
#define ATK_MW1278D_AUX()                   HAL_GPIO_ReadPin(ATK_MW1278D_AUX_GPIO_PORT, ATK_MW1278D_AUX_GPIO_PIN)
#define ATK_MW1278D_MD0(x)                  do{ x ?                                                                                     \
                                                HAL_GPIO_WritePin(ATK_MW1278D_MD0_GPIO_PORT, ATK_MW1278D_MD0_GPIO_PIN, GPIO_PIN_SET) :  \
                                                HAL_GPIO_WritePin(ATK_MW1278D_MD0_GPIO_PORT, ATK_MW1278D_MD0_GPIO_PIN, GPIO_PIN_RESET); \
                                            }while(0)

/* ʹ��ö�� */
typedef enum
{
    ATK_MW1278D_DISABLE             = 0x00,
    ATK_MW1278D_ENABLE,
} atk_mw1278d_enable_t;

/* ���书��ö�� */
typedef enum
{
    ATK_MW1278D_TPOWER_11DBM        = 0,   /* 11dBm */
    ATK_MW1278D_TPOWER_14DBM        = 1,   /* 14dBm */
    ATK_MW1278D_TPOWER_17DBM        = 2,   /* 17dBm */
    ATK_MW1278D_TPOWER_20DBM        = 3,   /* 20dBm��Ĭ�ϣ� */
} atk_mw1278d_tpower_t;

/* ����ģʽö�� */
typedef enum
{
    ATK_MW1278D_WORKMODE_NORMAL     = 0,    /* һ��ģʽ��Ĭ�ϣ� */
    ATK_MW1278D_WORKMODE_WAKEUP     = 1,    /* ����ģʽ */
    ATK_MW1278D_WORKMODE_LOWPOWER   = 2,    /* ʡ��ģʽ */
    ATK_MW1278D_WORKMODE_SIGNAL     = 3,    /* �ź�ǿ��ģʽ */
} atk_mw1278d_workmode_t;

/* ����ģʽö�� */
typedef enum
{
    ATK_MW1278D_TMODE_TT            = 0,    /* ͸�����䣨Ĭ�ϣ� */
    ATK_MW1278D_TMODE_DT            = 1,    /* ������ */
} atk_mw1278d_tmode_t;

/* ��������ö�� */
typedef enum
{
    ATK_MW1278D_WLRATE_0K3          = 0,    /* 0.3Kbps */
    ATK_MW1278D_WLRATE_1K2          = 1,    /* 1.2Kbps */
    ATK_MW1278D_WLRATE_2K4          = 2,    /* 2.4Kbps */
    ATK_MW1278D_WLRATE_4K8          = 3,    /* 4.8Kbps */
    ATK_MW1278D_WLRATE_9K6          = 4,    /* 9.6Kbps */
    ATK_MW1278D_WLRATE_19K2         = 5,    /* 19.2Kbps��Ĭ�ϣ� */
} atk_mw1278d_wlrate_t;

/* ����ʱ��ö�� */
typedef enum
{
    ATK_MW1278D_WLTIME_1S           = 0,    /* 1�루Ĭ�ϣ� */
    ATK_MW1278D_WLTIME_2S           = 1,    /* 2�� */
} atk_mw1278d_wltime_t;

/* ����ͨ�Ų�����ö�� */
typedef enum
{
    ATK_MW1278D_UARTRATE_1200BPS    = 0,    /* 1200bps */
    ATK_MW1278D_UARTRATE_2400BPS    = 1,    /* 2400bps */
    ATK_MW1278D_UARTRATE_4800BPS    = 2,    /* 4800bps */
    ATK_MW1278D_UARTRATE_9600BPS    = 3,    /* 9600bps */
    ATK_MW1278D_UARTRATE_19200BPS   = 4,    /* 19200bps */
    ATK_MW1278D_UARTRATE_38400BPS   = 5,    /* 38400bps */
    ATK_MW1278D_UARTRATE_57600BPS   = 6,    /* 57600bps */
    ATK_MW1278D_UARTRATE_115200BPS  = 7,    /* 115200bps��Ĭ�ϣ� */
} atk_mw1278d_uartrate_t;

/* ����ͨѶУ��λö�� */
typedef enum
{
    ATK_MW1278D_UARTPARI_NONE       = 0,    /* ��У�飨Ĭ�ϣ� */
    ATK_MW1278D_UARTPARI_EVEN       = 1,    /* żУ�� */
    ATK_MW1278D_UARTPARI_ODD        = 2,    /* ��У�� */
} atk_mw1278d_uartpari_t;

/* ������� */
#define ATK_MW1278D_EOK             0       /* û�д��� */
#define ATK_MW1278D_ERROR           1       /* ͨ�ô��� */
#define ATK_MW1278D_ETIMEOUT        2       /* ��ʱ���� */
#define ATK_MW1278D_EINVAL          3       /* �������� */
#define ATK_MW1278D_EBUSY           4       /* æ���� */

/* �������� */
uint8_t atk_mw1278d_init(uint32_t baudrate);                                                        /* ATK-MW1278D��ʼ�� */
void atk_mw1278d_enter_config(void);                                                                /* ATK-MW1278Dģ���������ģʽ */
void atk_mw1278d_exit_config(void);                                                                 /* ATK-MW1278Dģ����˳���ģʽ */
uint8_t atk_mw1278d_free(void);                                                                     /* �ж�ATK-MW1278Dģ���Ƿ���� */
uint8_t atk_mw1278d_send_at_cmd(char *cmd, char *ack, uint32_t timeout);                            /* ��ATK-MW1278Dģ�鷢��ATָ�� */
uint8_t atk_mw1278d_at_test(void);                                                                  /* ATK-MW1278Dģ��ATָ����� */
uint8_t atk_mw1278d_echo_config(atk_mw1278d_enable_t enable);                                       /* ATK-MW1278Dģ��ָ��������� */
uint8_t atk_mw1278d_sw_reset(void);                                                                 /* ATK-MW1278Dģ�������λ */
uint8_t atk_mw1278d_flash_config(atk_mw1278d_enable_t enable);                                      /* ATK-MW1278Dģ������������� */
uint8_t atk_mw1278d_default(void);                                                                  /* ATK-MW1278Dģ��ָ��������� */
uint8_t atk_mw1278d_addr_config(uint16_t addr);                                                     /* ATK-MW1278Dģ���豸��ַ���� */
uint8_t atk_mw1278d_tpower_config(atk_mw1278d_tpower_t tpower);                                     /* ATK-MW1278Dģ�鷢�书������ */
uint8_t atk_mw1278d_workmode_config(atk_mw1278d_workmode_t workmode);                               /* ATK-MW1278Dģ�鹤��ģʽ���� */
uint8_t atk_mw1278d_tmode_config(atk_mw1278d_tmode_t tmode);                                        /* ATK-MW1278Dģ�鷢��ģʽ���� */
uint8_t atk_mw1278d_wlrate_channel_config(atk_mw1278d_wlrate_t wlrate, uint8_t channel);            /* ATK-MW1278Dģ��������ʺ��ŵ����� */
uint8_t atk_mw1278d_wltime_config(atk_mw1278d_wltime_t wltime);                                     /* ATK-MW1278Dģ������ʱ������ */
uint8_t atk_mw1278d_uart_config(atk_mw1278d_uartrate_t baudrate, atk_mw1278d_uartpari_t parity);    /* ATK-MW1278Dģ�鴮������ */

#endif
