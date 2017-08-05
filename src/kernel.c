#include "io.h"
#include "serial.h"
#include "logger.h"

int kmain()
{
  char buf[] = "Hello There!";
  clear();
  print(buf);

  init_serial(SERIAL_COM1_BASE, 3);
  serial_log(INFO, buf);
  return 0;
}

