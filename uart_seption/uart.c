#include "uart.h"
#define F_CPU 16000000UL

#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define USART_BAUDRATE 38400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)



void USART1_SendByte(uint8_t u8Data){
	
	// VENT TIL SIST BYTE ER SENDT
	while((UCSR1A &(1<<UDRE1)) == 0);
	
	//SEND
	UDR1 = u8Data;
}



uint8_t USART1_ReceiveByte(){
	while((UCSR1A &(1<<RXC1)) == 0);
	return UDR1;
}

void USART1_Init(void){

	UBRR1L = BAUD_PRESCALE;
	UBRR1H = (BAUD_PRESCALE >> 8);
	UCSR1B = ((1<<TXEN1)|(1<<RXEN1) );
	UCSR1C = (3<<UCSZ00);

}

void USART3_Init(void){

	UBRR3L = BAUD_PRESCALE;
	UBRR3H = (BAUD_PRESCALE >> 8);
	UCSR3B = ((1<<TXEN3)|(1<<RXEN3) );
	UCSR3C = (3<<UCSZ00);

}

uint8_t USART3_ReceiveByte(){
	while((UCSR3A &(1<<RXC3)) == 0);
	return UDR3;
}


void USART_SendByte(uint8_t u8Data){
	
	// VENT TIL SIST BYTE ER SENDT
	while((UCSR0A &(1<<UDRE0)) == 0);
	
	//SEND
	UDR0 = u8Data;
}



uint8_t USART_ReceiveByte(){
	while((UCSR0A &(1<<RXC0)) == 0);
	return UDR0;
}

void USART_Init(void){
	UBRR0L = BAUD_PRESCALE;
	UBRR0H = (BAUD_PRESCALE >> 8);
	UCSR0B = ((1<<TXEN0)|(1<<RXEN0) );
	UCSR0C = (3<<UCSZ00);
	fdevopen(&USART_SendByte, &USART_ReceiveByte);
}

