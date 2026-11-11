typedef struct 
{
  s32 w[4];
} SortKeys4;
typedef struct 
{
  u32 w[5];
} SortKeys;
typedef struct 
{
  s32 v;
} __attribute__((packed)) SortVal;
extern u8 gOrderState[];
extern u8 *gRecords;

/* Copies the 4 sort keys stored at gOrderState+0x7DB0 into `keys` (slot 4 is zeroed) and the matching
 * record value (+0x44 of the record at gRecords + 40 * recIdx) into `vals`. Then bubble-sorts both
 * arrays together by key, ascending. */
void func_80052CF4(SortKeys *keys, SortVal *vals)
{
  u32 i;
  s32 changed;
  SortVal tmp;
  u32 x;
  u32 y;
  *((SortKeys4 *) keys) = *((SortKeys4 *) (gOrderState + 0x7DB0));
  keys->w[4] = 0;
  for (i = 0; i < 4; i++)
  {
    vals[i] = *((SortVal *) ((gRecords + (*(gRecords + i + 0x32) * 40)) + 0x44));
  }

  do
  {
    changed = 0;
    for (i = 4; i != 0; i--)
    {
      x = keys->w[i];
      y = keys->w[i - 1];
      if (y < x)
      {
        keys->w[i] = y;
        keys->w[i - 1] = x;
        tmp = vals[i];
        vals[i] = vals[i - 1];
        vals[i - 1] = tmp;
        changed = 1;
      }
    }

  }
  while (changed);
}
