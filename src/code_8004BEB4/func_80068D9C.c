#include "decompdecomp_snapshot_80068d9c.h"
#line 1 "func.c"
extern u8 *D_800A1468;
extern u8 D_800C02AE[];void *func_800592AC(u32);
extern void func_800592F4(s32 arg0, s32);
extern void func_80068E5C(s32);
extern void func_8008A0D8(void *, s32, s32);
s32 func_80068D9C(s32 arg0)
{
  u8 *rec;
  u8 *obj;
  u8 *p;
  u8 v;
  obj = D_800A1468;
  rec = (*((u8 **) (D_800C02AE + 0x32F2))) + ((*((s8 *) (obj + 0x22A))) * 0x28);
  v = rec[0x48];
  if (v & 0x10)
  {
    p = *((u8 **) (obj + 0xC));
    rec[0x48] = v & 0xEF;
    obj = p + 4;
    func_8008A0D8(*((void **) (D_800C02AE + 0x325A)), 0x17, 1);
    p = func_800592AC(6);
    p[0xF] = obj[0xB];
    p[0x10] = obj[0xC];
    p[0x11] = obj[0xD];
    func_800592F4(arg0, 0);
  }
  else
  {
    func_80068E5C(arg0);
  }
  return 0;
}

