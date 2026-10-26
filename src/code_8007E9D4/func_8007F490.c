#include "common.h"

extern char D_800C02AE[];
s32 osRecvMesg();
void func_8007F490(void *arg0)
{
  s32 sp10;
  void (*fn)();
 do { } while (0);
  osRecvMesg(((char *) arg0) + 0x14, &sp10, 1);
  fn = *((void (**)()) ((D_800C02AE + 0x7D8A) + ((*((u16 *) (((char *) arg0) + 0xE))) * 4)));
  fn();
  while (1)
  {
  }

}
