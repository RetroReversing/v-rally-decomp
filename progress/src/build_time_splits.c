extern char stream_state[];

/* Builds the split-time buffer for one record. Words 0-3 of the buffer come from
   the record's header fields; the remaining words hold the per-split times, which
   are nudged up or down 10% by the difficulty setting. The owner's result block
   then gets the total time and fixed flags. */
void build_time_splits(char *rec, char *owner)
{
  s32 *out;
  s32 *result;
  u32 i;
  s32 split_count;
  u32 split_time;
  char *settings;
  s32 *prev_out;
  s32 saved;
  s32 q;
  int unused_stride;
  char *cur;

  out = *((s32 **) (owner + 0x78));
  result = *((s32 **) (owner + 0x20));
  *((s32 *) (((char *) out) + 0x60)) = *((s32 *) (rec + 0x90));
  out[0] = *((s32 *) (rec + 0xDC));
  out[1] = *((s32 *) (rec + 0x128));
  out[2] = (*((s32 *) (rec + 0x174))) >> 2;
  out[3] = *((s32 *) (rec + 0x1C0));
  for (i = 4; i < 0x18; i++)
  {
    out[i] = 0;
  }

  i = 1;
  ;
  if (((out[1] - out[0]) / 1000) != 0)
  {
    settings = *((char **) (stream_state + 0x32F2));
    cur = rec + 0x4C;
    unused_stride = 0x1C0;
    do
    {
      prev_out = out;
      split_time = ((struct { u32 v; char pad[0x48]; } *)(rec + 0x90))[i + 4].v;
      if (i >= 5)
      {
        {
          split_count = *((u16 *) (settings + 0x16));
          switch (split_count)
          {
            case 0:
              split_time -= split_time / 10;
              break;

            case 1:
              break;

            case 2:
              split_time += split_time / 10;
              break;

          }

        }
      }
      out[i + 4] = split_time;
      cur += 0x4C;
      i++;
      q = (out[1] - prev_out[0]) / 1000;
    }
    while (((u32) ((out[1] - out[0]) / 1000)) >= i);
  }
  saved = out[0];
  result[0] = 0;
  result[2] = 0;
  result[5] = 0x10;
  result[1] = saved;
}
