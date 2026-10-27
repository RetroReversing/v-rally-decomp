#include "common.h"

typedef struct Node Node;
typedef struct Asset Asset;
typedef struct Root Root;
struct Asset
{
  char pad0[4];
  void *table;
};
struct Node
{
  u32 unk0;
  Node *next;
  char pad8[0x78];
  u32 flags;
  void (*callback)(Node *);
  u32 draw;
  u32 unk8c;
  u8 b90[4];
  char pad94[4];
  u16 val98;
  u16 val9a;
  s16 x9c;
  s16 y9e;
  s32 argA0;
  Asset *assetA4;
  char padA8[0xD0];
  s32 arg178;
};
struct Root
{
  Node *head;
  char pad4[4];
  s32 busy;
};
extern Root *D_800C35A0;
extern void *D_800C7F84;
extern s32 D_8009FEDC;
extern f64 D_800A4C10;
extern void *D_800B65F8;
extern void *func_8004240C(s32);
extern void func_8000A5EC(void *, s32, s32, s32, s32, s32, s32);
extern void func_8004CEB4(s32, s32, s16 *, s32, s32, s32, s32, s32, s32);
void func_80040328(Root *arg0)
{
  u8 count;
  s32 new_var;
  Node *p;
  Node *next;
  void *saved;
  s16 rect[4];
  s32 index;
  f64 scale;
  count = *(((u8 *) D_800C35A0) + 0xf);
  if (arg0->busy != 0)
  {
    return;
  }
  p = arg0->head;
  saved = D_800C7F84;
  D_800B65F8 = arg0;
  if (p == NULL)
  {
    return;
  }
  index = (count - 1) * 2;
  scale = D_800A4C10;
  do
  {
    next = p->next;
    if (p->flags & 1)
    {
      if (p->callback != NULL)
      {
        D_800C7F84 = func_8004240C(index + 1);
        p->callback(p);
      }
      *((u16 *) ((((u8 *) p) + (D_8009FEDC * 2)) + 0x7C)) = *((u16 *) (((u8 *) p) + 0x7A));
      D_800C7F84 = saved;
      if (!(p->flags & 4))
      {
        
        void *q = ((u8 *) p) + 0x10;
        func_8000A5EC(q, ((s32 *) p->assetA4->table)[*((s16 *) (((u8 *) p) + 0x7A))], 0, p->argA0, p->x9c, p->y9e, 0);
        *((u16 *) (((u8 *) p) + 0x52)) = p->val98;
        *((u16 *) (((u8 *) p) + 0x5a)) = p->val9a;
        if (p->flags & 0x80)
        {
          rect[0] = (*((u16 *) (((u8 *) p) + 0xc))) + *((u16 *) (((u8 *) p) + 0x70));
          rect[1] = (*((u16 *) (((u8 *) p) + 0xe))) + (*((u16 *) (((u8 *) p) + 0x72)));
          rect[2] = ((*((u16 *) (((u8 *) ((s32 *) p->assetA4->table)[*((s16 *) (((u8 *) p) + 0x7A))]) + 6))) * (*((s16 *) (((u8 *) p) + 0x98)))) * scale;
          rect[3] = ((*((u16 *) (((u8 *) ((s32 *) p->assetA4->table)[*((s16 *) (((u8 *) p) + 0x7A))]) + 8))) * (*((s16 *) (((u8 *) p) + 0x9a)))) * scale;
          new_var = ((s32 *) saved)[0x178 / 4];
          func_8004CEB4(new_var, ((s32 *) p->assetA4->table)[*((s16 *) (((u8 *) p) + 0x7A))], rect, 0, p->b90[0], p->b90[1], p->b90[2], p->b90[3], 0);
        }
        else
        {
          ((void (*)(s32, s32, s32, void *, s32, void *)) (*((u32 *) (((u8 *) p) + 0x88))))(((s32 *) saved)[0x178 / 4], (*((s16 *) (((u8 *) p) + 0xc))) + (*((s16 *) (((u8 *) p) + 0x70))), (*((s16 *) (((u8 *) p) + 0xe))) + (*((s16 *) (((u8 *) p) + 0x72))), q, p->argA0, ((u8 *) p) + 0x90);
        }
      }
    }
    p = next;
  }
  while (p != NULL);
}
