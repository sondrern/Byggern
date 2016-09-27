/*
 * Byggern.h
 *
 * Created: 06.09.2016 15:00:37
 *  Author: jareds
 */ 


#ifndef BYGGERN_H_
#define BYGGERN_H_

#pragma once
#define F_CPU 4915200UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(USART0_RXC_vect);
void USART_SendByte(uint8_t u8Data);
uint8_t USART_ReceiveByte();
void USART_Init(void);
void SRAM_test(void);




#endif 
