extern char gStreamState[];
extern void *gSelectState;
void *list_advance(u32, void *);

/* Sets the highlight colour (RGB 50,50,50 with alpha 100) on the sub-entry at index arg0 of the
 * selected menu item's entry list. Does nothing if no entry has that index. */
void text_obj_highlight(s32 arg0)
{
  u8 *entry;
  u8 *item;
  u32 index;

  item = list_advance(*((u16 *) ((*((u8 **) (gStreamState + 0x32F2))) + 0x20)), (void *)(*((void **) (((char *) gSelectState) + 0xC))));
  entry = *((u8 **) (item + 0x28));
  index = 0;
  if (item[0x4C] != index)
  {
    index = index;
    do
    {
      if ((index & 0xFF) == (arg0 & 0xFF))
      {
        entry[0xB] = 0x32;
        entry[0xC] = 0x32;
        entry[0xD] = 0x32;
        entry[0xE] = 0x64;
        return;
      }
      entry = *((u8 **) entry);
      index++;
    }
    while ((index & 0xFF) < item[0x4C]);
  }
}
