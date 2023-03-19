/***************************************************************************** 
* 
* File Name : wm_iouart.h
* 
* Description: IO uart Driver Module 
* 
* Copyright (c) 2014 Winner Microelectronics Co., Ltd. 
* All rights reserved. 
* 
* Author : dave
* 
* Date : 2015-8-13
*****************************************************************************/ 
#ifndef WM_IO_UART_H
#define WM_IO_UART_H

#include "wm_uart.h"
#include "wm_io.h"


#define IO_UART_FOR_PRINT	0

#define IO_UART_TX		WM_IO_PB_08
#define IO_UART_RX		WM_IO_PB_09

#define IO_UART_HIGH	1
#define IO_UART_LOW		0

#define TLS_IO_UART_RX_BUF_SIZE   1024
#define TLS_IO_UART_TX_BUF_SIZE   1024

#define IO_UART_RATE_MUL	8	//������=��ֵ*������

#define IO_UART_ONEBITE_SAMPLE_NUM	2
#define IO_UART_ONEBYTE_BIT	10

typedef struct tls_io_uart{
	struct tls_uart_circ_buf    recv;
	int timercnt;	
	u8 bit[IO_UART_ONEBITE_SAMPLE_NUM];			//ÿ��bit����3�Σ�Ȼ���жϸߵ͵�ƽ
	u8 bitcnt;		//����bit��������
	u8 bitnum;		//bit�ţ�һ��byte����10��bit(1����ʼλ+8������λ+1��ֹͣλ)
	u8 ifrx;			//�Ƿ�����rx	
	u8 iftx;			//�Ƿ�����tx
	u8 timerid;
	
}tls_io_uart_t;

/**
 * @defgroup Driver_APIs Driver APIs
 * @brief Driver APIs
 */

/**
 * @addtogroup Driver_APIs
 * @{
 */

/**
 * @defgroup IOUART_Driver_APIs IOUART Driver APIs
 * @brief IOUART driver APIs
 */

/**
 * @addtogroup IOUART_Driver_APIs
 * @{
 */

/**
 * @brief          	This function is used to initialize uart io
 *
 * @param[in]      	bandrate      iouart baudrate
 *
 * @return         	WM_SUCCESS    success
 * @return         	WM_FAILED     fail
 *
 * @note           	None
 */
int tls_iouart_init(int bandrate);

/**
 * @brief          	This function is used to restore uart io cfg
 *
 * @param[in]      	None
 *
 * @return         	WM_SUCCESS    success
 *
 * @note           	None
 */
int tls_iouart_destroy(void);

/**
 * @brief          	This function is used to read data from uart io
 *
 * @param[in]       buf        is the user buffer
 * @param[in]       readsize   is the user read size
 *
 * @return         	>0         	  copy data size
 * @return         	WM_FAILED     fail
 *
 * @note           	None
 */
int tls_iouart_read(u8 * buf, int bufsize);

/**
 * @brief          This function is used to transfer data synchronously.
 *
 * @param[in]      buf          is a buf for saving user data
 * @param[in]      writesize    is the user data length
 *
 * @retval         WM_SUCCESS    tx success
 * @retval         WM_FAILED     tx failed
 *
 * @note           None
 */
int tls_iouart_write(u8 * buf, int bufsize);

/**
 * @brief          This function is used to output a character to the serial port.
 *
 * @param[in]      ch      character to be output
 *
 * @retval         ch
 *
 * @note           None
 */
int tls_iouart_output_char(int ch);

/**
 * @}
 */

/**
 * @}
 */

#endif /* WM_IO_UART_H */

