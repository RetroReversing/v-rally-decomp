#include "common.h"

void func_8003A73C(void *arg0)
{
  char *new_var;
  s32 var_v0;
  int new_var2;
  void *temp_v1;
  temp_v1 = *((void **) (((char *) arg0) + 0));
  *((u8 *) (((char *) arg0) + 0x90)) = (u8) (*((u8 *) (((char *) temp_v1) + 0x90)));
  *((u8 *) (((char *) arg0) + 0x91)) = (u8) (*((u8 *) (((char *) temp_v1) + 0x91)));
  *((u8 *) (((char *) arg0) + 0x92)) = (u8) (*((u8 *) (((char *) temp_v1) + 0x92)));
  new_var2 = ~4;
  *((u8 *) (((char *) arg0) + 0x93)) = (u8) (*((u8 *) (((char *) temp_v1) + 0x93)));
  new_var = (char *) temp_v1;
  *((u16 *) (((char *) arg0) + 0xE)) = (u16) (*((u16 *) (((char *) temp_v1) + 0xE)));
  if ((*((s32 *) (new_var + 0x80))) & 4)
  {
    var_v0 = (*((s32 *) (((char *) arg0) + 0x80))) | 4;
  }
  else
  {
    var_v0 = (*((s32 *) (((char *) arg0) + 0x80))) & new_var2;
  }
  *((s32 *) (((char *) arg0) + 0x80)) = var_v0;
}
