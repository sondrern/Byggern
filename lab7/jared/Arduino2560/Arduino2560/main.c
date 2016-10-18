#include "joystick.h"
#include "uart.h"
#include "can.h"
#include "spi.h"
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
 USART_Init();
 SPI_init();
 //can_init();
/* DDRB |= (1<<DDB1) | (1<<DDB2)  | (1<<DDB0) ;
 DDRB |= (1<<DDB7);
 DDRB &=~(1<<DDB3);
 PORTB |= (1<<DDB3);
 
	while(1)
	{
		PORTB &= ~(1<<PB7);
		_delay_ms(1000);
		PORTB |= (1<<PB7);
		_delay_ms(1000);
		
		
		uint8_t temp=mcp2515_read(MCP_CANCTRL);
		printf("Temp = ");
		for(int i=0; i<8; i++){
			if(temp >> i & 1){
				printf("1");
			}
			else{
				printf("0");
			}
			
		}
		//printf("Temp value = %i \n", temp);
		printf("\n");
		
		
		//buttonrecieve();
		//TODO:: Please write your application code
		//printf("Testadasdad \n");
		_delay_ms(2000);
	}
	*/
		
		while (1){
			uint8_t temp=mcp2515_read(MCP_CANCTRL);
			printf("Temp = ");
			for(int i=0; i<8; i++){
				if(temp >> i & 1){
					printf("1");
				}
				else{
					printf("0");
				}
				
			}
			
		_delay_ms(3000)	;
			
		}
}