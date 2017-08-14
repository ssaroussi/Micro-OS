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

extern uint32_t kernel_end;
extern uint32_t kernel_base;
extern uint32_t kernel_size;

int32_t kmain(multiboot_info_t *mbinfo)
{

  clear();
  init_serial(SERIAL_COM1_BASE, 3);

  init_gdt();
  init_idt();

  init_isr();
  init_irq();

  enable_interrupts();

  init_pit();
  init_keyboard();

  init_mm(mbinfo, &kernel_base, &kernel_end, &kernel_size);

  return 0;
}
