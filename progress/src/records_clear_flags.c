/* identical to func_8002EDF8 in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to records_clear_flags in V-RALLY (matched), with its names changed by decompdecomp */

/* Clears the s32 at +0x20 of each of count records, which are 0x24 bytes apart. */ void records_clear_flags(void *records, s32 count)
{
  s32 remaining;
  void *rec;
  rec = records;
  count = count;
  remaining = count;
  goto loop_2;
  block_1:
  *((s32 *) (((char *) rec) + 0x20)) = 0;

  rec += 0x24;
  remaining = count;
  loop_2:
  count -= 1;

  if (remaining != 0)
  {
    goto block_1;
  }
  return;
}
