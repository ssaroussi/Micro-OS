#ifndef INCLUDE_PMM_H
#define INCLUDE_PMM_H

#define PMM_BLOCK_SIZE      (4096)           // 4KB
#define PMM_BLOCKS_PER_BYTE (8)             // One for each bit
#define PMM_BLOCK_ALIGN     PMM_BLOCK_SIZE

#include "util.h"

#define AVBL_MM_REGION  (0)
#define RVRSD_MM_REGION (1)
#define ACPI_REC_REGION (2)
#define ACPI_NVS_REGION (3)
#define BAD_MM_REGION   (4)

typedef struct memory_region
{
  unsigned int startLo;
  unsigned int startHi;
  unsigned int sizeLo;
  unsigned int sizeHi;
  unsigned int type;
  unsigned int acpi_3;
  
} memory_region_t;

void init_pmm(unsigned int memSize, void *bitmap);
void set_pmm_region(void *base, unsigned int size);
void unset_pmm_region(void *base, unsigned int size);

void mmap_set(unsigned int index);
void mmap_unset(unsigned int index);
char mmap_test(unsigned int index);

int  mmap_first_free();

void pmm_free_block(void *blockAddr);
void *pmm_alloc_block();

#endif /* INCLUDE_PMM_H */
