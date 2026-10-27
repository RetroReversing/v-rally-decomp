#include "common.h"

void func_8000BA38(void *a0, s16 a1, s16 a2, void *a3, s32 s4, s32 s5, s32 s6, s32 s7, s32 s8, s32 s9);
extern char D_800C02AE[];
void func_80036FD8(void *arg0, void *arg1)
{
  s16 temp_a2_3;
  s32 temp_a2;
  s32 temp_a2_2;
  void *temp_a3;
  unsigned long temp_a3_2;
  u16 new_var;
  void *temp_a3_3;
  void *temp_v0;
  char *new_var3;
  int new_var2;
  temp_a3 = *((void **) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x178));
  temp_a2 = ((s16) (*((u16 *) (((char *) temp_a3) + 0xC)))) / 2;
  new_var = *((u16 *) (((char *) arg0) + 0x12));
  temp_a3_2 = *((u16 *) (((char *) temp_a3) + 0xE));
  new_var3 = ((char *) arg1) + 0x10;
  *((u16 *) new_var3) = (u16) (temp_a2 + (((s32) (((s16) (temp_a2 - (*((u16 *) (((char *) arg0) + 0x10))))) * 0x19)) >> 5));
  temp_a2_2 = ((s32) (((s16) temp_a3_2) + (((u32) (temp_a3_2 << 0x10)) >> 0x1F))) >> 1;
  new_var2 = ((s16) (temp_a2_2 - new_var)) * 0x19;
  temp_a3_3 = *((void **) (((char *) arg1) + 0xC));
  temp_a2_3 = temp_a2_2;
  temp_a2_3 = temp_a2_3 + (((s32) new_var2) >> 5);
  *((s16 *) (((char *) arg1) + 0x12)) = temp_a2_3;
  temp_v0 = *((void **) (((char *) temp_a3_3) + 0x1C));
  func_8000BA38(*((void **) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x178)), (s16) ((*((u16 *) new_var3)) - (*((u16 *) (((char *) temp_v0) + 6)))), (s16) (temp_a2_3 - (*((u16 *) (((char *) temp_v0) + 8)))), temp_a3_3 + 0x10, 8, 0x64, (s32) (*((u8 *) (((char *) arg1) + 0x16))), (s32) (*((u8 *) (((char *) arg1) + 0x17))), (s32) (*((u8 *) (((char *) arg1) + 0x18))), 0xD2);
}
