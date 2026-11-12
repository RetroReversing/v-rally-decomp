/* Reads a little-endian u16 from the byte buffer at src. */
s32 readU16LE(void *src) {
    return *(u8 *)((s8 *)src + 0) | (*(u8 *)((s8 *)src + 1) << 8);
}
