extern int D_800B68EC;
extern int D_800C34D4;
extern char D_800AE850[];
extern char D_800C02AE[];
void func_800885CC(s8 *arg0)
{
  char *new_var4;
  int new_var;
  short temp_lo;
  s8 *temp_a2;
  char *var_a0;
  char *new_var3;
  u32 var_v1;
  s8 *new_var2;
  u8 temp_a3;
  var_a0 = arg0;
  temp_a2 = var_a0;
  temp_a3 = *((u8 *) (((char *) temp_a2) + 0xC1));
  var_v1 = 0;
  new_var4 = ((char *) temp_a2) + 0xC1;
  D_800C34D4 = D_800C34D4;
  *((s32 *) (((char *) temp_a2) + 0)) = 0;
  do
  {
    *((s8 *) var_a0) = 0;
    var_v1 += 1;
    var_a0 += 1;
  }
  while (var_v1 < 0x134U);
  *((u8 *) (((char *) temp_a2) + 0xC4)) = 0xFF;
  new_var = 0xFFFF;
  *((u8 *) (((char *) temp_a2) + 0xB6)) = 0xFF;
  temp_lo = 0x6000;
  new_var2 = temp_a2;
  temp_lo = temp_lo / ((s32) D_800B68EC);
  *((s8 *) (((char *) new_var2) + 0xCA)) = 0;
  *((s8 *) (((char *) new_var2) + 0xCB)) = 0x7F;
  *((s8 *) (((char *) temp_a2) + 0xB9)) = (*((s8 *) (((char *) temp_a2) + 0xBA)) = 0x7F);
  *((u8 *) (((char *) new_var2) + 0xBF)) = 0xFF;
  *((s8 *) (((char *) new_var2) + 0xB5)) = 0x40;
  *((s8 *) (((char *) new_var2) + 0xB7)) = 1;
  *((s8 *) (((char *) new_var2) + 0xBE)) = 1;
  *((s8 *) (((char *) temp_a2) + 0xC0)) = 0xF;
  *((s16 *) (((char *) new_var2) + 0x98)) = new_var;
  *((s16 *) (((char *) temp_a2) + 0x92)) = 1;
  *((s16 *) (((char *) new_var2) + 0x9A)) = 1;
  *((s16 *) (((char *) new_var2) + 0x9C)) = 1;
  *((s16 *) (((char *) new_var2) + 0x96)) = 0x80;
  *((s16 *) (((char *) new_var2) + 0xA8)) = 0x80;
  *((s16 *) (((char *) temp_a2) + 0x90)) = 0x80;
  new_var3 = (char *) new_var2;
  *((s8 *) (((char *) temp_a2) + 0xB4)) = 0x7F;
  *((u8 *) new_var4) = temp_a3;
  *((f32 *) (new_var3 + 0x24)) = 99.9f;
  *((f32 *) (((char *) temp_a2) + 0x68)) = 0.03125f;
  *((f32 *) (((char *) temp_a2) + 0x54)) = 1.0f;
  *((f32 *) (((char *) new_var2) + 0x58)) = 0.003921569f;
  *((f32 *) (new_var3 + 0x5C)) = 0.06666667f;
  *((s32 *) (new_var3 + 0x74)) = (s32) D_800C34D4;
  *((s16 *) (new_var3 + 0xA0)) = (s16) temp_lo;
  *((s16 *) (((char *) temp_a2) + 0x94)) = (s16) temp_lo;
  *((s32 *) (new_var3 + 0xC)) = -1;
}
