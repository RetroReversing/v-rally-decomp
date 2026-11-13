/* Reads a variable-length 7-bit / 15-bit encoded value from `src` and stores it
 * into the 16-bit field at `dst + 0xA6`. Returns the advanced `src` pointer. */
u8 *Fwave(u8 *dst, u8 *src) {
    u32 val;
    u32 byte2;

    val = *src++;
    if (val & 0x80) {
        byte2 = *src++;
        val = byte2 | ((val & 0x7F) << 8);
    }
    *(s16 *)(dst + 0xA6) = val;
    return src;
}
