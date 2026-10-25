#include "common.h"

extern f32 D_8009F584;
extern f32 D_8009F590;

void func_800101F8(s32 arg0)
{
  f32 *temp_v0;

  if (arg0 & 0x800)
  {
    temp_v0 = &D_8009F584;
    *temp_v0 = *temp_v0 + 2.0f;
  }
  if (arg0 & 0x400)
  {
    temp_v0 = &D_8009F584;
    *temp_v0 = *temp_v0 - 2.0f;
  }
  if (arg0 & 0x200)
  {
    temp_v0 = &D_8009F590;
    *temp_v0 = *temp_v0 + 1.0f;
  }
  if (arg0 & 0x100)
  {
    temp_v0 = &D_8009F590;
    *temp_v0 = *temp_v0 - 1.0f;
  }
}
