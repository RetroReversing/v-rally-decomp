extern s32 D_800C816C;
extern s8 D_800C3520;

typedef struct {
    s8 a;
    s8 b;
    s8 c;
    s8 d;
    s8 e;
    s8 f;
} Pack6;

/* Writes one controller-pak request into the PIF RAM buffer: zeroes zero_count
 * bytes, then the 6-byte command header (1, 3, 0, 0xFF, 0xFF, 0xFF), then the
 * 0xFE terminator. The word at PIF offset 0x3C is set to 1 as the request flag. */
void __osPfsRequestOneChannel(s32 zero_count) {
    s32 i;
    Pack6 cmd;
    Pack6 *pif;
    s32 *status_word;
    u8 fill;
    s8 pad[8];

    status_word = &D_800C816C;
    pif = (Pack6 *)((s8 *)status_word - 0x3C);
    i = 0;
    *status_word = 1;
    cmd.a = 1;
    cmd.b = 3;
    D_800C3520 = 0;
    cmd.c = 0;
    fill = 0xFF;
    cmd.d = fill;
    cmd.e = fill;
    cmd.f = fill;
    if (zero_count > 0) {
        do {
            *(s8 *)pif = 0;
            i++;
            pif = (Pack6 *)((s8 *)pif + 1);
        } while (i < zero_count);
    }
    *pif = cmd;
    ((u8 *)pif)[6] = 0xFE;
}
