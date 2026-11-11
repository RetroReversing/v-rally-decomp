extern f64 D_800A5890;
extern f64 D_800A58A0;
extern f64 D_800A5898;
extern u8 *gRecords;
extern u8 *gSlotTableB[];
extern u16 D_800C5D9C[];
extern u8 gRecordPackets[];
extern s32 func_8006B924(u8 *);

/* Packs one group of three rows into the byte buffer gRecordPackets. Each column
 * gets a code from func_8006B924 and a level from D_800C5D9C; code 5 writes a
 * fixed pattern, other codes write the level as 2-bit flags plus a 10-bit
 * value. The group base depends on the table selected by gRecords[31]. */
void pack_tile_rows(void)
{
  s32 r;
  u8 n;
  s32 code;
  s32 q;
  f64 fs1;
  u8 *s6;
  u8 j;
  u8 i;
  u8 b;
  s32 k;
  u8 *out;
  s32 group_index;
  u16 *level;
  u16 *lookup_base;
  f64 conversion_bound;
  s32 raw;
  u8 *item;
  s32 row_product;
  b = gRecords[31];
  n = gRecords[35];
  s6 = gSlotTableB[b];
  j = 0;
  switch (b)
  {
    case 0:
      break;

    case 2:
      j = 4;
      break;

    case 3:
      j = 9;
      break;

    case 4:
      j = 15;
      break;

  }

  n += j;
  i = 0;
  conversion_bound = D_800A5890;
  group_index = n;
  fs1 = ((f64) group_index) * D_800A5898;
  lookup_base = D_800C5D9C;
  level = lookup_base + group_index;
packed_loop:
  {
    { f64 value = fs1 + (((f64)(i & 255)) * D_800A58A0);
      if (!(conversion_bound <= value)) raw = (s32)value;
      else raw = ((s32)(value - conversion_bound)) | 0x80000000U;
      j = raw;
    }
    row_product = group_index * 9;
    k = i & 255;
    q = (((k * 3) + row_product) * 4) - ((j & 255) * 8);
    item = (s6 + (((*((u16 *) (gRecords + 34))) << 6) + 44)) + (k * 16);
    do {
      code = func_8006B924(item);
    } while (0);
    out = gRecordPackets;
    if ((code & 255) == 5)
    {
      if (q & 255)
      {
        do {
        out[(j & 255) + 1] = 255;
        out[j & 255] |= 240;
        } while (0);
      }
      else
      {
        do {
        out[j & 255] = 255;
        out[(j & 255) + 1] |= 15;
        } while (0);
      }
    }
    else
    {
      r = *level - (*((s32 *) ((s6 + ((k * 16) + ((*((u16 *) (gRecords + 34))) << 6))) + 44)));
      if (r >= 0)
      {
        if (r >= 1024)
        {
          r = 1022;
        }
        r = r & (~1);
      }
      else
      {
        r = -r;
        if (r >= 1024)
        {
          r = 1022;
        }
        r = r | 1;
      }
      if (q & 255)
      {
        switch (code & 255)
        {
          case 0:
            out[j & 255] &= 207;
            break;

          case 1:
            out[j & 255] = (out[j & 255] | 16) & 223;
            break;

          case 2:
            out[j & 255] = (out[j & 255] & 239) | 32;
            break;

          case 3:
            out[j & 255] |= 48;
            break;

        }

        if (r & 1)
        {
          out[j & 255] |= 64;
        }
        else
        {
          out[j & 255] &= 191;
        }
        if (r & 2)
        {
          out[j & 255] |= 128;
        }
        else
        {
          out[j & 255] &= 127;
        }
        out[(j & 255) + 1] = r >> 2;
      }
      else
      {
        switch (code & 255)
        {
          case 0:
            out[(j & 255) + 1] &= 243;
            break;

          case 1:
            out[(j & 255) + 1] = (out[(j & 255) + 1] | 4) & 247;
            break;

          case 2:
            out[(j & 255) + 1] = (out[(j & 255) + 1] & 251) | 8;
            break;

          case 3:
            out[(j & 255) + 1] |= 12;
            break;

        }

        if (r & 256)
        {
          out[(j & 255) + 1] |= 1;
        }
        else
        {
          out[(j & 255) + 1] &= 254;
        }
        if (r & 512)
        {
          out[(j & 255) + 1] |= 2;
        }
        else
        {
          out[(j & 255) + 1] &= 253;
        }
        out[j & 255] = r;
      }
    }
    i++;
  }
  if ((i & 255) < 3) goto packed_loop;
}
