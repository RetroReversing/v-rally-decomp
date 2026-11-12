extern u8 stream_state[];

/* Sets the 16-bit volume at stream_state+0x324A if bit 0 of flags is set, and the one at +0x705E if bit 1 is set. */
void MusSetMasterVolume(s32 flags, s16 volume) {
    if (flags & 1) {
        *(s16 *)(stream_state + 0x324A) = volume;
    }
    if (flags & 2) {
        *(s16 *)(stream_state + 0x705E) = volume;
    }
}
