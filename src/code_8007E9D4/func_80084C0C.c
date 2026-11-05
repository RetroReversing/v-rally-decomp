#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern u8 *D_800A1B70;
s8 func_80084C0C(s32 arg0, s32 arg1)
{
  s32 pad[1];
  signed char *e;
  signed char a2;
  int a1;
  int __repair_phase_val;
  signed char new_var2;
  s32 a0;
  int new_var;
  s32 v1;
  u8 *new_var3;
  u8 *tbl;
  u8 idx;
  if (arg1 != 0x10000)
  {
    if (arg1 != 0x20000)
    {
      return 0;
    }
    new_var3 = D_800A1B70;
    idx = arg0;
    __repair_phase_val = (a2 = *((signed char *) ((new_var3 - (-(idx * 6))) + 0x1E)));
    e = (signed char *) (D_800A1B70 + (idx * 20));
    a1 = e[0x5F];
    v1 = a1 + e[0x60];
    if (__repair_phase_val >= v1)
    {
      a1 = e[0x5C];
      a0 = v1;
    }
    else
    {
      v1 = a1 + e[0x5E];
      if (v1 < __repair_phase_val)
      {
        return 0;
      }
      a1 = e[0x5D];
      a0 = v1;
    }
  }
  else
  {
    tbl = D_800A1B70;
    idx = arg0;
    __repair_phase_val = (a2 = *((signed char *) ((tbl - (-(idx * 6))) + 0x1F)));
    do
    {
      e = (signed char *) (tbl + (idx * 20));
      a1 = e[0x64];
      v1 = a1 + e[0x65];
    }
    while (0);
    if (__repair_phase_val >= v1)
    {
      a1 = e[0x61];
      a0 = v1;
    }
    else
    {
      v1 = a1 + e[0x63];
      if (v1 < __repair_phase_val)
      {
        return 0;
      }
      new_var2 = e[0x62];
      a1 = new_var2;
      a0 = v1;
    }
  }
  if (a0 < a2)
  {
    if (a1 < a2)
    {
      return 0x7F;
    }
    if (a0 != 0)
    {
      a1 -= a0;
      a2 -= a0;
      a0 = 0;
    }
    v1 = a2 * 0x7F;
    new_var = a1 - a0;
    v1 = v1 / new_var;
    return v1;
  }
  new_var = a2 < a0;
  if (new_var)
  {
    if (a2 < a1)
    {
      return -0x80;
    }
    if (a0 != 0)
    {
      a1 -= a0;
      a2 -= a0;
      a0 = 0;
    }
    v1 = a2 << 7;
    new_var = a0 - a1;
    v1 = v1 / new_var;
    return v1;
  }
  return 0;
}

