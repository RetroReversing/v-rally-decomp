#include "common.h"

extern char D_800C02AE[];
s32 func_8008ACA0(s32 *a, s32 *b, s32 c);
s32 func_8008D090(s32 *a, s32 *b, s32 c);
s32 func_8008D4A0(char *a, s32 *b, s32 c);
typedef struct
{
  s32 w[6];
} Pkt6;
typedef struct
{
  s32 pkt[9];
  s32 sp34[6];
  s32 sp4C;
} Locals80;
void func_80081040(s32 arg0, s32 arg1, u32 arg2, Pkt6 arg3)
{
  Locals80 l;
  u32 len;

  while (arg2 != 0)
  {
    len = arg2;
    if (arg2 >= 0x4001U)
    {
      len = 0x4000;
    }
    l.pkt[0] = arg0;
    l.pkt[1] = arg1;
    l.pkt[2] = len;
    *((Pkt6 *) (l.pkt + 3)) = arg3;
    func_8008ACA0(l.sp34, &l.sp4C, 1);
    func_8008D4A0(D_800C02AE + 0x768A, l.pkt, 1);
    func_8008D090(l.sp34, &l.sp4C, 1);
    arg0 += len;
    arg2 -= len;
    arg1 += len;
  }
}
