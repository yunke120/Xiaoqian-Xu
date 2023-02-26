#ifndef __BSP_LORA_H__
#define __BSP_LORA_H__

#include "main.h"

/* LORA 模块配置参数定义 */
#define SLAVE_ADDR       2                               /* 从站设备地址 */
#define SLAVE_WLRATE     ATK_MW1278D_WLRATE_19K2         /* 从站空中速率 */
#define SLAVE_CHANNEL    20                              /* 从站信道 */
#define SLAVE_TPOWER     ATK_MW1278D_TPOWER_20DBM        /* 从站发射功率 */
#define SLAVE_WORKMODE   ATK_MW1278D_WORKMODE_NORMAL     /* 从站工作模式 */
#define SLAVE_TMODE      ATK_MW1278D_TMODE_DT            /* 从站发射模式 */
#define SLAVE_WLTIME     ATK_MW1278D_WLTIME_1S           /* 从站休眠时间 */
#define SLAVE_UARTRATE   ATK_MW1278D_UARTRATE_115200BPS  /* 从站UART通讯波特率 */
#define SLAVE_UARTPARI   ATK_MW1278D_UARTPARI_NONE       /* 从站UART通讯校验位 */


#define MASTER_ADDR       1                               /* 主站设备地址 */
#define MASTER_CHANNEL    20                              /* 主站信道 */

#define LORA_SENDBUF_LEN	5								/* 定义模块发送数据长度 */

int lora_init(void);
void lora_send(uint8_t *buf, uint8_t len);


#endif

