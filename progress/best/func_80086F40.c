#define HEAD (*(Node **)(D_800A73E0 + 0x4564))
#define FREE (*(Node **)(D_800A73E0 + 0x4568))
#define SIZE (*(s32 *)(D_800A73E0 + 0x4578))
#define TABLE (*(Packet **)(D_800A73E0 + 0x457C))
typedef struct Node
{
  struct Node *next;
  struct Node *prev;
  u32 start;
  s32 phys;
  void *data;
} Node;
typedef struct Five
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
} Five;
typedef struct Packet
{
  s32 first;
  Five rest;
} Packet;
extern u8 D_800A73E0[];
extern u8 D_800C02AE[];
extern s32 D_800A1BA4;
extern s32 D_800A1BA8;
extern s32 osVirtualToPhysical(void *);
extern void alLink(Node *, Node *);
extern void alUnlink(Node *);
extern void func_80081040(u32, void *, s32, s32, Five);
s32 func_80086F40(u32 a, s32 b)
{
  s32 end;
  s32 chunk;
  s32 new_var;
  s32 t;
  s32 start;
  s32 sum;
  void *data;
  s32 n;
  Packet *p;
  Node *walker;
  Node *old;
  Node *node;
  if ((*((u32 *) (D_800C02AE + 0x339A))) & 1)
  {
    return osVirtualToPhysical((void *) a);
  }
  end = a + b;
  old = 0;
  walker = HEAD;
  if (walker != 0)
  {
    chunk = SIZE;
    new_var = chunk;
    while (walker != 0)
    {
      start = walker->start;
      sum = start + new_var;
      if (a < ((u32) start))
      {
        break;
      }
      old = walker;
      if (sum >= end)
      {
        walker->phys = D_800A1BA4;
        return osVirtualToPhysical((((u8 *) walker->data) + a) - walker->start);
      }
      walker = walker->next;
    }

  }
  node = FREE;
  if (node == 0)
  {
    return osVirtualToPhysical(HEAD);
  }
  FREE = node->next;
  alUnlink(node);
  if (old != 0)
  {
    alLink(node, old);
    t = a & 1;
  }
  else
  {
    old = HEAD;
    if (old != 0)
    {
      HEAD = node;
      walker = old;
      node->next = walker;
      node->prev = 0;
      walker->prev = node;
    }
    else
    {
      HEAD = node;
      node->next = 0;
      node->prev = 0;
    }
    t = a & 1;
  }
  a -= t;
  node->start = a;
  chunk = D_800A1BA4;
  node->phys = chunk;
  data = node->data;
  n = D_800A1BA8;
  D_800A1BA8 = n + 1;
  ;
  func_80081040(a, data, SIZE, (&TABLE[n])->first, (&TABLE[n])->rest);
  return osVirtualToPhysical(data) + t;
}
