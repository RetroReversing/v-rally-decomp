s32 func_8003A794();
extern char D_800C02AE[];
extern s32 func_8003B660;
void func_8003D8F4(s32 arg0, s32 arg1)
{
  char *obj;
  char *temp_v0;
  char *temp_a3;
  char *new_var4;
  char **new_var3;
  u16 new_var2;
  s32 var_a1;
  s32 var_t3;
  s32 var_a2;
  s32 temp_t0;
  u16 temp_v1;
  s32 new_var;
  char *new_var5;
  new_var3 = &(*((char **) (D_800C02AE + 0x7CD6)));
  obj = *new_var3;
  temp_v0 = *((char **) (obj + 0x178));
  new_var5 = (new_var4 = obj + 0xC);
  var_a1 = *((s16 *) (temp_v0 + 8));
  var_t3 = var_a1;
  var_t3 += 0x14;
  var_a2 = (*((s16 *) (0xA + temp_v0))) + 6;
  temp_t0 = (*((s16 *) (temp_v0 + 0xE))) - 8;
  new_var = temp_t0;
  temp_a3 = *((char **) (D_800C02AE + 0x32F2));
  temp_v1 = *((u16 *) (temp_a3 + 0xE));
  switch (temp_v1)
  {
    case 1:
      if ((*((u16 *) (temp_a3 + 0x1E))) == 0)
    {
      var_a1 += 0x4A;
    }
    else
    {
      var_a1 += 0x1C;
      new_var = temp_t0;
      var_a2 = var_a2 + new_var;
      var_a2 = var_a2 - 0xE;
    }
      break;

    case 2:
      if ((*((u16 *) (temp_a3 + 0x1E))) != 0)
    {
      return;
    }
      temp_a3 = temp_a3 + 0x12;
      new_var2 = *((u16 *) temp_a3);
      if (new_var2 & 1)
    {
      var_a2 = var_a2 + new_var;
    }
    else
    {
      if ((*((s32 *) new_var5)) == 3)
      {
        var_t3 = var_a1 + 4;
      }
      var_a1 = var_t3;
      var_a2 += new_var;
    }
      var_a2 -= 0x1A;
      break;

    default:
      return;

  }

  func_8003A794(arg0, var_a1, var_a2, &func_8003B660, arg1, 0, 0);
}
