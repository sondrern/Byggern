#include "MCP2515.h"
#include "can.h"
#include "spi.h"
#include <stdlib.h>
#include <stdio.h>

void can_init(){

	uint8_t value;
	
	SPI_init(); // Initialize SPI
	SPI_high();
	//_delay_ms(200);
	mcp2515_reset(); // Send reset-command
	mcp2515_reset(); // Send reset-command
	
	// Self-test
	value=mcp2515_read(MCP_CANSTAT);
	printf("value=%i\n", value);
	if ((value & MODE_MASK) != MODE_CONFIG) {
		printf("value=%i\n", value);
		
		printf("MCP2515 is NOT in configuration mode after reset!\n");
		return 1;
	}
	
	mcp2515_bit_modify(MCP_RXB0CTRL, 0b01100100, 0b01100100);
	
	//	mcp2515_bit_modify(MCP_RXB0CTRL, 0b01100000, 0b01100000);

	//mcp2515_bit_modify(MCP_RXB0CTRL, 0b00000100, 0b00000000);

	mcp2515_bit_modify(MCP_CANINTE, 0b00000001, 0b00000001);

	//	mcp2515_bit_modify(MCP_CANCTRL, 0xE0, MODE_LOOPBACK);
	
	mcp2515_bit_modify(MCP_CANCTRL, 0xE0, MODE_NORMAL);
	value=mcp2515_read(MCP_CANSTAT);
	printf("value=%i\n", value);
	
	
	
	return 0;
}



void can_message_send(struct data msg) {
	/*
	while(mcp2515_read(MCP_TXB0CTRL)== 0b00010000){
		printf("MSG send shait \n");
		
	}
	*/
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
	/*
	if(mcp2515_read(MCP_CANINTF) == 0b00000001){
		printf("Interupt flag not cleared! b\n");
	}
	*/
	msg.id = (mcp2515_read(MCP_RXB0SIDH) << 3) | (mcp2515_read(MCP_RXB0SIDH) >> 5);
	msg.length=(mcp2515_read(RXB0DLC)) & (0x0f) ;

	//id
	for(int i =0; i<1;i++){
		
		msg.data[i]= mcp2515_read(RXB0D0+i);
		
	}
	//printf("interrupt flag reg = %i\n", mcp2515_read(MCP_CANINTF));
	mcp2515_bit_modify(MCP_CANINTF, 0b00000001, 0b00000000);
	return msg;
	
}