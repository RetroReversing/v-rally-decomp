#include "snapshot29_0433f7af8f6d.h"

extern unsigned char D_800C792F;
void func_80011178(void *);
extern s32 D_8009BA30;
extern s32 D_8009D538;
extern char D_800C02AE[];
void func_80012184(void *arg0)
{
  s32 var_a1;
  s16 temp_v0;
  int new_var;
  f32 one;
  u8 *obj;
  u8 *sub;
  s32 arg1;
  obj = *((u8 **) (0x7CD6 + D_800C02AE));
  one = 1.0f;
  arg1 = D_8009D538;
  D_8009BA30 = 1;
  *((f32 *) (obj + 0x114)) = one;
  if ((arg1 & 2) == 0)
  {
    var_a1 = *((s32 *) (((u8 *) arg0) + 0x60));
    *((s32 *) (((u8 *) arg0) + 0x30)) = 6;
    if (var_a1 < 0x800)
    {
      *((s32 *) (((u8 *) arg0) + 0x60)) = var_a1 + (D_800C792F * 12);
    }
    if ((*((s32 *) (((u8 *) arg0) + 0x60))) >= 0x321)
    {
      new_var = 0x6A;
      temp_v0 = *((s16 *) (new_var + (int)arg0));
      if (temp_v0 >= 0xA61)
      {
        *((s16 *) (((u8 *) arg0) + new_var)) = temp_v0 - (D_800C792F * 30);
      }
      else
      {
        sub = *((u8 **) (((u8 *) arg0) + 0x6C));
        D_8009BA30 = 0;
        *((s32 *) (sub + 8)) = 1;
      }
    }
  }
  func_80011178(arg0);
}
