extern s32 func_800056FC(void *, u32);
extern void *func_80006008(s32);
extern void func_80006014(void *, void *, void *, void *);
extern char D_800C02AE[];
static inline static static static static static char *inline_fn(void **arg0, int arg1)
{
  return ((char *) (*arg0)) + arg1;
}

void func_800485F8(s32 arg0, s32 arg1, void *arg2, void *arg3)
{
  void *new_var;
  char pad[8];
  s32 temp_a0_3;
  void *temp_a0;
  int new_var5;
  s32 temp_v0;
  void *temp_a0_2;
  void *temp_a1;
  void *temp_v0_2;
  void *temp_v0_3;
  char *new_var3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_6;
  void **new_var8;
  void *temp_v0_7;
  void *temp_v1;
  volatile char new_var2;
  void **new_var7;
  void *temp_v1_2;
  void *temp_v1_3;
  s16 new_var4;
  void **new_var6;
  u32 unaligned_word;
  int new_var9;
  new_var8 = (void **) (((char *) arg3) + 0x178);
  do
  {
    (void) pad;
  }
  while (0);
  if (arg1 > 0)
  {
    temp_v1 = *((void **) inline_fn((void **) (D_800C02AE + 0x7CD6), 0x178));
    if (arg0 < ((*((s16 *) (((char *) temp_v1) + 0xA))) + (*((s16 *) (((char *) temp_v1) + 0xE)))))
    {
      new_var6 = new_var8;
      *((u16 *) (*((void **) (((char *) arg2) + 0x2C)))) = *((u16 *) ((*new_var6) + 8));
      new_var3 = (char *) arg2;
      *((s16 *) inline_fn((void **) (new_var3 + 0x2C), 2)) = arg0;
      temp_v1_2 = *new_var8;
      *((s16 *) inline_fn((void **) (new_var3 + 0x2C), 4)) = (s16) ((*((u16 *) (((char *) temp_v1_2) + 8))) + (*((u16 *) (((char *) temp_v1_2) + 0xC))));
      *((s16 *) inline_fn((void **) (new_var3 + 0x2C), 6)) = (s16) (arg0 + arg1);
      temp_v0 = func_800056FC(*((void **) inline_fn((void **) (D_800C02AE + 0x7CD6), 0x178)), arg1);
      temp_v0_2 = func_80006008(temp_v0);
      temp_v0_3 = ((char *) temp_v0_2) + 8;
      do
      {
        *((s32 *) (((char *) temp_v0_2) + 0)) = 0xE7000000;
        *((s32 *) (((char *) temp_v0_2) + 4)) = (new_var2 = 0);
        *((s32 *) (((char *) temp_v0_2) + 8)) = 0xE3000A01;
        *((s32 *) (((char *) temp_v0_3) + 4)) = 0x300000;
        temp_a0 = *((void **) inline_fn((void **) (D_800C02AE + 0x7CD6), 0x178));
        temp_v0_4 = ((char *) temp_v0_3) + 8;
        new_var4 = *((s16 *) (((char *) temp_a0) + 8));
        temp_v0_2 = new_var3 + 0x30;
        *((s32 *) (((char *) temp_v0_3) + 8)) = (s32) (((((s32) (((f32) new_var4) * 4.0f)) & 0xFFF) << 0xC) | ((((unsigned long long) ((s32) (((f32) (*((s16 *) (((char *) temp_a0) + 0xA)))) * 4.0f))) & 0xFFF) | 0xED000000));
        temp_a0_2 = *((void **) inline_fn((void **) (D_800C02AE + 0x7CD6), 0x178));
        temp_v0_5 = ((char *) temp_v0_4) + 8;
        new_var9 = 0xF6000000;
        *((s32 *) (((char *) temp_v0_4) + 4)) = (s32) (((((s32) (((f32) (*((s16 *) (((char *) temp_a0_2) + 0xC)))) * 4.0f)) & 0xFFF) << 0xC) | (((s32) (((f32) (*((s16 *) (((char *) temp_a0_2) + 0xE)))) * 4.0f)) & 0xFFF));
        new_var5 = ((*((u8 *) temp_v0_2)) << 8) & 0xF800;
        *((s32 *) (((char *) (((char *) temp_v0_3) + 8)) + 8)) = 0xF7000000;
        temp_a0_3 = (new_var5 | (((2 * (*((u8 *) (new_var3 + 0x31)))) * 4) & 0x7C0)) | ((((u8) (*((u8 *) (new_var3 + 0x32)))) >> 2) & 0x3E);
        *((s32 *) (((char *) temp_v0_5) + 4)) = (s32) ((((temp_a0_3 | 1) << 0x10) | 1) | temp_a0_3);
        temp_v1_3 = *((void **) (new_var3 + 0x2C));
        temp_v0_6 = (char *) temp_v0_5;
        new_var7 = &temp_v0_6;
        new_var = temp_v1_3;
        temp_v0_6 = (*new_var7) + 8;
        ;
        *((s32 *) (((char *) temp_v0_5) + 8)) = (s32) (((((*((s16 *) (((char *) new_var) + 4))) - 1) & 0x3FF) << 0xE) | (((((*((s16 *) (((char *) temp_v1_3) + 6))) - 1) & 0x3FF) * 4) | new_var9));
        temp_a1 = *((void **) (new_var3 + 0x2C));
        temp_v0_7 = ((char *) temp_v0_6) + 8;
        *((s32 *) (((char *) temp_v0_6) + 4)) = (s32) ((((*((u16 *) (((char *) temp_a1) + 0))) & 0x3FF) << 0xE) | ((((u16) (*((s16 *) (((char *) temp_a1) + 2)))) & 0x3FF) * 4));
        *((s32 *) (((char *) temp_v0_6) + 8)) = 0xE7000000;
      }
      while (0);
      *((s32 *) (((char *) temp_v0_7) + 4)) = 0;
      func_80006014(temp_v0, ((char *) temp_v0_7) + 8, temp_v0_6, *((void **) (D_800C02AE + 0x7CD6)));
    }
  }
}

