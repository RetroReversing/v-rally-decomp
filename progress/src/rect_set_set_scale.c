/* Stores the three scale components (x, y, z) at offsets 0x81C, 0x820 and 0x824 of a rect set. */
void rect_set_set_scale(void *set, s32 scaleX, s32 scaleY, s32 scaleZ) {
    *(s32 *)((s8 *)set + 0x81C) = scaleX;
    *(s32 *)((s8 *)set + 0x820) = scaleY;
    *(s32 *)((s8 *)set + 0x824) = scaleZ;
}
