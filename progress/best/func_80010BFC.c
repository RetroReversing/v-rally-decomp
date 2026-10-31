extern u8 D_800C02AE[];
extern f64 D_800A4008;
void guMtxCatF(void *, void *, void *);
void guMtxF2L(void *, s32);
void func_8001C358(void *, void *);
void func_8001C108(void *, s32, s32, s32, void *, void *, void *);
s32 func_80010BFC(s32 arg0, u8 *arg1, u8 *arg2)
{
  s32 sp20[0x10];
  s32 s3;
  u8 *s2;
  u8 *s1;
  u8 *s0;
  u8 *temp_v1;
  s32 v;
  f64 lim;
  s2 = arg1;
  s3 = arg0;
  s1 = arg2;
  s0 = s2 + 0x80;
  guMtxCatF(s2 + 0x40, s2, s0);
  guMtxCatF(s1, s0, s0);
  temp_v1 = *((u8 **) (&D_800C02AE[0x32F2]));
  *((s32 *) (s2 + 0x108)) = 0;
  if (((*((u16 *) (temp_v1 + 0xE))) != 1) && ((*((u16 *) (temp_v1 + 0x12))) != 1))
  {
    *((f32 *) (s2 + 0x104)) = 0.5f;
  }
  else
  {
    *((f32 *) (s2 + 0x104)) = 1.0f;
  }
  if ((*((u16 *) (&D_800C02AE[0x32A8]))) == 1)
  {
    *((f32 *) (s2 + 0x104)) = (*((f32 *) (s2 + 0x104))) * 1.328f;
  }
  *((s32 *) (s2 + 0x10C)) = 0;
  *((f32 *) (s2 + 0x104)) = (*((f32 *) (s2 + 0x104))) * (*((f32 *) (s2 + 0xDC)));
  func_8001C358(s2 + 0x80, sp20);
  func_8001C108(sp20, *((s32 *) (s2 + 0x104)), *((s32 *) (s2 + 0x108)), *((s32 *) (s2 + 0x10C)), s2 + 0x110, s2 + 0x114, s2 + 0x118);
  lim = D_800A4008;
  v = (s32) (*((f32 *) (s2 + 0xB0)));
  if (v < 0)
  {
    v = -v;
  }
  if (!(((f64) v) < lim))
  {
    return 0;
  }
  ;
  if (((s32) (*((f32 *) (s2 + 0xB4)))) < 0)
  {
    v = -v;
  }
  if (!(((f64) v) < lim))
  {
    return 0;
  }
  ;
  if (((s32) (*((f32 *) (s2 + 0xB8)))) < 0)
  {
    v = -v;
  }
  if (!(((f64) v) < lim))
  {
    return 0;
  }
  if (s3 != 0)
  {
    guMtxF2L(s2 + 0x80, s3);
  }
  return 1;
}
