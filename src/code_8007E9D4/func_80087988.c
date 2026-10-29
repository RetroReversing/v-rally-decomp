#include "snapshot29_0433f7af8f6d.h"

extern f64 D_800A6D00;
u8 *func_80087988(S_func_80088D10_layout *p, u8 *s)
{
  s32 n;
  s32 v;
  f64 new_var;
  double new_var3;
  f64 rate54;
  f64 rate58;
  int new_var2;
  f64 base;

  n = *(s++);
  if (!n) {
    n = 1;
  }
  new_var2 = 1024;
  p->unk_60 = (long long) (new_var2 / n);
  p->unk_B7 = n;
  p->unk_B8 = *(s++);
  n = *(s++);
  base = D_800A6D00;
  new_var3 = base / ((f32) n);
  rate54 = new_var3;
  new_var = base;
  p->unk_BE = n;
  v = *(s++);
  rate54 *= (f32) (v - p->unk_B8);
  p->unk_B9 = v;
  p->unk_54 = (f32) rate54;
  n = *(s++);
  rate58 = (f32) n;
  rate58 = new_var / rate58;
  p->unk_BF = n;
  v = *(s++);
  rate58 *= (f32) (v - p->unk_B9);
  p->unk_BA = v;
  p->unk_58 = (f32) rate58;
  n = *(s++);
  p->unk_C0 = n;
  p->unk_5C = (f32) (base / ((f32) n));
  return s;
}
