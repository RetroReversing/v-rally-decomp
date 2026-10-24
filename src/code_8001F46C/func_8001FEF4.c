#include "common.h"

s32 func_800239CC();
extern char D_800C02AE[];
static inline char *inline_fn(int arg0)
{
  return D_800C02AE + arg0;
}

void func_8001FEF4(void *arg0)
{
  s32 temp_v1;
  u8 var_a1;
  int new_var;
  var_a1 = 0;
  new_var = 0xFF;
  if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) - -0x1E))) == 0)
  {
    if ((*((u16 *) (((char *) (*((void **) inline_fn(0x32F2)))) + 0x1A))) == 1)
    {
      temp_v1 = *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x48)))) + 0x2C));
      if (temp_v1 >= 0)
      {
        if (temp_v1 >= 2)
        {
          var_a1 = temp_v1 < 4;
        }
      }
    }
    else
    {
      goto block_5;
    }
  }
  else
  {
    block_5:
    var_a1 = *((u8 *) (((char *) (*((void **) (((char *) arg0) + 0x48)))) + 0x2F));

  }
  func_800239CC(arg0, (*((void **) (D_800C02AE + 0x32F2))) + (((*((u8 *) (((char *) ((*((void **) (D_800C02AE + 0x32F2))) + (var_a1 & new_var))) + 0x32))) * 0x28) + 0x44));
}
