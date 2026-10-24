#include "common.h"

void func_80027CFC(unsigned char *a)
{
  unsigned int x = a[1];
  unsigned int y = a[2];
  unsigned int v = (y | (~x)) | 0x90;
  unsigned int w = a[1] & v;
  a[2] = v;
  a[3] = a[1] & v;
}
