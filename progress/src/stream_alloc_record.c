s32 poolAllocNode(s32, s32);
void record_reset(s32);
extern char stream_state[];

/* Allocates a 0xF4-byte record from the stream pool, stores it in stream_state, resets it and returns it. */
s32 stream_alloc_record(void) {
    s32 rec;

    rec = poolAllocNode(*(s32 *)(stream_state + 0x6C5E), 0xF4);
    *(s32 *)(stream_state + 0x32F2) = rec;
    record_reset(rec);
    return *(s32 *)(stream_state + 0x32F2);
}
