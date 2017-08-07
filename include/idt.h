#ifndef INCLUDE_IDT_H
#define INCLUDE_IDT_H

#define IDT_SIZE (0x100)

struct idt_entry
{
  unsigned short baseLow;
  unsigned short seg;
  unsigned char  thisIs0;
  unsigned char  flags;
  unsigned short baseHigh;
} __attribute__((packed));

typedef struct idt_entry idt_entry_t;

struct idt_ptr
{
  unsigned short limit;
  unsigned int  base;
} __attribute__((packed));

typedef struct idt_ptr idt_ptr_t;


void set_idt_gate(unsigned char index, unsigned long base, unsigned short seg, unsigned char flags);
void init_idt();
extern void load_idt();


#endif /* INCLUDE_IDT_H */
