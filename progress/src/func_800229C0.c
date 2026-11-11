typedef struct Stage
{
  s32 count;
  s32 pad[3];
  void (*fn)(void *, void *, s32, void *);
  s32 pad2[2];
} Stage;
static inline void *inline_fn(s32 *arg0)
{
  return (void *) arg0;
}

/* Runs stage `index` of the stage table at ctx + 0xD0. When the stage has entries, copies
 * each entry's word at +0x1C into its word at +0x48 (count words, taken from the stage),
 * then calls the stage's handler with the entry as its last argument. */
void func_800229C0(s32 index, u8 *ctx, s32 unused, void *arg3)
{
  int has_entries;
  s32 buf[2];
  u32 i = 0;
  void *entry = arg3;
  has_entries = ((*((Stage **) (ctx + 0xD0))) + index)->count != 0;
  if (has_entries)
  {
    entry = inline_fn(((s32 *) ctx) + index);
    do
    {
      ((s32 *) (*((s32 **) (((u8 *) entry) + 0x48))))[i] = ((s32 *) (*((s32 **) (((u8 *) entry) + 0x1C))))[i];
      i++;
    }
    while (i < ((u32) ((*((Stage **) (ctx + 0xD0))) + index)->count));
  }
  ((*((Stage **) (ctx + 0xD0))) + index)->fn(ctx, ctx, i, entry);
}
