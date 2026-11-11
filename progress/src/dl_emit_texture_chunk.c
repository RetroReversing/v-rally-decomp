s32 osVirtualToPhysical();

/* Emits one texture-load command into the display list at obj+0x18 for the pending chunk at obj+0x7A. The count is the low 5 bits; the second word is the physical address of the chunk's data (base at obj+0x70, 16 bytes per unit). Then the pending offset advances by 0x20. */
void dl_emit_texture_chunk(u8 *obj) {
    s32 count;
    u16 offset;
    u32 *dl;
    s32 temp_a0;
    s32 temp_v0;

    offset = *(u16 *)(obj + 0x7A);
    count = offset & 0x1F;
    if (count != 0) {
        temp_a0 = count << 12;
        dl = *(u32 **)(obj + 0x18);
        temp_v0 = (count << 1) | 0x01000000;
        *dl = temp_a0 | temp_v0;
        offset &= 0xFFE0;
        dl[1] = osVirtualToPhysical(*(s32 *)(obj + 0x70) + offset * 16);
        offset += 0x20;
        *(u16 *)(obj + 0x7A) = offset;
    }
}
