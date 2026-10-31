extern s32 D_800AE850;
extern s32 D_800C02AE;
void func_8006E8A0(void)
{
  char *__repair_addr;
  s16 var_a1_2;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a2;
  char *new_var2;
  s32 var_t3;
  s32 var_t5;
  s32 var_v1;
  s32 var_v1_2;
  s8 temp_a2;
  s8 var_a1;
  u16 *new_var3;
  u16 temp_a1;
  u16 temp_v0;
  u16 temp_v0_2;
  u16 temp_v0_3;
  u16 temp_v0_4;
  u16 temp_v0_6;
  int new_var;
  u16 temp_v1;
  u32 temp_t0;
  u32 temp_v0_5;
  void *temp_t2;
  var_t3 = 4;
  if ((*((u8 *) (((char *) (&D_800AE850)) + 0x7FC9))) != 0)
  {
    var_t5 = 8;
  }
  else
  {
    var_t3 = 8;
    var_t5 = 0;
  }
  temp_t2 = ((u8 *) (&D_800C02AE)) + 0x6E64;
  new_var3 = &(*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE)));
  temp_v0 = ((*((u16 *) (((char *) (&D_800C02AE)) + 0x6E64))) & 0xBFFF) | (((*((u8 *) (((char *) (&D_800AE850)) + 0x7FCA))) & 1) << 0xE);
  new_var = (*((u8 *) (((char *) (&D_800AE850)) + 0x7FC8))) & 1;
  *((u16 *) (((char *) (&D_800C02AE)) + 0x6E64)) = temp_v0;
  temp_v0_2 = (temp_v0 & 0xDFFF) | (new_var << 0xD);
  *((u16 *) (((char *) (&D_800C02AE)) + 0x6E64)) = temp_v0_2;
  temp_v0_3 = (temp_v0_2 & 0x7FFF) | ((*((u8 *) (((char *) (&D_800AE850)) + 0x7FC9))) << 0xF);
  *((u16 *) (((char *) (&D_800C02AE)) + 0x6E64)) = temp_v0_3;
  temp_v0_4 = (temp_v0_3 & 0xFCFF) | (((*new_var3) & 3) << 8);
  *((u16 *) (((char *) (&D_800C02AE)) + 0x6E64)) = temp_v0_4;
  temp_a1 = (temp_v0_4 & 0xFF0F) | (((*((u8 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x32))) & 0xF) * 0x10);
  *((u16 *) (((char *) (&D_800C02AE)) + 0x6E64)) = temp_a1;
  __repair_addr = (char *) ((*((void **) (((char *) (&D_800C02AE)) + 0x32F2))) + ((*((u8 *) (((char *) (*((void **) ((0, ((char *) (&D_800C02AE)) + 0x32F2))))) + 0x32))) * 0x28));
  temp_a2 = (*((u8 *) (((char *) __repair_addr) + 0x4F))) & 0xF;
  *((s8 *) (((char *) (&D_800C02AE)) + 0x701E)) = temp_a2;
  if ((*new_var3) == 2)
  {
    *((u16 *) (((char *) (&D_800C02AE)) + ((short) 0x6E64))) = (u16) ((temp_a1 & 0xFFF0) | ((*((u8 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x33))) & 0xF));
    *((s8 *) (((char *) (&D_800C02AE)) + 0x701E)) = (s8) (temp_a2 + (((*((u8 *) (((char *) ((*((void **) (((char *) (&D_800C02AE)) + 0x32F2))) + ((*((u8 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x33))) * 0x28))) + 0x4F))) & 0xF) * 0x10));
  }
  else
  {
    *((u16 *) (((char *) (&D_800C02AE)) + 0x6E64)) = (u16) ((temp_a1 & 0xFFF0) | ((*((u16 *) (((char *) ((*((void **) (((char *) (&D_800C02AE)) + 0x32F2))) + ((*((u8 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x33))) * 0x28))) + 0x4E))) & 0xF));
  }
  temp_v1 = (*((u16 *) (((char *) ((*((void **) (((char *) (&D_800C02AE)) + 0x32F2))) + ((*((u8 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x34))) * 0x28))) + 0x4E))) & 0xF;
  temp_v1 = ((*((u16 *) (((char *) temp_t2) + 2))) & 0xFFF) | (temp_v1 << 0xC);
  *((u16 *) (((char *) temp_t2) + 2)) = temp_v1;
  var_a1 = 0;
  var_a0 = 0;
  temp_v0_5 = var_t3 & 0xFF;
  *((u16 *) (((char *) temp_t2) + 2)) = (u16) ((temp_v1 & 0xF0FF) | (((*((u16 *) (new_var2 = ((char *) ((*((void **) (((char *) (&D_800C02AE)) + 0x32F2))) + ((*((u8 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x35))) * 0x28))) + 0x4E))) & 0xF) << 8));
  if (temp_v0_5 != 0)
  {
    var_v1 = 0 & 0xFF;
    do
    {
      temp_v0_6 = *((u16 *) ((((var_t5 & 0xFF) + var_v1) * 2) + (((u8 *) (&D_800AE850)) + 0x7DC0)));
      var_a0 += 1;
      if (temp_v0_6 == 1)
      {
        var_a1 |= temp_v0_6 << var_v1;
      }
      var_v1 = var_a0 & 0xFF;
    }
    while (((u32) (var_a0 & 0xFF)) < temp_v0_5);
  }
  *((s8 *) (((char *) temp_t2) + 9)) = var_a1;
  var_a2 = 0;
  temp_t0 = var_t3 & 0xFF;
  do
  {
    var_a1_2 = 0;
    var_a0_2 = 0;
    if (temp_t0 != 0)
    {
      var_v1_2 = 0 & 0xFF;
      do
      {
        var_a0_2 += 1;
        var_v1_2 = (*((u8 *) (((((var_t5 & 0xFF) + var_v1_2) * 4) + (((u8 *) (&D_800AE850)) + 0x7DD8)) + (var_a2 & 0xFF)))) << (var_v1_2 * 2);
        var_a1_2 += var_v1_2;
        var_v1_2 = var_a0_2 & 0xFF;
      }
      while (((u32) (var_a0_2 & 0xFF)) < temp_t0);
    }
    *((s16 *) (((char *) (((var_a2 & 0xFF) * 2) + temp_t2)) + 0xA)) = var_a1_2;
    var_a2 += 1;
    *((s8 *) (((char *) temp_t2) + 7)) = (s8) (((s32) (*((s32 *) (((char *) (&D_800AE850)) + 0x7F1C)))) >> 8);
  }
  while (((u32) (var_a2 & 0xFF)) < 4U);
  *((s8 *) (((char *) temp_t2) + 3)) = (s8) (*((s32 *) (((char *) (&D_800AE850)) + 0x7F18)));
  *((s8 *) (((char *) temp_t2) + 5)) = (s8) (((s32) (*((s32 *) (((char *) (&D_800AE850)) + 0x7F18)))) >> 0x10);
  *((s8 *) (((char *) temp_t2) + 4)) = (s8) (((s32) (*((s32 *) (((char *) (&D_800AE850)) + 0x7F18)))) >> 8);
  *((s8 *) (((char *) temp_t2) + 8)) = (s8) (((s32) (*((s32 *) (((char *) (&D_800AE850)) + 0x7F1C)))) >> 0x10);
  var_t5 = *((s32 *) (((char *) (&D_800AE850)) + 0x7F1C));
  *((s8 *) (((char *) temp_t2) + 6)) = (s8) var_t5;
}
