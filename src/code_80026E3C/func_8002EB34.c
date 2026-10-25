#include "common.h"

extern char D_800C02AE[];
void *func_8002EB34(void *arg0, u8 arg1, void *arg2)
{
  char *temp_t0;
  s32 temp_a0;
  u16 temp_v0;
  u16 temp_v0_2;
  char *temp_a3;
  char *temp_v1;
  u32 off;
  temp_t0 = arg0;
  if ((arg1 == 1) && ((*((u16 *) ((*((char **) (D_800C02AE + 0x7E6E))) + 4))) == 3))
  {
    arg1 = 5;
  }
  if ((arg1 == 0) && ((*((u16 *) ((*((char **) (D_800C02AE + 0x7E6E))) + 4))) == 3))
  {
    arg1 = 6;
  }
  temp_v0 = *((u16 *) (temp_t0 + 0x1A));
  temp_a3 = *((char **) (temp_t0 + 0x10));
  temp_a3 = temp_a3 + (temp_v0 * 0x24);
  temp_v0_2 = temp_v0 + 1;
  *((u16 *) (temp_t0 + 0x1A)) = temp_v0_2;
  if (temp_v0_2 != *((u16 *) (temp_t0 + 0x16)))
  {
  }
  else
  {
    *((u16 *) (temp_t0 + 0x1A)) = 0;
  }
  off = arg1 * 4;
  temp_v1 = (char *) (off + (s32) temp_t0);
  temp_a0 = *((s32 *) (temp_v1 + 0x1C));
  *((s16 *) (temp_a3 + 0)) = 1;
  *((s16 *) (temp_a3 + 0x12)) = 0;
  *((s32 *) (temp_a3 + 0x20)) = temp_a0;
  *((u16 *) (temp_a3 + 0xA)) = *((u16 *) (((char *) arg2) + 0));
  *((u16 *) (temp_a3 + 0xC)) = *((u16 *) (((char *) arg2) + 2));
  *((u16 *) (temp_a3 + 0xE)) = *((u16 *) (((char *) arg2) + 4));
  *((u16 *) (temp_a3 + 0x10)) = *((u16 *) ((*((char **) (temp_v1 + 0x38))) + 0));
  *((u16 *) (temp_a3 + 0x16)) = *((u16 *) ((*((char **) (temp_v1 + 0x38))) + 2));
  *((u8 *) (temp_a3 + 0x14)) = *((u8 *) ((*((char **) (temp_v1 + 0x38))) + 4));
  *((u8 *) (temp_a3 + 0x15)) = *((u8 *) ((*((char **) (temp_v1 + 0x38))) + 5));
  *((u8 *) (temp_a3 + 0x1E)) = *((u8 *) ((*((char **) (temp_v1 + 0x38))) + 6));
  *((u16 *) (temp_a3 + 0x18)) = *((u16 *) ((*((char **) (temp_v1 + 0x38))) + 8));
  *((u16 *) (temp_a3 + 0x1A)) = *((u16 *) ((*((char **) (temp_v1 + 0x38))) + 0xA));
  *((u16 *) (temp_a3 + 0x1C)) = *((u16 *) ((*((char **) (temp_v1 + 0x38))) + 0xC));
  *((u8 *) (temp_a3 + 0x1F)) = arg1;
  *((u16 *) (temp_a3 + 2)) = *((u16 *) (temp_a3 + 0x16));
  return temp_a3;
}
