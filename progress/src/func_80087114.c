s32 al_link_push();
s32 alUnlink();
extern u32 cacheTick;
extern u32 cacheTableIndex;
extern char gGameState[];

/* Ages the audio cache list: entries not used since cacheTick are unlinked and
 * moved to the tail, then the table index is reset and cacheTick advances. */
void func_80087114(void)
{
  char pad[8];
  void *next;
  void *entry;
  void *tail;
  u32 i;

  i = 0;
  if (cacheTableIndex != 0)
  {
    do
    {
      i += 1;
    } while (i < cacheTableIndex);
  }
  entry = *((void **) (gGameState + 0x4564));
  if (entry != NULL)
  {
    do
    {
      next = *((void **) entry);
      if (((*((s32 *) ((char *) entry + 0xC))) + 1) < cacheTick)
      {
        if (*((void **) (gGameState + 0x4564)) == entry)
        {
          *((void **) (gGameState + 0x4564)) = next;
        }
        alUnlink(entry);
        tail = *((void **) (gGameState + 0x4564 + 4));
        if (tail != NULL)
        {
          al_link_push(entry, tail);
          entry = next;
        }
        else
        {
          *((void **) (gGameState + 0x4564 + 4)) = entry;
          *((void **) entry) = NULL;
          *((s32 *) ((char *) entry + 4)) = 0;
          entry = next;
        }
      }
      else
      {
        entry = next;
      }
    } while (entry != NULL);
  }
  cacheTableIndex = 0;
  cacheTick += 1;
}
