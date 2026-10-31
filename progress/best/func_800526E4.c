extern u8 D_800C02AE[];
typedef struct 
{
  s32 a[4];
  s16 b[12];
  u8 pad28[16];
  u8 c[4][4];
  u8 pad38[0x120];
  s32 d[4];
  u8 tail[0x8A];
} Temp;
void func_800526E4(u8 *arg0)
{
  Temp *p = (Temp *) arg0;
  u32 a;
  unsigned long long new_var4 = 0;
  u32 b;
  volatile int pad;
  u8 *q;
  u8 *base;
  u8 *new_var3;
  u8 *src;
  unsigned int new_var;
  u8 *dst;
  u8 *new_var2;
  for (a = 0; a < 4; a++)
  {
    p->a[a] = 0;
  }

  q = *((u8 **) (D_800C02AE + 0x1039A));
  a = 0;
  if (*((u16 *) (D_800C02AE + 0x1037A)))
  {
    q += 16;
    do
    {
      *((u16 *) q) &= 0xFFFD;
      q += 0x2C4;
    }
    while ((++a) < (*((u16 *) (D_800C02AE + 0x1037A))));
  }
  a = 0;
  while (a < (*((u16 *) (D_800C02AE + 0x1037A))))
  {
    p->b[a] = 0;
    a++;
  }

  for (a = 0; a < 4; a++)
  {
    b = 0;
    while (b < (*((u16 *) (D_800C02AE + 0x1037A))))
    {
      new_var2 = ((arg0 + 0x28) + (b * 4)) + a;
      new_var4 = 0;
      *((s32 *) (((arg0 + 0x58) + (a * 4)) + (b * 16))) = new_var4;
      *((u8 *) new_var2) = 3;
      b++;
    }

    p->d[a] = new_var4;
  }

  base = *((u8 **) (D_800C02AE + 0x32F2));
  src = base + 0x44;
  new_var = 0x178;
  dst = arg0 + new_var;
  new_var3 = base + 0xE4;
  while (src != new_var3)
  {
    typedef struct 
    {
      s32 w[4];
    } Quad;
    *((Quad *) dst) = *((Quad *) src);
    src += 16;
    dst += 16;
  }

  arg0[0x21A] = 1;
}
