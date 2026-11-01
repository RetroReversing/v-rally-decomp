s32 func_800056FC();
void *func_80006008();
s32 func_80006014();
s32 func_8000DEF0();
s32 osVirtualToPhysical();
extern void *D_8009B5A4;
void func_80005500(u8 *arg0, u16 *arg1)
{
  int new_var2;
  char pad[8];
  s16 temp_a2;
  s32 temp_c;
  s16 *new_var;
  s32 var_s3;
  u32 *dl;
  u32 *var_s2;
  u16 *var_s0;
  u8 *var_s1;
  var_s0 = arg1;
  var_s1 = arg0;
  var_s3 = func_800056FC();
  dl = func_80006008(var_s3);
  *((s16 *) (var_s1 + 8)) = var_s0[0];
  temp_c = (s16) var_s0[0];
  *((volatile s16 *) (var_s1 + 0xA)) = var_s0[1];
  new_var2 = 2;
  *((s16 *) (var_s1 + 0xC)) = var_s0[new_var2];
  var_s2 = dl;
  *((s16 *) (var_s1 + 0xE)) = var_s0[3];
  if (temp_c >= 0)
  {
    *((s16 *) (var_s1 + 0)) = temp_c;
    if ((*(new_var = (s16 *) (((u8 *) D_8009B5A4) + 4))) >= (temp_c + (*((s16 *) (var_s1 + 0xC)))))
    {
      *((s16 *) (var_s1 + 4)) = temp_c + (*((s16 *) (var_s1 + 0xC)));
    }
  }
  else
  {
    *((s16 *) (var_s1 + 4)) = (*((u16 *) (var_s1 + 0xC))) + temp_c;
  }
  temp_a2 = *((s16 *) (var_s1 + 0xA));
  if (temp_a2 >= 0)
  {
    do
    {
      dl = ((u8 *) D_8009B5A4) + 6;
      *((s16 *) (var_s1 + 2)) = temp_a2;
    }
    while (0);
    if ((*((s16 *) dl)) >= (temp_a2 + (*((s16 *) (var_s1 + 0xE)))))
    {
      *((s16 *) (var_s1 + 6)) = temp_a2 + (*((s16 *) (var_s1 + 0xE)));
    }
  }
  else
  {
    *((s16 *) (var_s1 + 6)) = (*((u16 *) (var_s1 + 0xC))) + temp_a2;
  }
  func_8000DEF0(*((s32 *) (var_s1 + 0x1C)), var_s0);
  dl = var_s2;
  var_s2 += 2;
  *dl = 0xDC080008;
  dl[1] = osVirtualToPhysical(*((s32 *) (var_s1 + 0x1C)));
  var_s2[0] = (short) (((((s32) (((f32) (*((s16 *) (var_s1 + 0)))) * 4.0f)) & 0xFFF) << 12) | ((((s32) (((f32) (*((s16 *) (var_s1 + 2)))) * 4.0f)) & 0xFFF) | 0xED000000));
  var_s2[1] = ((((s32) (((f32) (*((s16 *) (var_s1 + 4)))) * 4.0f)) & 0xFFF) << 12) | (((s32) (((f32) (*((s16 *) (var_s1 + 6)))) * 4.0f)) & 0xFFF);
  func_80006014(var_s3, var_s2 + 2, var_s2);
}

