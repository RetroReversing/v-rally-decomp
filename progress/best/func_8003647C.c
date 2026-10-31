#define sp10 vec[0]
#define sp12 vec[1]
#define sp14 vec[2]
#define sp18 rot[0]
#define sp1A rot[1]
#define sp1C rot[2]
extern s32 func_8002D2C8();
extern void func_8002E148();
extern void func_8002E514();
extern s32 func_80098090();
extern void *D_800C811C;
extern char D_800C02AE[];
void func_8003647C(u16 *arg0, u8 arg1)
{
  s16 vec[4];
  s16 rot[4];
  s32 sp20[7];
  s32 *matrix;
  void *new_var;
  f32 var_fs0;
  f32 var_fs1;
  u16 *var_s2;
  void *var_s0;
  void *temp_v1;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_ret;
  s32 temp_ret_2;
  s32 temp_ret_3;
  s32 temp_s1;
  s32 var_s1;
  s32 var_v0;
  s32 var_v0_2;
  var_s0 = *((void **) (D_800C02AE + 0x7CD6));
  temp_v1 = (arg1 * 0xC) + ((char *) D_800C811C);
  var_fs1 = (f32) ((s16) ((s32) ((*((f32 *) (((char *) temp_v1) + 0x18))) - (*((f32 *) (((char *) var_s0) + 0x118))))));
  var_fs0 = (f32) ((s16) ((s32) ((*((f32 *) (((char *) temp_v1) + 0x20))) - (*((f32 *) (((char *) var_s0) + 0x120))))));
  var_v0 = __builtin_abs((s32) var_fs1);
  if (var_v0 < 0x3E9)
  {
    var_v0_2 = __builtin_abs((s32) var_fs0);
    if (var_v0_2 < 0x3E9)
    {
      goto ok;
    }
  }
  var_fs0 = 0.0f;
  var_fs1 = 0.0f;
  ok:
  var_fs1 += 4.0f;

  var_fs0 += 2.0f;
  temp_ret = func_8002D2C8((s32) ((*((f32 *) (((char *) var_s0) + 0xE0))) * 4096.0f), (s32) ((*((f32 *) (((char *) var_s0) + 0xD8))) * (-4096.0f)));
  temp_ret = (-temp_ret) - 0x200;
  sp18 = 0;
  sp1C = 0;
  sp14 = 0;
  temp_s1 = *((s32 *) (((char *) D_800C811C) + 8));
  var_s1 = temp_s1;
  if ((var_s1--) == 0)
  {
    return;
  }
  matrix = sp20;
  var_s0 = (char *)(var_s2); var_s0 += (s32)(4);
  do
  {
    if ((*((s16 *) (((char *) (var_s2 + 4)) - 6))) == 0x3E9)
    {
      temp_ret_2 = func_80098090();
      sp10 = (temp_ret_2 % 4095) + 0x200;
      temp_ret_3 = func_80098090(temp_ret_2 / 4095);
      temp_a0 = temp_ret_3 / 511;
      sp12 = (temp_a0 * 0x1FF) - temp_ret_3;
      temp_a0_2 = func_80098090(temp_a0);
      sp1A = temp_ret + (temp_a0_2 % 1023);
      func_8002E148(&sp18, matrix, temp_a0_2 / 1023);
      func_8002E514(matrix, &sp10, var_s2);
    }
    *((u16 *) (((char *) (var_s2 + 4)) - 2)) = *var_s2;
    *((u16 *) (((char *) (var_s2 + 4)) + 2)) = *((u16 *) (((char *) (var_s2 + 4)) - 4));
    *var_s2 = (u16) ((s32) (((f32) ((s16) (*var_s2))) + var_fs1));
    temp_a0 = var_s1;
    {
      f32 z = (f32) (*((s16 *) (((char *) (var_s2 + 4)) - 4)));
      s32 age = *((u16 *) (((char *) (var_s2 + 4)) - 6));
      s32 decay = *((u8 *) (((char *) (var_s2 + 4)) + 4));
      var_s1--;
      age += 0x41;
      *((s16 *) (((char *) (var_s2 + 4)) - 6)) = age;
      z += var_fs0;
      var_s2 = (u16 *) (((char *) var_s2) + 0x14);
      *((s16 *) (var_s2 + 4)) = (s16) ((*((u16 *) (((char *) (var_s2 + 4)) - 6))) - decay);
      new_var = var_s0;
      *((s16 *) (((char *) new_var) - 4)) = (s32) z;
    }
    var_s0 = ((char *) var_s0) + 0x14;
  }
  while (temp_a0 != 0);
}
