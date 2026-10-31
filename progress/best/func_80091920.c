void func_80091920(u8 *p, s32 n) {
    s32 rem;
    s32 mis;
    s32 blocks;
    s32 words;
    u8 *end;
    mis=-(s32)p;
    rem = n;
    if (rem >= 12) {
        mis = -(s32)p & 3;
        rem -= mis;
        if (mis != 0) {
            *(s32 *)p = 0;
            p += mis;
        }
        blocks = rem & ~31;
        rem -= blocks;
        if (blocks != 0) {
            end = p + blocks;
            do {
                *(volatile s32 *)(p + 0) = 0;
                *(volatile s32 *)(p + 4) = 0;
                *(volatile s32 *)(p + 8) = 0;
                *(s32 *)(p + 12) = 0;
                p += 32;
                *(s32 *)(p - 16) = 0;
                *(s32 *)(p - 12) = 0;
                *(s32 *)(p - 8) = 0;
                *(s32 *)(p - 4) = 0;
            } while (p != end);
        }
        words = rem & ~3;
        rem -= words;
        if (words != 0) {
            end = p + words;
            do {
                p += 4;
                *(s32 *)(p - 4) = 0;
            } while (p != end);
        }
    }
    if (rem > 0) {
        end = p + rem;
        do {
            p++;
            *(p - 1) = 0;
        } while (p != end);
    }
}
