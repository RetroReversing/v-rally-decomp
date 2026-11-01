extern u8 D_800C02AE[];
extern f64 D_800A4008;
void guMtxCatF(void *, void *, void *);
void guMtxF2L(void *, s32);
void func_8001C358(void *, void *);
void func_8001C108(void *, s32, s32, s32, void *, void *, void *);
s32 func_80010BFC(s32 arg0, u8 *arg1, u8 *arg2)
{
  s32 sp20[0x10];
  u8 *temp_v1;
  f64 lim;
  s32 v;
  guMtxCatF(arg1 + 0x40, arg1, arg1 + 0x80);
  guMtxCatF(arg2, arg1 + 0x80, arg1 + 0x80);
  temp_v1 = *((u8 **) (&D_800C02AE[0x32F2]));
  *((s32 *) (arg1 + 0x108)) = 0;
  if (*(u16 *)(temp_v1 + 0xE) != 1 && *(u16 *)(temp_v1 + 0x12) != 1)
    *(f32 *)(arg1 + 0x104) = 0.5f;
  else
    *(f32 *)(arg1 + 0x104) = 1.0f;
  if (*(u16 *)(&D_800C02AE[0x32A8]) == 1)
    *(f32 *)(arg1 + 0x104) = *(f32 *)(arg1 + 0x104) * 1.328f;
  *(f32 *)(arg1 + 0x104) = *(f32 *)(arg1 + 0x104) * *(f32 *)(arg1 + 0xDC);
  *(s32 *)(arg1 + 0x10C) = 0;
  func_8001C358(arg1 + 0x80, sp20);
  func_8001C108(sp20, *(s32 *)(arg1 + 0x104), *(s32 *)(arg1 + 0x108), *(s32 *)(arg1 + 0x10C), arg1 + 0x110, arg1 + 0x114, arg1 + 0x118);
  v = (s32)*(f32 *)(arg1 + 0xB0);
  lim = D_800A4008;
  if (v < 0) v = -v;
  if (!((f64)v < lim)) return 0;
  v = (s32)*(f32 *)(arg1 + 0xB4);
  if (v < 0) v = -v;
  if (!((f64)v < lim)) return 0;
  v = (s32)*(f32 *)(arg1 + 0xB8);
  if (v < 0) v = -v;
  if (!((f64)v < lim)) return 0;
  if (arg0 != 0) guMtxF2L(arg1 + 0x80, arg0);
  return 1;
}
