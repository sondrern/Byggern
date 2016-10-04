
#include <MCP2515.h>

#define MCP_WRITE		0x02
#define MCP_READ		0x03

struct data {
	uint8_t id;
	uint8_t length;
	char data;
};


void SPI_init(void){
	/* Set MOSI and SCK output, all others input */
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
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

uint8_t mcp2515_read(uint8_t addr){
    SPI_enable(1);

    SPI_send(MCP_READ);
    SPI_send(addr);
    uint8_t value = SPI_receive();

    SPI_enable(0);

    return value;
}

void mcp2515_write(uint8_t value, uint8_t addr){
    SPI_enable(1);

    SPI_send(MCP_WRITE);
    SPI_send(addr);
    SPI_send(value);

    SPI_enable(0);
}
