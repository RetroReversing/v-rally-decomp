#include "snapshot29_0433f7af8f6d.h"

static inline int __repair_inline_sum(int left, int right)
{
  return left + right;
}

#define P (*(Obj **)(D_800C02AE+0x32F2))
extern u8 D_800C02AE[];
void func_80063264(s32);
typedef struct 
{
  u8 pad[42];
  u16 flags;
  u32 word;
} Obj;
void func_80063328(void)
{
  u8 i;
  u8 v;
  s32 flags;
  s32 w;
  s32 base;
  s32 off;
  s32 bit;
  s32 base2;
  i = 0;
  do
  {
    D_800C02AE[0x327E + i] = 0;
    i++;
  }
  while (i < 8);
  i = 0;
  do
  {
    D_800C02AE[0x327E + i] |= 1;
    i++;
  }
  while (i < 8);
  flags = P->flags;
  w = flags & 0x1000;
  v = w != 0;
  if (flags & 0x2000)
  {
    v++;
  }
  if (flags & 0x4000)
  {
    v++;
  }
  switch ((u8) v)
  {
    case 3:
      func_80063264(15);
      func_80063264(16);
      func_80063264(17);

    case 2:
      func_80063264(9);
      func_80063264(10);
      func_80063264(11);
      func_80063264(12);
      func_80063264(13);
      func_80063264(14);

    case 1:
      func_80063264(4);
      func_80063264(5);
      func_80063264(6);
      func_80063264(7);
      func_80063264(8);

    case 0:
      func_80063264(0);
      func_80063264(1);
      func_80063264(2);
      func_80063264(3);

  }

  base = 18;
  i = 0;
  bit = 1;
  base2 = 42;
  for (; i < 12; i++)
  {
    if ((P->flags & (bit << i)) == (bit << i))
    {
      if (i < 8)
      {
        off = i * 2;
        off += i;
        off = __repair_inline_sum(base, off);
        func_80063264(off);
        func_80063264(off + 1);
        func_80063264(off + 2);
      }
      else
      {
        off = i - 8;
        off = off * 2;
        func_80063264(__repair_inline_sum(base, off + 24) & 65534);
        off = __repair_inline_sum(base2, off);
        func_80063264((off + 1) & 65535);
        off += 2;
        func_80063264(off & 65534);
      }
    }
  }

  if ((P->word & 0x3000000) == 0x3000000)
  {
    i = 0;
    do
    {
      D_800C02AE[0x327E + i] = 255;
      i++;
    }
    while (i < 8);
  }
}
