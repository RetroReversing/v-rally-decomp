extern u8 *D_800C35A0;
extern void *D_800C7F84;
extern unsigned char D_800ADFE0;
extern unsigned char D_800ADFE1;
s32 func_80034FF0();
void *func_80040260();
void *func_8004240C();
extern char D_800A73E0[];
extern char D_800C02AE[];
extern s32 func_8003B614;
extern s32 func_8003B884;
extern s32 func_8003CC50;
extern s32 func_8003CC98;
void func_80039A00(s32 arg0, s32 arg1)
{
  char *__repair_addr;
  int new_var3;
  void *new_var2;
  s32 sp1C;
  u32 sp24;
  u32 sp2C;
  u32 sp34;
  u32 sp3C;
  u32 sp44;
  s32 sp4C;
  s32 sp54;
  s16 temp_s0;
  s16 temp_s0_10;
  int temp_s0_11;
  s16 temp_s0_2;
  s16 temp_s0_5;
  s16 temp_s0_6;
  s16 temp_s0_7;
  s16 temp_s0_8;
  s16 temp_s0_9;
  s16 temp_s1;
  s16 temp_s1_2;
  s32 temp_s3;
  s32 temp_s7;
  s32 *new_var;
  s32 temp_t0;
  s16 var_a1;
  s16 var_a2;
  s32 var_s6;
  s32 temp_s0_3;
  u32 temp_s1_3;
  s32 temp_s5;
  s32 temp_v1_2;
  s32 var_a0;
  s32 var_a0_2;
  u16 temp_a0;
  u16 temp_v1;
  u32 temp_t0_2;
  void *temp_s0_4;
  void *temp_s2;
  void *temp_s2_10;
  void *temp_s2_11;
  void *temp_s2_12;
  void *temp_s2_13;
  void *temp_s2_14;
  void *temp_s2_17;
  void *temp_s2_18;
  void *temp_s2_19;
  void *temp_s2_2;
  void *temp_s2_3;
  void *temp_s2_4;
  void *temp_s2_5;
  void *temp_s2_6;
  void *temp_s2_7;
  void *temp_s2_8;
  void *temp_s2_9;
  void *temp_v0;
  void *temp_v0_2;
  void *var_s2;
  void *var_s2_2;
  sp1C = arg1;
  if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) == 7)
  {
    goto block_47;
  }
  temp_a0 = *((u16 *) (((char *) D_800C35A0) + 0xE));
  sp4C = 0;
  sp24 = 1;
  sp44 = (u32) temp_a0;
  if (temp_a0 == 0)
  {
    goto block_47;
  }
  temp_s5 = arg1 + 0x4C;
  loop_3:
  temp_v0 = func_8004240C(((sp24 - 1) * 2) | 1);

  temp_v0_2 = *((void **) (((char *) temp_v0) + 0x178));
  temp_t0 = *((s16 *) (((char *) temp_v0_2) + 8));
  sp54 = (s32) temp_t0;
  temp_s7 = *((s16 *) (((char *) temp_v0_2) + 0xA));
  D_800C7F84 = temp_v0;
  var_s6 = temp_t0 + 0x14;
  sp2C = temp_s7 + 6;
  temp_s3 = *((s16 *) (((char *) temp_v0_2) + 0xC));
  temp_v1 = *((u16 *) (((char *) D_800C35A0) + 0xE));
  sp34 = temp_s3 - 0x10;
  sp3C = (*((s16 *) (((char *) temp_v0_2) + 0xE))) - 8;
  if (temp_v1 == 1)
  {
    goto block_6;
  }
  if (temp_v1 == 2)
  {
    goto block_19;
  }
  goto block_45;
  block_6:
  if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) != 0)
  {
    goto block_14;
  }

  if (((u8) D_800ADFE0) < 2U)
  {
    goto block_10;
  }
  __repair_addr = (char *) (D_800C35A0 + ((*((u8 *) (((char *) D_800C35A0) + 0x32))) * 0x28));
  if (!((*((u8 *) (((char *) __repair_addr) + 0x48))) & 1))
  {
    if (1)
    {
      goto block_12;
    }
  }
  temp_s0 = temp_s3 - 0x47;
  temp_s1 = temp_s7 + 0x11;
  temp_s2 = func_80040260(arg0, (s32) temp_s0, temp_s1, 5, &func_8003CC50);
  *((s32 *) (((char *) temp_s2) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((void **) (((char *) temp_s2) + 0xA8)) = (void *) D_800C7F84;
  temp_s2_2 = func_80040260(arg0, (s32) temp_s0, temp_s1, 5, &func_8003CC98, 1);
  *((s32 *) (((char *) temp_s2_2) + 0xA4)) = func_80034FF0(temp_s5);
  *((s16 *) (((char *) temp_s2_2) + 0x7A)) = 5;
  *((void **) (((char *) temp_s2_2) + 0xA8)) = (void *) D_800C7F84;
  temp_s2_3 = func_80040260(arg0, (s32) ((s16) (temp_s3 - 0x31)), temp_s1, 5, &func_8003CC98, 1);
  *((s32 *) (((char *) temp_s2_3) + 0xA4)) = func_80034FF0(temp_s5, 0);
  new_var3 = 7;
  *((void **) (((char *) temp_s2_3) + 0xA8)) = (void *) D_800C7F84;
  block_10:
  if (!((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) D_800C35A0) + 0x32))) * 0x28))) + 0x48))) & 1))
  {
    goto block_12;
  }

  temp_s0_2 = temp_s7 + new_var3;
  temp_s2_4 = func_80040260(arg0, (s32) ((s16) (sp34 + 0xFFB3)), temp_s0_2, 5, NULL, 1);
  *((s32 *) (((char *) temp_s2_4) + 0xA4)) = func_80034FF0(temp_s5, 0);
  temp_s2_5 = func_80040260(arg0, (s32) ((s16) (temp_s3 - 0x74)), temp_s0_2, 5, NULL, 1);
  *((s32 *) (((char *) temp_s2_5) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((s16 *) (((char *) temp_s2_5) + 0x7A)) = 1;
  temp_s2_6 = func_80040260(arg0, (s32) ((s16) (sp54 + 0x32)), temp_s0_2, 5, NULL, 1);
  *((s32 *) (((char *) temp_s2_6) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((s16 *) (((char *) temp_s2_6) + 0x7A)) = 1;
  block_12:
  if (!((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) D_800C35A0) + 0x32))) * 0x28))) + 0x48))) & 4))
  {
    goto block_45;
  }

  temp_s0_3 = sp2C + sp3C;
  temp_s2_7 = func_80040260(arg0, (s32) ((s16) var_s6), (s16) (temp_s0_3 - 0x12), 5, &func_8003B884, 1);
  *((s32 *) (((char *) temp_s2_7) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((s16 *) (((char *) temp_s2_7) + 0x76)) = 4;
  *((void **) (((char *) temp_s2_7) + 0xA8)) = (void *) D_800C7F84;
  temp_s0_4 = func_80040260(arg0, (s32) ((s16) (var_s6 + 0x14)), (s16) (temp_s0_3 - 0x44), 5, NULL, 1);
  *((s32 *) (((char *) temp_s0_4) + 0xA4)) = func_80034FF0(temp_s5, 0);
  new_var2 = (void *) D_800C7F84;
  *((s16 *) (((char *) temp_s0_4) + 0x7A)) = 4;
  *((void **) (((char *) temp_s0_4) + 0xA8)) = new_var2;
  *((void **) (((char *) temp_s2_7) + 0x8C)) = temp_s0_4;
  goto block_45;
  block_14:
  if (!((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) D_800C35A0) + 0x32))) * 0x28))) + 0x48))) & 1))
  {
    goto block_45;
  }

  if (D_800ADFE1 == 0)
  {
    goto block_17;
  }
  temp_s1_2 = temp_s3 - 0x47;
  temp_s0_5 = temp_s7 + 0x11;
  temp_s2_8 = func_80040260(arg0, (s32) temp_s1_2, temp_s0_5, 5, &func_8003CC98, 1);
  *((s32 *) (((char *) temp_s2_8) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((s16 *) (((char *) temp_s2_8) + 0x7A)) = 5;
  new_var = &func_8003CC98;
  *((void **) (((char *) temp_s2_8) + 0xA8)) = (void *) D_800C7F84;
  temp_s2_9 = func_80040260(arg0, (s32) ((s16) (temp_s3 - 0x31)), temp_s0_5, 5, new_var, 1);
  *((s32 *) (((char *) temp_s2_9) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((void **) (((char *) temp_s2_9) + 0xA8)) = (void *) D_800C7F84;
  var_s2 = func_80040260(arg0, (s32) temp_s1_2, temp_s0_5, 5, &func_8003CC50, 1);
  var_a0 = temp_s5;
  goto block_18;
  block_17:
  var_s2 = func_80040260(arg0, (s32) ((s16) (temp_s3 - 0x47)), (s16) (temp_s7 + 0x11), 5, NULL, 1);

  var_a0 = sp1C + 0x4C;
  block_18:
  *((s32 *) (((char *) var_s2) + 0xA4)) = func_80034FF0(var_a0, 0);

  *((void **) (((char *) var_s2) + 0xA8)) = (void *) D_800C7F84;
  temp_s0_6 = (sp2C + sp3C) + 0xFFE9;
  temp_s2_10 = func_80040260(arg0, (s32) ((s16) (var_s6 + 0xA)), temp_s0_6, 5, &func_8003B614, 1);
  var_a1 = var_s6 + 0x21;
  var_a2 = temp_s0_6;
  *((s32 *) (((char *) temp_s2_10) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((s16 *) (((char *) temp_s2_10) + 0x7A)) = 1;
  *((void **) (((char *) temp_s2_10) + 0xA8)) = (void *) D_800C7F84;
  goto block_43;
  block_19:
  if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) != 0)
  {
    goto block_32;
  }

  if (!((*((u16 *) (((char *) D_800C35A0) + 0x12))) & 1))
  {
    goto block_23;
  }
  if (!((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + sp24)) + 0x31))) * 0x28))) + 0x48))) & 1))
  {
    goto block_46;
    *((void **) (((char *) temp_s2_13) + 0xA8)) = (void *) D_800C7F84;
  }
  temp_s0_7 = temp_s7 + 0x11;
  temp_s2_11 = func_80040260(arg0, sp54, temp_s0_7, 5, &func_8003CC98, 1);
  var_s2 = temp_s2_11;
  *((s32 *) (((char *) var_s2) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((s16 *) (((char *) temp_s2_11) + 0x7A)) = 5;
  *((void **) (((char *) var_s2) + 0xA8)) = (void *) D_800C7F84;
  temp_s2_12 = func_80040260(arg0, (s32) ((s16) (sp54 + 0x17)), temp_s0_7, 5, new_var, 1);
  *((s32 *) (((char *) temp_s2_12) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((void **) (((char *) temp_s2_12) + 0xA8)) = (void *) D_800C7F84;
  var_s2_2 = func_80040260(arg0, (s32) ((s16) (sp54 - sp4C)), (s16) (temp_s7 + 7), 5, NULL, 1);
  var_a0_2 = temp_s5;
  sp3C = *((s32 *) (((char *) temp_v0) + 0xC));
  goto block_31;
  block_23:
  if (!((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + sp24)) + 0x31))) * 0x28))) + 0x48))) & 1))
  {
    goto block_45;
  }

  temp_v1_2 = sp3C;
  sp4C = (-(temp_v1_2 == 3)) & 0xE;
  if (temp_v1_2 != 3)
  {
    goto block_28;
  }
  temp_s0_8 = temp_s7 + 0x11;
  if (D_800ADFE1 == 0)
  {
    if (1)
    {
    }
    goto block_27;
  }
  temp_s1_3 = var_s6 + sp34;
  temp_s2_13 = func_80040260(arg0, (s32) ((s16) (temp_s1_3 - 0x46)), temp_s0_8, 5, &func_8003CC98, 1);
  *((s32 *) (((char *) temp_s2_13) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((s16 *) (((char *) temp_s2_13) + 0x7A)) = 5;
  temp_s2_14 = func_80040260(arg0, (s32) ((s16) (temp_s1_3 + 0xFFD1)), temp_s0_8, 5, &func_8003CC98, 1);
  *((s32 *) (((char *) temp_s2_14) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((void **) (((char *) temp_s2_14) + 0xA8)) = (void *) D_800C7F84;
  block_27:
  var_s2_2 = func_80040260(arg0, (s32) ((s16) ((var_s6 + sp34) - 0x5E)), (s16) (temp_s7 + new_var3), 5, NULL, 1);

  var_a0_2 = sp1C + 0x4C;
  goto block_31;
  block_28:
  if (D_800ADFE1 == 0)
  {
    goto block_30;
  }

  temp_s0_9 = temp_s7 + 0x11;
  var_s2 = func_80040260(arg0, (s32) ((s16) var_s6), temp_s0_9, 5, &func_8003CC98, 1);
  *((s32 *) (((char *) var_s2) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((void **) (((char *) var_s2) + 0xA8)) = (void *) D_800C7F84;
  *((s16 *) (((char *) var_s2) + 0x7A)) = 5;
  temp_s2_8 = func_80040260(arg0, (s32) ((s16) (sp54 + 0x2B)), temp_s0_9, 5, &func_8003CC98, 1);
  *((s32 *) (((char *) temp_s2_8) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((void **) (((char *) temp_s2_8) + 0xA8)) = (void *) D_800C7F84;
  block_30:
  var_s2_2 = func_80040260(arg0, (s32) ((s16) var_s6), (s16) (temp_s7 + new_var3), 5, NULL, 1);

  var_a0_2 = sp1C + 0x4C;
  block_31:
  *((s32 *) (((char *) var_s2_2) + 0xA4)) = func_80034FF0(var_a0_2, 0);

  *((s16 *) (((char *) var_s2_2) + 0x7A)) = 1;
  goto block_45;
  block_32:
  if (!((*((u16 *) (((char *) D_800C35A0) + 0x12))) & 1))
  {
    goto block_38;
  }

  if (!((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + sp24)) + 0x31))) * 0x28))) + 0x48))) & 1))
  {
    if (1)
    {
      goto block_46;
    }
  }
  if ((*((s32 *) (((char *) temp_v0) + 0xC))) != 1)
  {
    goto block_36;
  }
  sp2C = temp_s7 + 8;
  block_36:
  if (D_800ADFE1 == 0)
  {
    goto block_45;
  }

  temp_s0_10 = (var_a2 = (sp2C + sp3C) - 0x15);
  temp_s2_17 = func_80040260(arg0, sp54, temp_s0_10, 5, &func_8003CC98, 1);
  var_a1 = sp54 + 0x17;
  *((s32 *) (((char *) temp_s2_17) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((void **) (((char *) temp_s2_17) + 0xA8)) = (void *) D_800C7F84;
  *((s16 *) (((char *) temp_s2_17) + 0x7A)) = 5;
  goto block_44;
  block_38:
  if (!((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + sp24)) + 0x31))) * 0x28))) + 0x48))) & 1))
  {
    goto block_45;
  }

  if ((*((s32 *) (((char *) temp_v0) + 0xC))) != 3)
  {
    goto block_41;
  }
  var_s6 = sp54 + 6;
  block_41:
  if (D_800ADFE1 == 0)
  {
    goto block_45;
  }

  temp_s0_11 = sp3C + 0xFFE3;
  temp_s2_18 = func_80040260(arg0, (s32) ((s16) var_s6), temp_s0_11, 5, &func_8003CC98, 1);
  var_a1 = var_s6;
  var_a1 = var_a1 + 0x17;
  var_a2 = temp_s0_11;
  *((s32 *) (((char *) temp_s2_18) + 0xA4)) = func_80034FF0(temp_s5, 0);
  *((s16 *) (((char *) temp_s2_18) + 0x7A)) = 5;
  *((void **) (((char *) temp_s2_18) + 0xA8)) = (void *) D_800C7F84;
  goto block_44;
  block_43:
  temp_s2_19 = func_80040260(arg0, (s32) var_a1, var_a2, 5, &func_8003B614, 1);

  goto finish_node;
  block_44:
  temp_s2_19 = func_80040260(arg0, (s32) var_a1, var_a2, 5, &func_8003CC98, 1);

  finish_node:
  *((s32 *) (((char *) temp_s2_19) + 0xA4)) = func_80034FF0(temp_s5, 0);

  *((void **) (((char *) temp_s2_19) + 0xA8)) = (void *) D_800C7F84;
  block_45:
  block_46:
  temp_t0_2 = ++sp24;


  if (sp44 >= temp_t0_2)
  {
    goto loop_3;
  }
  block_47:
  return;

}
