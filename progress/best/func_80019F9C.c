extern u8 D_800A73E0[];
void func_80019F9C(u8 *arg0, u32 arg1, void *arg2, s32 arg3)
{
  u8 *var_s4;
  u32 var_s5;
  u8 *rec;
  u8 *tmp;
  u32 temp_s1;
  u32 temp_s0;
  u32 *prim;
  u32 *last;
  s32 pad[1];
  void *render;
  u32 mask;
  u32 *new_var;
  var_s4 = arg0;
  render = arg2;
  prim = *((u32 **) (((u8 *) render) + 0x14));
  *((u32 **) (((u8 *) render) + 0x14)) = prim + 2;
  prim[0] = 0xD9FFF9FF;
  prim[1] = 0;
  mask = 0xFCFFFFFF;
  *((u32 *) (((u8 *) render) + 0x84)) &= mask;
  func_80009964(render, 1);
  var_s5 = 0;
  new_var = (u32 *) (((u8 *) arg2) + 0x84);
  if (arg1 != 0)
  {
    do
    {
      do
      {
        rec = (*((u8 **) ((*((u8 **) (D_800A73E0 + 0x6C14))) + 0x24))) + ((*((u16 *) (var_s4 + 0x12))) * 0x14);
        tmp = *((u8 **) (rec + 0x10));
        var_s5 += 1;
        func_80009164(arg2, *((u32 *) (*((u8 **) (tmp + 4)))), *((u8 *) (rec + 0xF)));
        func_80009964(arg2, 0);
        temp_s1 = func_800199DC(arg2, arg3, var_s4);
        temp_s0 = temp_s1 & 0xFFFF;
        func_80008D70(arg2, temp_s0);
        func_80006984(arg2, temp_s0, *var_s4, var_s4[1], var_s4[2]);
        func_80006984(arg2, (temp_s1 + 1) & 0xFFFF, *var_s4, var_s4[1], var_s4[2]);
        func_80006984(arg2, (temp_s1 + 2) & 0xFFFF, *var_s4, var_s4[1], var_s4[2]);
        func_80006984(arg2, (temp_s1 + 3) & 0xFFFF, *var_s4, var_s4[1], var_s4[2]);
        var_s4 += 0x18;
      }
      while (var_s5 < arg1);
    }
    while (0);
  }
  var_s5 = ((*new_var) & 0xFCFFFFFF) | 0x01000000;
  *((u32 *) (((u8 *) arg2) + 0x84)) = var_s5;
  func_80009964(arg2, 0);
  last = *((u32 **) (((u8 *) render) + 0x14));
  *((u32 **) (((u8 *) render) + 0x14)) = last + 2;
  last[0] = 0xD9FFFFFF;
  last[1] = 0x400;
}
