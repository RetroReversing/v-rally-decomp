extern u8 *gRecords;
extern u8 gOrderState[];

/* Returns the rank (0..3) of entry `slot` in the 4-entry time table of the
   current record row (gOrderState+0x7E08, 16 bytes per row). Rank 0 is the
   fastest time: each entry slower than slot lowers the rank by one. */
u8 func_80078338(u8 slot)
{
  u8 i;
  u8 n;
  u32 *tbl;

  n = 4;
  tbl = (u32 *) (gOrderState + 0x7E08 + *(u16 *) (gRecords + 0x20) * 16);
  i = 0;
  do {
    if (tbl[slot] < tbl[i]) {
      n--;
    }
    i++;
  } while (i < 4);
  return n - 1;
}
