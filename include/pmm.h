#ifndef INCLUDE_PMM_H
#define INCLUDE_PMM_H

#define PMM_BLOCK_SIZE      (4096)           // 4KB
#define PMM_BLOCKS_PER_BYTE (8)             // One for each bit
#define PMM_BLOCK_ALIGN     PMM_BLOCK_SIZE

#include "util.h"

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
