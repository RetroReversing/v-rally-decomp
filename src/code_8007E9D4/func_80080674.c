#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Node Node;
struct Node
{
  Node *next;
  Node *prev;
  u8 x8[2];
  u8 used;
  u8 busy;
  u8 xc[4];
  u32 field10;
};
extern Node *D_800A19E0;
extern u32 D_800A19E4;
extern u32 D_800B5B40;
extern void (*D_800C8090)(void *);
extern void *func_8007F828(void *, u32);
extern u32 func_80080EA0(Node *);
void *func_80080674(void *arg0, u32 arg1)
{
  Node *s0 = arg0;
  u32 s2 = arg1;
  Node *s1;
  u32 a1;
  Node *a0;
  loop: { Node *head = D_800A19E0; if (head == 0) goto done; if (head == s0) goto done; if (D_800A19E4 < s2) goto done; if (func_80080EA0(head) < s2 + 0x14) goto done; s0 = D_800A19E0; goto loop; } done: s2 = (s2 + 3) & ~3;
  a0 = (Node *) (((u8 *) s0) - 0x14);
  if (s2 == 0)
  {
    D_800C8090(((u8 *) D_800B5B40) - 4);
    for (;;)
    {
      ;
    }

  }
  s1 = 0;
  if (a0->busy == 0)
  {
    u32 end = ((u32) a0->next) - 0x14;
    a1 = end - ((u32) a0);
    if ((s2 + 0x1c) < a1)
    {
      a0->busy = 1;
      s0 = (Node *) (((u8 *) a0) + 0x14);
      func_8007F828(s0, a1);
    }
    else
    {
      s0 = 0;
    }
  }
  else
  {
    s0 = (Node *) (((u8 *) a0) + 0x14);
  }
  a1 = 0x7fffffff;
  if (s0 != 0)
  {
    do
    {
      if (s0->used == 0)
      {
        u32 end = ((u32) s0->next) - 0x14;
        u32 size = end - ((u32) s0);
        if ((size >= s2) && ((size < a1) || (s1 == 0)))
        {
          a1 = size;
          s1 = s0;
        }
      }
      s0 = s0->next;
    }
    while (s0 != 0);
  }
  if (s1 != 0)
  {
    u32 total = s2 + 0x14;
    if (a1 >= total)
    {
      Node *v0 = s1->next;
      s0 = (Node *) (((u8 *) s1) + total);
      v0->prev = s0;
      s0->next = v0;
      s0->prev = s1;
      s0->x8[0] = 0;
      s0->x8[1] = 0;
      s0->used = 0;
      s0->busy = 0;
      s0->field10 = 0;
      s1->next = s0;
    }
    s1->used = 1;
    s1->field10 = 0;
    s1 = (Node *) (((u8 *) s1) + 0x14);
  }
  return s1;
}

