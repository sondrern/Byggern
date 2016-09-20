#include <avr/pgmspace.h>
#include <stdarg.h>
#include <stdio.h>

#include "oled.h"
#include "font.h"

static FontDescr font = font4x6(void);


static uint8_t page     = 0;
static uint8_t column = 0;

void oled_cmd(char c){
    *ext_oled_cmd = c;
}
void oled_data(char d){
    *ext_oled_data = d;
}

void oled_init(void){
	oled_cmd(0xae);// display off
	oled_cmd(0xa1);//segment remap
	oled_cmd(0xda);//common pads hardware: alternative
	oled_cmd(0x12);
	oled_cmd(0xc8);//common output scan direction:com63~com0
	oled_cmd(0xa8);//multiplex ration mode:63
	oled_cmd(0x3f);
	oled_cmd(0xd5);//display divide ratio/osc. freq. mode
	oled_cmd(0x80);
	oled_cmd(0x81);//contrast control
	oled_cmd(0x50);
	oled_cmd(0xd9);//set pre-charge period
	oled_cmd(0x21);
	oled_cmd(0x20);//Set Memory Addressing Mode
	oled_cmd(0x02);
	oled_cmd(0xdb);//VCOM deselect level mode
	oled_cmd(0x30);
	oled_cmd(0xad);//master configuration
	oled_cmd(0x00);
	oled_cmd(0xa4);//out follows RAM content
	oled_cmd(0xa6);//set normal display
	oled_cmd(0xaf);// display on
	oled_reset();
}





void oled_reset(void){
    for(uint8_t i = 0; i < DISP_PAGES; i++){
        oled_clear_page(i);
    }
    oled_go_to_page(0);
    oled_go_to_column(0);
}

void oled_clear_page(uint8_t page){
    oled_go_to_page(page);
    oled_go_to_column(0);
    for(int i = 0; i < DISP_WIDTH; i++){
        oled_write_data(0);
    }
}






void oled_go_to_page(uint8_t p){
    page = p;
    oled_write_cmd(OLED_PMODE_PAGE_ADDRESS + page);
}

void oled_go_to_column(uint8_t c){
    column = c;
    uint8_t x = column * font.width;
    oled_write_cmd(OLED_PMODE_COLUMN_ADDRESS_LOWER + (x & 0x0f));
    oled_write_cmd(OLED_PMODE_COLUMN_ADDRESS_UPPER + ((x & 0xf0) >> 4));
}



void oled_write_char(char c){
    if(c == '\n'){
        for(uint8_t i = column*font.width; i < DISP_WIDTH; i++){
            oled_write_data(0);
        }
        page = (page + 1) % DISP_PAGES;
        oled_go_to_page(page);
        oled_go_to_column(0);
    } else {
        for (uint8_t i = 0; i < font.width; i++){
            oled_write_data(pgm_read_byte( font.addr + (c-font.start_offset)*font.width + i ));
        }
        column++;
    }
}