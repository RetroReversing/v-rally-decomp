#define I(p,o) (*(u32 *)((u8*)(p)+(o)))
#define H(p,o) (*(u16 *)((u8*)(p)+(o)))
#define B(p,o) (*(u8 *)((u8*)(p)+(o)))
#ifdef PORT
#define UP(x) ((uintptr_t)(x))
#else
#define UP(x) ((u32)(x))
#endif
void strCpy(void *, s32, s32);
extern u8 D_8009D544;
extern u8 *gRecords;
/* Inserts a new record into the 16-byte entry table of the current group. The new entry
 * gets a weight taken from the record's length field, and the entries are kept in order
 * by sliding larger ones down with overlap-safe word copies. */
void func_80045404(u32 weight_in, u8 *recs, s8 kind, s32 payload, u8 flags, s32 slot)
{
  u32 saved[4];
  u8 *dst_rev;
  u8 *seg_end;
  u8 *src_end;
  u8 *src_fwd;
  u8 *src_rev;
  u8 *dst_end;
  u8 *src_fwd2;
  u8 *saved_end;
  u8 *dst_back;
  u8 *dst_fwd;
  u8 *dst_fwd3;
  u8 *src_back;
  u8 *group;
  u8 *cur;
  u8 *p;
  u8 *saved_base;
  u8 *dst_fwd_p;
  s32 ofs;
  s32 ofs_again;
  s32 left;
  s32 left2;
  s32 count_rev;
  s32 count_fwd;
  s32 count_last;
  u8 again = 1;
  s32 off;
  s32 pass;
  s32 cnt;
  u32 idx;
  u32 tmp_word;
  u32 tmp_word2;
  u32 tmp_word3;
  u32 rec_len;
  u32 rec_len2;
  u32 weight;
  u8 *hdr_p;
  void *entry;
  void *hdr;
  void *rec;
  weight = weight_in;
  idx = H(gRecords, 0x22);
  ofs = idx << 6;
  hdr = recs + ((int) (ofs + 0x2C));
  entry = hdr + 0x30;
  if (H(gRecords, 0x2C) & 0x4000)
  {
    rec = recs + ofs;
    if (B(rec, 0x38) != 0)
    {
      rec_len = I(rec, 0x2C);
      if (rec_len > (0xBU - 1))
      {
        weight = rec_len - 3;
      }
    }
    else
    {
      rec_len2 = I(rec, 0x2C);
      if (rec_len2 >= 0x1FU)
      {
        weight = rec_len2 - 0xA;
      }
    }
  }
  if (D_8009D544 == 0)
  {
    if (pass)
    {
      I(entry, 0) = (u32) (((u32) (weight * 3)) >> 1);
    }
    else
    {
      I(entry, 0) = (u32) (((u32) (weight * 3)) >> 1);
    }
  }
  else
  {
    I(entry, 0) = weight;
  }
  strCpy(entry + 6, payload, ofs);
  ofs_again = idx << 6;
  B(entry, 0xC) = 1;
  B(entry, 0x4) = kind;
  B(entry, 0x5) = flags;
  B(entry, 0xA) = (s8) slot;
  B(entry, 0xB) = (u8) B(recs + ofs_again, 0x37);
  if (again & 0xFF)
  {
    group = recs + (ofs_again + 0x2C);
    saved_end = (u8 *)(saved + 4);
    do
    {
      again = 0;
      pass = 3;
      p = group + 0x30;
      off = 0x20;
      loop_15:
      cur = group + off;

      if ((((u32) I(p, 0)) < ((u32) I(cur, 0))) ^ 0)
      {
        dst_fwd = (u8 *) saved;
        src_end = cur + 0x10;
        again = 1;
        if ((UP(dst_fwd) < UP(src_end)) & (UP(cur) < UP(dst_fwd)))
        {
          dst_rev = (u8 *)(saved + 4);
          left = 4;
          do
          {
            do
            {
              src_end -= 4;
              dst_rev -= 4;
              left -= 1;
              I(dst_rev, 0) = I(src_end, 0);
            }
            while (left != 0);
          }
          while (0);
          seg_end = p + 0x10;
        }
        else
        {
          src_fwd2 = cur;
          left2 = 4;
          do
          {
            tmp_word = I(src_fwd2, 0);
            src_fwd2 += 4;
            do
            {
              left2 -= 1;
              I(dst_fwd, 0) = tmp_word;
              dst_fwd += 4;
            }
            while (0);
          }
          while (left2 != 0);
          seg_end = p + 0x10;
        }
        if ((UP(cur) < UP(seg_end)) & (UP(p) < UP(cur)))
        {
          src_rev = seg_end;
          dst_end = cur + 0x10;
          count_rev = 4;
          do
          {
            src_rev -= 4;
            dst_end -= 4;
            count_rev -= 1;
            I(dst_end, 0) = I(src_rev, 0);
          }
          while (count_rev != 0);
        }
        else
        {
          src_fwd = p;
          dst_fwd3 = cur;
          count_fwd = 4;
          do
          {
            tmp_word2 = I(src_fwd, 0);
            src_fwd += 4;
            count_fwd -= 1;
            I(dst_fwd3, 0) = tmp_word2;
            dst_fwd3 += 4;
          }
          while (count_fwd != 0);
        }
        saved_base = (u8 *) saved;
        if ((UP(p) < UP(saved_end)) & (UP(saved_base) < UP(p)))
        {
          src_back = saved_end;
          dst_back = p + 0x10;
          count_last = 4;
          do
          {
            src_back -= 4;
            dst_back -= 4;
            count_last -= 1;
            I(dst_back, 0) = I(src_back, 0);
          }
          while (count_last != 0);
          p -= 0x10;
        }
        else
        {
          src_back = saved_base;
          dst_back = p;
          count_last = 4;
          do
          {
            tmp_word3 = I(src_back, 0);
            src_back += 4;
            count_last -= 1;
            I(dst_back, 0) = tmp_word3;
            dst_back += 4;
          }
          while (count_last != 0);
          goto block_36;
        }
      }
      else
      {
        block_36:
        p -= 0x10;

      }
      pass -= 1;
      off -= 0x10;
      if (pass != 0)
      {
        goto loop_15;
      }
    }
    while (again & 0xFF);
  }
}
