u32 func_8001FEE8();
s32 func_80038AE4();
s32 func_80046414();
s32 func_800464B0();
extern s32 D_8009D538;
extern char D_800C02AE[];
void func_80046530(void *arg0, s32 arg1, void *arg2)
{
  char *__repair_addr;
  char *new_var2;
  u32 temp_a0;
  u32 mask;
  u32 *new_var;
  s32 temp_v0_2;
  u32 temp_s2;
  void *temp_a1;
  void *temp_v0;
  if ((((!(D_8009D538 & 0x800)) && (!((*((s32 *) (((char *) arg2) + 0x14))) & 0x80))) && ((temp_s2 = func_8001FEE8(arg2), ((*(*((s32 **) (((char *) arg2) + 0x48)))) < 2) != 0))) && (func_800464B0(arg2) != 0))
  {
    if (!((*((s32 *) (((char *) arg2) + 0x14))) & 0x20))
    {
      temp_a1 = *((void **) (((char *) arg2) + 0x70));
      temp_v0 = *((void **) (((char *) temp_a1) + 0x1C));
      __repair_addr = (char *) (((char *) arg0) + 0);
      new_var2 = ((char *) (*((void **) (((char *) arg2) + 0x70)))) + 0x18;
      if (((temp_v0 != arg0) && ((mask = (0U - ((u32) (temp_v0 != ((void *) 0)))) & 0x64U, mask >= (*((u32 *) (((char *) temp_a1) + 0x18)))))) && (((((*((s32 *) __repair_addr)) & 0xFFFF0000) != 0x06060000) | (temp_s2 >= 0x50U)) != 0))
      {
        temp_a0 = *((s32 *) (((char *) arg0) + 4));
        new_var = (u32 *) new_var2;
        if ((temp_a0 != 1) & (temp_a0 != 5))
        {
          if (temp_a0 == 2)
          {
            *((s32 *) (((char *) temp_a1) + 0x14)) = (s32) (*((u8 *) (((char *) arg0) + 2)));
            *((s32 *) (((char *) (*((void **) (((char *) arg2) + 0x70)))) + 0x10)) = (s32) (*((u8 *) (((char *) arg0) + 3)));
          }
          else
          {
            *((s32 *) (((char *) temp_a1) + 0x14)) = (s32) (*((u8 *) (((char *) arg0) + 0)));
            *((s32 *) (((char *) (*((void **) (((char *) arg2) + 0x70)))) + 0x10)) = (s32) (*((u8 *) (((char *) arg0) + 1)));
          }
          *new_var = 0x7DU;
        }
        else
        {
          *((s32 *) (((char *) temp_a1) + 0x10)) = 4;
          *((s32 *) (((char *) (*((void **) (((char *) arg2) + 0x70)))) + 0x14)) = (s32) (*((u8 *) (((char *) arg0) + 0)));
          *((u32 *) (((char *) (*((void **) (((char *) arg2) + 0x70)))) + 0x18)) = 0x7DU;
        }
        *((void **) (((char *) (*((void **) (((char *) arg2) + 0x70)))) + 0x1C)) = arg0;
        if (((u16) (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE)))) < 2U)
        {
          func_80046414(*((u8 *) (((char *) arg0) + 1)), *((u8 *) (((char *) arg0) + 0)));
          if ((*((s32 *) (((char *) arg0) + 4))) == 1)
          {
            func_80038AE4(0x13);
            func_80046414(*((u8 *) (((char *) arg0) + 3)), *((u8 *) (((char *) arg0) + 2)));
          }
          temp_v0_2 = *((s32 *) (((char *) arg0) + 4));
          if (((temp_v0_2 == 2) | (temp_v0_2 == 5)) != 0)
          {
            func_80046414(*((u8 *) (((char *) arg0) + 3)), *((u8 *) (((char *) arg0) + 2)));
          }
        }
      }
    }
    else
    {
      *((void **) (((char *) (*((void **) (((char *) arg2) + 0x70)))) + 0x1C)) = NULL;
    }
  }
}
