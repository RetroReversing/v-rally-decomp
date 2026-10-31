extern int D_800C7F94;
extern int D_800C7FF4;
extern int D_800C7FFC;
extern unsigned char D_800C8002;
extern unsigned char D_800C7FA0;
s32 func_80078338();
s32 func_80098290();
s32 memset(void *, s32, s32);
extern s32 D_8009D540;
extern char D_800AE850[];
extern char D_800C02AE[];
extern char D_800C7F90[];
extern char D_800D0634[];
void func_800783A8(void)
{
  int __repair_literal;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a0_3;
  s32 temp_a1;
  s32 temp_s0;
  s32 temp_s1;
  s32 temp_v1_2;
  s32 var_a0;
  s32 var_a1;
  s32 var_a2;
  s32 var_a3;
  s32 var_v0;
  s32 var_v1;
  s8 var_s3;
  void *temp_a1_2;
  s32 *new_var;
  void *temp_s4;
  void *temp_v1;
  void *var_s2;
  var_s3 = 0;
  temp_s4 = D_800AE850 + 0x7DB0;
  var_s2 = *(*((void ***) (D_800AE850 + 0x73F0)));
  func_80097E30(D_800C7F90, 0);
  var_a1 = 0;
  if (var_s2 != NULL)
  {
    do
    {
      temp_s1 = var_s3 & 0xFF;
      var_a0 = func_80078338(temp_s1, var_a1);
      if ((*((void **) ((D_800C02AE + 0x7CF6) + ((var_a0 & 0xFF) * 0x18)))) != 0)
      {
        var_a0 -= 1;
      }
      temp_s0 = (var_a0 & 0xFF) * 0x18;
      *((void **) ((D_800C02AE + 0x7CF6) + temp_s0)) = var_s2;
      func_80098290(temp_s0 + (D_800C02AE + 0x7CE2), (*((void **) (D_800C02AE + 0x32F2))) + (((*((u8 *) (((char *) ((*((void **) (D_800C02AE + 0x32F2))) + temp_s1)) + 0x32))) * 0x28) + 0x44), *((void **) (D_800C02AE + 0x32F2)));
      *((D_800C02AE + 0x7CF3) + temp_s0) = var_s3;
      *((D_800C02AE + 0x7CF4) + temp_s0) = (s8) (*((u16 *) (((char *) ((*((void **) (D_800C02AE + 0x32F2))) - (-((*((u8 *) (((char *) ((*((void **) (D_800C02AE + 0x32F2))) + temp_s1)) + 0x32))) * 0x28)))) + 0x4E)));
      temp_a1 = temp_s1 * 4;
      var_a3 = 0;
      var_a2 = 0;
      *((s32 *) ((D_800C02AE + 0x7CE6) + temp_s0)) = *((s32 *) (((char *) ((((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20))) * 0x10) + temp_s4) + temp_a1)) + 0x58));
      temp_a1_2 = temp_a1 + temp_s4;
      temp_a0 = *((s32 *) (((char *) temp_a1_2) + 0x118));
      __repair_literal = 4;
      temp_v1 = (*((u8 **) ((__repair_literal * (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E)))) + (D_800C02AE + 0x10386)))) + ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20))) * 0x2C4);
      if (temp_a0 != 0)
      {
        var_a3 = *((s32 *) (((char *) temp_v1) + 0x22C));
        var_a2 = temp_a0;
      }
      temp_a0_2 = *((s32 *) (((char *) temp_a1_2) + 0x128));
      if (temp_a0_2 != 0)
      {
        var_a2 += temp_a0_2;
        var_a3 += *((s32 *) (((char *) temp_v1) + 0x230));
      }
      var_a0 = temp_s0;
      var_a1 = *((s32 *) (((char *) temp_a1_2) + 0x138));
      if (var_a1 != 0)
      {
        var_a3 += *((s32 *) (((char *) temp_v1) + 0x234));
      }
      *((u32 *) ((D_800C02AE + 0x7CEE) + var_a0)) = ((u32) ((var_a3 * D_8009D540) * 0xE10)) / ((u32) (var_a2 * 0x3E8));
      temp_v1_2 = *(*((s32 **) (((char *) var_s2) + 0x48)));
      *((D_800C02AE + 0x7CF2) + var_a0) = (s8) temp_v1_2;
      var_s2 = *((void **) (((char *) var_s2) + 4));
      var_s3 += 1;
    }
    while (var_s2 != NULL);
    var_a1 = 0;
  }
  var_v1 = 0 & 0xFF;
  do
  {
    temp_v1_2 = var_v1 * 0x18;
    do
    {
      new_var = (s32 *) ((D_800C02AE + 0x7CE6) + temp_v1_2);
      temp_a0_3 = *new_var;
    }
    while (0);
    var_a1 += 1;
    if (temp_a0_3 != 0)
    {
      var_v0 = temp_a0_3 - D_800C7F94;
      if (var_v0 < 0)
      {
        var_v0 = -var_v0;
      }
      *((s32 *) ((D_800C02AE + 0x7CEA) + temp_v1_2)) = var_v0;
    }
    else
    {
      *((s32 *) ((D_800C02AE + 0x7CEA) + temp_v1_2)) = 0;
    }
    var_v1 = var_a1 & 0xFF;
  }
  while (((u32) (var_a1 & 0xFF)) < 4U);
  var_a2 += var_a1;
  func_80098290(D_800C02AE + 0x7D42, ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20))) << 6) + (D_800C02AE + 0x34A8), D_800C02AE + 0x7CE6);
  D_800C7FF4 = *((s32 *) ((D_800C02AE + 0x34A2) + ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20))) << 6)));
  D_800C7FFC = *((u8 *) ((D_800C02AE + 0x34AC) + ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20))) << 6)));
  D_800C8002 = (u8) (*((D_800C02AE + 0x34A6) + ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20))) << 6)));
  if (((u8) D_800C7FA0) < 4U)
  {
    *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x2A)) |= 1 << (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20)));
  }
}
