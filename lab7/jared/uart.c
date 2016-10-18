#include "uart.h"

#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


// Define baud rate
#define atmega162

#ifdef atmega162
#define F_CPU 4915200UL
#define USART_BAUDRATE 38400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#else
#define F_CPU 1843200UL
#define USART_BAUDRATE 38400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#endif


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
	#ifdef atmega162
	UBRR0L = BAUD_PRESCALE;
	UBRR0H = (BAUD_PRESCALE >> 8);
	UCSR0B = ((1<<TXEN0)|(1<<RXEN0) );
	#else
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8);
	UCSRB = ((1<<TXEN0)|(1<<RXEN0) );
	UCSRC = ((1<<USBS) | (UCSZ0));
	#endif
	fdevopen(&USART_SendByte, &USART_ReceiveByte);
}



void SRAM_test(void)
{
	volatile char *ext_ram = (char *) 0x1800; // Start address for the SRAM
	uint16_t ext_ram_size       = 0x800;
	uint16_t write_errors       = 0;
	uint16_t retrieval_errors   = 0;

	printf("Starting SRAM test...\n");

	// rand() stores some internal state, so calling this function in a loop will
	// yield different seeds each time (unless srand() is called before this function)
	uint16_t seed = rand();

	// Write phase: Immediately check that the correct value was stored
	srand(seed);
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		ext_ram[i] = some_value;
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Write phase error: ext_ram[%4d] = %02X (should be %02X)\n", i, retreived_value, some_value);
			write_errors++;
		}
	}

	// Retrieval phase: Check that no values were changed during or after the write phase
	srand(seed);    // reset the PRNG to the state it had before the write phase
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Retrieval phase error: ext_ram[%4d] = %02X (should be %02X)\n", i, retreived_value, some_value);
			retrieval_errors++;
		}
	}
	printf("SRAM test completed with \n%4d errors in write phase and \n%4d errors in retrieval phase\n\n", write_errors, retrieval_errors);
}
