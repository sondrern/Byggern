#pragma once

volatile char *ext_oled_cmd = (char *) 0x1000;
volatile char *ext_oled_data = (char *) 0x1200;
#define DISP_HEIGHT             64
#define DISP_WIDTH              128
#define DISP_PAGES (DISP_HEIGHT/8)


#include <stdint.h>

#define OLED_MEMORY_ADDRESSING_MODE         0x20
#define ADDRESSING_MODE_HORIZONTAL          0x00
#define ADDRESSING_MODE_VERTICAL            0x01
#define ADDRESSING_MODE_PAGE                0x02

#define OLED_HVMODE_COLUMN_ADDRESS          0x21
//  Valid values (start addr):  0-127.  Reset: 0
//  Valid values (end addr):    0-127.  Reset: 127 (0x7f)

#define OLED_PMODE_COLUMN_ADDRESS_UPPER     0x10
//  Valid offset values: 0-15

#define OLED_PMODE_COLUMN_ADDRESS_LOWER     0x00
//  Valid offset values: 0-15

#define OLED_HVMODE_PAGE_ADDRESS            0x22
//  Valid values (start addr):  0-7.    Reset: 0
//  Valid values (end addr):    0-7.    Reset: 7

#define OLED_PMODE_PAGE_ADDRESS             0xB0
//  Valid offset values: 0-7.

#define OLED_CONTRAST                       0x81
//  Valid values: 0-255.    Reset: 127 (0x7f)

#define OLED_SEGMENT_REMAP_START            0xA0
#define OLED_SEGMENT_REMAP_END              0xA1

#define OLED_DISPLAY_ON__FOLLOW_RAM         0xA4
#define OLED_DISPLAY_ON__IGNORE_RAM         0xA5

#define OLED_DISPLAY_NORMAL                 0xA6
#define OLED_DISPLAY_INVERSE                0xA7

#define OLED_MUX_RATIO                      0xA8
//  Valid values: 0-14.     Reset: 63 (0x3f)

#define OLED_SELECT_IREF                    0xAD
#define IREF_INTERNAL                       0x10
#define IREF_EXTERNAL                       0x00

#define OLED_POWER_OFF                      0xAE
#define OLED_POWER_ON                       0xAF

#define OLED_MODE_CMD                       0x80
#define OLED_MODE_DATA                      0x40

#define OLED_VCOMH_DESELECT_LEVEL           0xDB
#define VCOMH_DESELECT_0_65                 0x00
#define VCOMH_DESELECT_0_77                 0x20
#define VCOMH_DESELECT_0_83                 0x30

#define OLED_DISPLAY_OFFSET                 0xD3
//  Valid values: 0-63.     Reset: 0

#define OLED_DISPLAY_CLOCK                  0xD5
//  Valid values:
//      upper nibble (osc freq):     0-15
//      lower nibble (divide ratio): 0-15
//                          Reset: 0x80

#define OLED_PRE_CHARGE_PERIOD              0xD9
//  Valid values:
//      upper nibble (phase 1 period): 1-15
//      lower nibble (phase 2 period): 1-15
//                          Reset: 0x22

#define OLED_COM_PINS                       0xDA
#define COM_PIN_SEQUENTIAL                  0x02
#define COM_PIN_SEQUENTIAL_LR_REMAP         0x22
#define COM_PIN_ALTERNATIVE                 0x12
#define COM_PIN_ALTERNATIVE_LR_REMAP        0x32

#define OLED_COM_SCAN_DIR_NORMAL            0xC0
#define OLED_COM_SCAN_DIR_REMAPPED          0xC8





typedef struct {
    void*   addr;
    uint8_t width;
    uint8_t height;
    uint8_t start_offset;

} FontDescr;

void oled_init(void);

void oled_cmd(char c);
void oled_data(char d);

void oled_reset(void);

void oled_clear_page(uint8_t page);

void oled_go_to_page(uint8_t p);

void oled_go_to_column(uint8_t c);

void oled_write_char(char c)
