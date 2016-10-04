

#define MCP_WRITE		0x02
#define MCP_READ		0x03

#define MCP_RTS_TX0		0x81
#define MCP_RTS_TX1		0x82
#define MCP_RTS_TX2		0x84
#define MCP_RTS_ALL		0x87





uint8_t mcp2515_read(uint8_t addr);

void mcp2515_write(uint8_t value, uint8_t addr);

void mcp2515_request_to_send();