#include "common.h"

s32 alLink();
s32 alUnlink();
extern u32 D_800A1BA4;
extern u32 D_800A1BA8;
extern char D_800A73E0[];
void func_80087114(void)
{
  char pad[8];
  void *temp_s1;
  void *var_s0;
  void *temp_a1;
  u32 var_v1;

  var_v1 = 0;
  if (D_800A1BA8 != 0)
  {
    do
    {
      var_v1 += 1;
    } while (var_v1 < D_800A1BA8);
  }
  var_s0 = *((void **) (D_800A73E0 + 0x4564));
  if (var_s0 != NULL)
  {
    do
    {
      temp_s1 = *((void **) var_s0);
      if (((*((s32 *) ((char *) var_s0 + 0xC))) + 1) < D_800A1BA4)
      {
        if (*((void **) (D_800A73E0 + 0x4564)) == var_s0)
        {
          *((void **) (D_800A73E0 + 0x4564)) = temp_s1;
        }
        alUnlink(var_s0);
        temp_a1 = *((void **) (D_800A73E0 + 0x4564 + 4));
        if (temp_a1 != NULL)
        {
          alLink(var_s0, temp_a1);
          var_s0 = temp_s1;
        }
        else
        {
          *((void **) (D_800A73E0 + 0x4564 + 4)) = var_s0;
          *((void **) var_s0) = NULL;
          *((s32 *) ((char *) var_s0 + 4)) = 0;
          var_s0 = temp_s1;
        }
      }
      else
      {
        var_s0 = temp_s1;
      }
    } while (var_s0 != NULL);
  }
  D_800A1BA8 = 0;
  D_800A1BA4 += 1;
}
