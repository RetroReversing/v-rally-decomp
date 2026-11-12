typedef struct PathRec
{
  void *block;
  s16 key;
  s16 pad6;
} PathRec;
typedef struct PathBlock
{
  u8 pad0[0x18];
  u16 count;
} PathBlock;
typedef struct PathEntry
{
  u16 type;
  u16 pad2;
  u32 dataSize;
  s16 value;
} PathEntry;
s32 updatePathDirection(void *, void *);

/* Finds the first block in track's record table that has key 0 and a type-1
 * entry. Calls updatePathDirection on that block and numbers the entry with
 * the next index from firstIndex. Returns 1 if an entry was numbered, else 0. */
s32 assignEntryIndices(void *track, s16 firstIndex)
{
  u32 recCount;
  int zero;
  PathRec *table;
  s16 nextIndex;
  u16 found;
  u16 i;
  u16 e;
  PathRec *rec;
  PathBlock *block;
  PathEntry *ent;
  s16 key;

  recCount = *((u32 *) (((u8 *) track) + 0x50));
  table = *((PathRec ***) (((u8 *) track) + 0x68));
  nextIndex = firstIndex;
  found = 0;
  if (recCount != 0)
  {
    i = 0;
    while ((((u32) i) < (*((u32 *) (((u8 *) track) + 0x50)))) && (found != 1))
    {
#ifdef PORT
      rec = (PathRec *) (((u8 *) table) + (((u32) i) * 8));
#else
      rec = (PathRec *) ((((u32) i) * 8) + ((u32) table));
#endif
      zero = 0;
      key = rec->key;
      if (key == zero)
      {
        block = (PathBlock *) rec->block;
        e = zero;
        ent = (PathEntry *) (((u8 *) block) + 0x1c);
        if ((((u32) key) < block->count) && (found != 1))
        {
          do
          {
            if (ent->type == 1)
            {
              updatePathDirection(track, block);
              do { ent->value = nextIndex; nextIndex++; } while (0);
              found = 1;
            }
            ent = (PathEntry *) (((u8 *) ent) + (ent->dataSize + 8));
            e++;
          }
          while ((((u32) e) < block->count) && (found != 1));
        }
      }
      i++;
    }

  }
  return found;
}
