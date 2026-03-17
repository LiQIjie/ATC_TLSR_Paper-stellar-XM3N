#pragma once
#include "etime.h"
// EPD hardware (SSD1675/SSD1680) RAM X address range is 0x00-0x13, i.e. 20 bytes = 160 pixels.
// This value must be 160 (not 152) to match the hardware. The web canvas height must also be 160.
// If set to 152, BLE uploaded images will be misaligned because canvas2bytes packs 19 bytes/column
// but the hardware expects 20 bytes/column, causing column data shift across the entire display.
#define epd_height 160
#define epd_width 296
#define epd_buffer_size ((epd_height/8) * epd_width)

void set_EPD_scene(uint8_t scene);
void set_EPD_wait_flush();

uint8_t EPD_read_temp(void);
void EPD_Display(unsigned char *image, unsigned char * red_image, int size, uint8_t full_or_partial);
void epd_display_tiff(uint8_t *pData, int iSize);
void epd_set_sleep(void);
uint8_t epd_state_handler(void);
void epd_display_char(uint8_t data);
void epd_clear(void);

void update_time_scene(struct date_time _time, uint16_t battery_mv, int16_t temperature, void (*scene)(struct date_time, uint16_t, int16_t,  uint8_t));
void epd_update(struct date_time _time, uint16_t battery_mv, int16_t temperature);

void epd_display(struct date_time _time, uint16_t battery_mv, int16_t temperature, uint8_t full_or_partial);
void epd_display_time_with_date(struct date_time _time, uint16_t battery_mv, int16_t temperature, uint8_t full_or_partial);
