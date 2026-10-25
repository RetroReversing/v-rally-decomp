#include "common.h"

void *func_80005C48(u8 *arg0)
{
  u8 *ret;

  ret = arg0;
  if (ret != NULL) {
    return *(void **)(ret + 0xC);
  }
  return NULL;
}
