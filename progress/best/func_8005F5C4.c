typedef struct Obj5F
{
  u8 p[6];
  s16 a6;
  u16 a8;
  u8 pA;
  u8 b;
  u8 c;
  u8 d;
  u8 e;
} Obj5F;
extern u8 D_800A14E0;
extern u8 D_800A14E1;
extern u8 D_800A14E2;
extern u8 D_800A5490;
extern u8 D_800A54FC;
extern u8 D_800A5508;
extern u8 D_800C02AE;
extern s16 D_800A5504;
extern s8 D_800A5506;
extern void *func_800592D0(s32);
extern void func_80052E94(s32, s16 *);
extern void func_80059618(void *, u8, u8, u8, s32);
extern void func_800596F4(void *, s16, s16, s16 *);
extern void func_8006874C(s32);
extern void func_80097E30(s16 *, s32, s32);
extern void func_800980D0(s16 *, void *);
extern void func_80099DF8(s16 *, void *, int, void *);
static inline static u8 inline_fn(Obj5F *arg0)
{
  return arg0->d;
}

void func_8005F5C4(void)
{
  int new_var2;
  s16 sp18;
  s32 s4 = 0;
  s32 fp = 0;
  void *new_var;
  s16 sp1A;
  u8 s6 = 0;
  u16 s0;
  u16 s1;
  u16 v;
  u8 s3;
  Obj5F *s2;
  Obj5F *s5;
  do
  {
    s2 = func_800592D0((s0 * 4) + 5);
    func_80097E30(&sp18, 0, 15);
    s3 = 0;
    new_var2 = s3 * 16;
    new_var = (void *) (0x800C3B16 + new_var2);
    do
    {
      if (s0 == 0)
      {
        func_80099DF8(&sp18, &D_800A54FC, s3 + 1, (void *) (0x800C3A56 + new_var2));
      }
      else
        if (s0 == 1)
      {
        func_80099DF8(&sp18, &D_800A54FC, s3 + 1, (void *) (0x800C3B56 + new_var2));
      }
      else
        if (s0 == 2)
      {
        func_80099DF8(&sp18, &D_800A54FC, s3 + 1, new_var);
      }
      func_80059618(s2, s2->b, s2->c, inline_fn(s2), s2->e);
      v = s3++;
      func_800596F4(s2, s2->a6, s2->a8 + (v * 22), &sp18);
    }
    while ((s3 & 255) < 3);
    s1 = s6 & 255;
    s2 = func_800592D0((s1 * 4) + 7);
    s5 = func_800592D0((s1 * 4) + 6);
    s3 = 0;
    do
    {
      if (s1 == 0)
      {
        s4 = *((s32 *) (0x800C3A50 + (s3 * 16)));
      }
      else
        if (s1 == 1)
      {
        s4 = *((s32 *) (0x800C3B50 + (s3 * 16)));
      }
      else
        if (s1 == 2)
      {
        s4 = *((s32 *) (0x800c3b16 + (s3 * 16)));
      }
      func_80097E30(&sp18, 0, 15);
      func_80052E94(s4, &sp18);
      v = s3 & 255;
      func_800596F4(s2, s2->a6, s2->a8 + (v * 22), &sp18);
      if (v == 0)
      {
        s0 = s6;
        s0 = s0 & 255;
        fp = s4;
      }
      else
      {
        func_80097E30(&sp18, 0, 15);
        sp18 = D_800A5504;
        do
        {
          sp1A = D_800A5506;
        }
        while (0);
        func_80052E94(s4 - fp, (s16 *) (&sp1A));
        func_800980D0(&sp18, &D_800A5508);
        func_800596F4(s5, s5->a6, s5->a8 + ((v - 1) * 22), &sp18);
      }
      s3++;
    }
    while ((s3 & 255) < 3);
    s6++;
    s0 = s6 & 255;
  }
  while ((s6 & 255) <= (3 - 1));
  s2 = func_800592D0(17);
  func_80059618(s2, s2->b, s2->c, s2->d, s2->e);
  func_80097E30(&sp18, 0, 15);
  func_80099DF8(&sp18, &D_800A5490, D_800A14E0, &sp18);
  func_800596F4(s2, s2->a6, s2->a8, &sp18);
  s2 = func_800592D0(18);
  func_80059618(s2, s2->b, s2->c, inline_fn(s2), s2->e);
  func_80097E30(&sp18, 0, 15);
  func_80099DF8(&sp18, &D_800A5490, D_800A14E1, &sp18);
  func_800596F4(s2, s2->a6, s2->a8, &sp18);
  s2 = func_800592D0(19);
  func_80059618(s2, s2->b, s2->c, s2->d, s2->e);
  func_80097E30(&sp18, 0, 15);
  func_80099DF8(&sp18, &D_800A5490, D_800A14E2, &sp18);
  func_800596F4(s2, s2->a6, s2->a8, &sp18);
  s2 = func_800592D0(20);
  func_80059618(s2, s2->b, s2->c, inline_fn(s2), s2->e);
  func_80097E30(&sp18, 0, 15);
  func_80099DF8(&sp18, &D_800A5490, ((D_800A14E0 + D_800A14E1) + D_800A14E2) / 3, &sp18);
  func_800596F4(s2, s2->a6, s2->a8, &sp18);
  func_8006874C(-1);
}
