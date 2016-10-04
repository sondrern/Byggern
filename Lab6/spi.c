#include <spi.h>

void SPI_init(void){
	/* Set MOSI and SCK output, all others input */
	//DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);


	DDRB    |=  (1<<DDB7)   // SCK
            |   (1<<DDB5)   // MOSI
            |   (1<<DDB4);  // SS
    DDRB    &= ~(1<<DDB6);  // MISO

	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_send(char cData){
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}


char SPI_receive(void){
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
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