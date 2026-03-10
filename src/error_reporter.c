#include "error_reporter.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void report_error(const char *format, ...) {
  fprintf(stderr, "ERROR: ");

  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);

  fprintf(stderr, "\n");
}
