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
typedef struct Rec
{
  u8 pad0[0x70];
  s32 f70;
  u8 pad74[0x20];
  s16 f94;
  u8 pad96[0xA];
  s16 fA0;
  u8 padA2[0x134 - 0xA2];
} Rec;
extern s32 D_800B68EC;
extern Rec *D_800B68F0;
extern s32 D_800C782C;
u8 *func_80087AB8(S_func_80087AB8_arg0 *arg0, u8 *arg1)
{
  s32 pad[1];
  s32 q;
  s32 s;
  s32 i;
  Rec *p;
  q = ((*arg1 * 0x6000) / 120) / D_800B68EC;
  s = (q * arg0->f90) >> 7;
  arg1++;
  if (arg0->f9E != 0)
  {
    arg0->f94 = q;
  }
  else
  {
    p = D_800B68F0;
    for (i = 0; i < D_800C782C; i++, p++)
    {
      if (p->f70 == arg0->f70)
      {
        p->fA0 = q;
        p->f94 = s;
      }
    }
  }
  return arg1;
}
