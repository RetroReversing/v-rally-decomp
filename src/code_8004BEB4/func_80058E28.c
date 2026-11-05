#include "decompdecomp_snapshot_80058e28.h"
#line 1 "func.c"
typedef struct Cfg
{
  u8 pad[0x22B];
  s8 ctrl;
} Cfg;
extern Cfg *D_800A1468;
extern u32 D_800A14A8;
extern u16 D_800A14AC;
extern u8 D_800A14AE;
extern u32 D_8009D540;
extern u8 D_800B65A0;
extern u8 D_800B5C6C;
extern s8 func_80084C0C(u8, s32);
extern s32 func_80084BF0(u8);
s32 func_80058E28(void)
{
  u8 pad[8];
  s32 c;
  s32 __repair_c_1;
  s32 out;
  s32 pos;
  s8 ctrl;
  s32 btn;
  s32 new_var;
  s32 __repair_guard;
  s8 i;
  s32 x;
  s32 y;
  u16 n;
  out = 0;
  y = 0;
  c = D_800A1468->ctrl;
  x = 0;
  i = 0;
  out = i;
  ctrl = c;
  pos = c >= 0;
  loop1:
  __repair_guard = D_800B65A0;
  if ((__repair_guard = i < __repair_guard))
  {
    if ((pos & (new_var = c == i)) || (c < 0))
    {
      x = func_80084C0C(i, 0x10000);
      y = func_80084C0C(i, 0x20000);
    }
    i++;
    if (!(y | x))
    {
      goto loop1;
    }
  }

  __repair_c_1 = 0;
  if (x >= 0x50)
  {
    __repair_c_1 = 0x800;
  }
  else
    if (x < (-0x4F))
  {
    __repair_c_1 = 0x400;
  }
  if (y >= 0x60)
  {
    __repair_c_1 |= 0x100;
  }
  else
    if (y < (-0x5F))
  {
    __repair_c_1 |= 0x200;
  }
  btn = 0;
  i = 0;
  x = (s8) ctrl;
  pos = x >= 0;
  loop2:
  __repair_guard = D_800B65A0;
  if ((__repair_guard = i < __repair_guard))
  {
    if ((pos & (__repair_guard = x == i)) || (x < 0))
    {
      new_var = func_80084BF0(i);
      btn |= new_var;
      if (new_var)
      {
        D_800B5C6C = i;
      }
    }
    i++;
    if (!btn)
    {
      goto loop2;
    }
  }

  if (btn == 0)
  {
    btn = __repair_c_1;
  }
  for (i = 0; i < 32; i++)
  {
    if ((btn & (1 << i)) == (1 << i))
    {
      btn &= 1 << i;
      break;
    }
  }

  if (btn)
  {
    if (D_800A14A8 == 0)
    {
      D_800A14AC = 0;
      D_800A14A8 = btn;
    }
    else
      if (D_800A14A8 == btn)
    {
      n = ++D_800A14AC;
      if (!D_800A14AE)
      {
        if (n == ((D_8009D540 * 3) >> 2))
        {
          D_800A14AE = 1;
          D_800A14AC = 0;
        }
        else
        {
          btn = 0;
        }
      }
      else
        if (n == (D_8009D540 / 6))
      {
        D_800A14AC = 0;
      }
      else
      {
        btn = 0;
      }
    }
    else
    {
      D_800A14A8 = btn;
      D_800A14AC = 1;
      D_800A14AE = 0;
    }
  }
  else
  {
    D_800A14A8 = 0;
    D_800A14AC = 0;
    D_800A14AE = 0;
  }
  if (btn & 0x800)
  {
    out |= 1;
  }
  if (btn & 0x400)
  {
    out |= 2;
  }
  if (btn & 0x200)
  {
    out |= 4;
  }
  if (btn & 0x100)
  {
    out |= 8;
  }
  if (btn & 0x4000)
  {
    out |= 0x20;
  }
  if (btn & 0x8000)
  {
    out |= 0x10;
  }
  if (btn & 0x1000)
  {
    out |= 0x80;
  }
  return out;
}


