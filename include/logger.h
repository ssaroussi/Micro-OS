#ifndef INCLUDE_LOGGER_H
#define INCLUDE_LOGGER_H

#include "common.h"
#include "serial.h"
#include "io.h"

typedef enum
  {
    INFO,
    DEBUG,
    ERROR
  } log_t;

void serial_log(log_t type, int8_t *content);
void global_log(log_t type, int8_t *content);
void log(log_t type, int8_t *content);

#endif // INCLUDE_LOGGER_H
