
#include "uart.h"
#include "can.h"
#include "spi.h"
#include "MCP2515.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
int main(){
	
	USART_Init();  //

can_init();

   while(1){   
    //buttonrecieve();
	  
	  float a= 20.000;
	  float b= 0.000;
	  
	  pwm_period(a);
	  pwm_width(b);
	  
	_delay_ms(5000);
	
	
   }
   return 0;
}
	
	/*SPør studass om tiden på klokka, den går for fort..*/
	

	 
	/*	struct data received;
		
		//printf("init [%i] = %i \n", 0, received.data[0]);
		received=can_data_receive();
		for (int i = 0; i<1; i++){
			printf("Received [%i] = %i \n", i, received.data[i]);
		}
	mcp2515_write(8, TXB0D0);
	printf("Sendt = %i\n", mcp2515_read(TXB0D0));
	*/
	
