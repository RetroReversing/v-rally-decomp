#include "snapshot29_0433f7af8f6d.h"

s32 func_8001B730();
s32 func_80097E30();
s32 func_80098290();
void *func_80015E94(void *arg0, void *arg1)
{
  s32 sp10[3];
  s32 off;
  s32 i;
  s32 n;
  s32 test;
  s32 key;
  s32 *p;
  void *entry;
  s32 count;
  func_8001B730(arg1);
  func_80097E30(sp10, 0, 12);
  func_80098290(sp10, arg1);
  i = 0;
  count = *((u16 *) (((u8 *) arg0) + 32));
  p = &sp10[1];
  if (count >= i)
  {
    key = sp10[0];
    n = count;
    off = 60;
    do
    {
      entry = (char *) ((u8 *) arg0);
      entry += off;
      i++;
      if ((*((s32 *) entry)) == key)
      {
        if ((*((s32 *) (((u8 *) entry) + 4))) == (*p))
        {
          return entry;
        }
      }
      test = n < i;
      off += 56;
    }
    while (!test);
  }
  return NULL;
}
