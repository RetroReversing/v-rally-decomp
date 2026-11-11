extern int gStringEntryCount;
extern int D_800B7318;
extern int D_800B7320;
extern unsigned short D_800C336A;
extern unsigned short D_800C3368;
extern int D_800C3354;
extern int inflateState;
extern int D_800C3340;
extern void * volatile gStreamSeekPos;
s32 copyStringAligned();

/* Claims the next slot in the 0x2C-byte string entry table, copies `name` into
 * it and fills in the entry's default fields. Returns the new entry. */
char *func_80082438(s32 name)
{
  s32 index;
  char *entry;
  index = gStringEntryCount;
  gStringEntryCount = index + 1;
  entry = (char *)D_800B7318 + index * 0x2C;
  copyStringAligned(entry, name);
  *(s32 *)(entry + 0x10) = D_800B7320;
  *(s32 *)(entry + 0x14) = *((s32 *)gStreamSeekPos + 1);
  *(u16 *)(entry + 0x1A) = D_800C336A;
  *(u16 *)(entry + 0x18) = D_800C3368;
  *(s32 *)(entry + 0x1C) = D_800C3354;
  *(s32 *)(entry + 0x28) = inflateState;
  *(s32 *)(entry + 0x24) = D_800C3340;
  *(s32 *)(entry + 0x20) = *(s32 *)gStreamSeekPos;
  return entry;
}
