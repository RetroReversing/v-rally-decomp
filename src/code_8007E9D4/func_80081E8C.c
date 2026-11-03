#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
} Five81;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern s32 D_800B7300;
void func_80081040(s32, void *, s32, s32, Five81);
void func_8008E13C(void *, void *, u32);
u32 func_80081E8C(u8 *dst, u32 len)
{
  u32 rem = len;
  u32 n;
  u32 words;
  u32 tail;
  u32 count;
  s32 *size;
  s32 *ptr;
  u32 *s;
  int new_var2;
  u32 *d;
  u32 *e;
  s32 *new_var;
  Five81 *five;
  int new_var3;
  if (len)
  {
    five = (Five81 *) (D_800AE850 + 0x235c);
    size = (s32 *) (D_800C02AE + 0x3092);
    ptr = size - 1;
    do
    {
      if ((*size) <= 0)
      {
        func_80081040(((*((s32 *) 0x800B7300)) + size[5]) + 8192, (void *) size[-2], 8192, ((s32 *) five)[-1], *five);
        *size = 8192;
        size[5] += 8192;
        size[-1] = size[-2];
      }
      n = rem;
      if (n >= ((u32) (*size)))
      {
        n = *size;
      }
      new_var3 = 0x308E;
      if ((((u32) dst) & 3) || ((*((u32 *) (D_800C02AE + new_var3))) & 3))
      {
        func_8008E13C(dst, *((void **) (D_800C02AE + 0x308E)), n);
        dst += n;
        *ptr += n;
      }
      else
      {
        u8 *src;
        u32 bytes;
        words = n >> 2;
        src = *((u8 **) (D_800C02AE + 0x308E));
        bytes = words << 2;
        ;
        if ((dst < (src + bytes)) & (src < dst))
        {
          d = (u32 *) (dst + bytes);
          e = (u32 *) (src + bytes);
          count = bytes >> 2;
          while (count)
          {
            e--;
            d--;
            count--;
            *d = *e;
          }

        }
        else
        {
          s = (u32 *) src;
          d = (u32 *) dst;
          count = bytes >> 2;
          while (count)
          {
            *d = *s;
            s++;
            count--;
            d++;
          }

        }
        dst += words * 4;
        *ptr += words * 4;
        tail = n & 3;
        func_8008E13C(dst, *((void **) (D_800C02AE + 0x308E)), tail);
        dst += tail;
        *ptr += tail;
      }
      rem -= n;
      *(new_var = size) -= n;
    }
    while (rem);
  }
  return len;
}


