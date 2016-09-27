#include "oled.h"
#include "uart.h"
#include "button.h"

int main(){
	
	USART_Init();  // Initialise USART
   
	mem_init();
   oled_init();
   
   
   
    buttons_init();
   //printf("test");
   //
   //SRAM_test();
   /*
    oled_char('!');
    oled_char('E');
	oled_printf("jared\nhjkhlkh");
	oled_printf("dasdsaa");
*/
   for(;;){    // Repeat indefinitely
	  SRAM_test();
	   
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
		
	   
	//mainmenu();              
   }
   return 0;
}
	
	
	

