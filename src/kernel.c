#include "io.h"
#include "serial.h"
#include "logger.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"
#include "pit.h"
#include "keyboard.h"
#include "interrupts.h"

int kmain()
{
  clear();

  init_gdt();
  init_idt();
  init_isr();
  init_irq();
  
  enable_interrupts();
  init_pit();
  init_keyboard();

  

  init_serial(SERIAL_COM1_BASE, 3);


  return 0;
}
