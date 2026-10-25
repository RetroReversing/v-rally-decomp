#include "common.h"

s32 func_800237BC();
void func_80024AC0(void *arg0)
{
  s32 buf[3];
  u32 i;
  s32 off;

  buf[0] = 0;
  buf[1] = 0;
  buf[2] = 0;
  i = 0;
  off = 0x10;
  do {
    i++;
    func_800237BC(arg0, *(s32 *)((char *)arg0 + 0x80) + off, buf);
    off += 0x14;
  } while (i < 12);
}
