extern s32 D_800AFA54;
extern u32 D_800AB974;
extern u8 D_800AB973;
extern char gGameState[];
extern char gOrderState[];

/* Records the new owner in D_800AFA54 and, while fewer than 3 objects are registered, puts obj
   in the first empty slot of the 4-entry slot ring at gGameState+0x4598, starting from
   D_800AB973. A placed object gets its flag byte at +8 cleared. */
void voice_queue_add(void *obj, s32 owner)
{
  s32 placed;
  u32 tries;
  int slot_idx;
  void **slot;
  u32 next;
  s32 more_tries;
  s32 keep_going;
  D_800AFA54 = owner;
  if (D_800AB974 < 3U)
  {
    placed = 0;
    slot_idx = D_800AB973;
    tries = 1;
    do
    {
      slot = ((void **) (gGameState + 0x4598)) + (slot_idx & 0xFF);
      tries += 1;
      if ((*slot) == NULL)
      {
        placed = 1;
        owner = D_800AB974;
        *slot = obj;
        D_800AB974 = owner + 1;
        *((s8 *) (((char *) obj) + 8)) = 0;
      }
      next = slot_idx + 1;
      slot_idx = next & (-((next & 0xFF) < 4U));
      keep_going = placed ^ 1;
      more_tries = (tries & 0xFF) < 4U;
    }
    while ((keep_going & more_tries) != 0);
  }
}
