void *poolAlloc();
extern s32 gRaceFlags;

/* Resets the two slot lists of the race object (at +0x3C and +0x68). When the
 * first list is still empty, allocates its table of six 12-byte slots (value
 * 0xFF at +4, 0 at +8) and links the table into both lists. */
void initRaceSlots(void *race)
{
  s32 idx;
  s32 i;
  void *table;
  void **head;

  *((s32 *) (((char *) (*((void **) (((char *) race) + 0x68)))) + 0x1C)) = 0;
  *((s32 *) (((char *) (*((void **) (((char *) race) + 0x3C)))) + 0x1C)) = 0;
  *((s32 *) (((char *) (*((void **) (((char *) race) + 0x68)))) + 4)) = 1;
  *((s32 *) (((char *) (*((void **) (((char *) race) + 0x3C)))) + 4)) = 1;
  *((s32 *) (((char *) (*((void **) (((char *) race) + 0x68)))) + 8)) = 0;
  *((s32 *) (((char *) (*((void **) (((char *) race) + 0x3C)))) + 8)) = 0;
  head = (void **) (((char *) (*((void **) (((char *) race) + 0x3C)))) + 0);
  gRaceFlags = 0;
  if ((*head) == NULL)
  {
    table = poolAlloc(1, 0x48);
    i = 0;
    do
    {
      idx = i & 0xFF;
      i += 1;
      ;
      *((s32 *) (((char *) ((idx * 0xC) + table)) + 4)) = 0xFF;
      *((s8 *) (((char *) ((idx * 0xC) + table)) + 8)) = 0;
    }
    while (((u32) (i & 0xFF)) < 6U);
    *((s32 *) (((char *) table) + 0)) = 1;
    *((s32 *) (((char *) table) + 0xC)) = 7;
    *((s32 *) (((char *) table) + 0x18)) = 0x1C;
    *((s32 *) (((char *) table) + 0x24)) = 2;
    *((s32 *) (((char *) table) + 0x30)) = 6;
    *((s32 *) (((char *) table) + 0x3C)) = 0x1D;
    *((void **) (((char *) (*((void **) (((char *) race) + 0x3C)))) + 0)) = table;
    *((void **) (((char *) (*((void **) (((char *) race) + 0x68)))) + 0)) = table;
  }
}
