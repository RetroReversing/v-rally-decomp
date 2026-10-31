extern f64 D_800A4A20;
extern f64 D_800A4A28;
s16 func_8002D2E4(s32 a);
extern int D_800C35A0;
void func_8003EE84(void *arg0);
void func_8003F2CC(u8 *arg0);
static inline static static static int inline_fn(s32 arg0, int arg1)
{
  return arg0 != arg1;
}

s32 func_800415A8(s32 arg0, s32 arg1)
{
  s32 var_a1;
  int new_var;
  s32 var_a2;
  u16 *var_a0;
  u16 temp_v1;
  ;
  var_a2 = arg0;
  var_a2 = arg1;
  if (inline_fn(var_a2, 0))
  {
    do
    {
      var_a0 = (u16 *) (arg0 + 0x10);
      loop_2:
      temp_v1 = *var_a0;

    }
    while (0);
    new_var = 1;
    if (temp_v1 & new_var)
    {
      var_a1 -= new_var;
      var_a2 = (var_a0 = 0x2C4);
      if (inline_fn(var_a1, 0))
      {
        goto loop_2;
      }
    }
    else
    {
      *var_a0 = temp_v1 | new_var;
      return var_a2;
    }
  }
  return 0;
}

void func_80038AE4(s32);
void func_80046414(s32 arg0, s32 arg1);
