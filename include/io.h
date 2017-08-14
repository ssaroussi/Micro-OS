#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

// Frame buffer properties
#define FB_ADDR        (0x00B8000)
#define FB_WIDTH_SIZE  (25)
#define FB_HIEGHT_SIZE (80)

// IO ports and commands
#define FB_COMMAND_PORT (0x3D4)
#define FB_DATA_PORT    (0x3D5)
#define FB_HIGH_BYTE_COMMAND (14)
#define FB_LOW_BYTE_COMMAND  (15)

#include "common.h"
#include "port.h"

// Frame buffer colors
typedef enum
  {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHT_GREY,
    DARK_GREY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    LIGHT_BROWN,
    WHITE
  } fb_color_t; // Frame Buffer C5Color

void write_char(uint32_t index, int8_t c, fb_color_t fg, fb_color_t bg);
void putc(int8_t c);
void move_cursor(uint16_t pos);
void print(int8_t *buf);
void clear();

#endif // INCLUDE_IO_H
