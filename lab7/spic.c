#include "spi.h""
#include <avr/pgmspace.h>

void SPI_init(void){

	
	DDRB |= (1<<DDB7) | (1<<DDB5) | (1<<DDB4) ;
	DDRB &=~(1<<DDB6);
	PORTB |= (1<<DDB6);
	
	
	
	
	
	
	
	
	
	
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_send(char cData){
	
	SPDR = cData;
	//SPDR=0b01000010;

	while(!(SPSR & (1<<SPIF))){};
}


char SPI_receive(void){
	SPDR=0b00000000;
	//SPI_send(0xff);
	while(!(SPSR & (1<<SPIF))){};
	return SPDR;
}

void SPI_enable(uint8_t enable){
	if(enable){
		(PORTB &= ~(1<<PB4));
	}
	else{
		(PORTB |= (1<<PB4));
	}

}