#include "pmm.h"

static unsigned int pmmMemSize = 0,
  pmmUsedBlocks = 0,
  pmmMaxBlocks  = 0,
  *pmmMemMap    = 0;

/** mmap_set
 *  Sets a block in the bitmap
 *
 *  @param index The block index in the bitmap
 */
void mmap_set(unsigned int index)
{
  pmmMemMap[index / 32] |= (1 << (index % 32));
}

/** mmap_unset
 *  Unsets a block in the bitmap
 *
 *  @param index The block index in the bitmap
 */
void mmap_unset(unsigned int index)
{
  pmmMemMap[index / 32] &= ~ (1 << (index % 32));
}

/** mmap_test
 *  Test if a block is in use
 *
 *  @param index The block index in the bitmap
 *  @return Rether the block is in use or not
 */
char mmap_test(unsigned int index)
{
  return pmmMemMap[index / 32] & (1 << (index % 32));
}

/** mmap_first_free
 *  Returns index of the first free block
 *  
 *  @return The index of the first free block
 */
int mmap_first_free()
{
  // Run on every blocks chunk (32 blocks)
  for (unsigned int i = 0; pmmMaxBlocks / 32; i++)
    {
      // Check if the whole blocks chunk is full
      if (pmmMemMap[i] != 0xFFFFFFFF)
	{
	  // Find the free bit in the block in the chunk
	  for (int j = 0; j < 32; j++)
	    {
	      int bit = i << j;

	      if (!(pmmMemMap[i] & bit))
		{
		  return i * 4 * 8 + j;
		}
	    }
	}
    }

  return -1;
}

/** init_pmm
 *  Initialize the pyshical memory manager
 *
 *  @param memSize The total size of the memory (RAM)
 *  @param bitmap A pointer to the bitmam
 */
void init_pmm(unsigned int memSize, void *bitmap)
{
  pmmMemSize = memSize;
  pmmMemMap  = (unsigned int *) bitmap;
  
  pmmMaxBlocks  = (pmmMemSize * 1024) / PMM_BLOCK_SIZE;

  // Set all the blocks as used ones
  memset(pmmMemMap, 0xF, pmmMaxBlocks / PMM_BLOCKS_PER_BYTE);
  pmmUsedBlocks = pmmMaxBlocks;
  
}

/** set_pmm_region
 *  Sets a region of memory for use
 *
 *  @param base The region's address
 *  @param size The size of the region
 */
void set_pmm_region(void *base, unsigned int size)
{
  int align     = (unsigned int) base / PMM_BLOCK_SIZE;
  int blocksNum = size / PMM_BLOCK_SIZE;

  for(; blocksNum > 0; blocksNum--)
    {
      mmap_unset(align++);
      pmmUsedBlocks--;
    }

  mmap_set(0);
}

/** unset_pmm_region
 *  Unsets a region of memory for use
 *  
 *  @param base The region's address
 *  @param size The size of the region
 */
void unset_pmm_region(void *base, unsigned int size)
{
  int align     = (unsigned int) base / PMM_BLOCK_SIZE;
  int blocksNum = size / PMM_BLOCK_SIZE;

  for(; blocksNum > 0; blocksNum--)
    {
      mmap_unset(align++);
      pmmUsedBlocks++;
    }
}

/** pmm_alloc_block
 *  Allocates a single bloack of physical memory
 *
 *  @return The address of the allocated block
 */
void *pmm_alloc_block()
{
  if (pmmMaxBlocks <= pmmUsedBlocks)
    return 0;

  int block = mmap_first_free();
  if (block == -1)
    return 0;

  mmap_set(block);
  pmmUsedBlocks++;
  
  return (void *)(block * PMM_BLOCK_SIZE);
}

/** pmm_free_block
 *  Releases a single block of physical memory
 *
 *  @param blockAddr The base address of the block to release
 */
void pmm_free_block(void *blockAddr)
{
  mmap_unset((unsigned int)blockAddr / PMM_BLOCK_SIZE);
  pmmUsedBlocks--;
}
