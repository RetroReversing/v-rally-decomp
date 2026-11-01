#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern void func_8000C188(s32);
extern void func_80035438(s32);
extern void func_80053A78(void);
extern void func_8007EE9C(s32);
extern void func_80081B28(s32);
extern u8 D_800A17F0;
extern u8 D_800AE850[];
extern char *D_800C35A0;
extern u8 D_800C02AE[];
typedef struct { s32 w[61]; } Blk;
typedef struct Slot16
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
} Slot16;
static inline s32 *inline_fn()
{
  return (s32 *) (D_800C02AE + 0x7F5A);
}

void func_80077054(void)
{
  u8 *flag;
  char *obj;
  s32 first;
  u8 *slots;
  Slot16 *src;
  Slot16 *dst;
  Slot16 *end;
  u8 *mode;
  u16 modeByte;
  if ((*((u16 *) (D_800C35A0 + 0x1E))) != 8)
  {
    return;
  }
  if (D_800A17F0 != 0)
  {
    return;
  }
  flag = D_800C02AE + 0x805A;
  if ((*flag) == 0)
  {
    return;
  }
  slots = (char *) D_800AE850;
  slots += (s32) 0x2408;
  first = *((s32 *) (D_800AE850 + 0x240C));
  *flag = 0;
  func_8007EE9C(first);
  func_8007EE9C(*((s32 *) slots));
  {
    typedef struct Rec
    {
      s32 a;
      s32 b;
      u16 c;
      u8 pad[0x3A];
    } Rec;
    Rec *r;
    u8 n;
    n = 0;
    r = (Rec *) slots;
    do
    {
      slots = (u8 *)((n * sizeof(Rec)) + (u32)r);
      ((Rec *)slots)->b = 0;
      ((Rec *)slots)->a = 0;
      ((Rec *)slots)->c &= 0xFFFE;
      n++;
    }
    while (n < 4);
  }
  *(Blk *)D_800C35A0 = *(Blk *)(D_800C02AE + 0x7F66);
  obj = D_800C35A0;
  mode = D_800C02AE + 0x7F4F;
  modeByte = *mode;
  *((u16 *) (obj + 0x1E)) = modeByte;
  if (modeByte == 5)
  {
    func_80035438(*((s32 *) (D_800C02AE + 0x7F4A)));
  }
  *((u16 *) (D_800C35A0 + 0xE)) = *((u8 *) (D_800C02AE + 0x7F51));
  if ((*mode) == 8)
  {
    *((s32 *) (D_800AE850 + 0x8030)) = 5;
    func_80053A78();
  }
  else
  {
    *((s32 *) (D_800AE850 + 0x8030)) = 3;
  }
  *((u8 *) (D_800C02AE + 0x7E72)) = 0;
  func_80081B28(*((s32 *) (D_800C02AE + 0x7F56)));
  func_80081B28(*inline_fn());
  func_8000C188(*((s32 *) (D_800C02AE + 0x7F5E)));
  func_8000C188(*((s32 *) (D_800C02AE + 0x7F62)));
}

