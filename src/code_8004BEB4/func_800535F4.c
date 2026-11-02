#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
static inline void cpy16(u32 *dst, u32 *src, u32 *se)
{
  s32 i;
  if (((u32)dst < (u32)se) & ((u32)src < (u32)dst))
  {
    u32 *s = se;
    u32 *d = dst + 4;
    for (i = 4; i != 0; --i) { s--; d--; *d = *s; }
  }
  else
  {
    u32 *s = src;
    u32 *d = dst;
    for (i = 4; i != 0; --i) { *d++ = *s++; }
  }
}

void func_800535F4(void *arg0)
{
  u8 *p = arg0;
  u32 *t0, *a3;
  s32 t1;
  u8 t2;
  u32 temp[4];
  u32 *t3 = temp + 4;
  p[0x3b] = p[0xb];
  t2 = 0;
  do
  {
    t2 = 0;
    t1 = 3;
    do
    {
      u32 off = (t1 & 255) << 4;
      t0 = (u32 *)(p + off);
      off -= 16;
      a3 = (u32 *)(p + off);
      if (*t0 < *a3)
      {
        t2 = 1;
        cpy16(temp, a3, a3 + 4);
        cpy16(a3, t0, t0 + 4);
        cpy16(t0, temp, t3);
      }
      t1--;
    } while ((t1 & 255) != 0);
  } while ((t2 & 255) != 0);
}

