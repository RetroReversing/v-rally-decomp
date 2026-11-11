typedef struct TransformEntry { s32 m00, m01, m10, m11; s16 offX, offY; u16 unk14, unk16; } TransformEntry;

/* Resets a transform entry to identity: unit matrix diagonal (1.0 in 16.16),
 * zero off-diagonal terms, zero offsets and unit scale (0x400) in the trailing fields. */
void resetTransform(TransformEntry *t) {
    t->m00 = 0x10000;
    t->m11 = 0x10000;
    t->m01 = 0;
    t->m10 = 0;
    t->offX = 0;
    t->offY = 0;
    t->unk14 = 0x400;
    t->unk16 = 0x400;
}
