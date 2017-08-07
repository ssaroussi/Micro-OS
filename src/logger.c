#include "logger.h"

static char *log_messages[] = {
  "INFO",
  "DEBUG",
  "ERROR"
};

/** serial_log
 *  Writes to COM1 given msg with type 
 *
 *  @param type The type of the  content (log_messages)
 *  @param content The content of the log
 */
void serial_log(log_t type, char *content)
{
  serial_print(SERIAL_COM1_BASE, log_messages[type]);
  serial_print(SERIAL_COM1_BASE, ": ");
  serial_print(SERIAL_COM1_BASE, content);
}
