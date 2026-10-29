#include "snapshot29_0433f7af8f6d.h"

s32 func_80005500();
s32 func_800056FC();
s32 func_8000E8B8();
s32 func_80015D68();
s32 func_80015F3C();
void *func_8004240C();
extern char D_800A73E0[];
extern char D_800C02AE[];
void func_8001B97C(void **arg0)
{
  char *s0;
  char *s1;
  char *s6;
  char *tmp;
  s32 s2;
  s32 s3;
  s32 s5;
  char *s4;
  s32 tmp2;
  s32 tmp3;
  s1 = *arg0;
  s6 = *((char **) (D_800C02AE + 0x32F2));
  s3 = 0;
  if (s1 != NULL)
  {
    s2 = -1;
    do
    {
 do { s2 += 2; s0 = func_8004240C(s2); tmp3 = *((s32 *) (s0 + 0x178)); *((char **) (D_800C02AE + 0x7CD6)) = s0; } while (0);
      func_8000E8B8(tmp3);
      s3 += 2;
      func_80005500(*((s32 *) (s0 + 0x178)), (*((s32 *) (s0 + 0x178))) + 8);
      s4 = s0 + 0x38;
      s5 = func_800056FC(*((s32 *) (s0 + 0x178)));
      do
      {
        u16 mode;
        volatile u16 *mode_ptr;
        mode_ptr = (volatile u16 *) (s6 + 0x1E);
        mode = *mode_ptr;
        tmp = *((char **) (s0 + 0x24));
        if (((u32) (mode - 7)) >= 2U)
        {
          *((s16 *) (D_800A73E0 + 0x6BE0)) = (*((s32 *) ((*((char **) (tmp + 0x5C))) + 0x58))) / 48;
        }
        else
        {
          *((s16 *) (D_800A73E0 + 0x6BE0)) = 0;
        }
        func_80015F3C(func_800056FC(*((s32 *) (s0 + 0x178))));
        s0 = func_8004240C(s3);
        func_8000E8B8(*((s32 *) (s0 + 0x178)));
        func_80005500(*((s32 *) (s0 + 0x178)), (*((s32 *) (s0 + 0x178))) + 8);
        tmp2 = func_800056FC(*((s32 *) (s0 + 0x178)));
        func_80015F3C(func_800056FC(*((s32 *) (s0 + 0x178))));
        s0 = (char *) tmp2;
        if ((*((u16 *) (s1 + 0x1A))) != 2)
        {
          func_80015D68(D_800A73E0 + 0x6BD0, s1, s5, s0, s4);
        }
      }
      while (0);
      s1 = *((char **) (s1 + 4));
    }
    while (s1 != NULL);
  }
}
