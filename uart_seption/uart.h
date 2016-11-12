/*
 * uart.h
 *
 * Created: 12.11.2016 09.54.19
 *  Author: sondre
 */ 

#ifndef UART_H_
#define UART_H_




#include <avr/io.h>
#include <avr/interrupt.h>





void USART1_SendByte(uint8_t u8Data);
uint8_t USART1_ReceiveByte();
void USART1_Init(void);

void USART_SendByte(uint8_t u8Data);
uint8_t USART_ReceiveByte();
void USART_Init(void);


void USART3_Init(void);
uint8_t USART3_ReceiveByte();



#endif /* UART_H_ */
