typedef struct { u8 pad[0x14]; u32 *dl; u8 pad2[0x64]; s32 a7c; s32 a80; u32 flags; } S9C90;

s32 func_80009C90(S9C90 *o, s8 mode) {
    u32 f;
    u32 sign;
    u32 *p;
    u32 m;
    u32 c = mode & 0xFF;
    u32 one;
    u32 nf;
    if (c == 1) {
        o->a7c = 0;
        o->a80 = 0;
    }
    f = o->flags;
    one = (c == 1);
    if ((((f >> 21) & 1) ^ (sign = f >> 31)) | one) {
        nf = (f & 0xFFDFFFFF) | (sign << 21);
        o->flags = nf;
        if ((s32)nf < 0) {
            p = o->dl;
            o->dl = p + 2;
            p[0] = 0xD7000002;
        } else {
            p = o->dl;
            o->dl = p + 2;
            p[0] = 0xD7000000;
        }
        p[1] = 0x80008000;
        f = o->flags;
    }
    m = (f >> 22) & 3;
    if ((((f >> 12) & 3) != m) | ((mode & 0xFF) == 1)) {
        f = (f & ~0x3000) | (m << 12);
        o->flags = f;
        switch ((f >> 22) & 3) {
        case 1:
            p = o->dl;
            o->dl = p + 2;
            p[0] = 0xE3001001;
            p[1] = 0x8000;
            break;
        case 2:
            p = o->dl;
            o->dl = p + 2;
            p[0] = 0xE3001001;
            p[1] = 0xC000;
            break;
        case 0:
            p = o->dl;
            o->dl = p + 2;
            p[0] = 0xE3001001;
            p[1] = 0;
            break;
        }
    }
    return 1;
}
