#define HEAD (*(Node **)(D_800A73E0 + 0x4564))
#define FREE (*(Node **)(D_800A73E0 + 0x4568))
#define SIZE (*(s32 *)(D_800A73E0 + 0x4578))
#define TABLE (*(Packet **)(D_800A73E0 + 0x457C))
typedef struct N { struct N *next; struct N **prev; } N;
typedef struct Node
{
  N link;
  u32 start;
  s32 phys;
  void *data;
} Node;
typedef struct Packet { s32 w[6]; } Packet;
extern u8 D_800A73E0[];
extern u8 D_800C02AE[];
extern u32 D_800A1BA4;
extern u32 D_800A1BA8;
extern s32 osVirtualToPhysical(s32);
extern void alLink(N *, N **);
extern void alUnlink(void *);
extern void func_80081040(s32, s32, u32, Packet);
s32 func_80086F40(s32 addr, s32 b, void *state)
{
  u32 a=(u32)addr;
  s32 end;
  s32 chunk;
  s32 start;
  s32 sum;
  void *data;
  u32 n;
  Node *walker;
  s32 old;
  if ((*((u32 *) (D_800C02AE + 0x339A))) & 1)
  {
    return osVirtualToPhysical((s32)a);
  }
  end = a + b;
  old = 0;
  walker = HEAD;
  if (walker != 0)
  {
    chunk = SIZE;
    while (walker != 0)
    {
      start = walker->start;
      sum = start + chunk;
      if (a < ((u32) start))
      {
        break;
      }
      old = (s32) walker;
      if (sum >= end)
      {
        walker->phys = D_800A1BA4;
        return osVirtualToPhysical((s32)((u32)walker->data + a - walker->start));
      }
      walker = (Node *)walker->link.next;
    }
  }
  walker = FREE;
  if (walker == 0)
  {
    return osVirtualToPhysical((s32)HEAD);
  }
  FREE = (Node *)walker->link.next;
  alUnlink(walker);
  if (old != 0)
  {
    alLink(&walker->link, &((Node *)old)->link.next);
    old = a & 1;
  }
  else
  {
    if (HEAD != 0)
    {
      old = (s32) HEAD;
      HEAD = walker;
      walker->link.next = &((Node *)old)->link;
      walker->link.prev = 0;
      ((Node *)old)->link.prev = &walker->link.next;
    }
    else
    {
      HEAD = walker;
      walker->link.next = 0;
      walker->link.prev = 0;
    }
    old = a & 1;
  }
  a -= old;
  walker->start = a;
  walker->phys = D_800A1BA4;
  data = walker->data;
  n = D_800A1BA8;
  D_800A1BA8 = n + 1;
  func_80081040((s32)a, (s32)data, (u32)SIZE, TABLE[n]);
  return osVirtualToPhysical((s32)data) + old;
}
