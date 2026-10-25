#include "common.h"

extern char D_800AE850[];
void func_8003E134(char *arg0)
{
  char *var_v1;
  char *var_v0;
  char *var_a1;
  u32 var_a2;
  var_a1 = *((char **) (arg0 + 0xA8));
  var_v1 = *((char **) (var_a1 + 0x24));
  if (var_v1 != 0)
  {
    var_v0 = *((char **) (var_v1 + 0x6C));
    var_a2 = *((u32 *) (var_v0 + 8));
    if (var_a2 >= 2)
    {
      var_v0 = *((char **) (var_a1 + 0x178));
      var_a1 = (char *) (-1);
      var_v0 = (char *) ((*((u16 *) (var_v0 + 0xA))) + 6);
    }
    else
    {
      var_v0 = *((char **) (var_a1 + 0x178));
      var_a1 = (char *) 1;
      var_v0 = (char *) ((*((u16 *) (var_v0 + 0xA))) + 0x10);
    }
    *((s16 *) (arg0 + 0xE)) = (s16) ((s32) var_v0);
    var_v0 = *((char **) (D_800AE850 + 0x73F0));
    var_v1 = *((char **) var_v0);
    if (var_v1 != 0)
    {
      ;
      do
      {
        var_v0 = *((char **) ((*((char **) (var_v1 + 0x6C))) + 8));
        if (var_v0 == ((char *) (var_a2 + ((u32) var_a1))))
        {
          *((s16 *) (arg0 + 0x7A)) = (s16) ((s32) var_v0);
          return;
        }
        var_v1 = *((char **) (var_v1 + 4));
      }
      while (var_v1 != 0);
    }
  }
}
