#include "common.h"

s32 func_8008BD90();
s32 func_8008BDB0();
s32 func_80091920();
extern void *D_800A255C;
extern char D_800AE850[];
extern char D_800C02AE[];
void *func_80095CE0(void)
{
  char *new_var2;
  s32 new_var3;
  char *new_var;
  s32 temp_a0;
  void *temp_s0;
  void *temp_s1;
  void *temp_v1;
  temp_s1 = D_800C02AE + 0x5D5E;
  temp_v1 += 0;
  *((s8 *) (D_800C02AE + 0x5D5E)) = 2;
  *((s32 *) (D_800C02AE + 0x5D66)) = 0xA5000000;
  *((s8 *) (D_800C02AE + 0x5D5F)) = 3;
  *((s8 *) (D_800C02AE + 0x5D62)) = 6;
  *((s8 *) (D_800C02AE + 0x5D60)) = 6;
  *(D_800C02AE + 0x5D61) = 2;
  *((s8 *) (D_800C02AE + 0x5D63)) = 1;
  *((s32 *) (D_800C02AE + 0x5D6A)) = 0;
  func_80091920(temp_s1 + 0x10, 0x60);
  temp_s0 = temp_s1 - 4;
  new_var3 = func_8008BD90();
  temp_v1 = D_800A255C;
  temp_a0 = new_var3;
  D_800A255C = temp_s0;
  new_var = ((char *) temp_s1) + (-4);
  *((void **) (new_var2 = D_800AE850 + 0x72A8)) = temp_s0;
  *((void **) new_var) = temp_v1;
  func_8008BDB0(temp_a0);
  return temp_s0;
}
