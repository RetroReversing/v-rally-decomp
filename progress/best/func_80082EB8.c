s32 func_80082094(void);
void func_800821A4(u8 *, s32, s32);
extern u8 D_800C3340[];
extern s32 D_800C33B8;
extern u32 D_800C33BC;
extern u32 D_800C33C0;
extern u8 D_800AE850[];

s32 func_80082EB8(void) {
    u32 bitCount;
    u32 bits;
    s32 out;
    u32 length;
    u32 i;
    s32 v;
    u8 *state;
    u8 *ring;
    u8 *p;

    bitCount = D_800C33C0;
    p = (u8 *)&D_800C33BC;
    bits = *(u32 *)p;
    out = D_800C33B8;
    i = bitCount & 7;
    bitCount -= i;
    if (bitCount < 16) {
        bits >>= i;
        state = (u8 *)&D_800C33BC - 0x7c;
        do {
            v = *(s32 *)state;
            v--;
            *(s32 *)state = v;
            if (v >= 0) {
                p = *(u8 **)(state - 4);
                *(u8 **)(state - 4) = p + 1;
                v = *p; } else {
                v = func_80082094();
            }
            if (v == -1) {
                return 1;
            }
            bits |= (u32)v << bitCount;
            bitCount += 8;
        } while (bitCount < 16);
    }
    length = bits & 0xffff;
    bitCount -= 16;
    bits >>= 16;
    if (bitCount < 16) {
        state = D_800C3340;
        do {
            v = *(s32 *)state;
            v--;
            *(s32 *)state = v;
            if (v >= 0) {
                p = *(u8 **)(state - 4);
                *(u8 **)(state - 4) = p + 1;
                v = *p; } else {
                v = func_80082094();
            }
            if (v == -1) {
                return 1;
            }
            bits |= (u32)v << bitCount;
            bitCount += 8;
        } while (bitCount < 16);
    }
    if (length != ((~bits) & 0xffff)) {
        return 1;
    }
    bits >>= 16;
    bitCount -= 16;
    length--;
    if (length != (u32)-1) {
        state = D_800C3340;
        ring = D_800AE850 + 0x18AE8;
        do {
            while (bitCount < 8) {
                v = *(s32 *)state;
                v--;
                *(s32 *)state = v;
                if (v >= 0) {
                    p = *(u8 **)(state - 4);
                    *(u8 **)(state - 4) = p + 1;
                    v = *p; } else {
                    v = func_80082094();
                }
                if (v == -1) {
                    return 1;
                }
                bits |= (u32)v << bitCount;
                bitCount += 8;
            }
            ring[out++] = (u8)bits;
            if (out == 0x8000) {
                func_800821A4(ring, 0x8000, 0);
                out = 0;
            }
            bits >>= 8;
            length--;
            bitCount -= 8;
        } while (length != (u32)-1);
    }
    D_800C33B8 = out;
    D_800C33BC = bits;
    D_800C33C0 = bitCount;
    return 0;
}
