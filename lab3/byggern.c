#include "byggern.h"

#define F_CPU 4915200UL
#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
 
// Define baud rate
#define USART_BAUDRATE 38400   
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
 
volatile unsigned char value;  
/* This variable is volatile so both main and RX interrupt can use it.
It could also be a uint8_t type */
 
/* Interrupt Service Routine for Receive Complete 
NOTE: vector name changes with different AVRs see AVRStudio -
Help - AVR-Libc reference - Library Reference - <avr/interrupt.h>: Interrupts
for vector names other than USART_RXC_vect for ATmega32 */
 
ISR(USART0_RXC_vect){
  
   value = UDR0;             //read UART register into value
   
}
 

 
 
void USART_SendByte(uint8_t u8Data){
 
  // Wait until last byte has been transmitted
  while((UCSR0A &(1<<UDRE0)) == 0);
 
  // Transmit data
  UDR0 = u8Data;
}
 
 
// not being used but here for completeness
      // Wait until a byte has been received and return received data 
uint8_t USART_ReceiveByte(){
  while((UCSR0A &(1<<RXC0)) == 0);
  return UDR0;
}
 
void USART_Init(void){
   // Set baud rate
   UBRR0L = BAUD_PRESCALE;// Load lower 8-bits into the low byte of the UBRR register
   UBRR0H = (BAUD_PRESCALE >> 8); 
     /* Load upper 8-bits into the high byte of the UBRR register
    Default frame format is 8 data bits, no parity, 1 stop bit
  to change use UCSRC, see AVR datasheet*/
 
  // Enable receiver and transmitter and receive complete interrupt 
  UCSR0B = ((1<<TXEN0)|(1<<RXEN0) );
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

uint8_t adc_read(int mux){
	volatile char *ext_adc = (char *) 0x1400;
	*ext_adc = mux;
	while(PINB & (1<<PINB3)){}
	return *ext_adc;
}

void mem_init(void){
	 MCUCR |= (1<<SRE);
	 SFIOR |= (1<<XMM2);
}

void buttons_init(void){
	DDRB &= ~(1 << DDB0);
	DDRB &= ~(1 << DDB1);
	DDRB &= ~(1 << DDB2);
	DDRB &= ~(1<<DDB3);
	PORTB |= (1 << PB0);
	
}
 
char joystick(){
	uint8_t a = adc_read(4);
	int b = (a-123)*0.758;
	printf("y = %i %% \n ", b);
	if(a>130){
		printf("y = Up \n ");
	}
	else if (a<120){
		printf("y = Down \n ");
	}	
	else{
		
		printf("y = Neutral \n ");
	}

	// X direction

	a = adc_read(5);
	b = (a-123)*0.758;
	printf("x = %i %% \n ", b);
	if(a>135){
		printf("x = RIGHT \n ");
	}
	else if (a<120){
		printf("x = LEFT \n ");
	}
	else{
		
		printf("x = Neutral \n ");
	}
}
 
int main(void){
   USART_Init();  // Initialise USART
   
	mem_init();
   
   
   
   
    buttons_init();
   //printf("test");
   //SRAM_test();
   

   for(;;){    // Repeat indefinitely
	   
		  printf("Joystick button = %i \n", (PINB & (1<<PINB0)));
		  printf("Right button = %i \n", !(PINB & (1<<PINB1)));
		  printf("LEft button = %i \n", !(PINB & (1<<PINB2)));
		  printf("\n");
		
	    joystick();
		printf("\n");
		
		printf("slider left = %i \n ", adc_read(6));
		printf("slider right = %i \n ", adc_read(7));
	    printf("\n");
		
		//SRAM_test();
		printf("\n");
		
	 _delay_ms(1000*1);               
   }
   
}
