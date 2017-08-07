#include "io.h"

unsigned char *fb = (unsigned char *)FB_ADDR; // Framebuffer pointer
static unsigned int curr_fb_x = 0, curr_fb_y = 5; // Starts when bochs's intro ends
static fb_color_t curr_fb_color = WHITE;

/** write_char
 *  Writes a char with given args into the framebuffer
 *
 *  @param index The index in the fb
 *  @param c The char
 *  @param fg The foreground color
 *  @param bg The background color
 */
void write_char(unsigned int index, char c, fb_color_t fg, fb_color_t bg)
{
  index *= 2;
  
  fb[index] = c;
  fb[index + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);

  move_cursor(index / 2);
}

/** putc
 *  Writes a char (includeing parameters like \n)
 *  
 *  @param c The char  
 */  
void putc(char c)
{
  if (!c) return;

  if (c == '\b')
    {
      curr_fb_x += 4;
      return;
    }

  #define NEW_LINE (c == '\n' || c == '\r')
  
  if (NEW_LINE || curr_fb_x >= (FB_HIEGHT_SIZE - 1))
    {
      curr_fb_y += 1;
      curr_fb_x = 0;

      if (NEW_LINE) return;
    }

  write_char(curr_fb_x + (FB_HIEGHT_SIZE * curr_fb_y), c, BLACK, curr_fb_color);
  
  curr_fb_x++;
  
}

/** print
 *  Writes given buf into the frame buffer. NULL TERMINATED
 *  
 *  @param buf The buffer to print / write
 */
void print(char *buf)
{
  for (unsigned int i = 0; buf[i]; i++)
      putc(buf[i]);

}

/** clear
 *  Clears the screen
 */
void clear()
{
  for (unsigned short i = 0; i < FB_HIEGHT_SIZE * FB_WIDTH_SIZE; i++)
    write_char(i, ' ', BLACK, BLACK);

  curr_fb_x = 0, curr_fb_y = 0;
  move_cursor(1);
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
