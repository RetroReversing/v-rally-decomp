typedef struct 
{
  u8 b[8];
} Buf8;
extern void func_80015460(s32, u32);
extern f32 D_8009CEC0[];
extern u32 D_800B56E8;
extern u32 D_800B56EC;
extern u32 D_800C7F80;
extern void *D_800C6ED8;
void *func_80018A14(void *arg0, u8 *arg1, u8 *arg2)
{
  s32 i;
  s32 *e;
  u8 *rec;
  u32 t;
  void *s3;
  s32 off;
  D_800B56E8 = 0;
  func_80015460((s32) arg0, 1);
  *((u16 *) (arg1 + 0x22)) = *((u16 *) (arg1 + 0x20));
  off = ((*((u16 *) (arg1 + 0x20))) * 0x38) + 0x3C;
  rec = arg1 + off;
  *((Buf8 *) rec) = *((Buf8 *) arg2);
  *((u32 *) (rec + 8)) = D_800C7F80;
  *((u16 *) (arg1 + 0x20)) = (*((u16 *) (arg1 + 0x20))) + 1;
  s3 = arg0;
  e = *((s32 **) s3);
  for (i = 0; i < (*((u16 *) (((u8 *) s3) + 4))); i++)
  {
    e[11] += D_800B56EC;
    e[4] = ((s32) (((f32) e[4]) * D_8009CEC0[0])) - 0x1F4;
    e[6] = ((s32) (((f32) e[6]) * D_8009CEC0[0])) + 0x1F4;
    e[5] = (s32) (((f32) e[5]) * D_8009CEC0[1]);
    e[7] = (s32) (((f32) e[7]) * D_8009CEC0[1]);
    e[8] = ((s32) (((f32) e[8]) * D_8009CEC0[2])) - 0x1F4;
    e[9] = ((s32) (((f32) e[9]) * D_8009CEC0[2])) + 0x1F4;
    func_80015460(e[11], e[10]);
    t = e[10];
    e = &t;
    if (D_800B56E8 < (*e))
    {
      D_800B56E8 = *e;
    }
    e += 12;
  }

  D_800C6ED8 = s3;
  return s3;
}
