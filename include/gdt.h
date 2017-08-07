#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H

#define GDT_NUM_ENTRIES (3)
#define CODE_SEG_SIZE   (0xFFFFFFFF)
#define DATA_SEG_SIZE   (0xFFFFFFFF)

struct gdt_entry
{
  unsigned short limitLow;
  unsigned short baseLow;
  unsigned char  baseMid;
  unsigned char  access;
  unsigned char  gran;
  unsigned char  baseHigh;
} __attribute__((packed));

typedef struct gdt_entry gdt_entry_t;

struct gdt_ptr
{
  unsigned short limit;
  unsigned int   base;
} __attribute__((packed));

typedef struct gdt_ptr gdt_ptr_t;


void init_gdt();
extern void gdt_flush(); // at loader.s
void gdt_set_gate(int index, unsigned long base, unsigned long limit,
		  unsigned char access, unsigned char gran);


#endif // INCLUDE_GDT_H
