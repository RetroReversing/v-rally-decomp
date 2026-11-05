void func_80030180(u8 *arg0, s32 arg1, s16 arg2, s16 *arg3)
{
  char *__repair_addr;
  s16 sp[3];
  s32 a0;
  s32 a1;
  s32 a3;
  s32 v1;
  s32 __repair_phase_v1;
  s16 d0;
  s16 d1;
  s16 d2;
  u8 *base;
  int new_var;
  s32 t1;
  v1 = *((u16 *) (arg0 + 0x8A)); t1 = arg2; a0 = ((*((s32 *) (arg0 + 0x4C)))) + ((arg1 * v1)); v1 = a0 - 2;
  __repair_phase_v1 = a0 + 2;
  if (t1 < 500)
  {
    if (__repair_addr || arg2)
    {
      base = *((u8 **) (arg0 + 0x54));
      a1 = a0 * 6;
      a3 = v1 * 6;
      __repair_addr = (char *) (base + a3);
      d0 = (*((u16 *) (base + a1))) - (*((u16 *) __repair_addr));
    }
    else
    {
      base = *((u8 **) (arg0 + 0x54));
      a1 = a0 * 6;
      a3 = v1 * 6;
      __repair_addr = (char *) (base + a3);
      d0 = (*((u16 *) (base + a1))) - (*((u16 *) __repair_addr));
    }
  }
  else
  {
    base = *((u8 **) (arg0 + 0x54));
    a3 = a0 * 6;
    a1 = __repair_phase_v1 * 6;
    d0 = (*((u16 *) (base + a1))) - (*((u16 *) (base + a3)));
    t1 -= 500;
  }
  sp[0] = d0;
  d1 = (*((u16 *) (((*((u8 **) arg0)) + (a1 + 0x54)) + 2))) - (*((u16 *) (((*((u8 **) (arg0 + 0x54))) + a3) + 2)));
  sp[1] = d1;
  d2 = (*((u16 *) (((*((u8 **) (arg0 + 0x54))) + a1) + 4))) - (*((u16 *) (((*((u8 **) (arg0 + 0x54))) + a3) + 4)));
  sp[new_var = 2] = d2;
  sp[0] = (((s16) d0) * t1) / 500;
  sp[1] = (((s16) d1) * t1) / 500;
  sp[new_var] = (((s16) d2) * t1) / 500;
  arg3[0] = (*((u16 *) ((*((u8 **) (arg0 + 0x54))) + a3))) + sp[0];
  arg3[1] = (*((u16 *) (((*((u8 **) (arg0 + 0x54))) + a3) + new_var))) + sp[1];
  arg3[new_var] = (*((u16 *) (((*((u8 **) (arg0 + 0x54))) + a3) + 4))) + sp[2];
}

