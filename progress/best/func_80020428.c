extern unsigned char D_800ADFE0;
extern unsigned short D_800ADFE4;
void *func_80041564();
s32 *func_8007EAA0();
extern s32 D_8009D534;
extern char D_800A73E0[];
extern char D_800C02AE[];
void func_80020428(void *arg0)
{
  char pad[8];
  s32 *var_a1_4;
  s32 *var_a1_5;
  unsigned char *new_var;
  s32 *var_v0;
  s32 temp_v1_3;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a1;
  s32 var_a1_2;
  s32 var_a1_3;
  int var_v0_2;
  s32 temp_a2;
  s32 temp_v0;
  s32 temp_v1;
  void *temp_s1;
  void *temp_v1_2;
  unsigned char *bp;
  temp_s1 = func_80041564();
  if ((*((u16 *) ((*((void **) (D_800C02AE + 0x32F2))) + 0x1E))) != 0)
  {
    *((s32 **) (*((char **) (((char *) arg0) + 0x40)))) = func_8007EAA0(1, (D_800ADFE0 + 1) * 4);
  }
  else
  {
    *((s32 **) (*((char **) (((char *) arg0) + 0x40)))) = func_8007EAA0(1, 0x10);
  }
  temp_v1 = *((u16 *) ((*((void **) (D_800C02AE + 0x32F2))) + 0xE));
  if (temp_v1 == 2)
  {
    goto block_10;
  }
  if (temp_v1 >= 3)
  {
    goto block_7;
  }
  if (temp_v1 == 1)
  {
    goto block_9;
  }
  goto block_13;
  block_7:
  if (temp_v1 >= 5)
  {
    goto block_13;
  }

  goto block_11;
  block_9:
  *((s32 **) ((*((void **) (((char *) arg0) + 0x40))) + 0x24)) = func_8007EAA0(1, 0x1C);

  *((s32 **) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x28)) = func_8007EAA0(1, 0x1C);
  goto block_13;
  block_10:
  *((s32 **) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x24)) = func_8007EAA0(1, 0x10);

  *((s32 **) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x28)) = func_8007EAA0(1, 0x10);
  goto block_13;
  block_11:
  *((s32 **) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x24)) = func_8007EAA0(1, 4);

  *((s32 **) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x28)) = func_8007EAA0(1, 4);
  block_13:
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x2C)) = 0;

  *((void **) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x14)) = temp_s1;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 4)) = 0;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 8)) = 1;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0xC)) = 0;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x10)) = D_800ADFE4;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x20)) = 0;
  temp_v0 = *((u16 *) (((char *) temp_s1) + 0x12));
  if (temp_v0 == 0)
  {
    *((s32 **) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x18)) = func_8007EAA0(1, 4);
  }
  else
  {
    *((s32 **) (((char *) (*((void **) (((char *) arg0) + 0x40)))) + 0x18)) = func_8007EAA0(1, temp_v0 * 4);
  }
  temp_v1_2 = *((void **) (((char *) arg0) + 0x40));
  var_a1_4 = *((s32 **) (((char *) temp_v1_2) + 0x24));
  temp_a2 = *((u16 *) ((*((void **) (D_800C02AE + 0x32F2))) + 0xE));
  var_a1_5 = *((s32 **) (((char *) temp_v1_2) + 0x28));
  var_a0 = 0;
  new_var = &D_800ADFE0;
  if (temp_a2 == 2)
  {
    goto block_24;
  }
  if (temp_a2 >= 3)
  {
    goto block_22;
  }
  if (temp_a2 != 1)
  {
    goto block_20;
  }
  var_a0 = 6;
  goto block_25;
  block_20:
  var_v0_2 = 0;

  goto block_26;
  block_25:
  var_v0_2 = var_a0;

  block_22:
  var_v0_2 = 0;

  if (temp_a2 >= 5)
  {
    goto block_26;
  }
  var_a0 = 1;
  goto block_25;
  block_24:
  var_a0 = 3;

  var_v0_2 = var_a0;
  block_26:
  var_a0_2 = var_a0 - 1;

  if (var_v0_2 == 0)
  {
    goto block_28;
  }
  loop_27:
  temp_v1_3 = var_a0_2;

  var_a0_2 -= 1;
  *var_a1_4 = D_8009D534;
  var_a1_4++;
  *var_a1_5 = 0;
  var_a1_5++;
  if (temp_v1_3 != 0)
  {
    goto loop_27;
  }
  block_28:
  var_a1_5 = *((s32 **) ((char *) (*((void **) (((char *) arg0) + 0x40)))));

  temp_a2 = 0;
  if ((*((u16 *) ((*((void **) (D_800C02AE + 0x32F2))) + 0x1E))) == 0)
  {
    goto loop_32;
  }
  bp = new_var;
  if ((bp[0] + 1) == 0)
  {
    goto block_33;
  }
  loop_30:
  *var_a1_5 = 0;

  temp_a2++;
  var_a1_5++;
  if (temp_a2 < ((u32) (bp[0] + 1)))
  {
    goto loop_30;
  }
  return;
  loop_32:
  *var_a1_5 = 0;

  temp_a2++;
  var_a1_5++;
  if (temp_a2 < 4U)
  {
    goto loop_32;
  }
  block_33:
  return;

}
