#include "isr.h"

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

  for (int32_t i = 0; i < ISR_NUM; i++)
    set_idt_gate(i, (uint32_t)isrs[i], 0x08, 0x8E);

  global_log(INFO, "Initialized Exception Interrupts");
}

/** interrupt_handler
 *  'catches' all the interrupt and handle them.
 */
void isr_handler(regs_t *regs)
{
  if (regs->interrupt_num < ISR_NUM)
    {
      int8_t int_num[3] = { 0 };
      itoa(regs->interrupt_num, int_num, 10);
      print(int_num);

      while(1);
    }


}
