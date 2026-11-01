#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Obj
{
  s32 x0;
  s32 x4;
} Obj;
typedef struct Entry
{
  char *key;
  void (*handler)(Obj *, u8 *, s32);
  s32 value;
} Entry;
extern Entry D_8009FE40[];
extern s32 func_80098180(u8 *, char *);
extern s32 func_80040084(Obj *, u8 *, s32);
s32 func_8003FFB4(Obj *a, u8 *b)
{
  Entry *e;
  s32 result;
  u8 done;
  result = (done = 0);
  e = D_8009FE40;
  loop:
  {
    if (e->handler == NULL)
    {
      goto end;
    }
    do
    {
      if (func_80098180(b + 0x4C, e->key) == 0)
      {
        result = a->x4;
        e->handler(a, b, e->value);
        if (a->x4 != result)
        {
          result = a->x4;
        }
        else
        {
          result = 0;
        }
        done = 1;
      }
      e++;
      if (!done)
      {
        goto loop;
      }
    }
    while (0);
  }

  end:
  if (!done)
  {
    if (e)
    {
      result = func_80040084(a, b, 0);
    }
    else
    {
      result = func_80040084(a, b, 0);
    }
  }

  return result;
}


