s32 streamReadBytes();
s32 order_stream_read_block();
s32 readStreamHeader();
s32 stream_seek_block();
extern char gOrderState[];
extern char stream_state[];

/* Makes entry index `index` of the table at gOrderState+0x8AE0 the current entry
 * (stored at +0x8AE4), starts it with stream_seek_block, reads the 4-byte stream
 * header and then the stream header, and passes the stream's u16 at +0x30C6 on. */
void stream_load_entry(s32 index) {
    s32 *entry;

    entry = (s32 *)((u8 *)*(void **)(gOrderState + 0x8AE0) + (index * 8));
    *(s32 * *)(gOrderState + 0x8AE4) = entry;
    stream_seek_block(*entry);
    streamReadBytes((gOrderState + 0x8AE0) - 8, 4);
    readStreamHeader();
    order_stream_read_block(*(u16 *)(stream_state + 0x30C6));
}
