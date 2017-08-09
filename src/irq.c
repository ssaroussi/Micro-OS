#include "irq.h"

void *irq_routines[IRQ_NUM] = { 0 };

/** set_irq_handler
 *  Sets given handler to given irq routine number
 *
 *  @param index IRQ routine number
 *  @param handler A pointer to the irq handler
 */
void set_irq_handler(unsigned char index, void (*handler)(regs_t *regs))
{
  irq_routines[index] = handler;
}

/** rem_irq_handler
 *  Remove given irq routine
 *
 *  @param index The IRQ routine number
 */
void rem_irq_handler(unsigned char index)
{
  irq_routines[index] = (void *) 0;
}

/** remap_irq
 *  Remap the pic irq's indexing so that the 
 *  irq routines and the isrs will not clash
 */
void remap_irq()
{
  outb(PIC_MASTER_CONTROL_PORT, 0x11);
  outb(PIC_SLAVE_CONTROL_PORT,  0x11);

  outb(PIC_MASTER_MASK_PORT, 0x20);
  outb(PIC_SLAVE_MASK_PORT,  0x28);

  outb(PIC_MASTER_MASK_PORT, 0x04);
  outb(PIC_SLAVE_MASK_PORT,  0x02);

  outb(PIC_MASTER_MASK_PORT, 0x01);
  outb(PIC_SLAVE_MASK_PORT,  0x01);

  outb(PIC_MASTER_MASK_PORT, 0x00);
  outb(PIC_SLAVE_MASK_PORT,  0x00);
  
}

/** init_irq
 *  Remap and set the irq routines in the IDT
 */
void init_irq()
{
  remap_irq();

  void *irqs[IRQ_NUM] = {
    &irq0,  &irq1,  &irq2,  &irq3,
    &irq4,  &irq5,  &irq6,  &irq7,
    &irq8,  &irq9,  &irq10, &irq11,
    &irq12, &irq13, &irq14, &irq15
  };

  for (unsigned char i = 0; i < IRQ_NUM; i++)
    set_idt_gate(i + IRQ_OFFSET, (unsigned)irqs[i], 0x08, 0x8E);
}

/** irq_handler
 *  Call the current irq handler and report about it to the relevant pics
 *
 *  @param regs The registers, before the interrupt's signal
 */
void irq_handler(regs_t *regs)
{
  void (*handler)(regs_t *regs) = irq_routines[regs->interrupt_num - IRQ_OFFSET];

  if (handler) handler(regs);

  if (regs->interrupt_num >= IRQ_OFFSET + 0x8)
    outb(PIC_SLAVE_CONTROL_PORT, PIC_EOI_COMMAND);

  outb(PIC_MASTER_CONTROL_PORT, PIC_EOI_COMMAND);
  
}
