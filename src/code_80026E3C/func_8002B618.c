#include "common.h"

extern u32 D_800A49D0;
u8 *func_8002B2DC();
u8 *func_8002B344();
u8 *func_8002B540();
s32 func_80081540();
u32 func_80081664();
s32 func_80081B28();
s32 func_80081B78();
s32 func_8002B618(u8 *arg0, u8 *arg1)
{
  u32 sp10;
  u32 sp14;
  u8 *start;
  u32 sp18;
  u8 *end;
  u8 *p;
  s32 c;
  func_80081540(&D_800A49D0);
  start = (u8 *) func_80081664(1, arg0);
  func_80081B78(arg0, &sp10, &sp14);
  end = start + sp10;
  {
    for (p = start; p < end; p++)
    {
      c = *p;
      if (((u32) (c - 0x61)) < 0x1A)
      {
        *p = c & (~0x20);
      }
    }

  }
  p = func_8002B2DC(start, end, (u8 *) (&sp18));
  if ((*((u8 *) (&sp18))) != 0)
  {
    p = func_8002B540(p, end);
  }
  if (arg1 != NULL)
  {
    p = func_8002B344(p, (0, end), arg1, (u8 *) (&sp18));
    if ((*((u8 *) (&sp18))) == 0)
    {
      func_80081B28(start);
      return 0;
    }
    func_8002B540(p, end);
  }
  func_80081B28(start);
  return 1;
}
