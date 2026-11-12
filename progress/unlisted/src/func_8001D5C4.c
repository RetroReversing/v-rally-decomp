s32 nameTableLookup();
extern char gOrderState[];
void func_8001D5C4(s32 arg0)
{
  s32 temp_v0;
  u8 var_v1;
  s16 *var_a0;

  temp_v0 = nameTableLookup(arg0 + 0x4C);
  var_a0 = *((s16 **) (gOrderState + 0x8A28));
  if (var_a0 != NULL)
  {
    var_v1 = temp_v0;
    if (var_v1 != 0)
    {
      var_a0[0x6E / 2] = var_v1;
    }
  }
}
