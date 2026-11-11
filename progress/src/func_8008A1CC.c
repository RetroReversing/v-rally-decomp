void *findRecordByRange();

/* Finds the record for id in the table (20-byte records, base id at +0xD) and then the
 * 12-byte item in its group whose key matches and whose owner byte is 0; sets that item's
 * value word to value. Does nothing if no item matches. */
void func_8008A1CC(s32 table, s32 id, s32 key, s32 value)
{
  char *item;
  s32 idx;
  u32 count;
  void *group;
  volatile int pad;
  void *rec;
  void *valueSlot;
  idx = id & 0xFFFF;
  rec = findRecordByRange(table, idx);
  group = (*((s32 *) (((char *) rec) + 8))) + ((idx - (*((u8 *) (((char *) rec) + 0xD)))) * 0xC);
  item = *((s32 **) (((char *) group) + 4));
  count = 0;
  if ((*((u8 *) (((char *) group) + 8))) != 0)
  {
    valueSlot = item + 8;
    loop_2:
    count += 1;

    if (((*((s32 *) item)) == key) && ((*((s8 *) (((char *) valueSlot) + (-4)))) == 0))
    {
      *((s32 *) (((char *) valueSlot) + 0)) = value;
      return;
    }
    valueSlot += 0xC;
    item += 0xC;
    if (count >= ((u8) (*((u8 *) (((char *) group) + 8)))))
    {
    }
    else
    {
      goto loop_2;
    }
  }
}
