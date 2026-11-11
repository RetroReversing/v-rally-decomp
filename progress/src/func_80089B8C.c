/* Updates one sequence group: calls the handler of each active member entry,
 * then the group's own handler. Groups are 0x14 bytes, members 0xC bytes. */
void func_80089B8C(u8 *group)
{
  u8 *grp;
  u8 idx;
  s32 slot;
  grp = (*((u8 **) (group + 0x10))) + ((*((s16 *) (group + 2))) * 0x14);
  idx = 0;
  if (grp[0xC] != 0)
  {
    do
    {
      ;
      if (((*((void (**)(s32, s32, s32)) ((*((u8 **) (grp + 8))) + (idx * 0xC)))) != NULL) && (((*((u8 **) (grp + 8))) + (idx * 0xC))[0xA] != 0))
      {
        slot = idx + grp[0xD];
        (*((void (**)(s32, s32, s32)) ((*((u8 **) (grp + 8))) + (idx * 0xC))))(slot == grp[0xE], slot, idx);
      }
      idx++;
    }
    while (idx < grp[0xC]);
  }
  if ((*((void (**)()) grp)) != NULL)
  {
    (*((void (**)()) grp))();
  }
}
