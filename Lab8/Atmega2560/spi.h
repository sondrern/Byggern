#include<stdint.h> 
void SPI_init(void);
void SPI_high(void);
void SPI_low(void);

void SPI_send(uint8_t cData);

char SPI_receive(void);

void SPI_enable(uint8_t enable);