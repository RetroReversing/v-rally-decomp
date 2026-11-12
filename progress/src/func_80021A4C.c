extern char *gRecords;
extern char stream_state[];

/* For the first four slots, adds the car's per-tick distance (the value at +0x84 of the
   object at +0x88, divided by 9000) to the u16 at +0x52 of the slot's gRecords entry. */
void func_80021A4C(void *car)
{
  s32 slot;
  s32 delta;
  void *entry;

  slot = *(*((s32 **) (((char *) car) + 0x48)));
  if (slot < 4)
  {
    delta = (*((s32 *) (((char *) (*((void **) (((char *) car) + 0x88)))) + 0x84))) / 9000;
    entry = gRecords + ((*((u8 *) (((char *) (gRecords + slot)) + 0x32))) * 0x28);
    *((u16 *) (((char *) entry) + 0x52)) += delta;
  }
}
