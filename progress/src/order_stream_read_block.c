s32 streamReadBytes();
extern char gOrderState[];

/* Reads nbytes bytes of order stream data into the order buffer at gOrderState+0x8A30 and NUL-terminates it. */ /* Reads byteCount bytes of order stream data into the order buffer and NUL-terminates it. */ s32 order_stream_read_block(s32 nbytes) {
    if (nbytes != 0) {
        streamReadBytes(gOrderState + 0x8A30, nbytes);
        *(gOrderState + 0x8A30 + nbytes) = 0;
    }
    return 0;
}
