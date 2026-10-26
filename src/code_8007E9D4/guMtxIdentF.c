#include "common.h"

void guMtxIdentF(s32 *arg0)
{
  s32 i;
  s32 j;
  s32 *p;
  s32 *diag;
  f32 one;

  i = 0;
  one = 1.0f;
  diag = arg0;
  do {
    j = 0;
    p = arg0;
    do {
      if (i == j) {
        *(f32 *)diag = one;
      } else {
        *p = 0;
      }
      j++;
      p++;
    } while (j < 4);
    diag += 5;
    i++;
    arg0 += 4;
  } while (i < 4);
}
