s32 __osPfsSelectBank(void *, s32);
s32 func_80091600(void *, void *, s32);
s32 __osContRamRead(s32, s32, s32, void *);
s32 func_80096A10(s32, s32, s32, void *, s32);
extern s32 D_800A3B30;
extern u8 D_800A3B34;
extern char D_800C02AE[];
static inline static static static static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

s32 __osPfsRWInode(void *arg0, void *arg1, u32 arg2, u32 arg3)
{
  s32 temp_a2;
  s32 temp_a2_2;
  s32 temp_s3;
  s32 temp_v1;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a1_3;
  s32 var_a3;
  s32 var_s0;
  s32 var_s0_2;
  s32 var_s0_3;
  s32 var_s5;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v1;
  char *var_a1;
  char *var_a1_2;
  char *var_a2;
  u8 var_v1_2;
  void *temp_a3;
  void *temp_a3_2;
  void *temp_s1;
  void *var_s1;
  void *var_s1_2;
  u8 idx;
  u8 mode;
  s32 fp_mode;
  s32 pad[4];
  idx = arg3;
  mode = arg2;
  if (((!mode) && (idx == D_800A3B34)) && ((*((s32 *) (((char *) arg0) + 8))) == D_800A3B30))
  {
    func_80091600(D_800C02AE + 0x7062, arg1, 0x100);
    return 0;
  }
  if ((*((u8 *) (((char *) arg0) + 0x65))) != 0)
  {
    var_v0 = __osPfsSelectBank(arg0, 0);
    var_v1 = var_v0;
    if (var_v1 != 0)
    {
      if (1)
      {
        return var_v0;
      }
    }
  }
  var_s5 = 1;
  if (!idx)
  {
    var_s5 = *((s32 *) (((char *) arg0) + 0x60));
  }
  var_s0 = 0;
  if (mode == 1)
  {
    var_a1 = (char *) (var_s5 * 2);
    var_a1 += (s32) arg1;
    var_a0 = 0;
    temp_a2 = (0x80 - var_s5) * 2;
    var_v1_2 = 0;
    if (temp_a2 > 0)
    {
      do
      {
        var_a0 += 1;
        var_v1_2 += *((u8 *) var_a1);
        var_a1 += 1;
      }
      while (var_a0 < temp_a2);
    }
    *((u8 *) (((char *) arg1) + 1)) = var_v1_2;
    var_s0 = 0;
  }
  temp_s3 = idx * 8;
  fp_mode = mode;
  var_v0_2 = 0;
  loop_13:
  temp_s1 = arg1 + var_v0_2;

  if (fp_mode == 1)
  {
    func_80096A10(*((s32 *) (((char *) arg0) + 4)), *((s32 *) (((char *) arg0) + 8)), (((*((s32 *) (((char *) arg0) + 0x54))) + temp_s3) + var_s0) & 0xFFFF, temp_s1, 0);
    var_v1 = func_80096A10(*((s32 *) (((char *) arg0) + 4)), *((s32 *) (((char *) arg0) + 8)), (((*((s32 *) (((char *) arg0) + 0x58))) + temp_s3) + var_s0) & 0xFFFF, temp_s1, 0);
  }
  else
  {
    do
    {
      var_v1 = __osContRamRead(*((s32 *) (((char *) arg0) + 4)), *((s32 *) (((char *) arg0) + 8)), (((*((s32 *) (((char *) arg0) + 0x54))) + temp_s3) + var_s0) & 0xFFFF, temp_s1);
    }
    while (0);
  }
  var_s0 += 1;
  if (var_v1 == 0)
  {
    var_v0_2 = (var_s0 << 1) << 4;
    if (var_s0 >= 8)
    {
      if (!mode)
      {
        var_a3 = 0;
        var_a1_2 = (char *) (var_s5 * 2);
        var_a1_2 += (s32) arg1;
        temp_a2_2 = (0x80 - var_s5) * 2;
        var_a0_2 = 0;
        if (temp_a2_2 > 0)
        {
          do
          {
            var_a0_2 += 1;
            var_a3 += *((u8 *) var_a1_2);
            var_a1_2 += 1;
          }
          while (var_a0_2 < temp_a2_2);
        }
        if ((var_a3 & 0xFF) != (*((u8 *) (((char *) arg1) + 1))))
        {
          var_s0_2 = 0;
          var_s1 = arg1;
          do
          {
            temp_a3 = var_s1;
            var_s1 += 0x20;
            __osContRamRead(*((s32 *) (inline_fn(arg0) + 4)), *((s32 *) (((char *) arg0) + 8)), (((*((s32 *) (((char *) arg0) + 0x58))) + (idx * 8)) + var_s0_2) & 0xFFFF, temp_a3);
            var_s0_2 += 1;
          }
          while (var_s0_2 < 8);
          var_a2 = (var_s5 * 2) + arg1;
          var_a0 = 0;
          temp_v1 = var_s5;
          temp_v1 = 0x80 - temp_v1;
          temp_v1 = temp_v1 * 2;
          var_a1_3 = 0;
          if (temp_v1 > 0)
          {
            do
            {
              var_a0 += 1;
              var_a1_3 += *((u8 *) var_a2);
              var_a2 += 1;
            }
            while (var_a0 < temp_v1);
          }
          if ((var_a1_3 & 0xFF) != (*((u8 *) (((char *) arg1) + 1))))
          {
            return 3;
          }
          var_s0_3 = 0;
          var_s1_2 = arg1;
          do
          {
            var_s1_2 += 0x20;
            temp_a3_2 = var_s1_2;
            func_80096A10(*((s32 *) (((char *) arg0) + 4)), *((s32 *) (((char *) arg0) + 8)), (((*((s32 *) (((char *) arg0) + 0x54))) + (idx * 8)) + var_s0_3) & 0xFFFF, temp_a3_2, 0);
            var_s0_3 += 1;
          }
          while (var_s0_3 < 8);
          goto block_31;
        }
        goto block_31;
      }
      block_31:
      D_800A3B34 = idx;

      func_80091600(arg1, D_800C02AE + 0x7062, 0x100);
      var_v0 = 0;
      D_800A3B30 = *((s32 *) (((char *) arg0) + 8));
      return var_v0;
    }
    goto loop_13;
  }
  return var_v1;
}
