s32 func_8006B924(u8 *);
extern s32 D_800ADF70;
extern char D_800C3A50[];
extern u16 D_800C72C6[];

/* For each of 4 groups of 3 entries, reads an entry's status (from func_8006B924) and writes a 16-bit value into D_800C72C6: 0xFFFF for status 5, otherwise the clamped distance to D_800ADF70 with the sign in bit 0 and the status in the top bits. */
void func_8006CB9C(void) {
    s32 status;
    s32 idx;
    s32 off;
    u8 i;
    u8 group;
    s32 dist;
    u16 *out;

    out = D_800C72C6;
    group = 0;
    do {
        i = 0;
        do {
            idx = i;
            off = idx << 4;
            status = func_8006B924((u8 *)(off + D_800C3A50));
            if ((status & 0xFF) == 5) {
                out[idx] = 0xFFFF;
            } else {
                dist = D_800ADF70 - *(s32 *)(D_800C3A50 + off);
                if (dist >= 0) {
                    if (dist >= 0x4000) {
                        dist = 0x3FFE;
                    }
                    dist &= ~1;
                } else {
                    dist = -dist;
                    if (dist >= 0x4000) {
                        dist = 0x3FFE;
                    }
                    dist |= 1;
                }
                out[i] = dist | ((status & 0xFF) << 14);
            }
            i++;
        } while (i < 3);
        group++;
    } while (group < 4);
}
