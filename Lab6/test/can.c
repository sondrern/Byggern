#include "MCP2515.h"
#include "can.h"


void can_init(void){

	uint8_t value;
	SPI_init(); // Initialize SPI
	mcp2515_reset(); // Send reset-command
	// Self-test
	value=mcp2515_read(MCP_CANSTAT);
	if ((value & MODE_MASK) != MODE_CONFIG) {
		printf("MCP2515 is NOT in configuration mode after reset!\n");
		return 1;
	}
		mcp2515_bit_modify(MCP_CANCTRL, 0xE0, MODE_LOOPBACK);
		mcp2515_request_to_send();
		
	
	return 0;
}



void can_message_send(struct data* msg) {

	uint8_t i;
	for (i = 0; i < msg->length; i++){
		mcp2515_write(msg.data[i], );

	}

}
void can_data_receive(){
	
	
	
	
	
	
	
	
	
}