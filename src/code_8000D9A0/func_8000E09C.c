#include "common.h"

typedef struct S_8000E09C
{
  s16 unk0;
  s16 unk2;
  s16 w;
  s16 h;
  s32 unk8;
  s32 alloc;
  s32 heap;
  s8 b14;
  s8 b15;
  s32 unk18;
  f32 f1c;
  f32 f20;
  s32 unk24;
} S_8000E09C;
u32 func_8000E2F0(s32);
s32 func_8007EAA0(s32, s32);
void func_8007EE9C(S_8000E09C *);
extern s32 D_8009B720[];
s32 func_8000E09C(S_8000E09C *arg0, s32 arg1)
{
  s32 var_a0 = arg1;
  s32 ret = 0;
  s32 mul = 2;
  u32 v;
  s32 temp_s1;
  s32 alloc;
  if (arg0 != NULL)
  {
    temp_s1 = var_a0;
    if (temp_s1 & 0x10000)
    {
      var_a0 = temp_s1 + 2;
    }
    v = func_8000E2F0(var_a0);
    if (v < 0xE)
    {
      var_a0 = D_8009B720[v];
      var_a0 |= 0x400;
    }
    else
      if (v < 0x1C)
    {
      v -= 0xE;
      var_a0 = D_8009B720[v];
      var_a0 |= 0x800;
    }
    else
      if (v >= 0x2A)
    {
      v -= 0x2A;
      var_a0 = D_8009B720[v];
      var_a0 |= 0x800;
    }
    else
    {
      v -= 0x1C;
      var_a0 = D_8009B720[v];
      var_a0 |= 0x400;
    }
    if (var_a0 & 0x80)
    {
      mul = 4;
    }
    arg0->unk0 = 0;
    arg0->unk2 = 0;
    if (var_a0 & 0x200)
    {
      arg0->h = 0x1E0;
      arg0->w = 0x280;
    }
    else
    {
      arg0->h = 0xF0;
      arg0->w = 0x140;
    }
    alloc = func_8007EAA0(arg0->heap, ((arg0->w * arg0->h) * mul) + 8);
    arg0->alloc = alloc;
    if (alloc != 0)
    {
      arg0->b14 = 1;
      arg0->unk18 = temp_s1;
      arg0->unk0 = 0;
      arg0->unk2 = 0;
      arg0->b15 = 0;
      arg0->unk24 = 0x4A;
      arg0->f1c = 1.0f;
      arg0->f20 = 1.0f;
    }
    else
    {
      func_8007EE9C(arg0);
    }
    ret = 1;
  }
  return ret;
}
