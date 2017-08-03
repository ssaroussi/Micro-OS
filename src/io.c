#include "io.h"

unsigned char *fb = (unsigned char *)+FB_ADDR; // Framebuffer pointer
static unsigned int curr_fb_index = 400; // Starts when bochs's intro ends

/** write_char
 * Writes a char with given args into the framebuffer
 *
 * @param index The index in the fb
 * @param c The char
 * @param fg The foreground color
 * @param bg The background color
 */
void write_char(unsigned int index, char c, unsigned char fg, unsigned char bg)
{
  index *= 2;
  
  fb[index] = c;
  fb[index + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);

  move_cursor(index / 2);
}


/** move_cursor
 *  Moves the curser to given position
 *
 *  @param pos The new cursor's position
 */
void move_cursor(unsigned short pos)
{

  // Write the lsb
  outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
  outb(FB_DATA_PORT, pos & 0x00FF);
  
  // Write the msb
  outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
  outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
  
}

/** wirte
 *  Writes given buf into the frame buffer
 *  
 *  @param buf The buffer to print / write
 *  @param len The length of the buffer
 */
void write(char *buf, unsigned int len)
{
  for (unsigned int i = 0; i < len; i++, curr_fb_index++)
    {
      write_char(curr_fb_index, buf[i], FB_BLACK, FB_WHITE);
    }
}

/** print
 *  Writes given buf into the frame buffer. NULL TERMINATED
 *  
 *  @param buf The buffer to print / write
 */
void print(char *buf)
{
  for (unsigned int i = 0; buf[i]; i++, curr_fb_index++)
    {
      write_char(curr_fb_index, buf[i], FB_BLACK, FB_WHITE);
    }
}
