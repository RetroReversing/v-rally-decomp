/* Audio handler callback: when msg is 2, appends value to the list at +0x1C and bumps the count at +0x14. */
s32 func_800915CC(u8 *obj, s32 msg, s32 value) {
    s32 *list = *(s32 **)(obj + 0x1C);

    if (msg == 2) {
        s32 n = *(s32 *)(obj + 0x14);

        *(s32 *)(obj + 0x14) = n + 1;
        list[n] = value;
    }
    return 0;
}
