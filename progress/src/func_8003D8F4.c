typedef void (*SpriteHook)(void *);
void func_8003A794(s32,s32,s32,SpriteHook,u8*,u16,u8*);
extern char D_800C02AE[];
void func_8003B660(void *);
void func_8003D8F4(s32 arg0, s32 arg1)
{
  char *obj;
  char *temp_v0;
  char *temp_a3;
  s32 var_a1;
  s32 var_t3;
  s32 var_a2;
  s32 temp_t0;
  obj = *((char **) (D_800C02AE + 0x7CD6));
  temp_v0 = *((char **) (obj + 0x178));
  var_a1 = *((s16 *) (temp_v0 + 8));
  var_t3 = var_a1 + 0x14;
  var_a2 = (*((s16 *) (temp_v0 + 0xA))) + 6;
  temp_t0 = (*((s16 *) (temp_v0 + 0xE))) - 8;
  temp_a3 = *((char **) (D_800C02AE + 0x32F2));
  switch (*((u16 *) (temp_a3 + 0xE)))
  {
    case 1:
      if ((*((u16 *) (temp_a3 + 0x1E))) == 0)
      {
        var_a1 += 0x4A;
        func_8003A794((s32)(arg0), var_a1, var_a2, &func_8003B660, (u8 *)(arg1), 0, 0);
        return;
      }
      else
      {
        var_a1 += 0x1C;
        var_a2 = var_a2 + temp_t0 - 0xE;
      }
      func_8003A794((s32)(arg0), var_a1, var_a2, &func_8003B660, (u8 *)(arg1), 0, 0);
      break;
    case 2:
      if ((*((u16 *) (temp_a3 + 0x1E))) != 0)
      {
        return;
      }
      if (*((u16 *) (temp_a3 + 0x12)) & 1)
      {
        var_a2 = var_a2 + temp_t0;
      }
      else
      {
        if ((*((s32 *) (obj + 0xC))) == 3)
        {
          var_t3 = var_a1 + 4;
        }
        var_a1 = var_t3;
        var_a2 += temp_t0;
      }
      var_a2 -= 0x1A;
      func_8003A794((s32)(arg0), var_a1, var_a2, &func_8003B660, (u8 *)(arg1), 0, 0);
      break;
  }
}
