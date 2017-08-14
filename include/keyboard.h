#ifndef INCLUDE_KEYBOARD_H
#define INCLUDE_KEYBOARD_H

#define CHARS_NUM          (0x80)
#define KEYBOARD_DATA_PORT (0x60)

#include "common.h"
#include "port.h"
#include "irq.h"
#include "io.h"

void keyboard_handler(regs_t *regs);
void init_keyboard();

#endif /* INCLUDE_KEYBOARD_H */
