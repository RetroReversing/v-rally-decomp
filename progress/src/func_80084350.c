#define D_800B7300 (*(s32 *)0x800B7300)
#define PKT D_800B0BA8
extern u32 D_800C3338;
extern u32 inflateState;
extern s32 D_800C3340;
extern s32 D_800C3354;
extern u8 gStreamState;
extern u8 gOrderState;
typedef struct 
{
  s32 w[6];
} Pkt6;
extern Pkt6 D_800B0BA8;
extern void dmaCopyChunks(s32, s32, s32, Pkt6);
extern void streamReadBytes(void *, s32);
extern s16 readU16LE(void *);
extern s32 readU32LE(void *);
extern s32 strncmp(s32, void *, s32);
static inline int inline_fn(s32 *arg0, int arg1, s32 *arg2)
{
  return arg0[arg1] - arg2[-1];
}

/* Scans the save buffer backwards for the 0x50 record marker in 0x2000-byte blocks,
   starting from the saved write position, and stores the search result (and the
   header fields it reads) into the globals at gStreamState. Returns 0. */
s32 func_80084350(s32 size)
{
  u8 hdr[0x16];
  s32 *pos_ptr = (s32 *) ((&gStreamState) + 0x30A2);
  s32 pos = *pos_ptr;
  s32 rem;
  s32 n;
  s32 blk;
  s32 found = 0;
  s32 *p;

  if (pos < 0x2001)
  {
    dmaCopyChunks(D_800B7300, D_800C3338, *pos_ptr, PKT);
    D_800C3340 = *pos_ptr;
    inflateState = (D_800C3338 + (*pos_ptr)) - 0x16;
    if (inflateState >= D_800C3338)
    {
      int marker = 0x50;
      pos_ptr = (s32 *) (((u8 *) pos_ptr) - 0x14);
      p = pos_ptr;
      for (;;)
      {
        if (((*(*((u8 **) ((&gStreamState) + 0x308E)))) == marker) && (strncmp(p[0], ((u8 *) p) + 0x26, 4) == 0))
        {
          p[1] -= inline_fn(p, 0, p);
          break;
        }
        p[0]--;
        if (((u32) p[0]) < ((u32) p[-1]))
        {
          break;
        }
      }

    }
  }
  else
  {
    rem = pos % 0x2000;
    if (rem >= 0x13)
    {
      dmaCopyChunks((D_800B7300 + *pos_ptr) - rem, *(u32 *)(&gStreamState + 0x308A), rem, PKT);
      D_800C3340 = rem;
      D_800C3354 = (*pos_ptr) - rem;
      inflateState = (D_800C3338 + rem) - 0x16;
      if (inflateState >= D_800C3338)
      {
        int marker = 0x50;
        pos_ptr = (s32 *) (((u8 *) pos_ptr) - 0x14);
        p = pos_ptr;
        for (;;)
        {
          if (((*(*((u8 **) ((&gStreamState) + 0x308E)))) == marker) && (strncmp(p[0], ((u8 *) p) + 0x26, 4) == 0))
          {
            found = 1;
            p[1] -= inline_fn(p, 0, p);
            break;
          }
          p[0]--;
          if (((u32) p[0]) < ((u32) p[-1]))
          {
            break;
          }
        }

      }
    }
    else
    {
      D_800C3354 = (*pos_ptr) - rem;
    }
    n = ((size - rem) + 0x1fff) / 0x2000;
    for (blk = 1; (!found) & (blk <= n); blk++)
    {
      s32 *q = (s32 *) ((&gStreamState) + 0x30A6);
      int marker;
      *q -= 0x2000;
      dmaCopyChunks(D_800B7300 + (*q), *((s32 *) (((u8 *) ((s32 *) ((&gStreamState) + 0x30A6))) - 0x1c)), 0x2000, PKT);
      marker = 0x50;
      *((s32 *) (((&gStreamState) + 0x30A6) - 0x18)) = (*((s32 *) (((&gStreamState) + 0x30A6) - 0x1c))) + 0x1fff;
      p = (s32 *) (((&gStreamState) + 0x30A6) - 0x18);
      if (((u32) p[0]) >= ((u32) p[-1]))
      {
        for (;;)
        {
          if (((*(*((u8 **) ((&gStreamState) + 0x308e)))) == marker) && (strncmp(p[0], ((u8 *) p) + 0x26, 4) == 0))
          {
            found = 1;
            p[1] -= inline_fn(p, 0, p);
            break;
          }
          p[0]--;
          if (((u32) p[0]) < ((u32) p[-1]))
          {
            break;
          }
        }
      }
    }
  }
  streamReadBytes(hdr, 0x16);
  *((s16 *) ((&gStreamState) + 0x30de)) = readU16LE((hdr + 10));
  *((s32 *) ((&gStreamState) + 0x30e6)) = readU32LE((hdr + 16));
  *((s32 *) ((&gStreamState) + 0x30e2)) = readU32LE((hdr + 12));
  return 0;
}
