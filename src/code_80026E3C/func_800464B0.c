#include "common.h"

extern unsigned char D_800ADFE1;
extern unsigned char D_800ADFE0;
extern int D_800ADFE8;
extern char D_800A73E0[];
extern char D_800C02AE[];
s32 func_800464B0(void *arg0)
{
  s16 temp_v1;
  s16 *new_var2;
  s32 var_a2;
  char *new_var;
  new_var2 = &(*((s16 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) arg0) + 0x8C)))) + 0x28)))) + 8)));
  var_a2 = 1;
  if ((((D_800ADFE1 != 0) && ((*(*((s32 **) (((char *) arg0) + 0x70)))) == (D_800ADFE0 - 1))) && (((temp_v1 = *new_var2, (((u32) temp_v1) < ((u32) (D_800ADFE8 - 1))) == 0)) || (temp_v1 <= 0))) && (!((*((s32 *) (((char *) arg0) + 0x14))) & 0x100)))
  {
    var_a2 = (*((u16 *) (((char *) (*((void **) (new_var = D_800C02AE + 0x32F2)))) + 0x1E))) == 0;
  }
  return var_a2;
}
