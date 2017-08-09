#include "io.h"
#include "serial.h"
#include "logger.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"

int kmain()
{
  clear();

  init_gdt();
  init_idt();
  init_isr();
  init_irq();
  
  init_serial(SERIAL_COM1_BASE, 3);

  
  return 0;
}

