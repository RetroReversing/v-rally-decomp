extern void stream_obj_free(s32);
extern void streamReleaseEntry(s32);
extern void records_restore_from_order(void);
extern void heapFreeBlock(s32);
extern void heap_free_stub(s32);
extern u8 D_800A17F0;
extern u8 gOrderState[];
extern char *gRecords;
extern u8 gStreamState[];
typedef struct { s32 w[61]; } Blk;
typedef struct Slot16
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
} Slot16;
static inline s32 *inline_fn()
{
  return (s32 *) (gStreamState + 0x7F5A);
}

/* Reset the audio record block from the state saved in gStreamState, but only
 * when record mode is 8, the guard is clear and the pending flag is set. */
void func_80077054(void)
{
  u8 *pending;
  char *rec;
  s32 first;
  u8 *slots;
  Slot16 *src;
  Slot16 *dst;
  Slot16 *end;
  u8 *mode;
  u16 modeByte;
  if ((*((u16 *) (gRecords + 0x1E))) != 8)
  {
    return;
  }
  if (D_800A17F0 != 0)
  {
    return;
  }
  pending = gStreamState + 0x805A;
  if ((*pending) == 0)
  {
    return;
  }
  slots = (char *) gOrderState;
  slots += (s32) 0x2408;
  first = *((s32 *) (gOrderState + 0x240C));
  *pending = 0;
  heapFreeBlock(first);
  heapFreeBlock(*((s32 *) slots));
  {
    typedef struct Rec
    {
      s32 a;
      s32 b;
      u16 c;
      u8 pad[0x3A];
    } Rec;
    Rec *r;
    u8 n;
    n = 0;
    r = (Rec *) slots;
    do
    {
      slots = (u8 *)((n * sizeof(Rec)) + (u32)r);
      ((Rec *)slots)->b = 0;
      ((Rec *)slots)->a = 0;
      ((Rec *)slots)->c &= 0xFFFE;
      n++;
    }
    while (n < 4);
  }
  *(Blk *)gRecords = *(Blk *)(gStreamState + 0x7F66);
  rec = gRecords;
  mode = gStreamState + 0x7F4F;
  modeByte = *mode;
  *((u16 *) (rec + 0x1E)) = modeByte;
  if (modeByte == 5)
  {
    streamReleaseEntry(*((s32 *) (gStreamState + 0x7F4A)));
  }
  *((u16 *) (gRecords + 0xE)) = *((u8 *) (gStreamState + 0x7F51));
  if ((*mode) == 8)
  {
    *((s32 *) (gOrderState + 0x8030)) = 5;
    records_restore_from_order();
  }
  else
  {
    *((s32 *) (gOrderState + 0x8030)) = 3;
  }
  *((u8 *) (gStreamState + 0x7E72)) = 0;
  heap_free_stub(*((s32 *) (gStreamState + 0x7F56)));
  heap_free_stub(*inline_fn());
  stream_obj_free(*((s32 *) (gStreamState + 0x7F5E)));
  stream_obj_free(*((s32 *) (gStreamState + 0x7F62)));
}
