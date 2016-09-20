#pragma once

volatile char *ext_oled_cmd = (char *) 0x1000;
volatile char *ext_oled_data = (char *) 0x1200;
#define DISP_HEIGHT             64
#define DISP_WIDTH              128
#define DISP_PAGES (DISP_HEIGHT/8)


#include <stdint.h>

typedef struct {
    void*   addr;
    uint8_t width;
    uint8_t height;
    uint8_t start_offset;

} FontDescr;

void oled_init(void);

void oled_cmd(char c);
void oled_data(char d);

void oled_init(void);
