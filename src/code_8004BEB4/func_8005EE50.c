#include "common.h"

void func_8004CF7C(s32, s32, s16, s16, f32, s32, s32);
void func_80059618(void *, u8, u8, u8, s32);
void func_800596F4(void *, s16, s16, void *);
void *func_8005A744(s32, s32);
extern void *D_800A1468;
extern s32 D_800A54D4;
extern s32 D_800C02AE;
extern s32 D_800D05D8;
void func_8005EE50(s32 arg0, s32 arg1)
{
  void *temp_v0;
  void *temp_v1;
  void *p;
  s32 var_s3;
  s8 var_s4;
  u16 var_s1;
  u16 var_s2;
  p = *((void **) (((u8 *) (&D_800C02AE)) + 0x325A));
  temp_v0 = func_8005A744(arg0 - (*((u8 *) (((*((u8 **) (((u8 *) p) + 0x10))) + (((s16 *) p)[1] * 0x14)) + 0xD))), *((s32 *) (((u8 *) D_800A1468) + 0xC)));
  temp_v1 = *((void **) (((u8 *) temp_v0) + 0x28));
  var_s1 = ((u16 *) temp_v1)[3];
  var_s2 = ((u16 *) temp_v1)[4];
  var_s3 = arg1;
  var_s4 = var_s3 - 1;
  if ((*((u8 *) (((u8 *) temp_v0) + 0x42))) != 0)
  {
    func_80059618(((u8 *) temp_v0) + 4, 0xDC, 0xDC, 0xE, 0xFF);
    var_s4 = var_s3 + 7;
  }
  else
  {
    func_80059618(((u8 *) temp_v0) + 4, *((u8 *) (((u8 *) temp_v0) + 0xF)), *((u8 *) (((u8 *) temp_v0) + 0x10)), *((u8 *) (((u8 *) temp_v0) + 0x11)), 0xFF);
  }
  if ((arg1 << 0x10) != 0)
  {
    var_s3 = 0x24D;
    if (((s16) var_s1) < 0)
    {
      var_s1 = -var_s1;
    }
    if (((s16) var_s2) < 0)
    {
      var_s2 = -var_s2;
    }
    if ((*((u8 *) (((u8 *) D_800A1468) + var_s3))) == 0)
    {
      func_8004CF7C(D_800D05D8, (u16) var_s4, (s16) (var_s1 - 0x60), (s16) var_s2, 1.0f, 0, 0xFF);
    }
  }
  else
  {
    func_800596F4(((u8 *) temp_v0) + 4, (s16) var_s1, (s16) var_s2, &D_800A54D4);
  }
}
