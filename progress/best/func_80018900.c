s32 func_800308B8();
s32 func_8004F27C();
s32 func_8007EE9C();
void func_80018900(void *arg0)
{
  void *new_var3;
  void *new_var5;
  char pad[8];
  void *new_var;
  u16 temp_v1;
  s32 var_s1;
  void *temp_v0;
  void *var_s0;
  char *new_var2;
  void **new_var7;
  s32 *new_var4;
  void *var_s2;
  void **new_var6;
  temp_v0 = *((void **) (((char *) arg0) + 8));
  temp_v1 = *((u16 *) (((char *) temp_v0) + 0x48));
  var_s2 = temp_v0 + 0x44;
  if (temp_v1 != 0)
  {
    var_s1 = 0;
    if (temp_v1 != 0)
    {
      new_var5 = temp_v0;
      new_var = new_var5;
      new_var7 = new_var6;
      new_var6 = (void **) (((char *) temp_v0) + 0x44);
      new_var3 = *new_var7;
      var_s0 = new_var3;
      do
      {
      }
      while (0);
      new_var2 = (char *) var_s2;
      if (1)
      {
        do
        {
          var_s1 += 1;
          func_8007EE9C(*(new_var4 = (s32 *) (((char *) var_s0) + 0x74)));
          func_8004F27C(var_s0);
          func_800308B8(var_s0);
          var_s0 = var_s0 + 0x94;
        }
        while (((s32) (*((u16 *) (new_var2 + 4)))) > var_s1);
      }
    }
  }
}
