#include "oled.h"
#include "uart.h"
#include "can.h"
#include "button.h"
#include "spi.h"
#include "MCP2515.h"

int main(){
	
	USART_Init();  //
   
	mem_init();
   oled_init();
   	//SPI_init();
	   


	//mcp2515_bit_modify(MCP_CANCTRL, 0xE0, 0x2);

   char test='L';
   
    buttons_init();
	
	
	/*
	SPI_enable(1);
	
	test= SPI_receive();
	SPI_enable(0);
	
	printf("test= %c ",test); 
	printf("\n");
	*/
	

	
   //printf("test");
   //
   //SRAM_test();
   /*
    oled_char('!');
    oled_char('E');
	oled_printf("jared\nhjkhlkh");
	oled_printf("dasdsaa");
*/
   uint8_t adresse= 0X0F;
   char mcpread;
   for(;;){    // Repeat indefinitely
	  //SRAM_test();
	   
		 /* printf("Joystick button = %i \n", (PINB & (1<<PINB0)));
		  printf("Right button = %i \n", !(PINB & (1<<PINB1)));
		  printf("LEft button = %i \n", !(PINB & (1<<PINB2)));
		  printf("\n");
		
	    joystick();
		printf("\n");
		
		printf("slider left = %i \n ", adc_read(6));
		printf("slider right = %i \n ", adc_read(7));
	    printf("\n");
		
		SRAM_test();
		printf("\n");*/
		
		
		
		
		
		
		
		
			can_init();
			struct data message;
			message.id = 59;
			message.length = 2;
			message.data[0] = 12;
			message.data[1] = 13;
			
			can_message_send(message);
			for (int i = 0; i<message.length; i++){
				printf("Message [%i] = %i \n", i, message.data[i]);
			}
			
			struct data received=can_data_receive();
			for (int i = 0; i<received.length; i++){
				printf("Received [%i] = %i \n", i, received.data[i]);
			}
		
		
		
		
		
		
			
		
		   
	   
	//mainmenu();         
	
			//mcp2515_write(99, TXB0D0);
			/*
			uint8_t test = mcp2515_read(TXB0D0);
			printf("test = %i \n", test);
	*/
	     _delay_ms(3000);
   }
   return 0;
}
	
	
	

