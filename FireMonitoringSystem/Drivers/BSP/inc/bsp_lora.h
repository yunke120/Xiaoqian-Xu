#ifndef __BSP_LORA_H__
#define __BSP_LORA_H__

#include "main.h"

/* LORA ģ�����ò������� */
#define SLAVE_ADDR       2                               /* ��վ�豸��ַ */
#define SLAVE_WLRATE     ATK_MW1278D_WLRATE_19K2         /* ��վ�������� */
#define SLAVE_CHANNEL    20                              /* ��վ�ŵ� */
#define SLAVE_TPOWER     ATK_MW1278D_TPOWER_20DBM        /* ��վ���书�� */
#define SLAVE_WORKMODE   ATK_MW1278D_WORKMODE_NORMAL     /* ��վ����ģʽ */
#define SLAVE_TMODE      ATK_MW1278D_TMODE_DT            /* ��վ����ģʽ */
#define SLAVE_WLTIME     ATK_MW1278D_WLTIME_1S           /* ��վ����ʱ�� */
#define SLAVE_UARTRATE   ATK_MW1278D_UARTRATE_115200BPS  /* ��վUARTͨѶ������ */
#define SLAVE_UARTPARI   ATK_MW1278D_UARTPARI_NONE       /* ��վUARTͨѶУ��λ */


#define MASTER_ADDR       1                               /* ��վ�豸��ַ */
#define MASTER_CHANNEL    20                              /* ��վ�ŵ� */

#define LORA_SENDBUF_LEN	5								/* ����ģ�鷢�����ݳ��� */

int lora_init(void);
void lora_send(uint8_t *buf, uint8_t len);


#endif

