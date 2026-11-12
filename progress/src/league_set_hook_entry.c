/* Looks up table entry (index & 0xFFFF) at ctx+0x10 (0x14-byte entries) and scans
 * its records (12 bytes: key at 0, flag byte at 4, value at 8). The first record
 * with key == key and a clear flag gets value stored in its value field. */
void league_set_hook_entry(void *ctx, s32 index, s32 key, s32 value)
{
  char *entry;
  char *rec;
  char *val;
  s32 i;
  s32 key_copy;

#ifdef PORT
  entry = *((char **) (((char *) ctx) + 0x10)) + ((index & 0xFFFF) * 0x14);
#else
  entry = (*((s32 *) (((char *) ctx) + 0x10))) + ((index & 0xFFFF) * 0x14);
#endif
  key_copy = key;
  rec = *((char **) (((char *) entry) + 4));
  i = 0;
  if ((*((u8 *) (((char *) entry) + 0xF))) == 0)
  {
    goto done;
  }
  val = rec + 8;
  scan:
  if ((*(s32 *)rec) == key_copy)
  {
    goto check_flag;
  }

  i += 1;
  goto next_rec;
  check_flag:
  if ((*((s8 *) (((char *) val) + (-4)))) == 0)
  {
    goto store;
  }

  i += 1;
  goto next_rec;
  store:
  *((s32 *) (((char *) val) + 0)) = value;

  return;
  next_rec:
  val += 0xC;

  rec += 0xC;
  if (((u32) (i & 0xFFFF)) < ((u8) (*((u8 *) (((char *) entry) + 0xF)))))
  {
    goto scan;
  }
  done:
  return;

}
