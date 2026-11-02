extern s32 D_800B68EC;
extern s32 D_800C34D4;
void func_800885CC(u8 *arg)
{
  u8 *p;
  u8 save;
  u32 i;
  s16 v;
  s32 t;
  p = arg;
  save = p[0xC1];
  *(s32 *) p = 0;
  for (i = 0; i < 0x134; i++)
    *arg++ = 0;
  p[0xC4] = 0xFF;
  p[0xB6] = 0xFF;
  v = 0x6000 / D_800B68EC;
  p[0xCA] = 0;
  p[0xCB] = 0x7F;
  p[0xB4] = 0x7F;
  p[0xB9] = 0x7F;
  p[0xBF] = 0xFF;
  p[0xBA] = 0x7F;
  p[0xB5] = 0x40;
  p[0xB7] = 1;
  p[0xBE] = 1;
  p[0xC0] = 0xF;
  t = D_800C34D4;
  *(u16 *) (p + 0x98) = 0xFFFF;
  *(s16 *) (p + 0x92) = 1;
  *(s16 *) (p + 0x9A) = 1;
  *(s16 *) (p + 0x9C) = 1;
  *(s32 *) (p + 0xC) = -1;
  *(s16 *) (p + 0x96) = 0x80;
  *(s16 *) (p + 0xA8) = 0x80;
  *(s16 *) (p + 0x90) = 0x80;
  p[0xC1] = save;
  *(f32 *) (p + 0x24) = 99.9f;
  *(f32 *) (p + 0x68) = 0.03125f;
  *(f32 *) (p + 0x54) = 1.0f;
  *(f32 *) (p + 0x58) = 0.003921569f;
  *(f32 *) (p + 0x5C) = 0.06666667f;
  *(s32 *) (p + 0x74) = t;
  *(s16 *) (p + 0xA0) = v;
  *(s16 *) (p + 0x94) = v;
}
