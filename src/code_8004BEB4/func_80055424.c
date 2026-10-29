#include "snapshot29_0433f7af8f6d.h"

extern char D_800C02AE[];
s32 func_800553E8();
u8 *func_8007EAA0();
static inline u8 **inline_fn(char *arg0, u32 arg1)
{
  return ((u8 **) arg0) + arg1;
}

void func_80055424(u8 *arg0, u16 arg1, s32 arg2)
{
  s32 v0 = func_800553E8(arg0, arg1 & 0xFFFF);
  u32 idx = v0 & 0xFFFF;
  u8 **new_var;
  u8 **slot;
  u8 **new_var2;
  u8 *n = *inline_fn(D_800C02AE + 0x3902, idx);
  u8 c;
  s32 i;
  if (n == 0)
  {
    n = func_8007EAA0(1, 0xC);
    *inline_fn(D_800C02AE + 0x3902, idx) = n;
    c = *arg0;
    n[2] = 1;
    *((s32 *) (n + 4)) = arg2;
    *((u16 *) n) = c + (arg1 + v0);
    n[8] = *arg0;
    return;
  }
  ;
  if (((*((u16 *) n)) == ((u32) (((arg1 & 0xFFFF) + idx) + (*arg0)))) && ((*((s8 *) (n + 8))) == (*arg0)))
  {
    n[2] += 1;
    return;
  }
  if (new_var || D_800C02AE)
  {
    i = 0;
  }
  else
  {
    i = 0;
  }
  if ((*((s32 *) (D_800C02AE + 0x3902))) != 0)
  {
    do
    {
      i++;
    }
    while ((*((s32 *) ((D_800C02AE + 0x3902) + ((i & 0xFF) * 4)))) != 0);
  }
  {
    u8 *fresh = func_8007EAA0(1, 0xC);
    u8 **tail = inline_fn(D_800C02AE + 0x3902, i & 0xFF);
    *tail = fresh;
    *((u16 *) fresh) = (*arg0) + (arg1 + v0);
    new_var = tail;
    *((s32 *) ((*new_var) + 4)) = arg2;
    new_var2 = tail;
    (*new_var)[2] = 1;
    (*new_var2)[8] = *arg0;
  }
}
