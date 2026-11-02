typedef struct { u8 b[8]; } Pair;
typedef struct { u8 pad[6]; u16 n; } Frm;
typedef struct { Frm *f; } Anim0;
typedef struct { u8 pad[4]; Anim0 *a; } Anim;
typedef struct {
  u8 pad0[0xC];
  Anim *anim;
  u8 pad10[4];
  s16 x14;
  u8 pad16[6];
  s16 x1C;
  u8 pad1E[0x50 - 0x1E];
} Item;
typedef struct { Pair pos; u16 x8; u8 pad[0x2C - 0xA]; Item *cur; } Node;
typedef struct { u8 b[0x178]; Node *p; } Obj;
typedef struct { u8 pad[4]; u16 base; u8 pad6[0x24 - 6]; Item *l0; Item *l1; } Src;
extern Obj *D_800C7F84;
extern u32 D_800AFA6C;
extern void func_8000A2C4(void *, s32, s32, s32);
void func_80048394(s32 a, Src *b, Obj *c, s32 d)
{
  Pair saved;
  Node *root = D_800C7F84->p;
  Item *list;
  Item *item;
  s32 x;
  s32 q;
  s32 prod;
  s32 h;

  if (D_800AFA6C & 1) {
    list = b->l0;
  } else {
    list = b->l1;
  }
  saved = D_800C7F84->p->pos;
  D_800C7F84->p->pos = c->p->pos;
  h = list->anim->a->f->n;
  x = (s16) (b->base + c->p->x8);
  q = x / h;
  prod = q * h;
  d *= 4;
  item = &list[q];
  item->x1C = d;
  item->x14 = (prod - x) * 4;
  root->cur = item;
  func_8000A2C4(D_800C7F84->p, 0, 0, 1);
  h = item->anim->a->f->n;
  x = x - prod;
  item[1].x1C = d;
  item[1].x14 = (h - x) * 4;
  root->cur = &list[q + 1];
  func_8000A2C4(D_800C7F84->p, 0, 0, 1);
  h = item[1].anim->a->f->n;
  item[2].x14 = (h * 2 - x) * 4;
  item[2].x1C = d;
  root->cur = &list[q + 2];
  func_8000A2C4(D_800C7F84->p, 0, 0, 1);
  D_800C7F84->p->pos = c->p->pos;
}
