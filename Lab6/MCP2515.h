

#define MCP_WRITE		0x02
#define MCP_READ		0x03

#define MCP_RTS_TX0		0x81
#define MCP_RTS_TX1		0x82
#define MCP_RTS_TX2		0x84
#define MCP_RTS_ALL		0x87


#define MCP_CANCTRL     0x0F
#define MCP_BITMOD      0x05

#define MCP_RESET       0xC0
#define MCP_READ_STATUS 0xA0

#define MCP_RTS_TX0     0x81
#define MCP_RTS_TX1     0x82
#define MCP_RTS_TX2     0x84
#define MCP_RTS_ALL     0x87


uint8_t mcp2515_read(uint8_t addr);

void mcp2515_write(uint8_t value, uint8_t addr);

void mcp2515_request_to_send(void);

void mcp2515_bit_modify(uint8_t addr, uint8_t mask, uint8_t val);

uint8_t mcp2515_read_status(void);

void mcp2515_reset(void);