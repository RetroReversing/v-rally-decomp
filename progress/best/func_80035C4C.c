#define sp10 vec[0]
#define sp12 vec[1]
#define sp14 vec[2]
#define sp18 rot[0]
#define sp1A rot[1]
#define sp1C rot[2]
s32 func_8002D2C8();
s32 func_8002E148();
s32 func_8002E514();
u64 osGetTime();
s32 func_80098090();
s32 func_800980C4();
extern char D_800C02AE[];
void func_80035C4C(s16 *arg0, s32 arg1)
{
  s16 vec[4];
  s16 rot[4];
  s32 sp20[8];
  register s32 *matrix;
  f32 var_fs0;
  f32 var_fs1;
  s32 new_var2;
  s16 *var_s2;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_ret;
  s32 temp_ret_2;
  s32 temp_ret_3;
  s32 temp_s1;
  s32 temp_v0;
  s32 var_s1;
  char *new_var;
  s32 var_v0;
  void *temp_v1;
  void *var_s0;
  var_s0 = *((void **) (D_800C02AE + 0x7CD6));
  var_s2 = arg0;
  {
    extern void *D_800C811C;
    temp_v1 = D_800C811C + ((arg1 & 0xFF) * 0xC);
  }
  var_fs1 = (f32) ((s16) ((s32) ((*((f32 *) (((char *) temp_v1) + 0x18))) - (*((f32 *) (((char *) var_s0) + 0x118))))));
  var_fs0 = (f32) ((s32) ((s16) ((s32) ((*((f32 *) (((char *) temp_v1) + 0x20))) - (*((f32 *) (((char *) var_s0) - (-0x120))))))));
  temp_a0_2 = var_fs1 > 1000.0f;
  var_v0 = var_fs0 > 1000.0f;
  if (!(temp_a0_2 & var_v0))
  {
    goto block_6;
  }
  var_fs0 = 0.0f;
  var_fs1 = 0.0f;
  block_6:
  temp_v0 = func_8002D2C8((s32) ((*((f32 *) (((char *) var_s0) + 0xE0))) * 4096.0f), (s32) ((*((f32 *) (((char *) var_s0) + 0xD8))) * (-4096.0f)));

  temp_v0 = -temp_v0;
  sp18 = 0;
  sp1C = 0;
  sp14 = 0;
  temp_s1 = *((s32 *) (((char *) (*((void **) (new_var = D_800C02AE - -0x7E6E)))) + 8));
  func_800980C4((u32) osGetTime());
  var_s1 = temp_s1 - 1;
  if (temp_s1 == 0)
  {
    return;
  }
  temp_v0 -= 0x200;
  var_s0 = var_s2 + 2;
  matrix = sp20;
  new_var2 = temp_v0;
  loop_8:
  if ((*((s16 *) (((char *) var_s0) - 2))) == 0x3E9)
  {
    temp_ret = func_80098090();
    sp10 = (temp_ret % 4095) + 0x200;
    temp_ret_2 = func_80098090(temp_ret / 4095);
    temp_a0 = temp_ret_2 / 511;
    sp12 = (temp_a0 * 0x1FF) - temp_ret_2;
    temp_ret_3 = func_80098090(temp_a0);
    sp1A = new_var2 + (temp_ret_3 % 1023);
    func_8002E148(&sp18, matrix, temp_ret_3 / 1023);
    func_8002E514(matrix, &sp10, var_s2);
  }

  temp_a0_2 = var_s1;
  *var_s2 = (s16) ((s32) (((f32) (*var_s2)) + var_fs1));
  var_s1--;
  var_s2 += 4;
  *((s16 *) (((char *) var_s0) - 2)) = (s16) (((u16) (*((s16 *) (((char *) var_s0) - 2)))) + 0x14);
  *((s16 *) var_s0) = (s16) ((s32) (((f32) (*((s16 *) var_s0))) + var_fs0));
  var_s0 += 8;
  if (temp_a0_2)
  {
    goto loop_8;
    matrix = sp20;
  }
}
