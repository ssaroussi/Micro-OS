#include "io.h"
#include "serial.h"
#include "logger.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"
#include "pit.h"

int kmain()
{
  clear();

  init_gdt();
  init_idt();
  init_isr();
  init_irq();

  asm("sti");
  
  init_pit();

  init_serial(SERIAL_COM1_BASE, 3);


  return 0;
}
