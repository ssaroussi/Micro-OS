#include "pit.h"

static unsigned long pit_ticks = 0;

/** pit_handler
 *  The handler of the pit (there's no much to tell)
 *
 *  @param regs The registers vlaus before the interrupt
 */
void pit_handler(regs_t *regs)
{
  pit_ticks++;

  if (!(pit_ticks % 18))
    putc(((pit_ticks) / 18) + '0'); // just prints the readable ascii crap, lol
}

/** pit_phase
 *  Calculates divisor by given wanted speed, and command it to the pit
 *
 *  @param speed The wanted speed
 */
void pit_phase(unsigned int speed)
{
  unsigned int divisor = PIT_DEFAULT_SPEED / speed;   /* Calculate our divisor */

  outb(PIT_COMMAND_PORT, 0x36);             /* Set our command byte 0x36 */
  outb(PIT_CHNL_0_PORT, divisor & 0xFF);   /* Set low byte of divisor */
  outb(PIT_CHNL_0_PORT, divisor >> 8);     /* Set high byte of divisor */
}

/** init_pit
 *  Get the handler into the routines arr and sets the phase
 */
void init_pit()
{
  pit_phase(100);
  set_irq_handler(0, pit_handler);
}
