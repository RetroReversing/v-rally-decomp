extern u8 stream_state[];
extern u8 gSelectState[];
extern u8 *gSlotTableB[];
s32 select_set_active_sub(s32, u16);

/* Steps the select cursor (+0x22 of the select block at stream_state+0x32F2)
   to the next item, wrapping to 0 after the last one of the current table,
   then marks that item active. Returns 1. */
s32 select_step_next(s32 slot) {
    u8 *cursor;
    u16 index;
    s32 count;

    cursor = *(u8 **) (stream_state + 0x32F2);
    index = *(u16 *) (cursor + 0x22);
    count = *(u16 *) (gSlotTableB[*(u8 *) (*(u8 **) gSelectState + 0x23C)] + 0x14) - 1;
    if (index >= count) {
        *(u16 *) (cursor + 0x22) = 0;
    } else {
        *(u16 *) (cursor + 0x22) = index + 1;
    }
    select_set_active_sub(slot, *(u16 *) (*(u8 **) (stream_state + 0x32F2) + 0x22));
    return 1;
}
