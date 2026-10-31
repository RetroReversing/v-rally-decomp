#define U(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define A(p,o) (*(u8 **)((u8 *)(p)+(o)))
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
typedef struct Blob
{
  u8 w[708];
} Blob;
extern u8 *D_800C3508;
extern u8 *D_800C35A0;
extern u8 *D_800A1468;
extern u8 *D_800A14D0;
extern Blob *D_800D0648;
extern s32 *D_800A11B0;
extern s32 D_800B0548;
extern s32 D_800D05D8;
extern f64 D_800A5D10;
extern void func_8005937C(s32, s32);
extern void func_8005C198(void);
extern void func_80061740(Blob);
extern void func_80062184(Blob);
extern unsigned char func_800592AC(s32);
extern void func_8006185C(s32, s32);
extern void func_800710F0(void);
extern void func_8004D08C(s32, s32, s16, s16, f32, f32, s32, s32);
void func_8007159C(void)
{
  u8 *__repair_cached_pointer = D_800C3508;
  Blob blob;
  u8 *p = A(__repair_cached_pointer, 16) + (H(D_800C3508, 2) * 20);
  u8 choice = p[14];
  s32 selected;
  u8 *new_var;
  s32 i;
  if (choice <= 33)
  {
    if (D_800A1468[0x245] == 0)
    {
      selected = choice - p[13];
      U(D_800C35A0, 32) = selected;
      func_8005937C(choice, U(&D_800D0648[selected], 20));
      if (selected != D_800B0548)
      {
        if (*D_800A11B0)
        {
          func_8005C198();
        }
        if (D_800A1468[0x2be] == 0)
        {
          new_var = D_800C35A0;
          func_80061740(D_800D0648[U(new_var, 32)]);
          D_800B0548 = selected;
        }
      }
    }
    else
    {
      func_8006185C(func_800592AC(U(D_800C35A0, 32)), 0);
    }
    if (H(D_800C3508, 2) == 2)
    {
      func_800710F0();
    }
    ;
    func_80062184(D_800D0648[U(D_800C35A0, 32)]);
    if (D_800A1468[0x24d] == 0)
    {
      u32 temp = D_800A1468[0x2be];
      if (temp == 0)
      {
        ;
        if (temp < U(&blob, 20))
        {
          do
          {
            func_8004D08C(D_800D05D8, 0 & 255, H(D_800A14D0, 0), (s16) (U(D_800A14D0, 2) + ((0 & ((0, 255))) * D_800A14D0[8])), (f32) (((f64) F((0, D_800A14D0), 4)) - D_800A5D10), F(D_800A14D0, 4), ((u8 *) (&blob))[0x2bc + (0 & 255)], 255);
            i++;
            if (!D_800B0548)
            {
            }
          }
          while (((u32) (0 & 255)) < U(&blob, 20));
        }
      }
    }
  }
}

