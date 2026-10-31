extern u8 D_800C02AE[];
extern s32 func_8003C8A4;
s32 func_8004240C(s32);
s32 func_80040260(s32, s32, s32, s32, s32, s32);
s32 func_80034FF0(s32, s32);
static inline static static int inline_fn(s32 arg0)
{
  return arg0 + 0x1A;
}

void func_8003C968(s32 arg0, s32 arg1, s32 arg2)
{
  s16 temp_a2;
  s32 temp_s0;
  s32 temp_s4;
  s32 eh_d;
  s32 y_coord;
  s32 *new_var;
  s32 var_a1;
  short var_s0;
  s32 var_s1;
  s32 new_var3;
  s32 var_s5;
  u32 coord_s7;
  s32 var_v0;
  u32 temp_v1;
  s32 var_s3;
  s32 temp_v0_obj;
  int new_var2;
  s32 entry;
  s32 mgr;
  temp_v0_obj = func_8004240C((((arg2 & 0xFFFF) - 1) * 2) | 1);
  entry = *((s32 *) (temp_v0_obj + 0x178));
  *((s32 *) (D_800C02AE + 0x7CD6)) = temp_v0_obj;
  mgr = *((s32 *) (D_800C02AE + 0x32F2));
  temp_a2 = *((s16 *) (entry + 8));
  temp_s0 = *((s16 *) (entry + 0xA));
  temp_s4 = *((s16 *) (entry + 0xC));
  temp_v1 = *((u16 *) (mgr + 0xE));
  eh_d = *((s16 *) (entry + 0xE));
  var_s5 = 0x14;
  var_s5 = temp_a2 + var_s5;
  coord_s7 = temp_s4 - 0x10;
  y_coord = temp_s0 + 6;
  switch (temp_v1)
  {
    case 1:
      var_s0 = temp_s0 + 0x1A;
      var_s3 = func_80040260(arg0, (s32) ((s16) (temp_s4 - 0x2D)), (s32) ((s16) var_s0), 2, (s32) (&func_8003C8A4), 0);
      var_s1 = arg1 + 0x4C;
      var_v0 = func_80034FF0(var_s1, 0);
      var_a1 = (s16) (coord_s7 + 0xFFEA);
      goto block_9;

    case 2:
      new_var2 = temp_s4 + 8;
      coord_s7 = ((*((u16 *) (mgr + 0x12))) & 1) != 0;
      if (coord_s7)
    {
      if (1)
      {
      }
      var_s0 = y_coord;
      var_s3 = func_80040260(arg0, (s32) ((s16) new_var2), (s32) ((s16) var_s0), 2, (s32) (&func_8003C8A4), 0);
      var_s1 = arg1 + 0x4C;
      var_v0 = func_80034FF0(var_s1, 0);
      var_a1 = (s16) (temp_s4 + 0xF);
    }
    else
    {
      if ((*((s32 *) (temp_v0_obj + 0xC))) == 3)
      {
        var_s5 = temp_a2 + 6;
      }
      var_s0 = eh_d - 0x12;
      new_var = &func_8003C8A4;
      new_var3 = var_s0;
      var_s3 = func_80040260(arg0, (s32) ((s16) inline_fn(var_s5)), (s32) ((s16) new_var3), 2, (s32) new_var, 0);
      var_s1 = arg1 + 0x4C;
      var_v0 = func_80034FF0(var_s1, 0);
      var_a1 = (s16) (var_s5 + 0x21);
    }
      goto block_9;

    default:
      return;

  }

  block_9:
  *((s32 *) (var_s3 + 0xA4)) = var_v0;

  *((s16 *) (var_s3 + 0x78)) = 0;
  var_s3 = func_80040260(arg0, (s32) ((s16) var_a1), (s32) new_var3, 2, (s32) new_var, 0);
  var_v0 = func_80034FF0(var_s1, 0);
  *((s32 *) (var_s3 + 0xA4)) = var_v0;
  *((s16 *) (var_s3 + 0x78)) = 1;
}
