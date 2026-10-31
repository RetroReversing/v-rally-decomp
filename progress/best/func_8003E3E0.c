s32 func_8003A794();
extern char D_800C02AE[];
extern s32 func_8003B574;
void func_8003E3E0(s32 arg0, s32 arg1)
{
  char *temp_t2;
  char *temp_v0;
  char *temp_a3;
  s32 temp_t3;
  s32 temp_a2;
  s32 var_a1;
  s16 temp_a1;
  s16 temp_t0;
  s16 temp_v1;
  s32 mode;
  temp_t2 = *((char **) (D_800C02AE + 0x7CD6));
  temp_v0 = *((char **) (temp_t2 + 0x178));
  temp_a1 = *((s16 *) (temp_v0 + 8));
  temp_v1 = *((s16 *) (temp_v0 + 0xA));
  temp_t0 = *((s16 *) (temp_v0 + 0xC));
  temp_a3 = *((char **) (D_800C02AE + 0x32F2));
  temp_a2 = temp_v1 + 6;
  var_a1 = temp_a1 + 0x14;
  temp_t3 = temp_t0 - 0x10;
  mode = *((u16 *) (temp_a3 + 0xE));
  switch (mode)
  {
    case 1:
      do
    {
      if ((*((u16 *) (temp_a3 + 0x1E))) != 0)
      {
        return;
      }
      var_a1 = temp_t0 - 0x4A;
    }
    while (0);
      break;

    case 2:
      if ((*((u16 *) (temp_a3 + 0x1E))) != 0)
    {
      return;
    }
      if ((*((u16 *) (temp_a3 + 0x12))) & 1)
    {
      var_a1 = temp_a1 + 0x18;
    }
    else
      if ((*((s32 *) (temp_t2 + 0xC))) == 3)
    {
      var_a1 = var_a1 + temp_t3;
      var_a1 = var_a1 - 0x48;
    }
    else
    {
      var_a1 = temp_a1 + 0x2C;
    }
      break;

    default:
      return;

  }

  func_8003A794(arg0, var_a1, temp_a2, &func_8003B574, arg1, 0, 0);
}
