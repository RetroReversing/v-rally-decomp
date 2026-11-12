extern s32 gOrderState[];

/* Returns nonzero when the order-state word at gOrderState[4] differs from toggle (a zero toggle tests the word alone). */
s32 func_80005FA4(s32 toggle) {
    s32 diff;

    if (toggle != 0) {
        diff = *(vs32 *)&gOrderState[4] ^ toggle;
    } else {
        diff = *(vs32 *)&gOrderState[4];
    }
    return diff != 0;
}
