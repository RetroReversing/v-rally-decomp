typedef struct {
    u32 b31 : 1;
    u32 pad0 : 7;
    u32 b22 : 2;
    u32 b21 : 1;
    u32 pad1 : 7;
    u32 b12 : 2;
    u32 pad2 : 12;
} S9C90Flags;
typedef struct { u8 pad[0x14]; u32 *dl; u8 pad2[0x64]; s32 a7c; s32 a80; S9C90Flags flags; } S9C90;

s32 func_80009C90(S9C90 *o, s8 mode) {
    u32 *p;

    if ((mode & 0xFF) == 1) {
        o->a7c = 0;
        o->a80 = 0;
    }
    if ((o->flags.b21 != o->flags.b31) | ((mode & 0xFF) == 1)) {
        o->flags.b21 = o->flags.b31;
        if (o->flags.b31) {
            p = o->dl;
            o->dl = p + 2;
            p[0] = 0xD7000002;
            p[1] = 0x80008000;
        } else {
            p = o->dl;
            o->dl = p + 2;
            p[0] = 0xD7000000;
            p[1] = 0x80008000;
        }
    }
    if ((o->flags.b12 != o->flags.b22) | ((mode & 0xFF) == 1)) {
        o->flags.b12 = o->flags.b22;
        switch (o->flags.b22) {
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
