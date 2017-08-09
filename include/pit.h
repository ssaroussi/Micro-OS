#ifndef __INCLUDE_PIT_H
#define __INCLUDE_PIT_H

#define PIT_CHNL_0_PORT  (0x40)
#define PIT_CHNL_1_PORT  (0x41)
#define PIT_CHNL_2_PORT  (0x42)
#define PIT_COMMAND_PORT (0x43)

#define PIT_DEFAULT_SPEED (1193180)

#include "interrupts.h"
#include "irq.h"
#include "io.h"

void pit_handler(regs_t *regs);
void pit_phase(unsigned int speed);
void init_pit();

#endif /* __INCLUDE_PIT_H */
