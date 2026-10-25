#include "common.h"

f32 sqrtf(f32);
void func_800945B0(f32 *arg0, f32 *arg1, f32 *arg2)
{
  f32 len;
  f32 inv;

  len = sqrtf((*arg0 * *arg0) + (*arg1 * *arg1) + (*arg2 * *arg2));
  inv = 1.0f / len;
  *arg0 *= inv;
  *arg1 *= inv;
  *arg2 *= inv;
}
