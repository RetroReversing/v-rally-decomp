#include "snapshot29_0433f7af8f6d.h"

typedef struct 
{
  u16 *pa;
  u16 na;
  u16 pad0;
  u16 *pb;
  u16 nb;
  u16 pad1;
} Lists;
void func_80056BA8(void *, u16 **, u16 *);
static inline int inline_fn(u16 arg0, int arg1)
{
  return arg0 > arg1;
}

s32 func_80056BEC(void *arg0, s32 arg1)
{
  Lists l;
  s32 pad[2];
  u16 *new_var;
  s32 i;
  s32 j;
  u16 na;
  u16 *new_var2;
  u16 cur;
  u16 nbr;
  new_var = &l.nb;
  (void) (&pad);
  func_80056BA8(arg0, &l.pa, &l.na);
  func_80056BA8((void *) arg1, &l.pb, new_var);
  na = l.na;
  i = 0;
  arg1 = 0;
  if (inline_fn(na, 0))
  {
    do
    {
      j = 0;
      if (l.nb & 0xFFFF)
      {
        cur = (new_var2 = l.pa)[i];
        nbr = l.nb;
        do
        {
          arg1 += cur == l.pb[j];
          j++;
        }
        while (j < nbr);
      }
      i++;
    }
    while (i < na);
  }
  return arg1;
}
