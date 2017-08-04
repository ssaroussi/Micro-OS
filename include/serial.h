#ifndef INCLUDE_SERIAL_H
#define INCLUDE_SERIAL_H

#define SERIAL_COM1_BASE (0x3F8)

#define SERIAL_DATA_PORT(BASE)          (BASE)
#define SERIAL_FIFO_COMMAND_PORT(BASE)  (BASE + 2)
#define SERIAL_LINE_COMMAND_PORT(BASE)  (BASE + 3)
#define SERIAL_MODEM_COMMAND_PORT(BASE) (BASE + 4)
#define SERIAL_LINE_STATUS(BASE)        (BASE + 5)


/* SERIAL_LINE_ENABLE_DLAB:
 * Tells the serial port to expect first the highest 8 bits on the data port,
 * then the lowest 8 bits will follow
 */
#define SERIAL_LINE_ENABLE_DLAB (0x80)

void serial_conf_baud_rate(unsigned short base, unsigned short divisor);

#endif // INCLUDE_SERIAL_H
