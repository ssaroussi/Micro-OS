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
#include "multiboot.h"
#include "util.h"
#include "mm.h"

extern unsigned int kernel_end;
extern unsigned int kernel_base;
extern unsigned int kernel_size;

int kmain(multiboot_info_t *mbinfo)
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
  init_mm(mbinfo, &kernel_base, &kernel_end, &kernel_size);
  
  return 0;
}
