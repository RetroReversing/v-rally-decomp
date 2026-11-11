/* Scans the entry list at owner+0x68 (count at owner+0x50). Each 8-byte entry holds
 * a group pointer and an index at +4; a group's items sit at +0x1C with a stride of
 * (size + 8). Marks the first item of type 1 as type 6 and stops after that one hit. */
void func_8004D414(void *owner)
{
  u16 itemIdx;
  u16 entIdx;
  int done;
  u16 found;
  u8 *entries;
  u8 *item;
  u8 *ent;
  u8 *group;
  u32 count;
  count = *((u32 *) (((u8 *) owner) + 0x50));
  if (count != 0)
  {
    found = (entIdx = 0);
    entries = *((u8 **) (((u8 *) owner) + 0x68));
    done = (*((u32 *) (((u8 *) owner) + 0x50))) == 0;
    if (done)
    {
      return;
    }
    do
    {
      ent = (u8 *)(((entIdx & 0xffff) * 8) + (s32)entries);
      if ((*((s16 *) (ent + 4))) == 0)
      {
        group = *((u8 **) ent);
        itemIdx = 0;
        item = group + 0x1c;
        if ((((u32) (*((s16 *) (ent + 4)))) < (*((u16 *) (group + 0x18)))) && (!found))
        {
          do
          {
            if ((*((u16 *) item)) == 1)
            {
              found = 1;
              *((u16 *) item) = 6;
            }
            itemIdx++;
            item += (*((s32 *) (item + 4))) + 8;
          }
          while ((((u32) (itemIdx & 0xffff)) < (*((u16 *) (group + 0x18)))) && (!found));
        }
      }
      entIdx++;
    }
    while ((((u32) (entIdx & 0xffff)) < (*((u32 *) (((u8 *) owner) + 0x50)))) && (!found));
  }
}
