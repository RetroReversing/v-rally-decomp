typedef struct InflateState { u8 *ptr; s32 cnt; u8 pad8[0x74]; u32 wp; u32 bb; u32 bk; } InflateState;
extern InflateState inflateState;
extern s32 func_80082094(void);
extern s32 inflateStoredBlock(void);
extern s32 inflateFixedBlock(void);
extern s32 inflate_dynamic(void);

#define NEXTBYTE() (--inflateState.cnt >= 0 ? (s32)*inflateState.ptr++ : func_80082094())
#define NEEDBITS(n) { while (bitCount < (n)) { s32 c = NEXTBYTE(); if (c == -1) return 1; bitBuf |= ((u32)c) << bitCount; bitCount += 8; } }
#define DUMPBITS(n) { bitBuf >>= (n); bitCount -= (n); }

/* Reads the 3-bit header of one deflate block and dispatches on its type:
 * 0 = stored, 1 = fixed Huffman, 2 = dynamic Huffman. The bit buffer lives in inflateState
 * between calls. Returns 2 for the reserved type 3, and sets *lastBlock from the first bit. */
s32 inflateBlock(s32 *lastBlock) {
    u32 type;
    u32 bitBuf;
    u32 bitCount;

    bitBuf = inflateState.bb;
    bitCount = inflateState.bk;
    NEEDBITS(1)
    *lastBlock = (s32)bitBuf & 1;
    DUMPBITS(1)
    NEEDBITS(2)
    type = (u32)bitBuf & 3;
    DUMPBITS(2)
    inflateState.bb = bitBuf;
    inflateState.bk = bitCount;
    if (type == 2) return inflate_dynamic();
    if (type == 0) return inflateStoredBlock();
    if (type == 1) return inflateFixedBlock();
    return 2;
}
