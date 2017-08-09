#ifndef INCLUDE_INTERRUPTS_H
#define INCLUDE_INTERRUPTS_H

#define ISR_NUM (32)
#define IRQ_NUM (16)
#define IRQ_OFFSET (ISR_NUM)

struct regs
{
  unsigned int gs, fs, es, ds;
  unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
  unsigned int interrupt_num, err_code;
  unsigned int eip, cs, eflags, useresp, ss;
};
typedef struct regs regs_t;

void enable_interrupts(); // At interrupts.s

#endif /* INCLUDE_INTERRUPTS_H */
