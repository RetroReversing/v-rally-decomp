typedef struct Node
{
  struct Node *next;
} Node;
typedef struct Grp
{
  struct Grp *next;
  char pad4[0x28 - 4];
  Node *subs;
  char pad2C[0x4C - 0x2C];
  u8 nsub;
} Grp;
typedef struct Ctx
{
  Node *list0;
  s32 x4;
  s32 cnt0;
  Grp *grp;
  s32 x10;
  s32 cnt1;
  Node *list2;
  s32 x1C;
  s32 cnt2;
  Node *list3;
  s32 x28;
  s32 cnt3;
  char pad30[0x222 - 0x30];
  s16 sel;
  char pad224[0x294 - 0x224];
  void (*cb)(void);
} Ctx;
extern void func_80059154(s32);
extern void func_80059FB4(void);
extern void func_8005A0A8(void);
extern void func_8007EE9C(void *);
extern Ctx *D_800A1468;
void func_8005A100(void)
{
  s32 m;
  Grp *g;
  Grp *gn;
  Node *p;
  s32 n;
  Node *q;
  if (D_800A1468->cb != NULL)
  {
    D_800A1468->cb();
    D_800A1468->cb = NULL;
  }
  n = D_800A1468->cnt1;
  D_800A1468->sel = -1;
  if (n != 0)
  {
    gn = D_800A1468->grp;
    while (n--)
    {
      g = gn;
 do { m = g->nsub; gn = g->next; } while (0);
      p = g->subs;
      if (m != 0)
      {
        while (m--)
        {
          q = p;
          p = q->next;
          func_8007EE9C(q);
        }

      }
      func_8007EE9C(g);
    }

    D_800A1468->x10 = (D_800A1468->cnt1 = 0);
  }
  n = D_800A1468->cnt0;
  if (n != 0)
  {
    p = D_800A1468->list0;
    while (n--)
    {
      q = p;
      p = q->next;
      func_8007EE9C(q);
    }

    D_800A1468->cnt0 = 0;
    D_800A1468->x4 = 0;
  }
  n = D_800A1468->cnt2;
  if (n != 0)
  {
    Node *r = D_800A1468->list2;
    while (n--)
    {
      Node *t = r;
      r = t->next;
      func_8007EE9C(t);
    }

    D_800A1468->cnt2 = 0;
    D_800A1468->x1C = 0;
  }
  n = D_800A1468->cnt3;
  if (n != 0)
  {
    Node *r = D_800A1468->list3;
    while (n--)
    {
      Node *t = r;
      r = t->next;
      func_8007EE9C(t);
    }

    D_800A1468->cnt3 = 0;
    D_800A1468->x28 = 0;
  }
  func_80059154(1);
  func_80059154(4);
  func_80059FB4();
  func_8005A0A8();
}
