s32 getTexturePack();

/* Copies the car's saved fields (at +0x128, +0x174, ... in steps of 0x4C) into the record block of each
 * node in the list starting at node. Each node's block is at offset slot*4 from its first word.
 * Also stores a texture pack handle in the node's entry at +0x1C. */
void carSaveToSlot(void *car, void *node, s32 slot)
{
  s32 slotOffset;
#ifdef PORT
  void *base;
#else
  s32 base;
#endif
  void *entry;
  void *block;
  s32 handle;
  if (node != NULL)
  {
    slotOffset = (slot & 0xFF) * 4;
    do
    {
#ifdef PORT
      base = *(*((void ***) (((char *) node) + 0x38)));
#else
      base = (s32) *(*((void ***) (((char *) node) + 0x38)));
#endif
      handle = getTexturePack(car + 0x98, 0);
#ifdef PORT
      entry = (void *) (((char *) base) + slotOffset);
#else
      entry = (void *) (slotOffset + base);
#endif
      *((s32 *) (((char *) entry) + 0x1C)) = handle;
      *((s16 *) (((char *) (*((void **) (((char *) entry) + 0x38)))) + 0)) = (s16) (*((s32 *) (((char *) car) + 0x128)));
      *((s16 *) (((char *) (*((void **) (((char *) entry) + 0x38)))) + 2)) = (s16) (*((s32 *) (((char *) car) + 0x174)));
      *((s8 *) (((char *) (*((void **) (((char *) entry) + 0x38)))) + 4)) = (s8) (*((s32 *) (((char *) car) + 0x1C0)));
      *((s8 *) (((char *) (*((void **) (((char *) entry) + 0x38)))) + 5)) = (s8) (*((s32 *) (((char *) car) + 0x20C)));
      *((s8 *) (((char *) (*((void **) (((char *) entry) + 0x38)))) + 6)) = (s8) (*((s32 *) (((char *) car) + 0x258)));
      *((s16 *) (((char *) (*((void **) (((char *) entry) + 0x38)))) + 8)) = (s16) (*((s32 *) (((char *) car) + 0x2A4)));
      *((s16 *) (((char *) (*((void **) (((char *) entry) + 0x38)))) + 0xA)) = (s16) (*((s32 *) (((char *) car) + 0x2F0)));
      *((s16 *) (((char *) (*((void **) (((char *) entry) + 0x38)))) + 0xC)) = (s16) (*((s32 *) (((char *) car) + 0x33C)));
      node = *((void **) (((char *) node) + 4));
    }
    while (node != NULL);
  }
}
