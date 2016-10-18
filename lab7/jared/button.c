#include "button.h"
#include "can.h"
#include "MCP2515.h"


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

void buttonsend(struct data button){
		uint8_t a = adc_read(4);
		int b = (a-123)*0.758;
		char X= '0';
		char Y='0';
		
		printf("y = %i %% \n ", b);
		if(a>130){
			printf("y = Up \n ");
			Y='U';
			
		}
		else if (a<120){
			printf("y = Down \n ");
			Y='D';
		}
		else{
			
			printf("y = Neutral \n ");
			Y='N'
		}

		// X direction

		a = adc_read(5);
		b = (a-123)*0.758;
		printf("x = %i %% \n ", b);
		if(a>135){
			printf("x = RIGHT \n ");
			X='D';
		}
		else if (a<120){
			printf("x = LEFT \n ");
			X='U';
		}
		else{
			
			printf("x = Neutral \n ");
			X='N';
		}
		
		
		
		
		
		
		
		
		
		button.id=1;
		button.length=1
		
		
		
		
		if(X=='N' && Y=='N'){
			button.data=0xb00000000;
			
		}
		else if(X=='N' && Y=='U'){
		button.data=0xb00000001;
		}
		else if(X=='N'&& Y=='D'){
		button.data= 0xb00000010;
		}
		else if(X=='U'&& Y=='N'){
			button.data= 0xb00000011;
		}
		else if (X=='U' && Y=='D'){
			button.data= 0Xb00000100;
		}
		else if (X=='D' && Y=='N'){
			button.data= 0xb00000110;
		}
		else if(X='D' && Y='U'){
			button.data=0xb00000111;
		}
		else if(X=D && Y=D){
			button.data= 0xb00001000;
		
	can_message_send(button);
}