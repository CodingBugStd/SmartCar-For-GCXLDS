#ifndef	_USART_H_
#define	_USART_H_

#include "system_core.h"

#define	USART_BOUND		115200

static uint8_t Usart_Tx_Flag[3] = { 0, 0, 0};			//DMA��æ��־λ
static uint8_t Usart_Sbuffer[3][64] = {{0},{0},{0}};		//Usart���ջ���  ÿ�е�һλ��ʾ���յ������ݳ���

/*****************�ⲿ�ӿ�***********************/
uint8_t Usart1_Send(uint8_t*data,uint8_t len);				//����DMA��Usartx��������
uint8_t Usart2_Send(uint8_t*data,uint8_t len);
uint8_t Usart3_Send(uint8_t*data,uint8_t len);
void Usart_TxFlag_Clear(uint8_t USARTx);				//DMA��æ��־���
void Usart_Sbuffer_Clear(uint8_t USARTx);				//���ڽ��ջ��������
uint8_t* Read_Usart_Sbuffer(uint8_t USARTx);			//��ȡ���ڽ��ջ���������
uint8_t Usart_Sbuffer_Push(uint8_t USARTx,uint8_t len);	//���ڻ���������ǰ��
/****************��ʼ��**************************/
void Usart_Config(void);
void Usart_DMA_Config(void);
/****************�ж�****************************/
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);

#endif

