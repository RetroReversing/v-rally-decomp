s32 func_800056FC();
s32 func_80005C48(s32);
void *func_80006008(s32);
s32 func_80006014(s32,  void *);
s32 osVirtualToPhysical(s32, void *);
extern void *D_8009B5A4;
extern s32 D_8009B5A8;
extern s32 D_8009B5D0;
static inline s32 inline_fn(int arg0, int arg1, int arg2)
{
  return (s32) (arg0 | (arg1 | arg2));
}

void func_8000A2C4(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  s16 var_v0;
  s32 temp_v0;
  s32 temp_v0_2;
  void *temp_s2;
  void *temp_s2_10;
  void *temp_s2_11;
  void *temp_s2_2;
  void *temp_s2_3;
  void *temp_s2_4;
  void *temp_s2_5;
  void *temp_s2_6;
  void *temp_s2_7;
  void *temp_s2_8;
  void *temp_s2_9;
  void *temp_s7;
  void *temp_v1;
  void *temp_v1_2;
  temp_s7 = *((void **) (((char *) arg0) + 0x2C));
  temp_v0 = func_800056FC();
  temp_s2 = func_80006008(temp_v0);
  temp_v0_2 = func_80005C48(D_8009B5A8);
  temp_s2_2 = temp_s2 + 8;
  *((s32 *) (((char *) temp_s2) + 0)) = 0xDE000000;
  temp_s2_3 = temp_s2_2 + 8;
  *((s32 **) (((char *) temp_s2) + 4)) = &D_8009B5D0;
  *((s32 *) (((char *) temp_s2) + 8)) = (s32) ((((*((s16 *) (((char *) D_8009B5A4) + 4))) - 1) & 0xFFF) | 0xFF100000);
  *((s32 *) (((char *) temp_s2_2) + 4)) = osVirtualToPhysical(temp_v0_2, D_8009B5A4);
  if (!(arg3 & 0xFF))
  {
    *((s16 *) (((char *) (*((void **) (((char *) arg0) + 0x2C)))) + 0x10)) = 0;
    *((s16 *) (((char *) (*((void **) (((char *) arg0) + 0x2C)))) + 0x18)) = 0;
    *((s16 *) (((char *) (*((void **) (((char *) arg0) + 0x2C)))) + 0x14)) = (s16) (arg1 * 4);
    *((s16 *) (((char *) (*((void **) (((char *) arg0) + 0x2C)))) + 0x1C)) = (s16) (arg2 * 4);
    temp_v1 = *((void **) (((char *) arg0) + 0x2C));
    *((u16 *) (((char *) temp_v1) + 0x16)) = (u16) (*((u16 *) (((char *) temp_v1) + 0x12)));
    temp_v1_2 = *((void **) (((char *) arg0) + 0x2C));
    *((u16 *) (((char *) temp_v1_2) + 0x1E)) = (u16) (*((u16 *) (((char *) temp_v1_2) + 0x1A)));
    *((s32 *) (((char *) temp_s2_2) + 8)) = inline_fn((((s32) (((f32) (*((s16 *) (((char *) arg0) + 0)))) * 4.0f)) & 0xFFF) << 0xC, ((s32) (((f32) (*((s16 *) (((char *) arg0) + 2)))) * 4.0f)) & 0xFFF, 0xED000000);
    var_v0 = *((s16 *) (((char *) arg0) + 4));
  }
  else
  {
    *((s16 *) (((char *) (*((void **) (((char *) arg0) + 0x2C)))) + 0x10)) = 0;
    *((s16 *) (((char *) (*((void **) (((char *) arg0) + 0x2C)))) + 0x18)) = 0;
    *((s32 *) (((char *) temp_s2_2) + 8)) = (s32) (((((s32) (((f32) (*((s16 *) (((char *) arg0) + 0)))) * 4.0f)) & 0xFFF) << 0xC) | ((((s32) (((f32) (*((s16 *) (((char *) arg0) + 2)))) * 4.0f)) & 0xFFF) | 0xED000000));
    var_v0 = (*((s16 *) (((char *) arg0) + 4))) + 8;
  }
  temp_s2_4 = temp_s2_3 + 8;
  *((s32 *) (((char *) temp_s2_3) + 4)) = (s32) (((((s32) (((f32) var_v0) * 4.0f)) & 0xFFF) << 0xC) | (((s32) (((f32) (*((s16 *) (((char *) arg0) + 6)))) * 4.0f)) & 0xFFF));
  temp_s2_5 = temp_s2_4 + 8;
  temp_s2_6 = temp_s2_5 + 8;
  temp_s2_7 = temp_s2_6 + 8;
  temp_s2_8 = temp_s2_7 + 8;
  temp_s2_9 = temp_s2_8 + 8;
  temp_s2_10 = temp_s2_9 + 8;
  temp_s2_11 = temp_s2_10 + 8;
  *((s32 *) (((char *) temp_s2_3) + 8)) = 0xE200001C;
  *((s32 *) (((char *) temp_s2_4) + 4)) = 0;
  *((s32 *) (((char *) temp_s2_5) + 4)) = 0x200000;
  *((s32 *) (((char *) temp_s2_4) + 8)) = 0xE3000A01;
  *((s32 *) (((char *) temp_s2_6) + 4)) = 0x8000;
  *((s32 *) (((char *) temp_s2_5) + 8)) = 0xE3001001;
  *((s32 *) (((char *) temp_s2_6) + 8)) = 0x05000017;
  *((void **) (((char *) temp_s2_7) + 4)) = (void *) (temp_s7 + 0x38);
  *((s32 *) (((char *) temp_s2_7) + 8)) = 0xE7000000;
  *((s32 *) (((char *) temp_s2_8) + 4)) = 0;
  *((s32 *) (((char *) temp_s2_8) + 8)) = 0x0A000000;
  *((void **) (((char *) temp_s2_9) + 4)) = (void *) (temp_s7 + 0x10);
  *((s32 *) (((char *) temp_s2_9) + 8)) = 0xE7000000;
  *((s32 *) (((char *) temp_s2_10) + 4)) = 0;
  *((s32 *) (((char *) temp_s2_10) + 8)) = 0xE3000A01;
  *((s32 *) (((char *) temp_s2_11) + 4)) = 0;
  func_80006014(temp_v0,  temp_s2_11 + 8);
}

