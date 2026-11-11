typedef struct Copy40 { s32 w[10]; } Copy40;
typedef struct HeaderView
{
  u8 pad[0x1A];
  u16 mode1A;
  u8 gap[2];
  u16 mode1E;
} HeaderView;
s32 func_80022A98();
s32 func_8007B204(void *);
extern void ** volatile gCarList;
extern void * volatile gRecords;

/* Sets up the 0x44-byte car display entries at entries. A mode of 0 refreshes
 * every entry from the driver list and the record block; a nonzero mode only
 * refreshes the entry it names (and its partner for the lap view). */
void car_entries_refresh(void *entries)
{
  s32 mode;
  s32 entryIdx;
  void *entry;
  void *entry2;
  void *src;
  void *src2;
  void *src3;
  void *records;
  void *base;
  void *dst;
  void *dst2;
  void *dst3;
  void *node;
  void *node2;
  s32 idx;
  s32 idx2;
  s32 i;
  s32 lastval;
  u16 mode8;
  records = gRecords;
  mode = *((u8 *) (((char *) entries) + 0x114));
  if (((HeaderView *) records)->mode1E == 0)
  {
    entryIdx = mode & 0xFF;
    if (((HeaderView *) records)->mode1A != 0)
    {
      node = *gCarList;
      if (entryIdx == 1)
      {
        node = *((void **) (((char *) node) + 4));
        node = *((void **) (((char *) node) + 4));
      }
      entry = entries + (entryIdx * 0x44);
      func_80022A98(node, *((s32 *) (((char *) entry) + 0)));
      base = gRecords;
      *((s16 *) (((char *) entry) + 0xE)) = 0;
      dst = entry + 0x1C;
      src = (void *) (((*((u8 *) (((char *) (base + entryIdx)) + 0x32))) * 0x28) + ((u32) base));
      *(Copy40 *)(entry + 0x1C) = *(Copy40 *)(src + 0x44);
      *((s32 *) (((char *) entry) + 0x18)) = (s32) (*(*((s32 **) (((char *) node) + 0x88))));
      func_8007B204(node);
      *((u16 *) (((char *) entry) + 8)) = (u16) (((*((u16 *) (((char *) entry) + 8))) | 0x200) & 0xFBFF);
      return;
    }
    mode8 = (u8)(s8)mode;
    if (mode8 != 0)
    {
      return;
    }
    {
      node2 = *gCarList;
      i = 0;
      if (((u32) (mode8 & 0xFF)) < ((u16) (*((u16 *) (((char *) entries) + 0x110)))))
      {
        do
        {
          idx = i & 0xFF;
          entry2 = entries + (idx * 0x44);
          func_80022A98(node2, *((s32 *) (((char *) entry2) + 0)));
          base = gRecords;
          *((s16 *) (((char *) entry2) + 0xC)) = 0;
          *((s16 *) (((char *) entry2) + 0xE)) = 0;
          dst2 = entry2 + 0x1C;
          src2 = (void *)(((*((u8 *) (((char *) (base + idx)) + 0x32))) * 0x28) + (u32)base);
          *(Copy40 *)(entry2 + 0x1C) = *(Copy40 *)(src2 + 0x44);
          *((s32 *) (((char *) entry2) + 0x18)) = (s32) (*(*((s32 **) (((char *) node2) + 0x88))));
          func_8007B204(node2);
          i += 1;
          *((s16 *) (((char *) entry2) + 0xA)) = 1;
          *((u16 *) (((char *) entry2) + 8)) = (u16) (((*((u16 *) (((char *) entry2) + 8))) | 0x200) & 0xFBFF);
          node2 = *((void **) (((char *) node2) + 4));

        }
        while (((u32) (i & 0xFF)) < ((u16) (*((u16 *) (((char *) entries) + 0x110)))));
      }
    }
  }
  else
  {
    i = 0;
    if (mode == 0)
    {
      node = *gCarList;
      do
      {
        idx2 = i & 0xFF;
        entry = entries + (idx2 * 0x44);
        *((s16 *) (((char *) entry) + 0xC)) = 0;
        *((s16 *) (((char *) entry) + 0xE)) = 0;
        func_80022A98(node, *((s32 *) (((char *) entry) + 0)));
        dst3 = entry + 0x1C;
        base = gRecords;
        src3 = (void *)(((*((u8 *) (((char *) (base + idx2)) + 0x32))) * 0x28) + (u32)base);
        *(Copy40 *)(entry + 0x1C) = *(Copy40 *)(src3 + 0x44);
        lastval = (s32) (*(*((s32 **) (((char *) node) + 0x88))));
        i += 1;
        *((s16 *) (((char *) entry) + 0xA)) = 1;
        *((u16 *) (((char *) entry) + 8)) = (u16) (((*((u16 *) (((char *) entry) + 8))) | 0x200) & 0xFBFF);
        *((s32 *) (((char *) entry) + 0x18)) = lastval;
        node = *((void **) (((char *) node) + 4));
      }
      while (((u32) (i & 0xFF)) < 4U);
    }
  }
}
