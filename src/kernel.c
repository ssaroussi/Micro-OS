#include "io.h"
#include "serial.h"
#include "logger.h"
#include "gdt.h"

int kmain()
{
  char *buf = "Hello There!\b";

  init_gdt();
  
  clear();

  for (int i = 0; i < 200; i++)
    print(buf);


  init_serial(SERIAL_COM1_BASE, 3);

  
  return 0;
}

