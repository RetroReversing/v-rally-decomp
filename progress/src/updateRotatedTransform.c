typedef struct TransformEntry { s32 m00, m01, m10, m11; s16 offX, offY; u16 unk14, unk16; } TransformEntry;
typedef struct TransformObj { u8 pad00[0x42]; u16 unk42; u8 pad44[6]; u16 unk4A; u8 pad4C[0xC]; TransformEntry *entry; u16 angle; u16 mode; } TransformObj;

void *entry_pool_alloc();                              /* extern */
void resetTransform(void *);                        /* extern */
s32 coss(u16);                                      /* extern */
s32 sins(u16);                                      /* extern */

/* Rebuilds the rotated transform at obj->entry: allocates a fresh entry, derives the
 * cos/sin terms from the object's angle (clamping the 0xFFFE edge case), writes the
 * 2x2 matrix, and fills in the scaled offsets when mode is zero. */
void updateRotatedTransform(TransformObj *obj, s32 x, s32 y) {
    s32 cosVal;
    s32 sinVal;
    u16 angle;
    u16 mode;
    TransformEntry *entry;
    TransformEntry *entry2;
    TransformEntry *entry3;

    entry = entry_pool_alloc();
    obj->entry = entry;
    resetTransform(entry);
    angle = obj->angle;
    mode = obj->mode;
    cosVal = (s32) (coss(angle) << 0x10) >> 0xF;
    sinVal = (s32) (sins(angle) << 0x10) >> 0xF;
    if (cosVal == 0xFFFE) {
        cosVal = 0x10000;
    }
    if (sinVal == 0xFFFE) {
        sinVal = 0x10000;
    }
    if (cosVal == 0xFFFE) {
        cosVal = -0x10000;
    }
    if (sinVal == 0xFFFE) {
        sinVal = -0x10000;
    }
    if (mode == 0) {
        obj->entry->offX = (s16) (x * 4);
        obj->entry->offY = (s16) (y * 4);
    }
    entry2 = obj->entry;
    entry2->m11 = cosVal;
    entry2->m00 = cosVal;
    entry3 = obj->entry;
    entry3->m10 = sinVal;
    entry3->m01 = (s32) -sinVal;
    obj->entry->unk14 = (u16) obj->unk42;
    obj->entry->unk16 = (u16) obj->unk4A;
}
