#include "common.h"

extern char D_800AE850[];
extern char D_800C02AE[];
void *func_8004C4D0(s32, s32);

void func_8001D1A4(s32 arg0)
{
  s32 var_v1;
  void *temp_v0;
  void *temp_v1;

  var_v1 = 1;
  do {
    var_v1++;
  } while ((u8) var_v1 < 0xD);
  var_v1++;
  temp_v1 = *((void **) (D_800C02AE + 0x5A7A));
  temp_v0 = func_8004C4D0(*((s32 *) ((char *) temp_v1 + 0x10)), arg0);
  var_v1 = *((s32 *) ((char *) temp_v0 + 0xC));
  *((void **) (D_800AE850 + 0x18)) = temp_v0;
  *((s32 *) ((char *) temp_v0 + 0xC)) = var_v1 | 4;
}
