#include "MCP2515.h"
#include "spi.h"





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

void mcp2515_request_to_send(void){

	SPI_enable(1);
	SPI_send(MCP_RTS_TX0);
	SPI_enable(0);

}

void mcp2515_bit_modify(uint8_t addr, uint8_t mask, uint8_t val){
	SPI_enable(1);

	SPI_send(MCP_BITMOD);
	SPI_send(addr);
	SPI_send(mask);
	SPI_send(val);

	SPI_enable(0);
}


uint8_t mcp2515_read_status(void){
	SPI_enable(1);
	SPI_send(MCP_READ_STATUS);
	uint8_t value = SPI_receive();
	SPI_enable(0);
	return value;
}


void mcp2515_reset(void){
	SPI_enable(1);
	//printf("in reset!\n");
	SPI_send(MCP_RESET);
	SPI_enable(0);
}
