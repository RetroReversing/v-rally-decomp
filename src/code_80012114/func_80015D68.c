#include "common.h"

s32 func_80016B3C();
extern u8 D_8009BBBC;
extern void *D_8009BFD8[];
extern char D_800C02AE[];
void func_80015D68(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  u32 var_s0;
  char *var_s1;
  s32 new_var;
  char *temp_s2;
  s32 var_s3;
  s32 temp_v0;
  char *temp_v1;
  s32 pad[2];
  do
  {
    new_var = *((s32 *) (arg0 + 0x44));
    temp_v0 = new_var;
    var_s3 = arg4;
    temp_v1 = *((char * volatile *) (arg0 + 0x44));
    temp_v0 = *((s32 *) (temp_v0 + 0x20));
    var_s0 = 0;
    temp_s2 = arg0 + 0x3C;
    *((s32 *) (D_800C02AE + 0x7022)) = arg3;
    var_s1 = temp_v1 + 0x24;
    if (temp_v0 != 0)
    {
      do
      {
        ((void (*)(void *, s32, s32, s32)) (*((void **) (((u8 *) D_8009BFD8) + ((*((u16 *) (var_s1 + 6))) << 2)))))(temp_s2, arg1, arg2, var_s3);
        var_s0 += 1;
        var_s1 += 8;
      }
      while (var_s0 < (*((u32 *) ((*((char **) (temp_s2 + 8))) + 0x20))));
    }
  }
  while (0);
  var_s0 = D_8009BBBC == 0;
  if (var_s0)
  {
    func_80016B3C(*((s32 *) ((*((char **) (D_800C02AE + 0x7CD6))) + 0x24)), arg3, var_s3);
  }
}
