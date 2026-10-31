typedef struct S_func_80087AB8_arg0
{
  u8 pad0[0x70];
  s32 f70;
  u8 pad1[0x1C];
  s16 f90;
  u8 pad2[2];
  s16 f94;
  u8 pad3[8];
  u16 f9E;
} S_func_80087AB8_arg0;
typedef struct S_func_80087AB8_rec
{
  s16 f0;
  u8 pad2[0xA];
  s16 fC;
  u8 padE[0x12];
  s32 f20;
} S_func_80087AB8_rec;
extern s32 D_800B68EC;
extern u8 *D_800B68F0;
extern s32 D_800C782C;
u8 *func_80087AB8(S_func_80087AB8_arg0 *arg0, u8 *arg1)
{
  s32 pad[2];
  u8 *new_var2;
  s32 new_var;
  s32 temp_lo;
  s32 count;
  s32 i;
  S_func_80087AB8_rec *p;
  i = arg0->f9E;
  temp_lo = ((s32) (((*arg1) * 0x6000) / 120)) / D_800B68EC;
  temp_lo = (temp_lo * arg0->f90) >> 7;
  arg1 += 1;
  if (i != 0)
  {
    arg0->f94 = temp_lo;
  }
  else
  {
    count = D_800C782C;
    p = (S_func_80087AB8_rec *) (D_800B68F0 + 0x94);
    if (count > 0)
    {
      if (1)
      {
        new_var2 = D_800B68F0;
        new_var = count;
        i = 0;
      }
      do
      {
        if ((*((s32 *) (((u8 *) p) - 0x24))) == arg0->f70)
        {
          p->fC = temp_lo;
          p->f0 = temp_lo;
        }
        if (new_var2)
        {
          i += 1;
          p = (S_func_80087AB8_rec *) (((u8 *) p) + 0x134);
        }
        else
        {
          i += 1;
          p = (S_func_80087AB8_rec *) (((u8 *) p) + 0x134);
        }
      }
      while (i < new_var);
    }
  }
  return arg1;
}
