extern u8 stream_state[];

/* Reads the 6-byte status entry for one channel from the controller-pak buffer at stream_state+0x7E82. It stores the channel's flag in out[3]; when the flag is 0 it also copies the 16-bit value and the trailing byte into out. */
void __osPfsGetOneChannelData(s32 channel, u8 *out) {
    struct { u8 b[6]; } entry;
    u8 *src;
    s32 i;
    u8 flag;

    src = stream_state + 0x7E82;
    for (i = 0; i < channel; i++) {
        src++;
    }
    entry = *(typeof(entry) *)src;
    flag = (entry.b[1] & 0xC0) >> 4;
    out[3] = flag;
    if (flag == 0) {
        *(s16 *)out = (s16)(entry.b[3] | (entry.b[4] << 8));
        out[2] = entry.b[5];
    }
}
