s32 func_800056F4(void *, s32);
s32 func_80005744(void *);
s32 func_80005CB8(s32, s32, s32, s32, s32);
s32 func_80005E3C(s32);
void *func_8007EAA0(s32, s32);
s32 *func_8007ED48(s32, s32, s32);
s32 func_8007EE9C(s32);
extern f32 D_8009BB94;
extern f32 D_8009BB98;
extern f32 D_8009BB9C;
extern f32 D_8009BBA0;
void *func_800051B4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  s32 var_s6;
  void *var_s2;
  void *var_s5;
  s32 var_a0;
  s32 var_s1;
  u32 var_a1;
  u32 var_s3;
  s32 var_s7;
  u16 sp1E;
  void *var_s0;
  s32 var_fp;
  s32 var_s4;
  char *new_var;
  s32 var_v0;
  s32 temp_v0;
  s32 var_a2;
  s32 var_a3;
  f32 *new_var3;
  s32 *var_v0_2;
  s32 *phi_v0;
  u32 var_v1;
  u32 var_t0;
  f32 *new_var2;
  f32 var_fv0;
  var_s6 = (u16) arg4;
  var_s2 = arg0;
  var_s5 = NULL;
  var_s1 = arg1;
  var_a1 = 0x48;
  var_s3 = arg2;
  var_s7 = arg3;
  var_s0 = func_8007EAA0(6, (s32) var_a1);
  var_fp = (u16) var_s6;
    sp1E = var_fp;
  if (var_s0 != NULL)
  {
    var_fp = 6;
    if (var_s3 != 0)
    {
      var_s4 = var_s1 & 0xFFFF;
      var_s1 = func_80005CB8(var_s4, (s32) var_s3, var_s7, 1, var_fp);
      var_v0 = var_s6 & 2;
      if (var_s1 != 0)
      {
        *((s32 *) (((char *) var_s0) + 0x20)) = var_s1;
        if (var_v0 != 0)
        {
          new_var = ((char *) var_s0) + 0x24;
          temp_v0 = func_80005CB8(var_s4, (s32) var_s3, var_s7, 1, var_fp);
          if (temp_v0 != 0)
          {
            *((s32 *) new_var) = temp_v0;
            var_s5 = var_s0;
          }
          else
          {
            func_80005E3C(var_s1);
            goto block_8;
          }
        }
        else
        {
          *((s32 *) (((char *) var_s0) + 0x24)) = 0;
          var_s5 = var_s0;
        }
      }
      else
      {
        block_8:
        func_8007EE9C((s32) var_s0);

      }
    }
    else
    {
      var_s5 = var_s0;
      *((s32 *) (((char *) var_s0) + 0x20)) = 0;
      *((s32 *) (((char *) var_s0) + 0x24)) = 0;
    }
  }
  if (var_s5 != NULL)
  {
    var_v0_2 = func_8007ED48(1, 0x10, 8);
    *((s32 **) (((char *) var_s0) + 0x1C)) = var_v0_2;
    var_v1 = 4;
    phi_v0 = var_v0_2;
    do
    {
      *phi_v0 = 0;
      var_v1 -= 1;
      phi_v0++;
    }
    while (var_v1 != 0);
    if (var_s7 || var_s3)
    {
      var_v0 = *((u16 *) ((char *) var_s2));
      var_s7 = 2;
      var_v1 = *((u16 *) (((char *) var_s2) + var_s7));
      var_a0 = (s32) (*((u16 *) (((char *) var_s2) + 4)));
      var_a1 = *((u16 *) (((char *) var_s2) + 6));
      *((u16 *) (((char *) var_s0) + 8)) = (u16) var_v0;
      *((u16 *) (((char *) var_s0) + 0xA)) = (u16) var_v1;
      *((s16 *) (((char *) var_s0) + 0xC)) = (s16) var_a0;
      *((u16 *) (((char *) var_s0) + 0xE)) = (u16) var_a1;
      var_v0 = *((u16 *) ((char *) var_s2));
      var_v1 = *((u16 *) (((char *) var_s2) + 2));
      var_a0 = (s32) (*((u16 *) (((char *) var_s2) + 4)));
      var_a1 = *((u16 *) (((char *) var_s2) + 6));
      *((u16 *) ((char *) var_s0)) = (u16) var_v0;
      *((u16 *) (((char *) var_s0) + 2)) = (u16) var_v1;
      *((s16 *) (((char *) var_s0) + 4)) = (s16) var_a0;
      *((u16 *) (((char *) var_s0) + 6)) = (u16) var_a1;
      var_v0 = (u16) ((s16) (*((u16 *) (((char *) var_s2) + 4))));
      var_fv0 = (f32) ((s32) ((s16) var_v0));
      *((f32 *) (((char *) var_s0) + 0x34)) = var_fv0;
      new_var2 = (f32 *) (((char *) var_s0) + 0x34);
      var_v0 = (u16) ((s16) (*((u16 *) (((char *) var_s2) + 6))));
      var_fv0 = (f32) ((s32) ((s16) var_v0));
      *new_var2 = var_fv0;
      func_80005744(var_s5);
      new_var3 = (f32 *) (((char *) var_s0) + 0x3C);
      *new_var3 = 150.0f;
      *((f32 *) (((char *) var_s0) + 0x40)) = 20000.0f;
      D_8009BB94 = 150.0f;
      D_8009BB9C = 13000.0f;
      D_8009BB98 = 130.0f;
      var_fp = 8000.0f;
      D_8009BBA0 = var_fp;
      *((f32 *) (((char *) var_s0) + 0x44)) = 4096.0f;
      *((s16 *) (((char *) var_s0) + 0x32)) = 0x10;
      func_800056F4(var_s0, 1);
      var_t0 = sp1E;
      *((u16 *) (((char *) var_s0) + 0x28)) = (u16) var_t0;
      *((s8 *) (((char *) var_s0) + 0x10)) = 0;
      *((s8 *) (((char *) var_s0) + 0x11)) = 0;
      *((s8 *) (((char *) var_s0) + 0x12)) = 0;
      *((s8 *) (((char *) var_s0) + 0x13)) = 0;
      *((s32 *) (((char *) var_s0) + 0x18)) = 0;
    }
    else
    {
      var_v0 = *((u16 *) ((char *) var_s2));
      var_s7 = 2;
      var_v1 = *((u16 *) (((char *) var_s2) + var_s7));
      var_a0 = (s32) (*((u16 *) (((char *) var_s2) + 4)));
      var_a1 = *((u16 *) (((char *) var_s2) + 6));
      *((u16 *) (((char *) var_s0) + 8)) = (u16) var_v0;
      *((u16 *) (((char *) var_s0) + 0xA)) = (u16) var_v1;
      *((s16 *) (((char *) var_s0) + 0xC)) = (s16) var_a0;
      *((u16 *) (((char *) var_s0) + 0xE)) = (u16) var_a1;
      var_v0 = *((u16 *) ((char *) var_s2));
      var_v1 = *((u16 *) (((char *) var_s2) + 2));
      var_a0 = (s32) (*((u16 *) (((char *) var_s2) + 4)));
      var_a1 = *((u16 *) (((char *) var_s2) + 6));
      *((u16 *) ((char *) var_s0)) = (u16) var_v0;
      *((u16 *) (((char *) var_s0) + 2)) = (u16) var_v1;
      *((s16 *) (((char *) var_s0) + 4)) = (s16) var_a0;
      *((u16 *) (((char *) var_s0) + 6)) = (u16) var_a1;
      var_v0 = (u16) ((s16) (*((u16 *) (((char *) var_s2) + 4))));
      var_fv0 = (f32) ((s32) ((s16) var_v0));
      *((f32 *) (((char *) var_s0) + 0x34)) = var_fv0;
      new_var2 = (f32 *) (((char *) var_s0) + 0x34);
      var_v0 = (u16) ((s16) (*((u16 *) (((char *) var_s2) + 6))));
      var_fv0 = (f32) ((s32) ((s16) var_v0));
      *new_var2 = var_fv0;
      func_80005744(var_s5);
      new_var3 = (f32 *) (((char *) var_s0) + 0x3C);
      *new_var3 = 150.0f;
      *((f32 *) (((char *) var_s0) + 0x40)) = 20000.0f;
      D_8009BB94 = 150.0f;
      D_8009BB9C = 13000.0f;
      D_8009BB98 = 130.0f;
      var_fp = 8000.0f;
      D_8009BBA0 = var_fp;
      *((f32 *) (((char *) var_s0) + 0x44)) = 4096.0f;
      *((s16 *) (((char *) var_s0) + 0x32)) = 0x10;
      func_800056F4(var_s0, 1);
      var_t0 = sp1E;
      *((u16 *) (((char *) var_s0) + 0x28)) = (u16) var_t0;
      *((s8 *) (((char *) var_s0) + 0x10)) = 0;
      *((s8 *) (((char *) var_s0) + 0x11)) = 0;
      *((s8 *) (((char *) var_s0) + 0x12)) = 0;
      *((s8 *) (((char *) var_s0) + 0x13)) = 0;
      *((s32 *) (((char *) var_s0) + 0x18)) = 0;
    }
  }
  return var_s0;
}
