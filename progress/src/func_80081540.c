s32 func_80081470(s32, u8 *);
s32 func_80081540(u8 *arg0)
{
  u8 sp10[16];
  s32 var_a0;
  s32 var_s0;
  s32 var_s2;
  s32 var_t0;
  u8 *base;
  u8 *var_a2;
  u8 *var_a3;
  u8 temp_a1;
  u8 temp_v0;
  u8 temp_v0_2;
  temp_v0 = *arg0;
  if (((temp_v0 == 0x5C) | (temp_v0 == 0x2F)) != 0)
  {
    *((s32 *) 0x800B7308) = *((s32 *) 0x800B7304);
    return 1;
  }
  var_a0 = *((s32 *) 0x800B7304);
 do { var_s0 = 0; var_s2 = 0; base = sp10; var_t0 = 0; loop_3: var_a3 = base; var_a2 = (u8 *) (((u32) var_s0) + ((u32) arg0)); loop_4: temp_v0_2 = *var_a2; var_a2 += 1; do { var_s0 += 1; } while (0); *var_a3 = temp_v0_2; temp_a1 = var_a2[-1]; var_t0 += 1; var_a3 += 1; if ((temp_a1 != 0x5C) & (temp_a1 != 0x2F)) { if (temp_a1 != 0) { goto loop_4; } } } while (0);
  if ((temp_v0_2 = temp_a1) == 0)
  {
    var_s2 = 1;
    sp10[var_t0 - 1] = 0x2F;
  }
  else
    if ((*var_a2) == 0)
  {
    var_s2 = 1;
  }
  base[var_t0] = 0;
  var_a0 = func_80081470(var_a0, sp10);
  if (var_a0 == 0)
  {
    return 0;
  }
  var_t0 = 0;
  if (var_s2 != 0)
  {
    *((s32 *) 0x800B7308) = var_a0;
    return 1;
  }
  goto loop_3;
}
