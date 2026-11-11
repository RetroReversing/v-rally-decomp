/* Checksums a 14-word block: sum of the words and sum of their complements. */
static inline static static static void checksum(u16 *p, u16 *sum, u16 *inv)
{
  u16 *end = p + 14;
  *inv = 0;
  *sum = 0;
  do
  {
    u16 v = *(p++);
    *sum += v;
    *inv += ~v;
  }
  while (p < end);
}

s32 __osPfsSelectBank(void *, s32);
s32 __osContRamRead(s32, s32, u16, u16 *);
s32 __osContRamWrite(s32, s32, u16, u16 *, s32);

/* Checks the controller pak ID block. Four copies live in the pak at the page numbers in
   banks[]; the first copy whose checksum matches the stored words at buf[14]/buf[15] is
   the good one, and it is then written back over the other copies. Returns 0 on success,
   10 if no copy is valid, or the error from a failed read or write. */
s32 __osCheckPackId(void *pfs, u16 *buf)
{
  u16 banks[4];
  u16 sum;
  u16 inv;
  s32 ret;
  s32 bad_copy;
  s32 i;
  u16 *page;
  u16 *write_page;
  s32 err;
  u16 sum_copy;
  u16 inv_copy;
  int write_flag;
  int last_page;
  int bad_id;

  if (((*((u8 *) (((s8 *) pfs) + 0x65))) == 0) || ((ret = __osPfsSelectBank(pfs, 0)) == 0))
  {
    bad_copy = 1;
    page = &banks[1];
    banks[0] = 1;
    banks[1] = 3;
    last_page = 6;
    banks[2] = 4;
    banks[3] = last_page;
    loop_3:
    ret = __osContRamRead(*((s32 *) (((s8 *) pfs) + 4)), *((s32 *) (((s8 *) pfs) + 8)), *page, buf);

    if (ret == 0)
    {
      do
      {
        checksum(buf, &sum, &inv);
        sum_copy = sum;
      }
      while (0);
      inv_copy = inv;
      bad_id = 10;
      if (((*((u16 *) (((s8 *) buf) + 0x1c))) != (sum_copy & 0xffff)) || ((*((u16 *) (((s8 *) buf) + 0x1e))) != (inv_copy & 0xffff)))
      {
        do
        {
          bad_copy++;
        }
        while (0);
        page++;
        if (bad_copy >= 4)
        {
          goto block_10;
        }
        goto loop_3;
      }
      block_10:
      i = 0;
      if (bad_copy == 4)
      {
        return bad_id;
      }

      write_flag = 1;
      write_page = &banks[0];
      for (i = 0; i < 4; i++, write_page++)
      {
        if (i != bad_copy)
        {
          err = __osContRamWrite(*((s32 *) (((s8 *) pfs) + 4)), *((s32 *) (((s8 *) pfs) + 8)), *write_page, buf, write_flag);
          if (err != 0)
          {
            return err;
          }
        }
      }

      return 0;
    }
    return ret;
  }
  return ret;
}
