#include "common.h"

extern char *D_800C35A0;
void func_8003BADC(void *arg0)
{
  u16 mode;
  char *v;

  mode = *(u16 *)(D_800C35A0 + 0xE);
  if ((mode >= 2 && (*(s32 *)(*(char **)((char *)arg0 + 0xA8) + 0x20) & 0x880000)) || mode == 1)
  {
    if (*(u16 *)((char *)arg0 + 0x78) == 0)
    {
      v = *(char **)(*(char **)((char *)arg0 + 0xA8) + 0x24);
      if (v != NULL)
      {
        *(u16 *)((char *)arg0 + 0x7A) += *(s32 *)(*(char **)(v + 0x78) + 0x60);
      }
      *(u16 *)((char *)arg0 + 0x78) = 1;
    }
    *(s32 *)((char *)arg0 + 0x80) &= ~4;
  }
  else
  {
    *(s32 *)((char *)arg0 + 0x80) |= 4;
  }
}
