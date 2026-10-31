s32 func_80009C90();
s32 func_800566B4();
s32 func_80056884();
void func_80056AB8(void *arg0, void *arg1, s32 arg2)
{
  int new_var2;
  s32 pad[2];
  s32 temp_s3;
  s32 var_s1;
  char *new_var;
  u8 temp_v0;
  u32 val;
  void *var_s0;
  var_s0 = *((void **) arg1);
  val = *((u32 *) (((char *) arg0) + 0x84));
  new_var2 = (val & 0x87FFFFFF) | 0x08000000;
  temp_s3 = *((u16 *) (((char *) arg1) + 4));
  new_var = ((char *) arg0) + 0x84;
  *((s32 *) new_var) = 0xFBFFFFFF;
  *((s32 *) new_var) = (new_var2 & (*((s32 *) new_var))) | 0x04000000;
  func_80009C90(arg0, 1);
  var_s1 = 0;
  if (temp_s3)
  {
    do
    {
      temp_v0 = *(((u8 *) var_s0) + 3);
      val = temp_v0;
      switch (val)
      {
        case 6:
          func_800566B4(arg0, var_s0, arg2);
          break;

        case 0xA:
          func_80056884(arg0, var_s0, arg2);
          break;

        default:
          break;

      }

      if (temp_s3)
      {
        var_s1++;
        var_s0 = ((char *) var_s0) + 0x22;
      }
      else
      {
        var_s1++;
        var_s0 = ((char *) var_s0) + 0x22;
      }
    }
    while (var_s1 < ((s32) temp_s3));
  }
}
