#include "uart.h"

uint8_t adc_read(int mux);
void mem_init(void);

void buttons_init(void);
void buttonsend(struct data button);
char joystick();
