#ifndef INCLUDE_IRQ_H
#define INCLUDE_IRQ_H

#include "interrupts.h"
#include "port.h"
#include "idt.h"

#define PIC_MASTER_CONTROL_PORT (0x20)
#define PIC_MASTER_MASK_PORT    (0x21)

#define PIC_SLAVE_CONTROL_PORT  (0xA0)
#define PIC_SLAVE_MASK_PORT     (0xA1)

#define PIC_EOI_COMMAND         (0x20)

#include "common.h"

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

void irq_handler(regs_t *regs);
void init_irq();
void remap_irq();
void rem_irq_handler(uint8_t index);
void set_irq_handler(uint8_t index, void (*handler)(regs_t *regs));


#endif /* INCLUDE_IRQ_H */
