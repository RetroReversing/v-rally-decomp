extern char stream_state[];

/* Returns a byte offset into the stream state: the table entry at 0x10386 indexed by the
 * record's u16 at +0x1E, plus the record's u16 at +0x20 times 0x2C4. */
s32 func_80041564(void) {
    void *rec;
    u16 index;
    u16 stride_index;

    rec = *(void **)(stream_state + 0x32F2);
    index = *(u16 *)((u8 *)rec + 0x1E);
    stride_index = *(u16 *)((u8 *)rec + 0x20);
    return *(s32 *)(stream_state + 0x10386 + index * 4) + stride_index * 0x2C4;
}
