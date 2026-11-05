#define U(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define A(p,o) (*(u8 **)((u8 *)(p)+(o)))
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
typedef struct Blob
{
  s32 w[175];
  u8 tab[8];
} Blob;
extern u8 *D_800C3508;
extern u8 *D_800C35A0;
extern u8 *D_800A1468;
extern u8 *D_800A14D0;
extern Blob *D_800D0648;
extern s32 *D_800A11B0;
extern s32 D_800B0548;
extern s32 D_800D05D8;
extern const f64 D_800A5D10;
extern void func_8005937C(s32, s32);
extern void func_8005C198(void);
extern void func_80061740(Blob);
extern void func_80062184(Blob, s32);void *func_800592AC(u32);
extern void func_8006185C(s32, s32);
extern void func_800710F0(void);
extern void func_8004D08C(s32, s32, s16, s16, f32, f32, u8, u8);
void func_8007159C(void)
{
  u8 *p = A(D_800C3508, 16) + H(D_800C3508, 2) * 20;
  s32 sel = p[14];
  Blob blob;
  u8 i;
  if (sel < 34)
  {
    if (D_800A1468[0x245] == 0)
    {
      sel -= p[13];
      U(D_800C35A0, 32) = sel;
      func_8005937C(p[14], U(&D_800D0648[sel], 20));
      if (sel != D_800B0548)
      {
        if (*D_800A11B0)
        {
          func_8005C198();
        }
        if (D_800A1468[0x2be] == 0)
        {
          func_80061740(D_800D0648[U(D_800C35A0, 32)]);
          D_800B0548 = sel;
        }
      }
    }
    else
    {
      func_8006185C((s32)func_800592AC(U(D_800C35A0, 32)), 0);
    }
    if (H(D_800C3508, 2) == 2)
    {
      func_800710F0();
    }
    blob = D_800D0648[U(D_800C35A0, 32)];
    func_80062184(blob, 0);
    if (D_800A1468[0x24d] == 0 && D_800A1468[0x2be] == 0)
    {
      for (i = 0; i < U(&blob, 20); i++)
      {
        func_8004D08C(D_800D05D8, i, H(D_800A14D0, 0), U(D_800A14D0, 2) + i * D_800A14D0[8], F(D_800A14D0, 4) - D_800A5D10, F(D_800A14D0, 4), blob.tab[i], 255);
      }
    }
  }
}
