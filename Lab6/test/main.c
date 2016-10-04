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
   	SPI_init();
	   


	//mcp2515_bit_modify(MCP_CANCTRL, 0xE0, 0x2);

   char test='L';
   
    buttons_init();
	
	SPI_enable(1);
	SPI_send('a');
	test= SPI_receive();
	printf("test= %c ",test); 
	printf("\n");
	
	

	
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
   uint8_t mcpread;
   for(;;){    // Repeat indefinitely
	  //SRAM_test();
	   
		/*  printf("Joystick button = %i \n", (PINB & (1<<PINB0)));
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
		
		*/
		
		
		
		
		
		
			can_init();
			struct data message;
			message.id = 3;
			message.length = 1;
			message.data[0] = (uint8_t)’U’;
			can_message_send(&message);

		
		
		
		
		
		
		
	   SPI_send('a');
		   mcpread = mcp2515_read(MCP_CANCTRL);
		   printf("\n");
		   printf("mcpread= %i",mcpread);
		   
	   
	//mainmenu();         
	
	
	
	     _delay_ms(3000);
   }
   return 0;
}
	
	
	

