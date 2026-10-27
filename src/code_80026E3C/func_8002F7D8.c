#include "common.h"

s32 func_800056FC();
s32 func_8002EE00();
s32 func_8002F270();
void *func_8004240C();
extern u16 D_800B0558;
extern u32 D_800AFA8C;
extern u8 D_800B6818;
extern void *D_800B5C40;
extern void *D_800C35A0;
extern void *D_800C6ED0;
extern void *D_800C7F84;
void func_8002F7D8(void)
{
  char *new_var;
  u8 s5;
  s32 s3;
  s32 s4;
  s32 s2;
 s32 arg;
  s32 v0;
  void *s0;
  void *s1;
  void *tmp;
  char *p;
  s32 v1;
  if ((*((u16 *) (((char *) D_800C35A0) + 0xE))) == 2)
  {
    return;
  }
  v1 = 0x14;
  if (D_800B0558 != 0)
  {
    do
    {
      v1 = 0xA;
    }
    while (0);
  }
  v0 = D_800AFA8C;
  D_800AFA8C = 0;
  v0 = v1 < ((u32) v0);
  D_800B0558 = v0;
  s5 = *((u8 *) (((char *) D_800C35A0) + 0xF));
  s3 = 1;
  if (s5 == 0)
  {
    return;
  }
  s4 = v0 & 0xFF;
  do
  {
    tmp = func_8004240C((s3 & 0xFF) << 1);
    arg = *((s32 *) (((char *) tmp) + 0x178));
    D_800C7F84 = tmp;
    s2 = func_800056FC(arg);
    p = D_800C35A0;
    if ((((*((u16 *) (p + 0x1E))) == 0) && ((*((u16 *) (p + 0x1A))) != 0)) || (((*((u16 *) (p + 0x1E))) == 5) && (D_800B6818 == 0)))
    {
      s0 = *((void **) D_800B5C40);
      v0 = *((s32 *) (((char *) D_800C7F84) + 0x24));
      tmp = (void *) v0;
      while (s0 != tmp)
      {
        s0 = *((void **) (((char *) s0) + 4));
      }

      s1 = *(*((void ***) (((char *) s0) + 0x38)));
      func_8002EE00(s0, *((s32 *) (((char *) s1) + 0x10)), *((u16 *) (((char *) s1) + 0x16)), s2, s1, s4);
      func_8002F270(s0, *((s32 *) (((char *) s1) + 0)), *((u16 *) (((char *) s1) + 0x14)), *(*((s32 **) (((char *) D_800C6ED0) + 4))), s2);
    }
    else
    {
      s0 = *((void **) D_800B5C40);
      while (s0 != NULL)
      {
        new_var = ((char *) s0) + 0x38;
        s1 = *(*((void ***) new_var));
        func_8002EE00(s0, *((s32 *) (((char *) s1) + 0x10)), *((u16 *) (((char *) s1) + 0x16)), s2, s1, s4);
        func_8002F270(s0, *((s32 *) (((char *) s1) + 0)), *((u16 *) (((char *) s1) + 0x14)), *(*((s32 **) (((char *) D_800C6ED0) + 4))), s2);
        s0 = *((void **) (((char *) s0) + 4));
      }

    }
    s3 += 1;
  }
  while (((u8) s3) <= s5);
}
