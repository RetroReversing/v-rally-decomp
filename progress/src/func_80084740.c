s32 streamReadHeader();

/* Reads a stream header and returns it unchanged; the mask pass leaves the value as-is. */
s32 func_80084740(void) {
    s32 header;
    s32 mask;
    s32 result;

    header = streamReadHeader();
    mask = header != 0;
    mask = -mask;
    result = header & mask;
    return result;
}
