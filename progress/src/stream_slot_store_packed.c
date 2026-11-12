extern u8 *gSelectState;
extern u8 D_800A1683;
extern u8 stream_state[];
s32 func_800671A0(s32, s32);
s32 glyph_record_pack(u8, void *, s32);
s32 save_race_to_pak(void);

/* Packs the 8 bytes ending at D_800A1683 into one 32-bit value, stores it in the stream slot
 * of the current select index (slot size 0x28 bytes, at +0x68), then refreshes the select state. */
s32 stream_slot_store_packed(void) {
    s32 packed;
    s32 slot_index;
    u8 i;
    u8 byte;
    u8 *slot_base;

    packed = 0;
    i = 0;
    do {
        byte = *(&D_800A1683 - i);
        packed = packed << 4;
        i++;
        packed |= byte;
    } while (i < 8);
    slot_index = (s8)gSelectState[0x22A];
    slot_base = *(u8 **)(stream_state + 0x32F2);
    *(s32 *)(slot_base + ((slot_index * 5) << 3) + 0x68) = packed;
    glyph_record_pack((s8)gSelectState[0x22A], gSelectState, packed);
    save_race_to_pak();
    func_800671A0(0, 0);
    return 0;
}
