#include "MCP2515.h"

int main(void){
	can_init();
	struct data message;
	message.id = 3;
	message.length = 1;
	message.data[0] = (uint8_t)’U’;
	can_message_send(&message);

}


void can_init(void){

	uint8_t value;
	SPI_init(); // Initialize SPI
	mcp2515_reset(); // Send reset-command
	// Self-test
	mcp2515_bit_modify(MCP_CANCTRL, 0xE0, 0x2);
	mcp2515_read(MCP_CANSTAT, &value);
	if ((value & MODE_MASK) != MODE_CONFIG) {
		printf("MCP2515 is NOT in configuration mode after reset!\n");
		return 1;
	}
	// More initialization
	
	return 0;
}



void can_message_send(struct data* msg) {

	uint8_t i;
	for (i = 0; i < msg->length; i++){
		mcp2515_write(msg.data[i], );

	}

}