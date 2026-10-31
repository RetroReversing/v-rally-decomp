s32 func_800863B0(s32, s32);
s32 osPfsIsPlug(void *, u8 *, void *);
s32 osMotorInit(void *, void *, s32);
s32 osPfsInitPak(void *, void *, s32);
extern void *D_800A1B70;
extern u8 D_800AE850[];
static inline static static static static static int inline_fn(void *arg0, void *arg1, s32 arg2, int arg3)
{
  return osPfsInitPak(arg0, arg1, arg2) == arg3;
}

static inline static static char *inline_fn2(void *arg0)
{
  return (char *) arg0;
}

void func_80086138(s32 arg0, unsigned int arg1)
{
  s32 new_var2;
  void *temp_v0;
  u8 sp10;
  char *new_var;
  unsigned int temp_s1;
  char *new_var3;
  void **new_var4;
  s32 temp_s2;
  s32 var_v1;
  void *temp_a2;
  char *new_var5;
  void *temp_s3;
  s32 new_var6;
  void *temp_v1;
  temp_s2 = arg0 * 0x18;
  new_var2 = temp_s2;
  sp10 = 0;
  temp_a2 = D_800A1B70 + new_var2;
  *((s32 *) (((char *) temp_a2) + 0x330)) = 0;
  new_var4 = &temp_v0;
  var_v1 = arg0;
  new_var3 = ((char *) D_800A1B70) + 4;
  if (((((((s32) (arg1 & 0xFF)) >> arg0) & 1) && ((*((void **) (((char *) (((*((s32 *) new_var3)) * 4) + D_800A1B70)) + 0x38C)) = (void *) (D_800A1B70 + (new_var2 + 0x32C)), temp_v1 = D_800A1B70 + (var_v1 * 4), *((s32 *) (inline_fn2(temp_a2) + 0x32C)) = arg0, ((*((u16 *) (((char *) temp_v1) + 0xC))) & 4) != 0))) && ((*((u8 *) (((char *) temp_v1) + 0xE))) & 1)) && ((temp_s3 = D_800AE850 + 0x5A38, osPfsIsPlug(temp_s3, &sp10, temp_a2), ((((s32) sp10) >> var_v1) & 1) != 0)))
  {
    temp_s1 = (arg0 * 0x68) + 0x18C;
    if (osMotorInit(temp_s3, D_800A1B70 + temp_s1, var_v1) == 0)
    {
      func_800863B0(var_v1, 0);
      temp_v0 = D_800A1B70 + new_var2;
      *((s32 *) (((char *) (*new_var4)) + 0x330)) = 1;
      *((s32 *) (((char *) temp_v0) + 0x334)) = 0;
      return;
    }
    if (inline_fn(temp_s3, D_800A1B70 + temp_s1, arg0, 0))
    {
      if (D_800A1B70 || temp_s3)
      {
        var_v1 = 2;
      }
      else
      {
        var_v1 = 2;
      }
    }
    if (var_v1)
    {
      var_v1 = 3;
      new_var = ((char *) (D_800A1B70 + new_var2)) + 0x330;
      *((s32 *) new_var) = (new_var6 = var_v1);
    }
    else
    {
      new_var5 = (char *) (D_800A1B70 + new_var2);
      new_var = new_var5 + 0x330;
      *((s32 *) new_var) = new_var6;
    }
  }
}
