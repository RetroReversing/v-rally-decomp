#include "common.h"

extern char D_800AE850[];
extern char D_800C02AE[];
void func_80048CB8(void *arg0)
{
  u8 count;
  char *cfg;
  char *new_var;
  char *node;
  s32 temp;
  u32 i;
  cfg = *((char **) (D_800C02AE + 0x32F2));
  count = *((u8 *) (cfg + 0xF));
  node = *((char **) (*((char **) (D_800AE850 + 0x6D94))));
  i = 1;
  if (count != 0)
  {
    do
    {
      *((s32 *) (node + 0x14)) = 0x12C;
      temp = -(*((s32 *) (((char *) arg0) + 0xDC)));
      *((s32 *) (node + 0x18)) = temp;
      new_var = cfg;
      if ((*((u16 *) (new_var + 0xE))) == 2)
      {
        if ((*((u16 *) (new_var + 0x12))) & 1)
        {
          *((s32 *) (node + 0x18)) = temp + 0x28;
        }
      }
      if (!((*((u16 *) (new_var + 0xE))) < 3))
      {
        *((s32 *) (node + 0x18)) += 0x64;
      }
      node = *((char **) (node + 4));
      i++;
    }
    while (count >= i);
  }
}
