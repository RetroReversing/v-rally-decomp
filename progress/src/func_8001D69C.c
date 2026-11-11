extern s32 gOrderSlotTable;

/* Copies four 32-bit values from the source record (offsets 0x90, 0xDC, 0x128, 0x174) into the
 * low byte of each of the four slots in gOrderSlotTable (fields at +0x40, +0x44, +0x48, +0x4C).
 * Does nothing if the table isn't allocated. */
void func_8001D69C(void *src) {
    s32 temp_a0;
    s32 var_a1;

    if (gOrderSlotTable != 0) {
        var_a1 = 0;
        do {
            temp_a0 = var_a1 & 0xFF;
            *(s8 *)((s8 *)(gOrderSlotTable + temp_a0) + 0x40) = (s8) *(s32 *)((s8 *)src + 0x90);
            *(s8 *)((s8 *)(gOrderSlotTable + temp_a0) + 0x44) = (s8) *(s32 *)((s8 *)src + 0xDC);
            *(s8 *)((s8 *)(gOrderSlotTable + temp_a0) + 0x48) = (s8) *(s32 *)((s8 *)src + 0x128);
            var_a1 += 1;
            *(s8 *)((s8 *)(gOrderSlotTable + temp_a0) + 0x4C) = (s8) *(s32 *)((s8 *)src + 0x174);
        } while ((u32) (var_a1 & 0xFF) < 4U);
    }
}
