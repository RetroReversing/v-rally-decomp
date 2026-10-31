extern u8 D_800C02AE[];
extern s32 D_800C35A0;
s32 func_8001FEE8(void *);
s32 func_80027CFC(void *);
u8 func_80027D24(u8, s32);
u8 func_80027D7C(u8, s32);
s8 func_80027DB4(s8, s32, u8);
s32 func_80085374(s32);
s8 func_80085714(s32, s32);
void func_80027E8C(void *arg0, s32 arg1, s8 *arg2)
{
  s32 var_a1;
  int new_var;
  
  int new_var2;
  s32 var_a1_3;
  s32 temp_s2;
  s32 temp_v1_3;
  s32 var_v0;
  s32 temp_v0;
  u32 temp_v1_2;
  u8 temp_v1;
  arg2[0] = 0;
  temp_s2 = func_80085374(arg1 & 255);
  temp_v1 = arg2[1] & 0xEF;
  arg2[1] = temp_v1;
  if (temp_s2 & 0x10)
  {
    arg2[1] = temp_v1 | 0x10;
  }
  if (temp_s2 & 0x80)
  {
    arg2[1] |= 0x80;
  }
  var_v0 = temp_s2 & 1;
  if (var_v0)
  {
    temp_v1 = arg2[4];
    var_a1 = 255;
    arg2[1] = 0;
  }
  else
  {
    temp_v1 = arg2[4];
    var_a1 = 0;
  }
  arg2[4] = func_80027D24(temp_v1, var_a1);
  if (temp_s2 & 2)
  {
    temp_v1 = arg2[5];
    var_v0 = 255;
  }
  else
  {
    temp_v1 = arg2[5];
    var_v0 = 0;
  }
  arg2[5] = func_80027D7C(temp_v1, var_v0);
  new_var2 = arg1;
  *((s32 *) ((D_800C02AE + 0x8062) + (new_var2 * 4))) = func_8001FEE8(arg0);
  temp_v1_2 = temp_s2 & 0xC;
  if (temp_v1_2 == 8)
  {
    goto b19;
  }
  if (temp_v1_2 >= 9)
  {
    goto b14;
  }
  if (temp_v1_2 == 4)
  {
    goto b18;
  }
  goto b21;
  b14:
  if (temp_v1_2 != 12)
  {
    goto b16;
  }

  goto b20;
  b16:
  goto b21;

  b18:
  temp_v0 = arg2[0];

  var_a1_3 = -128;
  goto b22;
  b19:
  temp_v0 = arg2[0];

  var_a1_3 = 127;
  goto b22;
  b20:
  arg2[0] = func_80027DB4(arg2[0], 0, new_var2 & 255);

  b21:
  temp_v0 = arg2[0];

  var_a1_3 = 0;
  b22:
  arg2[0] = func_80027DB4(temp_v0, var_a1_3, new_var2 & 255);

  {
    s8 axis = func_80085714(new_var2 & 255, 0x200);
    if ((axis << 24) != 0)
    {
      arg2[0] = axis;
    }
  }
  if ((*((s32 *) ((*((void **) (((u8 *) arg0) + 0x24))) + 4))) == 1)
  {
    goto b34;
  }
  new_var = D_800C35A0 + ((*((u8 *) ((D_800C35A0 + (*((u8 **) (((u8 *) arg0) + 0x48)))[3]) + 0x32))) * 0x28);
  temp_v1_3 = temp_s2 & 0x21;
  if (!((*((u8 *) (new_var + 0x48))) & 0x10))
  {
    goto b30;
  }
  if (temp_v1_3 != 0x21)
  {
    goto b28;
  }
  arg2[1] = 0x20;
  b28:
  if (temp_v1_3 != 0x20)
  {
    goto b34;
  }

  goto b33;
  b30:
  if (!(temp_s2 & 0x20))
  {
    goto b32;
  }

  arg2[1] = 0x20;
  b32:
  if (!(temp_s2 & 0x40))
  {
    goto b34;
  }

  b33:
  arg2[1] = 0x40;

  b34:
  func_80027CFC(arg2);

}
