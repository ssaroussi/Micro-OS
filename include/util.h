#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H

#include "common.h"

void *memset(void *src, uint16_t val, size_t size);
char *itoa(int32_t val, int8_t *str, int32_t base);

#endif /* INCLUDE_UTIL_H */
