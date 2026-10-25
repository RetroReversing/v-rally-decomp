#include "common.h"

s32 func_8008169C();
s32 func_800817A0(void *arg0, s32 arg1)
{
  s32 temp_s1;
  s32 temp_v0;
  s32 var_s2;
  s32 var_s3;
  void *var_s0;
  var_s2 = *((s32 *) (((char *) arg0) + 0x7C));
  var_s3 = 1;
  do
  {
    temp_s1 = (var_s3 + var_s2) / 2;
    var_s0 = (void *)((temp_s1 << 2) + (s32)arg0);
    if (func_8008169C(arg1, *((s32 *) (((char *) var_s0) + 0x80))) == 2)
    {
      return *((s32 *) (((char *) var_s0) + 0x80));
    }
    temp_v0 = func_8008169C(arg1, *((s32 *) (((char *) var_s0) + 0x80)));
    if (temp_v0 == 1)
    {
      if ((var_s2 - var_s3) == temp_v0)
      {
        var_s0 = arg0;
        if (func_8008169C(arg1, *((s32 *) (((char *) ((var_s2 * 4) + var_s0)) + 0x80))) == 2)
        {
          return *((s32 *) (((char *) ((var_s2 * 4) + var_s0)) + 0x80));
        }
      }
      else
      {
        var_s3 = temp_s1;
      }
    }
    else
    {
      var_s2 = temp_s1;
    }
  }
  while (var_s3 != var_s2);
  return 0;
}
