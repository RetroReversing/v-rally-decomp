extern void *D_800C7F84;
extern char *D_800C35A0;
s32 func_80034FF0(s32, s32);
void *func_80040260(s32, s16, s16, s32, void *, s32);
void func_8003E06C(void);
void func_8003E0D4(void);
void func_8003E134(void);
void func_8003E1BC(s32 arg0, s32 arg1)
{
  void *a3;
  char *tbl;
  void *state;
  void *new_var3;
  char *new_var5;
  u16 mode;
  s32 new_var4;
  int new_var6;
  s16 field8;
  s16 fieldA;
  s32 s5;
  s32 s1;
  s32 s4;
  s32 a1;
  void *new_var;
  s32 s0;
  u16 s2;
  int new_var2;
  void *s3;
  s32 s6;
  void *s7;
  a3 = D_800C7F84;
  new_var = a3;
  tbl = D_800C35A0;
  mode = *((u16 *) (tbl + 0xE));
  state = *((void **) (((char *) a3) + 0x178));
  s1 = arg1;
  field8 = *((s16 *) (((char *) state) + 8));
  new_var6 = 0xA;
  fieldA = *((s16 *) (((char *) state) + new_var6));
  s5 = arg0;
  s4 = fieldA + 6;
  a1 = field8 + 0x14;
  if (mode == 1)
  {
    if ((*((u16 *) (tbl + 0x1E))) != 0)
    {
      new_var4 = a1 << 16;
      s0 = new_var4;
      s7 = (void *) func_8003E06C;
      s6 = 1;
      s2 = 0;
      s5 = s2 < 4U;
      do
      {
        do
        {
          s3 = func_80040260(s5, (s16) (s0 >> 16), (s16) (s4 + (s2 * 0xB)), 5, func_8003E06C, 1);
          *((s32 *) (((char *) s3) + 0xA4)) = func_80034FF0(s1 + 0x4C, 0);
          s2 += 1;
        }
        while (0);
        *((u16 *) (((char *) s3) + 0x7A)) = s2;
        new_var = a3;
        *((void **) (((char *) s3) + 0xA8)) = new_var;
      }
      while (s5);
    }
  }
  else
    if (mode == 2)
  {
    if ((s0 = *((u16 *) (tbl + 0x1E))) != 0)
    {
      if (0 == ((*((u16 *) (tbl + 0x12))) & 1))
      {
        a1 = field8;
        new_var2 = field8 + 6;
        if ((*((s32 *) (((char *) new_var) + 0xC))) == 3)
        {
          a1 = new_var2;
        }
      }
      s0 = a1 << 16;
      s0 = s0 >> 16;
      s2 = 1;
      s3 = func_80040260(s5, (s16) s0, (s16) (s4 + new_var6), 5, func_8003E0D4, 1);
      new_var3 = s3;
      s1 += 0x4C;
      *((s32 *) (((char *) new_var3) + 0xA4)) = func_80034FF0(s1, 0);
      *((u8 *) (((char *) new_var3) + 0x90)) = 0xFE;
      *((u8 *) (((char *) new_var3) + 0x91)) = 0xD5;
      *((s8 *) (((char *) new_var3) + 0x92)) = 0x1E;
      *((u8 *) (((char *) new_var3) + 0x93)) = 0xFF;
      new_var5 = (char *) new_var3;
      *((void **) (new_var5 + 0xA8)) = new_var;
      s3 = func_80040260(s5, (s16) s0, (s16) s4, 5, func_8003E134, 1);
      *((s32 *) (((char *) s3) + 0xA4)) = func_80034FF0(s1, 0);
      *((void **) (((char *) s3) + 0xA8)) = new_var;
    }
  }
}
