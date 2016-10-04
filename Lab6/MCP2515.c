#include <MCP2515.h>



struct data {
	uint8_t id;
	uint8_t length;
	char data;
};




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

void mcp2515_request_to_send(){

}

void mcp2515_bit_modify(uint8_t addr, uint8_t mask, uint8_t val){
    SPI_enable(1);

    spi_write(MCP_BITMOD);
    spi_write(addr);
    spi_write(mask);
    spi_write(val);

    SPI_enable(0);
}




mcp2515_bit_modify(MCP_CANCTRL, 0xE0, 0x2);