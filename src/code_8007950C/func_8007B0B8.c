#include "common.h"

extern int D_800C35A0;
s32 func_8007A6D0();
s32 func_8008A140();
extern void *D_800A1468;
extern char D_800C02AE[];
static inline void *inline_fn(char *arg0, int arg1)
{
  return *((void **) (arg0 + arg1));
}

s32 func_8007B0B8(void)
{
  u16 temp_v1;
  void *temp_a0;
  void *temp_a1;
  *((s8 *) (((char *) D_800A1468) + 0x245)) = 0;
  func_8008A140(inline_fn(D_800C02AE, 0x325A));
  temp_a1 = D_800A1468;
  temp_a0 = D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + (*((s8 *) (((char *) temp_a1) + 0x228))))) + 0x32))) * 0x28);
  temp_v1 = *((u16 *) (((char *) temp_a0) + 0x4E));
  if ((*((u8 *) (((char *) temp_a1) + 0x237))) != temp_v1)
  {
    *((u8 *) (((char *) temp_a1) + 0x237)) = (u8) temp_v1;
    func_8007A6D0(temp_a0, temp_a1);
    *((s8 *) (((char *) D_800A1468) + 0x2BD)) = 1;
  }
  return (*((u8 *) (((char *) (((*((s16 *) (((char *) inline_fn(D_800C02AE, 0x325A)) + 2))) * 0x14) + (*((s32 *) (((char *) inline_fn(D_800C02AE, 0x325A)) + 0x10))))) + 0xD))) + (*((u8 *) (((char *) D_800A1468) + 0x238)));
}
