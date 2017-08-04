#ifndef INCLUDE_SERIAL_H
#define INCLUDE_SERIAL_H

#define SERIAL_COM1_BASE (0x3F8)
#define SERIAL_COM2_BASE (0x2F8)
#define SERIAL_COM3_BASE (0x3E8)
#define SERIAL_COM4_BASE (0x2E8)

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
void serial_conf_line(unsigned short base);
void serial_conf_buff(unsigned short base);
void serial_conf_modem(unsigned short base);
void serial_write_byte(unsigned short base, char byte);
void serial_write(unsigned short base, char *buf, unsigned int len);
void serial_print(unsigned short base, char *buf);
void init_serial(unsigned short base, unsigned short divisor);

int serial_is_transmit_fifo_empty(unsigned int base);

#endif // INCLUDE_SERIAL_H
