#include "snapshot29_0433f7af8f6d.h"

static inline int __repair_pointer_bits(void *value)
{
  return (int)value;
}

typedef struct Node
{
  s32 x0;
  s32 x4;
  s32 x8;
  s32 xc;
  s32 x10;
  s32 x14;
  u16 x18;
  u16 x1a;
  u16 x1c;
  s32 x20;
  s16 x24[2];
  u8 b28[20];
} Node;
typedef struct Control
{
  Node *node;
  s16 state;
  s16 enabled;
} Control;
typedef struct 
{
  u8 pad00[0x24];
  s32 x24;
  s32 x28;
  s32 x2c;
  u8 pad30[0x20];
  s32 unk50;
  u8 *unk54;
  u8 pad58[0x10];
  Control *unk68;
  u8 pad6c[0x1e];
  u16 unk8a;
} Ctx;
extern void *func_8007EAA0(s32, s32);
void func_8004ED08(Ctx *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g)
{
  u8 *o = 0;
  s32 new_var;
  s32 z = 0;
  s32 q;
  s32 q2;
  s32 r;
  s32 q3;
  s32 q4;
  s32 eb;
  Node *p;
  Control *m;
  if (a->unk50 == 0)
  {
    a->unk68 = func_8007EAA0(1, 8);
    a->unk68->enabled = 1;
    a->unk68->state = 3;
    a->unk50 = 1;
  }
  m = a->unk68;
  if (m->state == 3)
  {
    m->state = 0;
    p = func_8007EAA0(1, 60);
    p->x0 = (*((s16 *) ((g * 6) + a->unk54))) + a->x24;
    r = g * 6;
    p->x4 = (*((s16 *) (a->unk54 + ((g * 6) + 2)))) + a->x28;
    p->x8 = (*((s16 *) (a->unk54 + (r + 4)))) + a->x2c;
    new_var = __repair_pointer_bits(a->unk54);
    q = new_var;
    q2 = (g - a->unk8a) * 6;
    p->xc = (*((s16 *) (q2 + q))) - (*((s16 *) ((g * 6) + q)));
    q = __repair_pointer_bits(a->unk54);
    p->x10 = (*((s16 *) ((((g - a->unk8a) * 6) + q) + 2))) - (*((s16 *) (((g * 6) + q) + 2)));
    q = __repair_pointer_bits(a->unk54);
    q3 = *((s16 *) ((((g - a->unk8a) * 6) + q) + 4));
    q4 = *((s16 *) ((r + q) + 4));
    o = ((u8 *) p) + 0x1c;
    p->x18 = 1;
    p->x1a = 0;
    p->x14 = q3 - q4;
    m->node = p;
  }
  else
    if (m->state == 0)
  {
    p = m->node;
    o = ((u8 *) p) + 0x1c;
    if ((*((u16 *) o)) == 0)
    {
      o = ((u8 *) p) + 0x28;
      p->x20 = 4;
      p->x18++;
    }
    else
    {
      z = 1;
    }
  }
  else
  {
    z = 1;
  }
  if (z == 0)
  {
    *((s16 *) o) = 5;
    *((s32 *) (o + 4)) = 0;
    *((s16 *) (o + 2)) = 1;
    o[8] = c;
    o[9] = d;
    eb = (o[0xa] = e);
    o[0xb] = f;
    *((s32 *) (o + 0xc)) = b;
  }
}
