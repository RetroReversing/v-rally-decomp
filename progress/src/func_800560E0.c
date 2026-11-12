typedef struct 
{
  s32 a;
  s16 b;
  s16 c;
  s32 d;
  s32 e[4];
} FuncBlk;
typedef struct 
{
  u8 pad[0x64];
  u16 count;
  u8 pad2[2];
  u8 *records;
} FuncArg0;
extern u8 D_800A1310[];
extern s32 poolAlloc(s32, s32);
extern void func_80056FE4(s32 *);
extern void gfx_draw_item_list(s32, s32 *, s32);
extern void *gfx_get_dl(s32);
extern void gfx_set_dl(s32, void *);
extern void heapFreeBlock(s32);

/* Builds a block of 8-byte records: sums their sizes to allocate a buffer, runs each
 * record's handler from D_800A1310 to fill it, then appends a G_ENDDL to the display list. */
void func_800560E0(FuncArg0 *arg0, s32 dlIndex)
{
  FuncBlk blk;
  u32 *p;
  s32 total = 0;
  s32 i = 0;
  s32 count = arg0->count;
  u8 *rec = arg0->records;
  if (count)
  {
    do
    {
      total += *((u16 *) (rec + 4));
      i++;
      rec += 8;
    }
    while (i < count);
  }
  i = poolAlloc(1, total * 0x22);
  blk.a = i;
  blk.b = total;
  blk.c = 0;
  rec = arg0->records;
  i = 0;
  blk.d = blk.a;
  if (count)
  {
    do
    {
      #ifdef PORT
      ((void (*)(s32 *, u8 *)) (uintptr_t) (*((s32 *) (D_800A1310 + ((*((u16 *) (rec + 6))) << 2)))))(&blk.d, rec);
#else
      ((void (*)(s32 *, u8 *)) (*((s32 *) (D_800A1310 + ((*((u16 *) (rec + 6))) << 2)))))(&blk.d, rec);
#endif
      rec += 8;
      i++;
    }
    while (i < count);
  }
  func_80056FE4(&blk.a);
  gfx_draw_item_list(dlIndex, &blk.a, *((s32 *) (((u8 *) arg0) + 0x50)));
  if (arg0->records && arg0->records)
  {
  }
  p = gfx_get_dl(dlIndex);
  p[0] = 0xDF000000;
  p[1] = 0;
  gfx_set_dl(dlIndex, p + 2);
  heapFreeBlock(blk.a);
}
