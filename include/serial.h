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

#include "common.h"

void serial_conf_baud_rate(uint16_t base, uint16_t divisor);
void serial_conf_line(uint16_t base);
void serial_conf_buff(uint16_t base);
void serial_conf_modem(uint16_t base);
void serial_write_byte(uint16_t base, int8_t byte);
void serial_write(uint16_t base, int8_t *buf, uint32_t len);
void serial_print(uint16_t base, int8_t *buf);
void init_serial(uint16_t base, uint16_t divisor);

int serial_is_transmit_fifo_empty(uint32_t base);

#endif // INCLUDE_SERIAL_H
