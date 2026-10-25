#include "common.h"

s32 func_8008E118();
s32 func_80098290();
s32 func_80098370();
extern u8 D_800A14A4;
extern char D_800A5220[];
extern char D_800AE850[];
void func_800576D4(void *arg0)
{
  s32 *new_var;
  s32 var_v1;
  char *temp_s0;
  s32 temp_v0;
  char *new_var2;
  s32 idx;
  var_v1 = 1;
  while (((u32) (var_v1 & 0xFF)) <= (6U - 1))
  {
    var_v1 += 1;
  }

  var_v1 += 1;
  idx = D_800A14A4 * 0x1C;
  new_var2 = ((char *) arg0) + 0x128;
  if (D_800A14A4)
  {
  }
  *((s8 *) ((D_800AE850 + 0x1300) + idx)) = *((s32 *) (((char *) arg0) + 0x90));
  new_var = (s32 *) new_var2;
  idx = D_800A14A4 * 0x1C;
  *((s8 *) ((D_800AE850 + 0x1301) + idx)) = *((s32 *) (((char *) arg0) + 0xDC));
  temp_s0 = ((char *) arg0) + 0x1C8;
  idx = D_800A14A4 * 0x1C;
  var_v1 += 1;
  *((s8 *) ((D_800AE850 + 0x1302) + idx)) = *new_var;
  temp_v0 = D_800A14A4 * 0x1C;
  *((f32 *) ((D_800AE850 + 0x1304) + temp_v0)) = (f32) (*((s32 *) (((char *) arg0) + 0x174)));
  *((f32 *) ((D_800AE850 + 0x1308) + temp_v0)) = (f32) (*((s32 *) (((char *) arg0) + 0x1C0)));
  func_80098370(temp_s0, D_800A5220, func_8008E118(temp_s0, arg0));
  func_80098290((D_800A14A4 * 0x1C) + (D_800AE850 + 0x130C), temp_s0);
  D_800A14A4 += 1;
}
