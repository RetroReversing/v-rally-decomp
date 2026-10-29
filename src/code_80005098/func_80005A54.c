#include "snapshot29_0433f7af8f6d.h"

extern signed char D_800AE865;
s32 func_8007F798();
extern volatile unsigned char D_8009B5B0;
extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_80005A54(void *arg0, void *arg1)
{
  void **new_var;
  s32 var_v1;
  char *new_var3;
  int new_var2;
  var_v1 = 0;
  if (D_8009B5B0 == 0)
  {
    new_var3 = D_800C02AE;
    D_800AE865 = 1;
    *((void **) (new_var3 + 0x1030A)) = arg0;
    *((void **) (D_800C02AE + 0x3252)) = arg1;
    *((s8 *) (((char *) arg0) + 0x14)) = 0;
    new_var = (void **) (D_800C02AE + 0x3252);
    *((s8 *) (((char *) (*new_var)) + 0x14)) = 0;
    D_8009B5B0 = 1;
    func_8007F798(6, 0, *((void **) (D_800C02AE + 0x1030A)));
    new_var2 = 1;
    var_v1 = new_var2;
  }
  return var_v1;
}
