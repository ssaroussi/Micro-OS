#ifndef INCLUDE_INTERRUPTS_H
#define INCLUDE_INTERRUPTS_H

#define ISR_NUM (32)
#define IRQ_NUM (16)
#define IRQ_OFFSET (ISR_NUM)

#include "common.h"

struct regs
{
  uint32_t gs, fs, es, ds;
  uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint32_t interrupt_num, err_code;
  uint32_t eip, cs, eflags, useresp, ss;
};
typedef struct regs regs_t;

void enable_interrupts(); // At interrupts.s

#endif /* INCLUDE_INTERRUPTS_H */
