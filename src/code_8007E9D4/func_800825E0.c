#include "common.h"

unsigned char func_800825E0(char arg0)
{
  if (((unsigned char) (arg0 - 0x41)) < 0x1B)
  {
    return arg0 + 0x20;
  }
  return arg0;
}
