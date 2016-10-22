
#include "uart.h"
#include "can.h"
#include "spi.h"
#include "MCP2515.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	USART_Init();  //
   
can_init();
mem_init();
buttons_init();


struct data a;

   for(;;){   
	  buttonsend(a);

		_delay_ms(3000);
		
   }
   return 0;
}
	
	
	




/*struct data message;
		message.id = 59;
		message.length = 1;
		message.data[0] = i2;
		
		can_message_send(message);
		for (int i = 0; i<message.length; i++){
			printf("Message [%i] = %i \n", i, message.data[i]);
		}
		i2++;

		printf("transmitt = %i\n", mcp2515_read(TXB0D0));
		printf("erceive = %i\n", mcp2515_read(RXB0D0));
		
	
		struct data received;
		
		//printf("init [%i] = %i \n", 0, received.data[0]);
		received=can_data_receive();
		for (int i = 0; i<1; i++){
			printf("Received [%i] = %i \n", i, received.data[i]);
		}
	
	mcp2515_write(8, TXB0D0);
	printf("Sendt = %i\n", mcp2515_read(TXB0D0));
	*/