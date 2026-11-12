/* Packs four byte values into one word, most significant first: a0 goes in the top byte, then a1, a2 and a3 (each masked to 8 bits). */
s32 packBytes4(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 hi;
    s32 b1;
    s32 b2;
    s32 b3;

    b3 = a3 & 0xFF;
    b2 = a2 & 0xFF;
    b2 <<= 8;
    b3 += b2;
    b1 = a1 & 0xFF;
    b1 <<= 0x10;
    b3 += b1;
    hi = a0 << 0x18;
    b3 += hi;
    return b3;
}
