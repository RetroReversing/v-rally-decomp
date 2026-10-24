#include "common.h"

extern int D_800C35A0;
s32 func_800239CC();
extern void *D_800A0384;
extern char D_800AE850[];
extern char D_800C02AE[];
void func_80049450(void)
{
  s32 temp_a0;
  void *var_s0;
  var_s0 = *(*((void ***) (D_800AE850 + 0x73F0)));
  if (var_s0 != NULL)
  {
    do
    {
      ;
      if ((*(*((s32 **) (((char *) var_s0) + 0x48)))) == (*((u8 *) (((char *) D_800A0384) + 0x382))))
      {
        temp_a0 = ((*((u8 *) (((char *) (D_800C35A0 + (*(*((s32 **) (((char *) var_s0) + 0x48)))))) + 0x32))) * 0x28) + 0x44;
        func_800239CC(var_s0, D_800C35A0 + temp_a0);
      }
      var_s0 = *((void **) (((char *) var_s0) + 4));
    }
    while (var_s0 != NULL);
  }
}
