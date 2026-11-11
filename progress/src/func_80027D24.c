extern char gOrderState[];
extern char gStreamState[];

/* Moves the state byte `cur` 30/128 of the way toward `target`, then caps it
 * at the limit stored in gOrderState. Results below 2 snap to 0. */
s32 func_80027D24(u32 cur, u32 target) {
    u8 next;
    u8 limit;

    next = cur + (((target - cur) * 0x1E) >> 7);
    if (next < 2) {
        return 0;
    }
    limit = gOrderState[0x18B4 + *(u16 *) (*(char **) (gStreamState + 0x32F2) + 0x16)];
    if (limit < next) {
        next = limit;
    }
    return next;
}
