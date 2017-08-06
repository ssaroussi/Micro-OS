#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H

#define GDT_NUM_ENTRIES (6)

struct gdt_entry
{
  unsigned short limitLow;
  unsigned short baseLow;
  unsigned char baseMid;
  unsigned char access;
  unsigned char gran;
  unsigned char baseHigh;
} __attribute__((packed));

typedef struct gdt_entry gdt_entry_t;

struct gdt_ptr
{
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

typedef struct gdt_ptr gdt_ptr_t;


void init_gdt(unsigned int addr);

#endif // INCLUDE_GDT_H
