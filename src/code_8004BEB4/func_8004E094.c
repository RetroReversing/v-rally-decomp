#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
static inline s16 inline_second(f32 arg0)
{
 return (s16)((s32)(-arg0));
}
static inline static static static s16 inline_fn(f32 arg0)
{
  return (s16) ((s32) (-arg0));
}

static inline f32 inline_fn2(u8 *arg0)
{
  return (f32) (*((u16 *) (arg0 + 6)));
}

void func_8004E094(void *arg0)
{
  u8 *p = (u8 *) arg0;
  u8 *new_var5;
  f32 temp_ft0;
  f32 p8;
  f32 new_var4;
  u8 *v0;
  int new_var3;
  u8 *a4;
  u8 *v1;
  float new_var2;
  s32 flags;
  int new_var;
  f32 p6;
  if ((*((u16 *) (p + 0x74))) == 4)
  {
    *((volatile s16 *) (p + 0x98)) = 0x100;
    temp_ft0 = 1024.0f;
    temp_ft0 = temp_ft0 / ((f32) (*((s16 *) (p + 0x98))));
    ;
    new_var = 0x80;
    a4 = *((u8 **) (p + 0xA4));
    new_var3 = new_var;
    *((s32 *) (p + new_var3)) = (*((s32 *) (p + 0x80))) | 5;
    *((s16 *) (p + 0x7A)) = 0;
    *((s16 *) (p + 0x78)) = 1;
    *((s32 *) (p + new_var3)) |= 4;
    *((u16 *) (p + 0x9A)) = (double) 0x100;
    v0 = *((u8 **) (a4 + 4));
    v1 = *((u8 **) v0);
    new_var2 = 0.5f; p6 = (temp_ft0 * inline_fn2(v1)) * 0.5f;
    new_var4 = (f32) (*((u16 *) (v1 + 8)));
    p8 = (temp_ft0 * new_var4) * new_var2;
    new_var5 = p;
    *((u16 *) (new_var5 + 0x9A)) = *((u16 *) (new_var5 + 0x98));
    *((s32 *) (new_var5 + 0xA0)) |= 4;
    *((s16 *) (new_var5 + 0x70)) = inline_fn(p6);
    *((s16 *) (new_var5 + 0x72)) = inline_second(p8);
  }
}

