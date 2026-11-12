extern void *gRecords;
/* Copies a value from the linked sub-record into obj+0x7A, adding 4 when the global mode word is 2. */ void func_8003BA9C(void *obj)
{
  s32 value;
  u16 *modePtr;
  void *link;
  link = *((void **) (((s8 *) (*((void **) (((s8 *) obj) + 0xA8)))) + 0x24));
  if (link != NULL)
  {
    modePtr = (u16 *) (((s8 *) gRecords) + 0xE);
    value = *((s32 *) (((s8 *) (*((void **) (((s8 *) link) + 0x5C)))) + 0x60));
    *((s16 *) (((s8 *) obj) + 0x7A)) = (s16) value;
    if ((*modePtr) == 2)
    {
      *((s16 *) (((s8 *) obj) + 0x7A)) = (s16) (value + 4);
    }
  }
}
