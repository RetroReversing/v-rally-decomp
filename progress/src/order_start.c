extern signed char D_800AE864;
s32 func_8000DD40(void *, s32, s32, void **);
extern char gOrderState[];

/* Starts an order for obj: records obj and the order in gOrderState and sets
 * D_800AE864. If the order's flag byte (+0x14) is set, it is submitted at once
 * through func_8000DD40. Returns 1 when submitted, 0 otherwise. */
u8 order_start(void *obj, void *order) {
    s32 zero;
    s32 one;
    u8 flag;
    u8 submitted;
    void **slot;

    slot = (void **)(gOrderState + 0xC);
    one = 1;
    *(void **)(gOrderState + 0x10) = obj;
    *slot = order;
    D_800AE864 = 1;
    *(s32 *)((char *)obj + 8) = one;
    flag = *(u8 *)((char *)order + 0x14);
    submitted = 0;
    if (flag != 0) {
        *(void **)(gOrderState + 0x10) = obj;
        *slot = order;
        zero = 0;
        *(volatile s32 *)((char *)obj + 8) = one;
        func_8000DD40(obj, zero, one, slot);
        submitted = 1;
    }
    return submitted;
}
