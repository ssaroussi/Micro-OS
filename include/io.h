#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

// Frame buffer properties
#define FB_ADDR        (0x00B8000)
#define FB_WIDTH_SIZE  (25)
#define FB_HIEGHT_SIZE (80)

// Frame buffer colors
#define FB_BLACK         (0)
#define FB_BLUE          (1)
#define FB_GREEN         (2)
#define FB_CYAN          (3)
#define FB_RED           (4)
#define FB_MAGENTA       (5)
#define FB_BROWN         (6)
#define FB_LIGHT_GREY    (7)
#define FB_DARK_GREY     (8)
#define FB_LIGHT_BLUE    (9)
#define FB_LIGHT_GREEN   (10)
#define FB_LIGHT_CYAN    (11)
#define FB_LIGHT_RED     (12)
#define FB_LIGHT_MAGENTA (13)
#define FB_LIGHT_BROWN   (14)
#define FB_WHITE         (15)

// IO ports and commands
#define FB_COMMAND_PORT (0x3D4)
#define FB_DATA_PORT    (0x3D5)
#define FB_HIGH_BYTE_COMMAND (14)
#define FB_LOW_BYTE_COMMAND  (15)


void write_char(unsigned int index, char c, unsigned char fg, unsigned char bg);
void write(char *buf, unsigned int len);
void move_cursor(unsigned short pos);
void print(char *buf);
void clear();

#endif // INCLUDE_IO_H
