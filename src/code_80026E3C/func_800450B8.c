#include "decompdecomp_snapshot_800450b8.h"
#line 1 "func.c"
extern char *D_800C35A0;
extern s32 D_8009D540;
s32 func_80041564(void);
void func_800450B8(void *arg0)
{
  s32 mode;
  u8 swapped;
  void *ctx;
  s32 *slot;
  s32 *other;
  s32 base;
  u32 val;
  u32 prev;
  s32 i;
  u32 off;
  s32 *q;
  s32 tmp;
  char *cfg;
  unsigned char *rec;
  s32 t;
  u32 numer;
  u32 denom;
  mode = *((u16 *) (D_800C35A0 + 0xE));
  swapped = 1;
  if (mode == 2)
  {
    goto mode2;
  }
  if (mode >= 3)
  {
    goto done;
  }
  if (mode != 1)
  {
    goto done;
  }
  ctx = *((void **) (((u8 *) arg0) + 0x6C));
  slot = *((s32 **) (((u8 *) ctx) + 0x24));
  slot += 6;
  *slot = *((s32 *) (((u8 *) ctx) + 4));
  ctx = *((void **) (((u8 *) arg0) + 0x6C));
  other = *((s32 **) (((u8 *) ctx) + 0x28));
  other += 6;
  base = func_80041564();
  cfg = D_800C35A0;
  if (((*((u16 *) (cfg + 0x2C))) & 0x4000) && ((*((u16 *) (cfg + 0x1E))) == 0))
  {
    rec = ((char *) base) + ((*((u16 *) (cfg + 0x22))) << 6);
    if (rec[0x38] != 0)
    {
      t = *((s32 *) (rec + 0x2C));
      if (((u32) t) >= 0xBU)
      {
        *slot = t - 3;
      }
    }
    else
    {
      t = *((s32 *) (rec + 0x2C));
      if (((u32) t) >= 0x1FU)
      {
        *slot = t - 0xA;
      }
    }
  }
  numer = *((s32 *) ((((char *) base) + ((*((u16 *) (D_800C35A0 + 0x22))) * 4)) + 0x22C)); numer *= D_8009D540; denom = *slot; *other = (numer * 0xE10) / (denom * 0x3E8);
  ctx = *((void **) (((u8 *) arg0) + 0x6C));
  slot = *((s32 **) (((u8 *) ctx) + 0x24));
  other = *((s32 **) (((u8 *) ctx) + 0x28));
  if (swapped != 0)
  {
    do
    {
      swapped = 0;
      i = 6;
      do
      {
        off = (i & 0xFF) * 4;
        q = (s32 *) (off + ((int) slot));
        val = q[0];
        prev = q[-1];
        if (prev > val)
        {
          q[0] = prev;
          q[-1] = val;
          tmp = *((s32 *) (off + ((int) other)));
          swapped = 1;
          *((s32 *) (((u8 *) other) + off)) = *((s32 *) ((((u8 *) other) + off) - 4));
          *((s32 *) ((((u8 *) other) + off) - 4)) = tmp;
        }
        i -= 1;
      }
      while ((i & 0xFF) != 0);
    }
    while (swapped != 0);
  }
  goto done;
  mode2:
  ctx = *((void **) (((u8 *) arg0) + 0x6C));
  slot = *((s32 **) (((u8 *) ctx) + 0x24));
  slot += 3;
  *slot = *((s32 *) (((u8 *) ctx) + 4));
  ctx = *((void **) (((u8 *) arg0) + 0x6C));
  do
  {
    other = *((s32 **) (((u8 *) ctx) + 0x28));
    other += 3;
    base = func_80041564();
    cfg = D_800C35A0;
    if (((*((u16 *) (cfg + 0x2C))) & 0x4000) && ((*((u16 *) (cfg + 0x1E))) == 0))
    {
      rec = ((char *) base) + ((*((u16 *) (cfg + 0x22))) << 6);
      if (rec[0x38] != 0)
      {
        t = *((s32 *) (rec + 0x2C));
        if (((u32) t) >= 0xBU)
        {
          *slot = t - 3;
        }
      }
      else
      {
        t = *((s32 *) (rec + 0x2C));
        if (((u32) t) >= 0x1FU)
        {
          *slot = t - 0xA;
        }
      }
    }
    numer = *((s32 *) ((((char *) base) + ((*((u16 *) (D_800C35A0 + 0x22))) * 4)) + 0x22C)); numer *= D_8009D540; denom = *slot; *other = (numer * 0xE10) / (denom * 0x3E8);
  }
  while (0);
  ctx = *((void **) (((u8 *) arg0) + 0x6C));
  slot = *((s32 **) (((u8 *) ctx) + 0x24));
  other = *((s32 **) (((u8 *) ctx) + 0x28));
  if (swapped != 0)
  {
    do
    {
      swapped = 0;
      i = 3;
      do
      {
        off = (i & 0xFF) * 4;
        q = (s32 *) (off + ((int) slot));
        val = q[0];
        prev = q[-1];
        if (val < prev)
        {
          q[0] = prev;
          q[-1] = val;
          tmp = *((s32 *) (off + ((int) other)));
          swapped = 1;
          *((s32 *) (((u8 *) other) + off)) = *((s32 *) ((((u8 *) other) + off) - 4));
          *((s32 *) ((((u8 *) other) + off) - 4)) = tmp;
        }
        i -= 1;
      }
      while ((i & 0xFF) != 0);
    }
    while (swapped != 0);
  }
  done:
  return;
}

