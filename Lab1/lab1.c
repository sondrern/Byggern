#define F_CPU 4915200UL
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
 
 
int main(void){
   USART_Init();  // Initialise USART
   sei();         // enable all interrupts
    
   printf("test");
   
   for(;;){    // Repeat indefinitely
              
     _delay_ms(250);
	 char c = USART_ReceiveByte(); 
	 USART_SendByte(c);
     //USART_ReceiveByte();        
     //_delay_ms(250); 
                      
   }
   
}
