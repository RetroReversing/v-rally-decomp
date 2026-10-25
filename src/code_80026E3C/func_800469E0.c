#include "common.h"

extern s32 D_800A0264[];
s32 func_8002E778(s32 *, s32 *);

typedef struct {
  s32 x;
  s32 y;
  s32 z;
} S_vec3;

void func_800469E0(s32 **arg0, s32 *arg1)
{
  S_vec3 sp10;
  S_vec3 sp20;
  u32 sp30;
  S_vec3 *temp_v0;
  s32 *temp_s0;

  if (*(s32 *)(*(s32 **)((u8 *)arg1 + 0x48)) < 4)
  {
    temp_v0 = *(S_vec3 **)((u8 *)arg1 + 0x58);
    temp_s0 = *arg0;
    sp10 = *(S_vec3 *)((u8 *)temp_v0 + 0xC);
    sp20.x = sp10.x - temp_s0[0];
    sp20.y = 0;
    sp20.z = sp10.z - temp_s0[2];
    func_8002E778((s32 *)&sp20, (s32 *)&sp20);
    sp30 = sp20.x + sp20.z;
    if (sp30 < (u32)temp_s0[3])
    {
      ((void (*)(s32 *, s32, s32 *, u32 *))D_800A0264[*(u16 *)((u8 *)temp_s0 + 0x14)])((s32 *)((u8 *)temp_s0 + 0x1C), *(u16 *)((u8 *)temp_s0 + 0x16), arg1, &sp30);
    }
  }
}
