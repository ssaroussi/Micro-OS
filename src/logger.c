#include "logger.h"

static int8_t *log_messages[] = {
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
void serial_log(log_t type, int8_t *content)
{
  serial_print(SERIAL_COM1_BASE, log_messages[type]);
  serial_print(SERIAL_COM1_BASE, ": ");
  serial_print(SERIAL_COM1_BASE, content);
  serial_print(SERIAL_COM1_BASE, "\n");
}

/** serial_log
 *  Writes to COM1 given msg with type
 *
 *  @param type The type of the  content (log_messages)
 *  @param content The content of the log
 */
void log(log_t type, int8_t *content)
{
  print("[");
  print(log_messages[type]);
  print("]: ");
  print(content);
  print("\n");
}


void global_log(log_t type, int8_t *content)
{
  log(type, content);
  serial_log(type, content);
}

