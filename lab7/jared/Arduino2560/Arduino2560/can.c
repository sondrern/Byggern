#include "MCP2515.h"
#include "can.h"
#include "spi.h"

void can_init(){

	uint8_t value;
	
	SPI_init(); // Initialize SPI
	mcp2515_reset(); // Send reset-command
	
	// Self-test
	value=mcp2515_read(MCP_CANSTAT);
	printf("value=%i\n", value);
	if ((value & MODE_MASK) != MODE_CONFIG) {
		printf("value=%i\n", value);
		
		printf("MCP2515 is NOT in configuration mode after reset!\n");
		return 1;
	}
	mcp2515_bit_modify(MCP_RXB0CTRL, 0b01100000, 0b01100000);
	//mcp2515_bit_modify(MCP_CANCTRL, 0xE0, MODE_LOOPBACK);
	mcp2515_bit_modify(MCP_CANCTRL, 0xE0, MODE_NORMAL);
	
	
	return 0;
}



void can_message_send(struct data msg) {
	mcp2515_write(msg.id >> 3, TXB0SIDH);
	mcp2515_write(msg.id << 5, TXB0SIDL);
	mcp2515_write(msg.length, TXB0DLC);
	uint8_t i;
	for (i = 0; i < msg.length; i++){
		mcp2515_write(msg.data[i], TXB0D0 + i);

	}
	
	mcp2515_request_to_send();
}
struct data can_data_receive(){
	struct data msg;
	//memset(msg,0,sizeof(msg));
	msg.length=mcp2515_read(RXB0DLC);
	//id
	for(int i =0; i<msg.length;i++){
		
		msg.data[i]= mcp2515_read(RXB0D0+i);
		
	}
	return msg;
	
}
