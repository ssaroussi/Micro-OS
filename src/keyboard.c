#include "keyboard.h"

uint8_t kb_us[CHARS_NUM] = {
  0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  '-', '=', '\b', '\t',
  'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
   0,
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
  '\'', '\`', 0,
  '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
  '*', 0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0, 0, 0, '+',
  0, 0, 0, 0, 0, 0, 0, 0, 0
};

void keyboard_handler(regs_t *regs)
{
  uint8_t key_code = inb(0x60);

  if (key_code & 0x80) // Key released
    {

    }
  else
    {
      if (key_code)
	putc(kb_us[key_code]);
    }

}

void init_keyboard()
{
  set_irq_handler(1, keyboard_handler);
  global_log(INFO, "Loaded A Basic Keyboard Driver");
}
