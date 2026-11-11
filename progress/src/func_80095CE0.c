s32 osDisableInt();
s32 osRestoreInt();
s32 func_80091920();
extern void *D_800A255C;
extern char gOrderState[];
extern char gStreamState[];

/* Initialises the record at gStreamState+0x5D5E (type 2, status 0xA5000000, and the fields
 * that follow), sets up its 0x60-byte block, links it as the head of D_800A255C, stores it
 * at gOrderState+0x72A8, and returns it. */
void *func_80095CE0(void)
{
  char *slot;
  s32 handle;
  char *link;
  s32 temp_a0;
  void *node;
  void *rec;
  void *prevHead;
  rec = gStreamState + 0x5D5E;
  prevHead += 0;
  *((s8 *) (gStreamState + 0x5D5E)) = 2;
  *((s32 *) (gStreamState + 0x5D66)) = 0xA5000000;
  *((s8 *) (gStreamState + 0x5D5F)) = 3;
  *((s8 *) (gStreamState + 0x5D62)) = 6;
  *((s8 *) (gStreamState + 0x5D60)) = 6;
  *(gStreamState + 0x5D61) = 2;
  *((s8 *) (gStreamState + 0x5D63)) = 1;
  *((s32 *) (gStreamState + 0x5D6A)) = 0;
  func_80091920(rec + 0x10, 0x60);
  node = rec - 4;
  handle = osDisableInt();
  prevHead = D_800A255C;
  temp_a0 = handle;
  D_800A255C = node;
  link = ((char *) rec) + (-4);
  *((void **) (slot = gOrderState + 0x72A8)) = node;
  *((void **) link) = prevHead;
  osRestoreInt(temp_a0);
  return node;
}
