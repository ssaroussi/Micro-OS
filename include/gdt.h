#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H

#define GDT_NUM_ENTRIES (3)
#define CODE_SEG_SIZE   (0xFFFFFFFF)
#define DATA_SEG_SIZE   (0xFFFFFFFF)

#include "common.h"

/* a segment descriptor/gdt entry struct */
struct gdt_entry
{
  uint16_t limitLow;
  uint16_t baseLow;
  uint8_t  baseMid;
  uint8_t  access;
  uint8_t  gran;
  uint8_t  baseHigh;
} __attribute__((packed));

typedef struct gdt_entry gdt_entry_t;

/* pointer to the gdt */
struct gdt_ptr
{
  uint16_t limit;
  unsigned int   base;
} __attribute__((packed));

typedef struct gdt_ptr gdt_ptr_t;


void init_gdt();
extern void gdt_flush(); // at loader.s
void gdt_set_gate(int index, uint32_t base, uint32_t limit,
		  uint8_t access, uint8_t gran);


#endif // INCLUDE_GDT_H
