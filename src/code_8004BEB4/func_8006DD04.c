#include "common.h"

s32 func_800535F4(void *);
typedef struct
{
  s32 w[4];
} S_func_8006DD04_blk;

void func_8006DD04(void *arg0)
{
  S_func_8006DD04_blk sp10[3];
  u8 i;
  u32 off;
  S_func_8006DD04_blk *src;
  S_func_8006DD04_blk *dst;

  i = 0;
  do {
    off = i << 4;
    dst = (S_func_8006DD04_blk *)(off + (u32)sp10);
    src = (S_func_8006DD04_blk *)(off + (u32)arg0);
    *dst = *src;
    src->w[0] = -1;
    i++;
  } while (i < 3);
  i = 0;
  do {
    *((S_func_8006DD04_blk *)((char *)arg0 + 0x30)) = sp10[i];
    func_800535F4(arg0);
    i++;
  } while (i < 3);
}
