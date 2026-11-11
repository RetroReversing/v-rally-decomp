typedef struct {
  u16 type;
  u16 pad2;
  s32 size;
  s16 a;
  s16 b;
} DCEnt;
typedef struct {
  u8 pad0[0x18];
  u16 count;
  u16 mask;
} DCBlock;
typedef struct {
  DCBlock *ptr;
  s16 kind;
  s16 pad6;
} DCRec;
typedef struct DCObj {
  u8 pad0[0x50];
  u32 count;
  u8 pad54[4];
  struct DCObj *parent;
  struct DCObj *next;
  u8 pad60[8];
  DCRec *list;
} DCObj;
typedef struct {
  u8 pad0[0x170];
  s16 f170;
  u8 pad172[0xE];
  s32 *f180;
} DCInfo;
typedef struct {
  u8 pad0[0x10];
  s32 flags;
  u8 pad14[0x14];
  DCInfo *info;
} DCItem;

extern u8 D_800A73E0[];
extern u8 gOrderState[];
extern u8 *gRecords;
s32 updatePathDirection(void *, void *);
DCItem *findEntryById(DCObj *);
s32 func_8004D7D4(DCObj *, s32, s32);
s32 assignEntryIndices(DCObj *, s32);
u8 *func_80041530(u16, u16);

/* Assigns render slots to the objects in the chain starting at `root`. Objects flagged 8 get a
 * slot in chain order (every 20th one always, the rest only when their info has f170 set), and
 * the draw-state block at D_800A73E0 is updated with the next free slot and a mode code. */
void func_8004DC50(DCObj *root)
{
  DCObj *prev;
  DCObj *obj;
  DCItem *item;
  DCInfo *info;
  DCBlock *block;
  DCEnt *entry;
  DCRec *recs;
  u16 i;
  u16 j;
  u16 k;
  u16 n;
  u16 v;
  u16 mode;
  u8 done;
  s32 nextSlot;
  s32 chainPos;
  u16 m;

  prev = 0;
  nextSlot = 1;
  chainPos = 2;
  if (root->count != 0)
  {
    recs = root->list;
    for (i = 0, done = 0; i < root->count && !done; i++)
    {
      if (recs[i].kind == 0)
      {
        block = recs[i].ptr;
        entry = (DCEnt *) ((u8 *) block + 0x1C);
        for (j = 0; j < block->count && !done; j++)
        {
          if (entry->type == 1)
          {
            updatePathDirection(root, block);
            {
              u8 t = gOrderState[0x87A2];
              entry->a = 0;
              entry->b = t;
            }
            done = 1;
            for (k = 0; k < 5; k++)
            {
              n = (k * 2) | 1;
              for (m = 0, v = 1; m < n; m++)
              {
                v = v * 2;
              }
              block->mask |= v * 2;
            }
          }
          entry = (DCEnt *) ((u8 *) entry + (entry->size + 8));
        }
      }
    }
  }

  for (obj = root->next; obj != root && obj != 0; chainPos++)
  {
    item = findEntryById(obj);
    if (item != 0)
    {
      info = item->info;
      mode = *(u16 *) (gRecords + 0x1E);
      if (mode == 0 || mode == 5)
      {
        if (chainPos == 20)
        {
          func_8004D7D4(obj, info->f180[3], nextSlot);
          nextSlot++;
        }
        else if (info->f170 != -1 && (item->flags & 8))
        {
          func_8004D7D4(obj, info->f180[3], nextSlot);
          nextSlot++;
          item->flags &= ~8;
        }
        item->flags &= ~8;
      }
      else if (info->f170 != -1 && (item->flags & 8))
      {
        func_8004D7D4(obj, info->f180[3], nextSlot);
        nextSlot++;
      }
    }
    prev = obj;
    obj = prev->next;
  }

  D_800A73E0[0x6C01] = 1;
  if (obj == 0)
  {
    if (*(u16 *) (gRecords + 0x1E) != 0)
    {
      D_800A73E0[0x6C00] = 2;
    }
    D_800A73E0[0x6C01] = 0;
    prev = prev->parent->parent;
    if (prev != 0)
    {
      done = assignEntryIndices(prev, nextSlot);
      if (!done)
      {
        prev = prev->next;
        done = assignEntryIndices(prev, nextSlot);
        if (!done)
        {
          prev = prev->next;
          assignEntryIndices(prev, nextSlot);
        }
      }
      nextSlot++;
    }
  }
  *(u16 *) (D_800A73E0 + 0x6BFC) = nextSlot;
  *(s16 *) (D_800A73E0 + 0x6C04) = gOrderState[0x87A2] + gOrderState[0x87A5];
  *(s16 *) (func_80041530(*(u16 *) (gRecords + 0x1E), *(u16 *) (gRecords + 0x20)) + 0x12) = *(u16 *) (D_800A73E0 + 0x6BFC) - 1;
}
