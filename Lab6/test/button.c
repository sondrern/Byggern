#include "button.h"

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

