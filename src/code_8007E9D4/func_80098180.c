#include "snapshot31_verified.h"

s32 func_80098180(const u8 *arg0, const u8 *arg1)
{
  s32 diff;
  u32 word0;
  u32 word1;
  if ((((u32) arg0) - ((u32) arg1)) & 3)
  {
    do
    {
      u32 d = *arg1;
      u32 c = *arg0;
      arg0++;
      arg1++;
      diff = (word0 = c) - d;
      if ((diff != 0) || (c == 0))
      {
        return diff;
      }
    }
    while (1);
  }
  while (((u32) arg0) & 3)
  {
    u32 d = *arg1;
    u32 c = *arg0;
    arg0++;
    arg1++;
    diff = (word0 = c) - d;
    if ((diff != 0) || (word0 == 0))
    {
      return diff;
    }
  }

  for (;;)
  {
    word0 = *((const u32 *) arg0);
    word1 = *((const u32 *) arg1);
    arg0 += 4;
    arg1 += 4;
    diff = word0 - word1;
    if (diff != 0)
    {
      if (!(word0 & 0xFF000000))
      {
        diff = 0xFF000000;
      }
      else
        if (!(word0 & 0xFF0000))
      {
        diff = 0xFFFF0000;
      }
      else
        if (!(word0 & 0xFF00))
      {
        diff = 0xFFFFFF00;
      }
      else
      {
        return diff;
      }
      return (word0 & diff) - (word1 & diff);
    }
    if (((((word0 << 24) == 0) || (!(word0 & 0xFF00))) || (!(word0 & 0xFF0000))) || (!(word0 & 0xFF000000)))
    {
      return diff;
    }
  }

}
