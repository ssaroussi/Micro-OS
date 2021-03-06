#include "util.h"

/** memset
 *  Writes given value to given addr space (src to (src + size))
 *
 *  @param src The base, start of the write
 *  @param val The value to write
 *  @param size The size of the chunk to write to
 */
void *memset(void *src, uint16_t val, uint32_t size)
{
  for (char *tmp = (char *) src; size; size--, tmp++) *tmp = val;

  return src;
}

/* Credit to osdev */
char * itoa( int32_t value, int8_t * str, int32_t base )
{
  int8_t * rc;
  int8_t * ptr;
  int8_t * low;
  // Check for supported base.
  if ( base < 2 || base > 36 )
    {
      *str = '\0';
      return str;
    }
  rc = ptr = str;
  // Set '-' for negative decimals.
  if ( value < 0 && base == 10 )
    {
      *ptr++ = '-';
    }
  // Remember where the numbers start.
  low = ptr;
  // The actual conversion.
  do
    {
      // Modulo is negative for negative value. This trick makes abs() unnecessary.
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
      value /= base;
    } while ( value );
  // Terminating the string.
  *ptr-- = '\0';
  // Invert the numbers.
  while ( low < ptr )
    {
      int8_t tmp = *low;
      *low++ = *ptr;
      *ptr-- = tmp;
    }
  return rc;
}
