s32 streamReadBytes();
extern char gOrderState[];

/* Reads byteCount bytes of order stream data into the order buffer and NUL-terminates it. */ s32 order_stream_read_block(s32 byteCount) {
    if (byteCount != 0) {
        streamReadBytes(gOrderState + 0x8A30, byteCount);
        *(gOrderState + 0x8A30 + byteCount) = 0;
    }
    return 0;
}
