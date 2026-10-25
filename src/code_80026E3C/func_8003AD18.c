#include "common.h"

s32 func_8003AB38(s32, void *);
extern u8 D_8009FE18[];

void func_8003AD18(void *arg0)
{
  s32 flags;
  s32 s1;
  s32 var_v0;
  void *temp_a0;

  flags = *(s32 *) ((u8 *) arg0 + 0x80) & ~4;
  *(s32 *) ((u8 *) arg0 + 0x80) = flags;
  temp_a0 = *(void **) (*(u8 **) ((u8 *) arg0 + 0xA8) + 0x24);
  if (temp_a0 != NULL) {
    s1 = *(s32 *) (*(u8 **) ((u8 *) temp_a0 + 0x70) + 0x28);
    if (*(s32 *) ((u8 *) temp_a0 + 0x14) & 0x100) {
      *(s32 *) ((u8 *) arg0 + 0x80) = flags | 4;
    }
    if ((*(u16 *) ((u8 *) arg0 + 0x78) == 0) && (s1 != -1)) {
      func_8003AB38(((s32 *) *(u8 **) ((u8 *) temp_a0 + 0x6C))[1], D_8009FE18);
    }
    if (s1 == -1) {
      func_8003AB38(0, D_8009FE18);
      var_v0 = 0xE;
    } else {
      var_v0 = D_8009FE18[*(u16 *) ((u8 *) arg0 + 0x78)] - 0x30;
    }
    *(s16 *) ((u8 *) arg0 + 0x7A) = var_v0;
  }
}
