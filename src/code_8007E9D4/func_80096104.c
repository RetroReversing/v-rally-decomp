#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define sp18 banks[0]
#define sp1A banks[1]
#define sp1C banks[2]
#define sp1E banks[3]
static inline static static static void checksum(u16 *p, u16 *sum, u16 *inv)
{
  u16 *end = p + 14;
  *inv = 0;
  *sum = 0;
  do
  {
    u16 v = *(p++);
    *sum += v;
    *inv += ~v;
  }
  while (p < end);
}

s32 __osPfsSelectBank(void *, s32);
s32 func_80096830(s32, s32, u16, u16 *);
s32 func_80096A10(s32, s32, u16, u16 *, s32);
s32 func_80096104(void *arg0, u16 *arg1)
{
  u16 banks[4];
  u16 sp20;
  s32 temp_v0;
  u16 sp22;
  s32 var_s0_2;
  s32 var_s3;
  s32 var_v0;
  u16 *var_a1;
  u16 *var_s0;
  int new_var3;
  int new_var;
  u16 *var_s1;
  u16 temp_a0;
  u16 temp_a2;
  u16 temp_v0_2;
  int new_var2;
  if (((*((u8 *) (((s8 *) arg0) + 0x65))) == 0) || ((var_v0 = __osPfsSelectBank(arg0, 0), var_v0 == 0)))
  {
    var_s3 = 1;
    var_s0 = &sp1A;
    sp18 = 1;
    sp1A = 3;
    new_var2 = 6;
    sp1C = 4;
    sp1E = new_var2;
    loop_3:
    var_v0 = func_80096830(*((s32 *) (((s8 *) arg0) + 4)), *((s32 *) (((s8 *) arg0) + 8)), *var_s0, arg1);


    var_a1 = arg1;
    if (var_v0 == 0)
    {
      do
      {
        checksum(arg1, &sp20, &sp22);
        temp_a2 = sp20;
      }
      while (0);
      temp_a0 = sp22;
      new_var3 = 10;
      if (((*((u16 *) (((s8 *) arg1) + 0x1c))) != (temp_a2 & 0xffff)) || ((*((u16 *) (((s8 *) arg1) + 0x1e))) != (temp_a0 & 0xffff)))
      {
        do
        {
          var_s3++;
        }
        while (0);
        var_s0++;
        if (var_s3 >= 4)
        {
          goto block_10;
        }
        goto loop_3;
      }
      block_10:
      var_s0_2 = 0;
      if (var_s3 == 4)
      {
        return new_var3;
      }

      new_var = 1;
      var_s1 = &sp18;
      for (var_s0_2 = 0; var_s0_2 < 4; var_s0_2++, var_s1++)
      {
        if (var_s0_2 != var_s3)
        {
          temp_v0 = func_80096A10(*((s32 *) (((s8 *) arg0) + 4)), *((s32 *) (((s8 *) arg0) + 8)), *var_s1, arg1, new_var);
          if (temp_v0 != 0)
          {
            return temp_v0;
          }
        }
      }

      return 0;
    }
    return var_v0;
  }
  return var_v0;
}


