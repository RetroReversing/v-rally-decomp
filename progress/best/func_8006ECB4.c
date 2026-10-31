extern u8 D_800C02AE[];
extern s32 func_8006FA8C(s32, u8, void *);
static inline static static static static static static static static int inline_fn(u16 arg0, int arg1)
{
  return (arg0 & 0xFF0F) | arg1;
}

void func_8006ECB4(void)
{
  f32 scale = 8.0f;
  s32 a;
  u8 *new_var4;
  int new_var5;
  s32 b;
  u8 *new_var3;
  s32 c;
  u32 w;
  u16 h;
  int new_var2;
  u8 *o;
  unsigned short new_var;
  u8 *p = D_800C02AE + 0x6E5E;
  a = (s32) ((*((f32 *) (D_800C02AE + 0x3332))) * scale);
  w = *((u32 *) (D_800C02AE + 0x6E76));
  b = (s32) ((*((f32 *) (D_800C02AE + 0x333A))) * scale);
  w &= 0xF0FFFFFF;
  w |= (a & 15) << 24;
  h = *((u16 *) p);
  h = inline_fn(h, (b & 15) << 4);
  do
  {
    *((u16 *) p) = h;
    c = (s32) ((*((f32 *) (D_800C02AE + 0x332E))) * scale);
    h = (h & 0xFFF0) | (c & 15);
    *((u16 *) p) = h;
  }
  while (0);
  new_var5 = 0x32F2;
  *((u32 *) (D_800C02AE + 0x6E76)) = w;
  o = *((u8 * volatile *) (D_800C02AE + new_var5));
  new_var3 = o + 0x50;
  h = (h & 0xEFFF) | (((*((u16 *) new_var3)) & 1) << 12);
  *((u16 *) p) = h;
  *((u16 *) (D_800C02AE + 0x6E60)) = *((u16 *) ((*((u8 * volatile *) (D_800C02AE + new_var5))) + 0x2A));
  h = (*((u16 *) (o + 0x38))) ? (h | 0x8000) : (h & 0x7FFF);
  *((u16 *) p) = h;
  new_var2 = ((*((u32 *) (D_800C02AE + 0x32AA))) & 3) << 8;
  o = *((u8 * volatile *) (D_800C02AE + new_var5));
  h = (h & 0xBFFF) | (((*((u16 *) (D_800C02AE + 0x32A8))) & 1) << 14);
  *((u16 *) p) = (h & 0xBFFF) | (((*((u16 *) (D_800C02AE + 0x32A8))) & 1) << 14);
  *((s16 *) (p + 4)) = *((u8 *) (o + 0x2F));
  h = (((*((u16 *) (o + 0x12))) & 1) << 13) | (h & 0xDFFF);
  *((u16 *) p) = h;
  h = (h & 0xF3FF) | (((*((u16 *) (o + 0x16))) & 3) << 10);
  a = new_var2;
  new_var = a;
  *((u16 *) p) = h;
  new_var4 = D_800C02AE + 0x6E5E;
  *((u16 *) new_var4) = (h & 0xFCFF) | new_var;
  new_var2 = *((u8 *) (o + 0x2F));
  func_8006FA8C(new_var, new_var2, p);
}
