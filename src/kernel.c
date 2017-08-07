#include "io.h"
#include "serial.h"
#include "logger.h"

int kmain()
{
  char *buf = "Hello There!\b";
  
  //  clear();

  for (int i = 0; i < 200; i++)
    print(buf);


  init_serial(SERIAL_COM1_BASE, 3);

  
  return 0;
}

