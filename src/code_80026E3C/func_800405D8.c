#include "common.h"

s32 func_80005500();
s32 func_8000E8B8();
void *func_80022318();
s32 func_8003FD0C();
void *func_8004240C();
extern s32 D_8009B5A4;
extern s32 D_800A1468;
extern char D_800A4C18[];
extern void *D_800C35A0;
extern void *D_800C7F84;
static inline char *inline_fn()
{
  return (char *) D_800C35A0;
}

void func_800405D8(void)
{
  void *temp_v0;
  void *temp_v0_2;
  char *new_var;
  temp_v0 = func_8004240C(((*((u16 *) (inline_fn() + 0xE))) * 2) | 1);
  { s32 arg = *((s32 *) (((char *) temp_v0) + 0x178));
  D_800C7F84 = temp_v0;
  func_8000E8B8(arg);
  }
  func_80005500(*((s32 *) (((char *) temp_v0) + 0x178)), D_8009B5A4);
  if (D_800A1468 == 0)
  {
    func_8003FD0C(0);
  }
  if ((*((u16 *) (new_var = ((char *) D_800C35A0) + 0x1E))) != 7)
  {
    D_800C7F84 = temp_v0;
    temp_v0_2 = func_80022318(((char *) temp_v0) + 0x28, D_800A4C18);
    if (temp_v0_2 != NULL)
    {
      (*((s32 (**)(s32)) (((char *) temp_v0_2) + 0x14)))(*((s32 *) (((char *) temp_v0_2) + 0x10)));
    }
  }
}
