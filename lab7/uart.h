#ifndef BYGGERN_H_
#define BYGGERN_H_

#pragma once
#define F_CPU 4915200UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>




void USART_SendByte(uint8_t u8Data);
uint8_t USART_ReceiveByte();
void USART_Init(void);
void SRAM_test(void);

#endif
/*
LES DATABLAD:

1. Send på buffer 0;
2. motta på buffer 0;
3. ikke skift for mye mellom loopback og vanlig wtf,. 

*/