#include "isr.h"
#include "idt.h"
#include "io.h"

/** init_isr
 *  initialize the first 32 interrupt service routinens
 */
void init_isr()
{
  void *isrs[32] = {
    &isr0,  &isr1,  &isr2,  &isr3,  &isr4,  &isr5,  &isr6,
    &isr7,  &isr8,  &isr9,  &isr10, &isr11, &isr12, &isr13,
    &isr14, &isr15, &isr16, &isr17, &isr18, &isr19, &isr20,
    &isr21, &isr22, &isr23, &isr24, &isr25, &isr26, &isr27,
    &isr29, &isr30, &isr31
  };

  for (int i = 0; i < 32; i++)
    set_idt_gate(i, (unsigned)isrs[i], 0x08, 0x8E);
}

/** interrupt_handler
 *  This function 'catches' all the interrupt and handle them.
 */
void interrupt_handler(regs_t *regs)
{
  if (regs->interrupt_num < 32)
    {
      putc(regs->interrupt_num + '0');
    }

  while(1);
}
