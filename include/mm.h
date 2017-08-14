#ifndef INCLUDE_MM_H
#define INCLUDE_MM_H

#include "pmm.h"
#include "multiboot.h"

void init_mm(multiboot_info_t *mbinfo, unsigned int kernelStart, unsigned int kernelEnd, unsigned int kernelSize);

#endif /* INCLUDE_MM_H */
