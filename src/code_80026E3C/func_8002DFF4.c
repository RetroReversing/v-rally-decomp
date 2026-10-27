#include "common.h"

static inline char *inline_fn(char *arg0)
{
  return arg0;
}

void func_8002DFF4(void *arg0, void *arg1)
{
  f32 temp_fv0;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 temp_t0;
  s32 temp_t1;
  s32 var_a2;
  s32 var_a3;
  var_a3 = 0;
  do
  {
    var_a2 = 0;
    temp_v1 = var_a3 & 0xFF;
    temp_t1 = inline_fn(((char *) arg0) + (temp_v1 * 0x10));
    temp_t0 = temp_v1 * 2;
    do
    {
      temp_v1_2 = var_a2 & 0xFF;
      temp_fv0 = ((f32) (*((s16 *) (temp_t0 + (u32)(((char *) arg1) + (temp_v1_2 * 6)))))) * 0.000244140625f;
      ++var_a2;
      *((f32 *) (temp_t1 + (temp_v1_2 * 4))) = temp_fv0;
    }
    while (((u32) (var_a2 & 0xFF)) < 3U);
    var_a3 += 1;
  }
  while (((u32) (var_a3 & 0xFF)) < 3U);
  *((f32 *) (((char *) arg0) + 0x30)) = (f32) (*((s32 *) (((char *) arg1) + 0x14)));
  *((f32 *) (((char *) arg0) + 0x34)) = (f32) (*((s32 *) (((char *) arg1) + 0x18)));
  *((f32 *) (((char *) arg0) + 0x38)) = (f32) (*((s32 *) (((char *) arg1) + 0x1C)));
  *((s32 *) (((char *) arg0) + 0xC)) = 0;
  *((s32 *) (((char *) arg0) + 0x1C)) = 0;
  *((s32 *) (((char *) arg0) + 0x2C)) = 0;
  *((f32 *) (((char *) arg0) + 0x3C)) = 1.0f;
}
