typedef struct Node
{
  void *next;
} Node;
typedef struct Grp
{
  void *next;
  char pad4[0x28 - 4];
  void *subs;
  char pad2C[0x4C - 0x2C];
  u8 nsub;
} Grp;
typedef struct Ctx
{
  void *list0;
  void *tail0;
  s32 count0;
  void *grp;
  void *grp_tail;
  s32 count1;
  void *list2;
  void *tail2;
  s32 count2;
  void *list3;
  void *tail3;
  s32 count3;
  char pad30[0x222 - 0x30];
  s16 sel;
  char pad224[0x294 - 0x224];
  void (*cb)(void);
} Ctx;
extern void func_80059154(s32);
extern void func_80059FB4(void);
extern void stream_list_free_all(void);
extern void heapFreeBlock(void *);
extern Ctx *gSelectState;

/* Resets the pool: runs and clears the pending callback, frees every group
 * with its sub-nodes, then frees the three node lists and zeroes their
 * counts and tails. Finally it calls the module reset helpers. */
void func_8005A100(void)
{
  s32 m;
  Grp *g;
  Grp *gn;
  Node *p;
  s32 n;
  Node *q;
  if (gSelectState->cb != NULL)
  {
    gSelectState->cb();
    gSelectState->cb = NULL;
  }
  n = gSelectState->count1;
  gSelectState->sel = -1;
  if (n != 0)
  {
    gn = gSelectState->grp;
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
          heapFreeBlock(q);
        }

      }
      heapFreeBlock(g);
    }

    gSelectState->count1 = 0; gSelectState->grp_tail = NULL;
  }
  n = gSelectState->count0;
  if (n != 0)
  {
    p = gSelectState->list0;
    while (n--)
    {
      q = p;
      p = q->next;
      heapFreeBlock(q);
    }

    gSelectState->count0 = 0;
    gSelectState->tail0 = 0;
  }
  n = gSelectState->count2;
  if (n != 0)
  {
    Node *r = gSelectState->list2;
    while (n--)
    {
      Node *t = r;
      r = t->next;
      heapFreeBlock(t);
    }

    gSelectState->count2 = 0;
    gSelectState->tail2 = 0;
  }
  n = gSelectState->count3;
  if (n != 0)
  {
    Node *r = gSelectState->list3;
    while (n--)
    {
      Node *t = r;
      r = t->next;
      heapFreeBlock(t);
    }

    gSelectState->count3 = 0;
    gSelectState->tail3 = 0;
  }
  func_80059154(1);
  func_80059154(4);
  func_80059FB4();
  stream_list_free_all();
}
