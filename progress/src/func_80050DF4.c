extern char stream_state[];
extern signed char D_800C3BA0;
extern signed char D_800C3B9E;
extern unsigned char D_800C3B9C;
extern unsigned char D_800C3B9D;
extern unsigned char gSlotGroup;

u64 osGetTime();
s32 rand_next15();
s32 rand_seed();

/* Picks a random slot that is not yet in D_800C3B9C's used mask, marks it
 * used, and returns its index. After three picks the mask is cleared and the
 * slot group toggles between 0 and 1. Also reloads the two parameter bytes
 * from the current stream record. */
s32 func_80050DF4(void)
{
    u8 *rec;
    u8 *flags;
    u8 cnt;
    s32 v;
    s32 t;
    s32 a3;
    s32 bit;

    rand_seed((u32)osGetTime());
    rec = *(u8 **)(stream_state + 0x32F2);
    D_800C3BA0 = *(u16 *)(rec + 0x12);
    D_800C3B9E = *(u16 *)(rec + 0xE);
    if (D_800C3B9C == 0xFF) {
        D_800C3B9C = 0x14;
    }
    do {
        v = rand_next15();
        t = v;
        if (v < 0) {
            t = v + 7;
        }
        a3 = v - ((t >> 3) * 8);
        bit = 1 << (a3 & 0xFF);
    } while ((D_800C3B9C & bit) == bit);
    flags = &D_800C3B9C;
    cnt = D_800C3B9D + 1;
    *flags = *flags | (1 << (a3 & 0xFF));
    D_800C3B9D = cnt;
    if ((cnt & 0xFF) == 3) {
        D_800C3B9D = 0;
        gSlotGroup = gSlotGroup + 1;
        if (gSlotGroup == 2) {
            gSlotGroup = 0;
        }
    }
    return a3 & 0xFF;
}
