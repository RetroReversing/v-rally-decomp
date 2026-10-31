s32 func_800520D4(s32, s32);
s32 func_80098400(s32, s32 *, s32);
extern s32 D_800A5000;
extern s32 D_800AE850;
void func_80052108(s32 arg0)
{
  s32 temp_a1;
  s32 var_s0;
  s32 var_s1;
  s32 var_s2;
  var_s2 = 0;
  var_s0 = 0;
  temp_a1 = 0;
  if (arg0 > temp_a1)
  {
    var_s1 = 0;
    do
    {
      if (func_80098400((*((s32 *) (((char *) (&D_800AE850)) + 0x237C))) + var_s1, &D_800A5000, 5) == 0)
      {
        temp_a1 = var_s2 & 0xFFFF;
        var_s2 += 1;
        func_800520D4(var_s0 & 0xFFFF, temp_a1);
      }
      var_s0 += 1;
      var_s1 += 0x14;
    }
    while (var_s0 < arg0);
  }
}

