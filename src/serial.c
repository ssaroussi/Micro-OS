#include "serial.h"

/** serial_conf_baud_rate
 *  Sets the speed of the data beign send from given com port
 *
 *  @param base The port of the com
 *  @param divisor The divisor of the total speed (finall speed: 115200 / divisor)
 */
void serial_conf_baud_rate(unsigned short base, unsigned short divisor)
{
  outb(SERIAL_LINE_COMMAND_PORT(base), SERIAL_LINE_ENABLE_DLAB); // Enable DLAB
  
  // Send the divisor (high - > low)
  outb(SERIAL_DATA_PORT(base), (divisor >> 8) & 0x00FF);
  outb(SERIAL_DATA_PORT(base), divisor & 0x00FF);
}

/** serial_conf_line
 *  Confs the line of the given port base
 * 
 *  @param base The serial port to configure
 */
void serial_conf_line(unsigned short base)
{
  outb(SERIAL_LINE_COMMAND_PORT(base), 0x03);
}

/** serial_conf_buff
 *  Confs the buffer of the given port base
 * 
 *  @param base The serial port to configure
 */
void serial_conf_buff(unsigned short base)
{
  outb(SERIAL_FIFO_COMMAND_PORT, 0xC7);
}

/** serial_conf_modem
 *  Confs the modem of the given port base
 * 
 *  @param base The serial port to configure
 */
void serial_conf_modem(unsigned short base)
{
  outb(SERIAL_MODEM_COMMAND_PORT(base), 0x03);
}

/** serial_is_transmit_fifo_empty
 *  Checks if the fifo buffer is empty
 *
 *  @param base The serial port to test
 */
int serial_is_transmit_fifo_empty(unsigned int base)
{
  return inb(SERIAL_LINE_STATUS_PORT(base)) & 20;
}
