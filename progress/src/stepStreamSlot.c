extern u8 gStreamState[];
extern s32 slot_set_selected(s32, s32);

/* Steps the stream's selected-slot counter (byte 0x30 of the object at 0x32F2) down
 * by one, wrapping to 9 from zero, then selects that slot for arg. */
s32 stepStreamSlot(s32 slot)
{
  u8 *obj = *((u8 **) (gStreamState + 0x32F2));
  u8 **cur;
  u32 count = obj[0x30];
  s32 next;
  if (((u8) count) != 0)
  {
    if (((u8) count) < 2)
    {
      goto skip;
    }
    next = count;
    next = next;
    next = next - 1;
  }
  else
  {
    next = 9;
  }
 do { obj[0x30] = next; } while (0);
  cur = (u8 **) (gStreamState + 0x32F2);
  skip:
  slot_set_selected(slot, (*cur)[0x30]);

  return 0;
}
