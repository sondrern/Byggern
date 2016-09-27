#include "oled.h"
#include <util/delay.h>
#include <avr/io.h>
void mainmenu(){
	int row=0;
	int x = 0;
	int y=0;
	int z=0;
	int u=0;
	oled_reset();
	while(1){
		if(row==0){
			oled_printf("MAINMENU  * \n");
	
		}
		else{
			oled_printf("MAINMENU\n");
		}
		if(row==1){
			oled_printf("Highscore  * \n");
		}
		else{
			oled_printf("Highscore\n");
		}
		if(row==2){
			oled_printf("Play  * \n");
		}
		else{
			oled_printf("Play\n");
		}
		if(row==3){
			oled_printf("settings  * ");
		}
		else{
			oled_printf("settings");
		}
		//*x=0;
		//*y=0;
		pollbutton(&x, &y,&z,&u);
		if(y==2){
			row--;
			if(row<0){
				row=0;
			}
		}
		else if(y==1){
			row++;
			if(row>3){ //husk å inkrementer hvis menyen blir større
				row=3;
			}
		}
		else{
			y=0;
		}
		
		if(z){
			if (row==0){
				submenu1();
			}
					
		}
	 _delay_ms(750);
	 oled_reset();
		
	}
	
	
	
	
	
	

	
	
}


void pollbutton(int *x, int *y,int *z,int* u){
	//bruker joystick funksjonen:
	/* Y: 0= NØYTRAL, 1= NED, 2: OPP
		X: 0=NØYTRAL, 1=HØYRE, 2: VENSTRE*/
	
	
	uint8_t a = adc_read(4);
	int b = (a-123)*0.758;
	if(a>130){
		*y=2;
	}
	else if (a<120){
		*y=1;
	}
	else{
		
		*y=0;
	}

	// X direction

	a = adc_read(5);
	b = (a-123)*0.758;
	if(a>135){
		*x=1;
	}
	else if (a<120){
		*x=2;
	}
	else{
		
		*x=0;
	}
	
	
	
	if(PINB & (1<<PINB1)){
		
		*z=1;
	}
	else{
	*z=0;
	}
	
	if(PINB & (1<<PINB2)){
		*u=1;
	}
		else{
			*u=0;
		}
		
	}
void submenu1(){
	while(1){
	oled_reset();
	oled_printf("Submenu1");
	int x=0;
	int y=0;
	int z=0;
	int u=0;
	pollbutton(&x,&y,&z,&u);
	if(u){
		oled_reset();
		return;
		
	}
	_delay_ms(750);
	}
	
	
}