/* Inflate state lives in one block of globals; these are its fields. */
#define INFLATE_TL (*(s32 *)(stream_state + 0x30FA))
#define INFLATE_TD (*(s32 *)(stream_state + 0x30FE))
#define INFLATE_BL (*(s32 *)(stream_state + 0x3102))
#define INFLATE_BD (*(s32 *)(stream_state + 0x3106))

extern s32 inflate_codes(s32, s32, s32, s32);
extern s32 huft_build(s32 *, s32, s32, void *, void *, s32 *, s32 *);
extern void huft_free(s32);
extern u8 cplens[];
extern u8 cplext[];
extern u8 cpdist[];
extern u8 cpdext[];
extern u8 stream_state[];

/* Inflates one block with the fixed Huffman codes (RFC 1951 3.2.6). Builds the
 * literal/length and distance tables on first use, then decodes the block. */
s32 inflateFixedBlock(void)
{
  s32 lengths[0x120];
  u8 *bdSlot;
  s32 fillLen;
  s32 fillValue;
  s32 i;
  s32 *lenp;
  s32 *blSlot;

  if (INFLATE_TL == 0)
  {
    fillValue = 8;
    i = 0x8f;
    lenp = &lengths[0x8f];
    do
    {
      lengths[i] = fillValue;
    }
    while ((--i) >= 0);
    for (i = 0x90; i < 0x100; i++)
    {
      lengths[i] = 9;
    }

    for (; i < 0x118; i++)
    {
      lengths[i] = 7;
    }

    for (; i < 0x120; i++)
    {
      lengths[i] = 8;
    }

    blSlot = (s32 *) (stream_state + 0x3102);
    *blSlot = 7;
    i = huft_build(lengths, 0x120, 0x101, cplens, cplext, blSlot - 2, blSlot);
    if (i)
    {
      *((s32 *) (blSlot - 2)) = 0;
      return i;
    }
    fillLen = 5;
    for (lenp = lengths; i < 0x1e; i++, lenp++)
    {
      *lenp = fillLen;
    }

    bdSlot = stream_state + 0x3106;
    ;
    *((s32 *) bdSlot) = 5;
    i = huft_build(lengths, 0x1e, 0, cpdist, cpdext, ((s32 *)bdSlot) - 2, (s32 *)bdSlot);
    if (i >= 2)
    {
      huft_free(INFLATE_TL);
      INFLATE_TL = 0;
      return i;
    }
  }
  i = inflate_codes(INFLATE_TL, INFLATE_TD, INFLATE_BL, INFLATE_BD);
  return i != 0;
}
