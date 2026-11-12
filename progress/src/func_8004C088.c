extern u8 D_800A03DB;

/* Increments frame counter up to 2; once reached, sets bit 1 in object flags at offset 0xC. */
void func_8004C088(s32 *obj) {
    s32 flags;

    if (D_800A03DB >= 2) {
        flags = obj[3];
        if (!(flags & 6)) {
            obj[3] = flags | 2;
        }
    } else {
        D_800A03DB++;
    }
}
