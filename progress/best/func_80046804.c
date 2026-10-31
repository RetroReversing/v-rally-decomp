extern void (*D_800A0264[])(u8 *, s32, u8 *, s32);
void func_80046804(u8 **arg0, u8 *arg1)
{
  u8 *temp_s2;
  s32 *new_var;
  s32 dv[3];
  s32 pv[3];
  s32 dd[3];
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_a1_3;
  s32 temp_v0;
  s32 temp_v1;
  s32 temp_v1_2;
  u8 *var_s1;
  s32 var_s0;
  s32 var_s3;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v1;
  s32 pad[4];
  temp_s2 = *arg0;
  pv[0] = *((s32 *) ((*((u8 **) (arg1 + 0x80))) + 0x2B8));
  new_var = &(*((s32 *) temp_s2));
  pv[2] = *((s32 *) ((*((u8 **) (arg1 + 0x80))) + 0x2C0));
  var_v0 = 2;
  dd[0] = pv[0] - (*((s32 *) temp_s2));
  temp_v1 = dd[0] >> 4;
  dd[2] = pv[var_v0] - (*((s32 *) (temp_s2 + 0x8)));
  temp_v0 = dd[2] >> 4;
  if (((u32) ((temp_v1 * temp_v1) + (temp_v0 * temp_v0))) <= 0xC34F)
  {
    var_s3 = 1;
    var_s3 = *((u16 *) ((*((u8 **) (arg1 + 0x48))) + 0x2E));
    temp_v1_2 = ((var_s3 * 2) | 1) & 0xFFFF;
    var_s0 = 0;
    if (temp_v1_2 > 0)
    {
      var_v0 = var_s3 & 0xFFFF;
      do
      {
        var_s3 = var_v0 * 2;
        var_s0 += 1;
        var_v0 = var_s3 & 0xFFFF;
      }
      while (var_s0 < temp_v1_2);
    }
    temp_a1_3 = (var_s3 & 0xFFFF) * 2;
    dv[0] = pv[0] - (*new_var);
    dv[1] = pv[1] - (*((s32 *) (temp_s2 + 0x4)));
    dv[2] = pv[2] - (*((s32 *) (temp_s2 + 0x8)));
    if (((dv[0] * (*((s32 *) (temp_s2 + 0xC)))) + (dv[2] * (*((s32 *) (temp_s2 + 0x14))))) < 0)
    {
      var_s1 = temp_s2 + 0x1C;
      if (((*((u16 *) (temp_s2 + 0x1A))) & temp_a1_3) == (temp_a1_3 & 0xFFFF))
      {
        var_s0 = 0;
        temp_a1 = *((u16 *) (temp_s2 + 0x18));
        if (temp_a1 > 0)
        {
          do
          {
            ((void (*)(u8 *, s32, u8 *, s32)) D_800A0264[*((u16 *) var_s1)])(var_s1 + 8, *((u16 *) (var_s1 + 2)), arg1, 0);
            var_s0 += 1;
            var_s1 += (*((s32 *) (var_s1 + 4))) + 8;
          }
          while (var_s0 < (*((u16 *) (temp_s2 + 0x18))));
        }
      }
      var_v1 = ~temp_a1_3;
      var_v0_2 = (*((u16 *) (temp_s2 + 0x1A))) | var_s3;
    }
    else
    {
      var_v1 = ~var_s3;
      var_v0_2 = (*((u16 *) (temp_s2 + 0x1A))) | temp_a1_3;
    }
    *((u16 *) (temp_s2 + 0x1A)) = var_v0_2 & var_v1;
  }
}
