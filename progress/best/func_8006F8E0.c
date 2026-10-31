typedef struct 
{
  u8 pad[0x14];
  u16 count;
  u8 rest[0x2AE];
} Entry;
extern Entry *D_800D0634;
extern u8 D_800C02AE[];
void func_8006C024(s32, s32);
void func_8006BA44(s32, s32);
void func_8006C3E4(s32);
void func_8006CF7C(s32);
void func_8006CCD0(void);
void func_8006C780(void);
void func_8006F8E0(void)
{
  s32 outer = 0;
  s32 *new_var;
  s32 inner;
  do
  {
    s32 index = outer & 0xff;
    inner = 0;
    if (D_800D0634[index].count != 0)
    {
      unsigned short v1;
      s32 v0;
      s32 base;
      do
      {
        func_8006C024(index, inner & 0xff);
        new_var = &v0;
        v1 = index;
        base = *((s32 *) (D_800C02AE + 0x10386));
        inner = v1;
        v0 = inner << 1;
        v0 = (*new_var) + inner;
        v0 = (*new_var) << 2;
        v0 = (*new_var) - inner;
        v0 = (*new_var) << 4;
        v0 = v0 + inner;
        v0 = v0 << 2;
        v0 = v0 + base;
        v1 = *((u16 *) (v0 + 0x14));
        inner++;
      }
      while (((u32) (inner & 0xff)) < ((u32) v1));
    }
    outer++;
  }
  while (((u32) (outer & 0xff)) < 8);
  for (inner = 0; ((u32) (inner & 0xff)) < 4; inner++)
  {
    func_8006BA44(1, inner & 0xff);
  }

  for (inner = 0; ((u32) (inner & 0xff)) < 5; inner++)
  {
    func_8006BA44(2, inner & 0xff);
  }

  for (inner = 0; ((u32) (inner & 0xff)) < 6; inner++)
  {
    func_8006BA44(3, inner & 0xff);
  }

  for (inner = 0; ((u32) (inner & 0xff)) < 3; inner++)
  {
    func_8006BA44(4, inner & 0xff);
  }

  for (outer = 0; ((u32) (outer & 0xff)) < 12; outer++)
  {
    func_8006C3E4(outer & 0xff);
  }

  for (outer = 0; ((u32) (outer & 0xff)) < 4; outer++)
  {
    func_8006CF7C(outer & 0xff);
  }

  func_8006CCD0();
  func_8006C780();
}
