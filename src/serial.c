#include "serial.h"
#include "port.h"

/** serial_conf_baud_rate
 *  Sets the speed of the data beign send from given com port
 *
 *  @param base The port of the com
 *  @param divisor The divisor of the total speed (finall speed: 115200 / divisor)
 */
void serial_conf_baud_rate(uint16_t base, uint16_t divisor)
{
  outb(SERIAL_LINE_COMMAND_PORT(base), SERIAL_LINE_ENABLE_DLAB); // Enable DLAB

  // Send the divisor (high - > low)
  outb(SERIAL_DATA_PORT(base), (divisor >> 8) & 0x00FF);
  outb(SERIAL_DATA_PORT(base) + 1, divisor & 0x00FF);
}

/** serial_conf_line
 *  Confs the line of the given port base
 *
 *  @param base The serial port to configure
 */
void serial_conf_line(uint16_t base)
{
  outb(SERIAL_LINE_COMMAND_PORT(base), 0x03);
}

/** serial_conf_buff
 *  Confs the buffer of the given port base
 *
 *  @param base The serial port to configure
 */
void serial_conf_buff(uint16_t base)
{
  outb(SERIAL_FIFO_COMMAND_PORT(base), 0xC7);
}

/** serial_conf_modem
 *  Confs the modem of the given port base
 *
 *  @param base The serial port to configure
 */
void serial_conf_modem(uint16_t base)
{
  outb(SERIAL_MODEM_COMMAND_PORT(base), 0x0B);
}

/** init_serial
 *  Sets default settings with given divisor to given port
 *
 *  @param base The port of the COM
 *  @param dividor The divisor of the baud rate (blah blah blah)
 */
void init_serial(uint16_t base, uint16_t divisor)
{
  outb(SERIAL_DATA_PORT(base) + 1, 0x00);
  serial_conf_baud_rate(base, divisor);
  serial_conf_line(base);
  serial_conf_buff(base);
  serial_conf_modem(base);
}

/** serial_is_transmit_fifo_empty
 *  Checks if the fifo buffer is empty
 *
 *  @param base The serial port to test
 */
int serial_is_transmit_fifo_empty(uint32_t base)
{
  return inb(SERIAL_LINE_STATUS(base)) & 20;
}

/** serial_write_byte
 *  Writes a byte to given serial port
 *
 *  @param base The serial port
 *  @param byte The byte to write
 */
void serial_write_byte(uint16_t base, int8_t byte)
{
  outb(SERIAL_DATA_PORT(base), byte);
}

/** serial_write
 *  Writes a string to given serial port
 *
 *  @param base The serial port
 *  @param buf The string to write
 *  @param len The length of the string
 */
void serial_write(uint16_t base, int8_t *buf, uint32_t len)
{
  // while (!serial_is_transmit_fifo_empty(base)); // busy wait :( (for now)
  for (uint32_t i = 0; i < len; i++)
    {
      serial_write_byte(base, buf[i]);
    }
}

/** serial_write
 *  Writes a string to given serial port (null terminated)
 *
 *  @param base The serial port
 *  @param buf The string to write
 */
void serial_print(uint16_t base, int8_t *buf)
{
  // while (serial_is_transmit_fifo_empty(base)); // busy wait :( (for now)
  for (uint32_t i = 0; buf[i]; i++)
    {
      serial_write_byte(base, buf[i]);
    }
}
