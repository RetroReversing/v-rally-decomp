extern short D_800ADFDC;
extern unsigned char D_800ADFE0;
extern short D_800ADFDE;
extern unsigned char D_800B55E0;
extern int D_800D0658;
extern unsigned char D_800B6FF6;
extern char D_800A73E0[];
extern char D_800AE850[];
extern void *D_800C35A0;
void func_80046E54(void *arg0)
{
  void *__repair_cached_pointer = D_800C35A0;
  s32 temp_a1;
  u8 var_a1;
  s32 var_a1_2;
  u8 var_a2_2;
  s32 var_v0_2;
  u8 var_v1;
  u8 var_v1_2;
  u8 var_v1_3;
  u16 temp_a3;
  u16 temp_v0_2;
  u16 temp_v0_3;
  u16 temp_v0_4;
  u32 var_a3;
  char *var_a2;
  u8 temp_a0;
  u8 var_v0;
  u8 temp_a0_2;
  u8 temp_v0;
  u8 temp_v1;
  void *var_a0;
  var_a0 = arg0;
  D_800ADFDC = -1;
  if ((*((u16 *) (((char *) __repair_cached_pointer) + 0x1E))) != 0)
  {
    var_v0 = (*((s32 *) (((char *) var_a0) + 0x90))) + 1;
    goto block_3;
  }
  temp_v0 = *((u8 *) (((char *) D_800C35A0) + 0x30));
  D_800ADFE0 = temp_v0;
  var_v0 = temp_v0 + 1;
  if (temp_v0 != 0)
  {
    block_3:
    D_800ADFE0 = var_v0;

  }
  var_a3 = 0;
  if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) == 0)
  {
    if ((*((u16 *) (((char *) D_800C35A0) + 0xE))) == 4)
    {
      D_800ADFDE = 0x10;
      var_a3 = 0;
    }
  }
  D_800ADFDE = 0;
  var_a2 = D_800AE850 + 0x87A2;
  D_800B55E0 = (u8) (*((s32 *) (((char *) var_a0) + 0xDC)));
  do
  {
    temp_a1 = *((s32 *) (((char *) var_a0) + 0x128));
    *((u8 *) var_a2) = (u8) temp_a1;
    if ((*((u16 *) (((char *) D_800C35A0) + 0x16))) == 0)
    {
      *((u8 *) var_a2) = (((temp_a1 & 0xFF) * D_800B55E0) / 50) + temp_a1;
    }
    if ((*((u16 *) (((char *) D_800C35A0) + 0x16))) == 1)
    {
      temp_v1 = *((u8 *) var_a2);
      *((u8 *) var_a2) = temp_v1 + ((temp_v1 * D_800B55E0) / 100);
    }
    if (D_800AE850)
    {
      var_a2 += 1;
      var_a3 += 1;
      var_a0 += 0x4C;
    }
    else
    {
      var_a2 += 1;
      var_a3 += 1;
      var_a0 += 0x4C;
    }
  }
  while (var_a3 < 5U);
  temp_v0_2 = *((u16 *) (((char *) D_800C35A0) + 0x1E));
  if ((temp_v0_2 != 0) & (temp_v0_2 < 5U))
  {
    temp_v0_3 = *((u16 *) (((char *) (((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) D_800C35A0) + 0x32))) * 0x28))) + 0x4F))) * 0x2C4) + D_800D0658)) + 0x14));
    temp_a3 = *((u16 *) (((char *) D_800C35A0) + 0xE));
    var_v1 = ((temp_v0_3 == 1) | (temp_v0_3 == 3)) & 0xFF;
    if (temp_a3 == 2)
    {
      temp_v0_4 = *((u16 *) (((char *) (((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) D_800C35A0) + 0x33))) * 0x28))) + 0x4F))) * 0x2C4) + D_800D0658)) + 0x14));
      var_v1 = ((temp_v0_4 == 1) | (temp_v0_4 == 3)) & 0xFF;
    }
    var_a2_2 = 0;
    if (var_v1 == 1)
    {
      var_a1_2 = (var_a1 = 0);
      if (temp_a3 != 0)
      {
        var_v0_2 = 0 & 0xFF;
        do
        {
          if ((*((u16 *) (((char *) (((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + var_v0_2)) + 0x32))) * 0x28))) + 0x4F))) * 0x2C4) + D_800D0658)) + 0x14))) == 3)
          {
            var_a2_2 += 1;
          }
          var_a1 += 1;
          var_v0_2 = var_a1 & 0xFF;
        }
        while (((u32) (var_a1 & 0xFF)) < temp_a3);
      }
      if ((var_a2_2 & 0xFF) == (*((u16 *) (((char *) D_800C35A0) + 0xE))))
      {
        var_v1_2 = 0 & 0xFF;
        do
        {
          temp_a0 = *((D_800AE850 + 0x87A2) + var_v1_2);
          var_a1_2 += 1;
          *((D_800AE850 + 0x87A2) + var_v1_2) = temp_a0 + (temp_a0 >> 1);
          var_v1_2 = var_a1_2 & 0xFF;
        }
        while (((u32) (var_a1_2 & 0xFF)) < 4U);
        return;
      }
      var_v1_3 = 0 & 0xFF;
      do
      {
        temp_a0_2 = *((D_800AE850 + 0x87A2) - (-var_v1_3));
        var_a1_2 += 1;
        *((D_800AE850 + 0x87A2) + var_v1_3) = temp_a0_2 + ((temp_a0_2 * D_800B6FF6) / 100);
        var_v1_3 = var_a1_2 & 0xFF;
      }
      while (((u32) (var_a1_2 & 0xFF)) < 4U);
    }
  }
}
