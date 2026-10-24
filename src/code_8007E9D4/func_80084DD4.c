#include "common.h"

extern unsigned char D_800AFA40;
extern s32 D_800A1B70;
extern char D_800AE850[];
s32 func_80084DD4(s32 arg0)
{
  int new_var;
  u8 *new_var2;
  if (D_800AFA40 != 0)
  {
    new_var2 = (u8 *) (((char *) (D_800A1B70 + ((arg0 & 0xFF) * 4))) + 0xF);
    return ((*new_var2) & (new_var = 8)) == 0;
  }
  if (D_800AFA40 || D_800A1B70)
  {
    return 0;
  }
  else
  {
    return 0;
  }
  if (1)
  {
    do
    {
    }
    while (0);
  }
}
