#include "isr.h"
#include "idt.h"
#include "io.h"

/** init_isr
 *  Initialize the exception interrupts
 */
void init_isr()
{
  void *isrs[ISR_NUM] = {
    &isr0,  &isr1,  &isr2,  &isr3,  &isr4,  &isr5,  &isr6,
    &isr7,  &isr8,  &isr9,  &isr10, &isr11, &isr12, &isr13,
    &isr14, &isr15, &isr16, &isr17, &isr18, &isr19, &isr20,
    &isr21, &isr22, &isr23, &isr24, &isr25, &isr26, &isr27,
    &isr29, &isr30, &isr31
  };

  for (int i = 0; i < ISR_NUM; i++)
    set_idt_gate(i, (unsigned)isrs[i], 0x08, 0x8E);
}

/** interrupt_handler
 *  'catches' all the interrupt and handle them.
 */
void isr_handler(regs_t *regs)
{
  if (regs->interrupt_num < ISR_NUM)
    {
      putc(regs->interrupt_num + '0');
    }

  while(1);
}
