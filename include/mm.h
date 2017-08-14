#ifndef INCLUDE_MM_H
#define INCLUDE_MM_H

#include "common.h"
#include "pmm.h"
#include "multiboot.h"

void init_mm(multiboot_info_t *mbinfo, uint32_t kernelStart, uint32_t kernelEnd, uint32_t kernelSize);

#endif /* INCLUDE_MM_H */
