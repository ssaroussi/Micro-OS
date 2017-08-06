#include "logger.h"

static char *log_messages[] = {
  "INFO",
  "DEBUG",
  "ERROR"
};

void serial_log(log_t type, char *content)
{
  serial_print(SERIAL_COM1_BASE, log_messages[type]);
  serial_print(SERIAL_COM1_BASE, ": ");
  serial_print(SERIAL_COM1_BASE, content);
}
