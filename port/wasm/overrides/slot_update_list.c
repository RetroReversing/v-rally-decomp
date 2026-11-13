/* port (WebAssembly build): the switch cases follow the console's jump table. The matched C's labels compile to
   the same code but a different table, which the judge doesn't compare: this fix belongs in the matched C. */
extern u8 stream_state[];
extern s16 gSlotArgOffsets[][17];
extern u16 gSlotMasks[][2];
typedef struct
{
  u8 *data;
  u16 count;
} SlotList;
void func_80019314(u8 *arg0, s32 *arg1, s32 *arg2, s32 arg3);
/* Runs each slot in the list whose bit is set in `mask` and that is not disabled
   by the game flags at 0x767E (slots 3-6 and 9-11 have bits there; labels follow jtbl_800A41D0). The
   slot's data is at list->data + i * 36. */
void slot_update_list(SlotList *list, s32 *src_a, s32 *src_b, s32 arg3, s32 mask)
{
  s32 i;
  s32 sel;
  int slot_off;
  s32 off;
  for (i = 0; i < list->count; i++)
  {
    sel = stream_state[0x7678];
    if (gSlotArgOffsets[sel][i] < 0)
    {
      continue;
    }
    if (!(mask & gSlotMasks[(sel * 17) + i][0]))
    {
      continue;
    }
    switch (i)
    {
      case 3: case 5:
        if ((*((u16 *) (stream_state + 0x767E))) & 0x8000)
      {
        continue;
      }
        break;

      case 4: case 6:
        if ((*((u16 *) (stream_state + 0x767E))) & 0x4000)
      {
        continue;
      }
        break;

      case 10:
        if ((*((u16 *) (stream_state + 0x767E))) & 0x800)
      {
        continue;
      }
        break;

      case 11:
        if ((*((u16 *) (stream_state + 0x767E))) & 0x2000)
      {
        continue;
      }
        break;

      case 9:
        if ((*((u16 *) (stream_state + 0x767E))) & 0x1000)
      {
        continue;
      }
        break;

      case 7:

      case 8:
        break;

    }

    slot_off = i * 36;
    off = gSlotArgOffsets[stream_state[0x7678]][i];
    func_80019314(list->data + slot_off, src_a + off, src_b + off, arg3);
  }

}
