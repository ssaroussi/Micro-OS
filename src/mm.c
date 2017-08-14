#include "mm.h"

/** init_mm
 *  Initialize the memory managers
 *
 *  @param mbinfo A pointer to a multiboot info struct
 *  @param kernelStart The base address of the kernel itself
 *  @param kernelEnd   The final adress of the kernel
 *  @param kernelSize  The total size of the kernel
 */
void init_mm(multiboot_info_t *mbinfo, uint32_t kernelStart, uint32_t kernelEnd, uint32_t kernelSize)
{
  uint32_t memSize = 0x400 + mbinfo->mem_lower + mbinfo->mem_upper * 64;

  init_pmm(memSize, kernelEnd * 512);

  memory_region_t *region = (memory_region_t *) 0x1000;

  for (int32_t i = 0; i < 15; i++)
    {
      if (region[i].type > BAD_MM_REGION) region[i].type = AVBL_MM_REGION;
      if (i && !region[i].startLo) break;

      if (region[i].type == AVBL_MM_REGION)
	set_pmm_region(region[i].startLo, region[i].sizeLo);
    }

  unset_pmm_region ((uint32_t *)0x100000, kernelSize * 512);
}
