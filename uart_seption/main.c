/*
 * atmega2560.c
 *
 * Created: 12.11.2016 09.51.20
 * Author : sondre
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#define F_CPU 16000000UL

#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>



void init_interrupt(void){
		DDRE &= ~(1<<PE5);		// Set PE5 as input (Using for interupt INT5)
		//PORTE = 1<<PE5;		// Enable PE5 pull-up resistor

		EIMSK |= (1<<INT5);					// Enable INT0
		EICRB = (1<<ISC50) | (1<<ISC51);
		//sei();	
}

void init_interrupt2(void){
	DDRE &= ~(1<<PE4);		// Set PE5 as input (Using for interupt INT5)
	//PORTE = 1<<PE5;		// Enable PE5 pull-up resistor

	EIMSK |= (1<<INT4);					// Enable INT0
	EICRB = (1<<ISC50) | (1<<ISC51);
	//sei();
}



int main(void)
{
	USART1_Init();
	USART_Init();
	USART3_Init();
	init_interrupt();	
	init_interrupt2();
	sei();
	

	while (1) 
    {
		
		printf("Main \n");
		int b = 4+'0';
		//USART1_SendByte(b);
		_delay_ms(1000);
		
		
    }
}



ISR(INT5_vect)
{
			
			int a = USART1_ReceiveByte();
			//USART1_SendByte(a);
			//a=a-'0';
			printf("Atmega Received = %i \n",a);
		
}

ISR(INT4_vect)
{
	char a = "A";
	//char a = USART3_ReceiveByte();
	//USART1_SendByte(a);
	//a=a-'0';
	printf("Interrupt 4 Received = %c \n",a);
	
}
