#include "io.h"
#include "serial.h"

int kmain()
{
  char buf[] = "Hello There!";
  clear();
  print(buf);

  init_serial(SERIAL_COM1_BASE, 3);

  serial_print(SERIAL_COM1_BASE, buf);
  
  return 0;
}

