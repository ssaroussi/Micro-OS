/** memset
 *  Writes given val togiven addr space (val to (val + size))
 *  
 *  @param src The base, start of the write
 *  @param val The value to write
 *  @param size The size of the chunk to write to
 */
void *memset(void *src, unsigned short val, unsigned int size)
{
  for (char *tmp = (char *) src; size; size--, tmp++) *tmp = val;
  return src;
}