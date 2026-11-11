extern u32 D_800A1634[];
extern u8 D_800A167C[16];
#define D_800A1684 (D_800A167C + 8)

/* Cache update for entry arg1: looks for one of the 8 slots in D_800A1684 whose key
 * (D_800A1634 indexed through the slot) equals the key of entry arg1. If found, that
 * slot takes over entry arg1's values in both tables. Then entry arg1 is refreshed
 * from the first table. Always returns 0. */
s32 func_80068CD4(s32 arg0, s32 arg1)
{
    u8 slot;
    u32 key;

    key = D_800A1634[D_800A167C[arg1]];
    for (slot = 0; slot < 8; slot++) {
        if (D_800A1634[D_800A1684[slot]] == key) {
            break;
        }
    }
    if (slot != 8) {
        D_800A167C[slot] = D_800A1684[arg1];
        D_800A1684[slot] = D_800A1684[arg1];
    }
    D_800A1684[arg1] = D_800A167C[arg1];
    return 0;
}
