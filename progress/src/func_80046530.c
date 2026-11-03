u32 func_8001FEE8();
void func_80038AE4(s32);
s32 func_80046414();
s32 func_800464B0();
extern s32 D_8009D538;
extern char D_800C02AE[];
typedef struct 
{
  s32 pad0[4];
  s32 a10;
  s32 a14;
  u32 a18;
  void *a1C;
} Sub70;
void func_80046530(u8 *arg0, s32 arg1, u8 *arg2)
{
  u32 temp_a0;
  s32 t;
  char *new_var3;
  unsigned int new_var2;
  u32 temp_s2;
  int new_var;
  u32 mask;
  u32 k;
  Sub70 *temp_a1;
  void *temp_v0;
  if (D_8009D538 & 0x800)
  {
    return;
  }
  if ((*((s32 *) (arg2 + 0x14))) & 0x80)
  {
    return;
  }
  temp_s2 = func_8001FEE8(arg2);
  new_var2 = 100U;
  if ((*(*((s32 **) (arg2 + 0x48)))) >= 2)
  {
 return; }
  if (func_800464B0(arg2) == 0)
  {
    return;
  }
  new_var = 0x14;
  if (!((*((s32 *) (arg2 + new_var))) & 0x20))
  {
    temp_a1 = *((Sub70 **) (arg2 + 0x70));
    temp_v0 = temp_a1->a1C;
    new_var3 = D_800C02AE + 0x32F2;
    if (((temp_v0 != arg0) && ((mask = (0U - ((u32) (temp_v0 != 0))) & new_var2, mask >= temp_a1->a18))) && ((((*((s32 *) arg0)) & 0xFFFF0000) != 0x06060000) | (temp_s2 >= 0x50U)))
    {
      temp_a0 = *((s32 *) (arg0 + 4));
      k = (temp_a0 != 1) & (temp_a0 != 5);
      if (k)
      {
        if (temp_a0 == 2)
        {
          temp_a1->a14 = arg0[2];
          (*((Sub70 **) (arg2 + 0x70)))->a10 = arg0[3];
        }
        else
        {
          temp_a1->a14 = arg0[0];
          (*((Sub70 **) (arg2 + 0x70)))->a10 = arg0[1];
        }
        k = 0x7D;
        (*((Sub70 **) (arg2 + 0x70)))->a18 = k;
      }
      else
      {
        temp_a1->a10 = 4;
        (*((Sub70 **) (arg2 + 0x70)))->a14 = arg0[0];
        (*((Sub70 **) (arg2 + 0x70)))->a18 = 0x7D;
      }
      (*((Sub70 **) (arg2 + 0x70)))->a1C = arg0;
      if ((*((u16 *) ((*((u8 **) new_var3)) + 0xE))) < 2U)
      {
        func_80046414(arg0[1], arg0[0]);
        if ((*((s32 *) (arg0 + 4))) == 1)
        {
          func_80038AE4(0x13);
          func_80046414(arg0[3], arg0[2]);
        }
        t = *((s32 *) (arg0 + 4));
        if ((t == 2) | (t == 5))
        {
          func_80046414(arg0[3], arg0[2]);
        }
      }
    }
  }
  else
  {
    (*((Sub70 **) (arg2 + 0x70)))->a1C = 0;
  }
}
