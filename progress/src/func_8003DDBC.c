extern int D_800C7F84;
s32 func_8003C968();
s32 func_8003CD18();
s32 func_8003D780();
s32 func_8003D8F4();
s32 func_8003D9C8();
s32 func_8003E1BC();
s32 func_8003E3E0();
s32 func_8003E4A8();
s32 func_8004240C();
extern void *D_800C35A0;
static inline static static static static static static static char *inline_fn(s32 arg0)
{
  return (char *) (D_800C35A0 + arg0);
}

static inline static static char *inline_fn2(char *arg0, int arg1)
{
  return arg0 + arg1;
}

void func_8003DDBC(s32 arg0, s32 arg1)
{
  int new_var5;
  s32 temp_a2;
  s32 temp_s0;
  s32 var_s0;
  s32 var_s3;
  void *new_var3;
  int new_var7;
  u16 temp_s5;
  int new_var;
  u16 temp_v1;
  void *temp_s4;
  char *new_var6;
  void *new_var4;
  void *new_var2;
  s32 temp_v0;
  temp_s4 = D_800C35A0;
  if ((*((u16 *) inline_fn2((char *) temp_s4, 0x1E))) != 7)
  {
    temp_s5 = *((u16 *) inline_fn2((char *) temp_s4, 0xE));
    if (temp_s5 != 0)
    {
      var_s3 = (temp_s5 | 1) & 1;
      var_s0 = (u16) var_s3;
      do
      {
        temp_v0 = func_8004240C(((var_s0 - 1) * 2) | 1);
        temp_v1 = *((u16 *) inline_fn2((char *) temp_s4, 0x1E));
        D_800C7F84 = temp_v0;
        if (temp_v1 == 0)
        {
          if ((*((u8 *) inline_fn2(inline_fn((*((u8 *) inline_fn2(inline_fn(var_s0), 0x31))) * 0x28), 0x48))) & 4)
          {
            do
            {
            }
            while (0);
            goto block_7;
          }
          goto block_8;
        }
        new_var2 = inline_fn2(D_800C35A0, (4 * (*((u8 *) inline_fn2(inline_fn(var_s0), 0x31)))) * 10);
        if ((*((u8 *) inline_fn2((char *) new_var2, 0x48))) & 1)
        {
          block_7:
          func_8003D780(arg0, arg1, var_s0);

          block_8:
          temp_a2 = var_s3 & 0xFFFF;

          new_var7 = (8 * (*((u8 *) inline_fn2(inline_fn(temp_a2), 0x31)))) * 5;
          if ((*((u8 *) inline_fn2((char *) inline_fn2(D_800C35A0, new_var7), 0x48))) & 1)
          {
            func_8003D8F4(arg0, arg1, temp_a2);
          }
        }
        temp_s0 = var_s3;
        temp_s0 = temp_s0 & 0xFFFF;
        new_var4 = temp_s4;
        new_var6 = inline_fn(temp_s0);
        new_var3 = inline_fn2(D_800C35A0, (*((u8 *) inline_fn2(new_var6, 0x31))) * 0x28);
        new_var5 = 4;
        if ((*((u8 *) inline_fn2((char *) new_var3, 0x48))) & new_var5)
        {
          func_8003D9C8(arg0, arg1, temp_s0);
        }
        if ((*((u8 *) inline_fn2((char *) inline_fn2(D_800C35A0, (*((u8 *) inline_fn2(inline_fn(temp_s0), 0x31))) * 0x28), 0x48))) & 1)
        {
          func_8003CD18(arg0, arg1, temp_s0);
        }
        new_var = 0x31;
        if ((*((u8 *) inline_fn2((char *) (D_800C35A0 - (-((*((u8 *) inline_fn2(inline_fn(temp_s0), 0x31))) * 0x28))), 0x48))) & 4)
        {
          func_8003E4A8(arg0, arg1, temp_s0);
        }
        if ((*((u8 *) inline_fn2(inline_fn(10 * (4 * (*((u8 *) inline_fn2(inline_fn(temp_s0), 0x31))))), 0x48))) & 1)
        {
          func_8003E3E0(arg0, arg1, temp_s0);
        }
        if ((*((u8 *) inline_fn2(inline_fn((*((u8 *) inline_fn2(inline_fn(temp_s0), new_var))) * 0x28), 0x48))) & 4)
        {
          func_8003E1BC(arg0, arg1, temp_s0);
        }
        temp_v1 = *((u16 *) inline_fn2((char *) new_var4, 0x1E));
        if ((temp_v1 != 5) & (temp_v1 != 0))
        {
          func_8003C968(arg0, arg1, temp_s0);
        }
        var_s3 += 1;
        var_s0 = (s32) ((u16) var_s3);
      }
      while (temp_s5 >= ((u32) (var_s3 & 0xFFFF)));
    }
  }
}

