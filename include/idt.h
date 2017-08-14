#ifndef INCLUDE_IDT_H
#define INCLUDE_IDT_H

#define IDT_SIZE (0x100)

#include "common.h"

struct idt_entry
{
  uint16_t baseLow;
  uint16_t seg;
  uint8_t  thisIs0;
  uint8_t  flags;
  uint16_t baseHigh;
} __attribute__((packed));

typedef struct idt_entry idt_entry_t;

struct idt_ptr
{
  uint16_t limit;
  uint32_t  base;
} __attribute__((packed));

typedef struct idt_ptr idt_ptr_t;


void set_idt_gate(uint8_t index, uint32_t base, uint16_t seg, uint8_t flags);
void init_idt();
extern void load_idt();


#endif /* INCLUDE_IDT_H */
