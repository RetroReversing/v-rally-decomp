extern u8 stream_state[];
extern u8 *gRecords;
extern u8 *gSlotTableB;
extern u16 D_800C5D38[];
extern u8 D_800C7125[];
extern f64 D_800A58A8;
extern f64 D_800A58B0;
extern f64 D_800A58B8;
u8 func_8006B9E0(u8, u8);
s32 func_8006B924(void *, int);

/* Fills the lookup cells in D_800C7125 for the car's record: three rows, each
 * stepping through 256 entries. Every cell is written from the row's value
 * (its bound check picks the high or low bits), and the cell's delta is
 * clamped to 0..1022 with its sign in bit 0. */
long build_glyph_lookup(void)
{
  f64 bound = D_800A58A8;
#ifdef PORT
  u8 *rec = gRecords;
  s32 code = 0;
#else
  s32 code = (s32)gRecords;
#endif
  u8 *tab = D_800C7125;
  s32 i = 0;
#ifdef PORT
  u8 *base = *(u8 **)0x800D0634 + (rec[0x21] * 0x2c4);
#else
  u8 *base = *(u8 **)0x800D0634 + (((u8 *)code)[0x21] * 0x2c4);
#endif
  u32 idx;
  u32 x;
  s32 raw;
  u32 idx2;
  s16 nibble_sel;
  s32 delta;
  s32 stride;
  f64 base_val;
  int bit40;
#ifdef PORT
  code = func_8006B9E0(rec[0x21], rec[0x23]);
#else
  code = func_8006B9E0(((u8 *)code)[0x21], ((u8 *)code)[0x23]);
#endif
  stride = gRecords[0x23] * 64;
  idx = (u8) code;
  idx2 = idx * 2;
  base_val = ((f64) ((s32) idx)) * D_800A58B0;
  bit40 = 0x40;
  loop:
  {
    {
      f64 value = base_val + (((f64) (i & 255)) * D_800A58B8);
      if (!(bound <= value))
      {
        raw = (s32) value;
      }
      else
      {
        raw = ((s32) (value - bound)) | 0x80000000;
      }
      x = raw;
    }
    nibble_sel = ((idx * 36) + ((i & 255) * 12)) - (((u8) x) * 8);
    { s32 off16;
    code = func_8006B924((base + (stride + 0x2c)) + (off16 = (i & 255) * 16), i & 255); }
    if (((u8) code) == 5)
    {
      if ((u8) nibble_sel)
      {
 do { tab[((u8) x) + 1] = 255; tab[(u8) x] |= 0xf0; } while (0);
      }
      else
      {
        do { tab[(u8) x] = 255; tab[((u8) x) + 1] |= 15; } while (0);
      }
    }
    else
    {
      if (code)
      {
        delta = (*((u16 *) (((u8 *) D_800C5D38) + idx2))) - (*((s32 *) ((char *) ((base + (((i & 255) * 16) + stride)) + 0x2c))));
      }
      else
      {
        delta = (*((u16 *) (((u8 *) D_800C5D38) + idx2))) - (*((s32 *) ((char *) ((base + (((i & 255) * 16) + stride)) + 0x2c))));
      }
      if (delta >= 0)
      {
        if (delta >= 1024)
        {
          delta = 1022;
        }
        delta &= ~1;
      }
      else
      {
        delta = -delta;
        if (delta >= 1024)
        {
          delta = 1022;
        }
        delta |= 1;
      }
      if ((u8) nibble_sel)
      {
        switch ((u8) code)
        {
          case 0:
            tab[(u8) x] &= 0xcf;
            break;

          case 1:
            nibble_sel = (tab[(u8) x] = (tab[(u8) x] | 0x10) & 0xdf);
            break;

          case 2:
            tab[(u8) x] = (tab[(u8) x] & 0xef) | 0x20;
            break;

          case 3:
            tab[(u8) x] |= 0x30;
            break;

        }

        if (delta & 1)
        {
          tab[(u8) x] |= bit40;
        }
        else
        {
          tab[(u8) x] &= 0xbf;
        }
        if (delta & 2)
        {
          tab[(u8) x] |= 0x80;
        }
        else
        {
          tab[(u8) x] &= 0x7f;
        }
        tab[((u8) x) + 1] = delta >> 2;
      }
      else
      {
        switch ((u8) code)
        {
          case 0:
            tab[((u8) x) + 1] &= 0xf3;
            break;

          case 1:
            tab[((u8) x) + 1] = (tab[((u8) x) + 1] | 4) & 0xf7;
            break;

          case 2:
            tab[((u8) x) + 1] = (tab[((u8) x) + 1] & 0xfb) | 8;
            break;

          case 3:
            tab[((u8) x) + 1] |= 12;
            break;

        }

        if (delta & 0x100)
        {
          tab[((u8) x) + 1] |= 1;
        }
        else
        {
          tab[((u8) x) + 1] &= 0xfe;
        }
        if (delta & 0x200)
        {
          tab[((u8) x) + 1] |= 2;
        }
        else
        {
          tab[((u8) x) + 1] &= 0xfd;
        }
        tab[(u8) x] = delta;
      }
    }
    i++;
  }

  if (((u32) (i & 255)) < 3)
  {
    goto loop;
  }
}
