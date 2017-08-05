#include "logger.h"

static char log_messages[][5] = {
  "INFO",
  "DEBUG",
  "ERROR"
};

void serial_log(log_t type, char *content)
{
  char sep[] = ": ";
  
  serial_print(SERIAL_COM1_BASE, log_messages[type]);
  serial_print(SERIAL_COM1_BASE, sep);
  serial_print(SERIAL_COM1_BASE, content);
}
