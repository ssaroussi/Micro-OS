#include "io.h"
#include "serial.h"
#include "logger.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"

int kmain()
{
  clear();

  init_gdt();
  init_idt();
  init_isr();

  int b = 1 / 0;
  putc(b);
  
  init_serial(SERIAL_COM1_BASE, 3);

  
  return 0;
}

