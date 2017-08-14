#include "gdt.h"

gdt_entry_t GDTEntries[GDT_NUM_ENTRIES] = { 0 };
gdt_ptr_t pGDT;


/** gdt_set_gate
 *  Initialize a gdt entry by given index and params
 *
 *  @param index The index of the enrty (in GDTEntries)
 *  @param base  The base addr of the seg
 *  @param limit The limit of the seg (highest addr)
 *  @param access and gran The flags of the seg (type, priv, etc)
 */
void gdt_set_gate(int32_t index, uint32_t base, uint32_t limit,
		  uint8_t access, uint8_t gran)
{
  gdt_entry_t *currEntry = GDTEntries + index;

  // Base
  currEntry->baseLow  = base & 0xFFFF;
  currEntry->baseMid  = (base >> 16) & 0xFF;
  currEntry->baseHigh = (base >> 24) & 0xFF;

  // Limit
  currEntry->limitLow = limit & 0xFFFF;
  currEntry->gran     = (limit >> 16) & 0x0F;

  // Flags
  currEntry->gran  |= gran & 0xF0;
  currEntry->access = access; // tnx intel
}

/** init_gdt
 *  Sets 3 entries (segs), null (dummy), code and data
 */
void init_gdt()
{
  pGDT.limit =  (sizeof(gdt_entry_t) * GDT_NUM_ENTRIES) - 1;
  pGDT.base  =  (uint32_t) &GDTEntries;

  gdt_set_gate(0, 0, 0, 0, 0); // dummy segment
  gdt_set_gate(1, 0, CODE_SEG_SIZE, 0x9A, 0xCF); // code segment
  gdt_set_gate(2, 0, DATA_SEG_SIZE, 0x92, 0xCF); // data segment

  gdt_flush(); // Oh-My-God, Damn
}
