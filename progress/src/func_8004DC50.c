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
extern u8 D_800AE850[];
extern u8 *D_800C35A0;
s32 func_8004D4D8(void *, void *);
DCItem *func_8004D784(DCObj *);
s32 func_8004D7D4(DCObj *, s32, s32);
s32 func_8004DB30(DCObj *, s32);
u8 *func_80041530(u16, u16);

void func_8004DC50(DCObj *o)
{
  DCObj *last;
  DCObj *p;
  DCItem *it;
  DCInfo *info;
  DCBlock *blk;
  DCEnt *e;
  DCRec *list;
  u16 i;
  u16 j;
  u16 k;
  u16 m;
  u16 n;
  u16 v;
  u8 found;
  s32 idx;
  s32 cnt;
  u16 mode;

  last = 0;
  idx = 1;
  cnt = 2;
  if (o->count != 0)
  {
    list = o->list;
    for (i = 0, found = 0; i < o->count && !found; i++)
    {
      if (list[i].kind == 0)
      {
        blk = list[i].ptr;
        e = (DCEnt *) ((u8 *) blk + 0x1C);
        for (j = 0; j < blk->count && !found; j++)
        {
          if (e->type == 1)
          {
            func_8004D4D8(o, blk);
            {
              u8 t = D_800AE850[0x87A2];
              e->a = 0;
              e->b = t;
            }
            found = 1;
            for (k = 0; k < 5; k++)
            {
              n = (k * 2) | 1;
              for (m = 0, v = 1; m < n; m++)
              {
                v = v * 2;
              }
              blk->mask |= v * 2;
            }
          }
          e = (DCEnt *) ((u8 *) e + (e->size + 8));
        }
      }
    }
  }

  for (p = o->next; p != o && p != 0; cnt++)
  {
    it = func_8004D784(p);
    if (it != 0)
    {
      info = it->info;
      mode = *(u16 *) (D_800C35A0 + 0x1E);
      if (mode == 0 || mode == 5)
      {
        if (cnt == 20)
        {
          func_8004D7D4(p, info->f180[3], idx);
          idx++;
        }
        else if (info->f170 != -1 && (it->flags & 8))
        {
          func_8004D7D4(p, info->f180[3], idx);
          idx++;
          it->flags &= ~8;
        }
        it->flags &= ~8;
      }
      else if (info->f170 != -1 && (it->flags & 8))
      {
        func_8004D7D4(p, info->f180[3], idx);
        idx++;
      }
    }
    last = p;
    p = last->next;
  }

  D_800A73E0[0x6C01] = 1;
  if (p == 0)
  {
    if (*(u16 *) (D_800C35A0 + 0x1E) != 0)
    {
      D_800A73E0[0x6C00] = 2;
    }
    D_800A73E0[0x6C01] = 0;
    last = last->parent->parent;
    if (last != 0)
    {
      found = func_8004DB30(last, idx);
      if (!found)
      {
        last = last->next;
        found = func_8004DB30(last, idx);
        if (!found)
        {
          last = last->next;
          func_8004DB30(last, idx);
        }
      }
      idx++;
    }
  }
  *(u16 *) (D_800A73E0 + 0x6BFC) = idx;
  *(s16 *) (D_800A73E0 + 0x6C04) = D_800AE850[0x87A2] + D_800AE850[0x87A5];
  *(s16 *) (func_80041530(*(u16 *) (D_800C35A0 + 0x1E), *(u16 *) (D_800C35A0 + 0x20)) + 0x12) = *(u16 *) (D_800A73E0 + 0x6BFC) - 1;
}
