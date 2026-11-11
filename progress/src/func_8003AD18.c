s32 format_time_text(s32, void *);
extern u8 gTimeModeChars[];

/* Clears the 'changed' flag (bit 4) of obj, sets it again when its target has bit 0x100 in
 * the state word at 0x14, shows the target's value when obj's digit slot is 0, and stores
 * the digit character for obj's current slot at 0x7A. An index of -1 shows the blank form. */
void func_8003AD18(void *obj) {
    s32 flags;
    s32 index;
    s32 digit;
    void *target;

    flags = *(s32 *)((u8 *)obj + 0x80) & ~4;
    *(s32 *)((u8 *)obj + 0x80) = flags;
    target = *(void **)(*(u8 **)((u8 *)obj + 0xA8) + 0x24);
    if (target != NULL) {
        index = *(s32 *)(*(u8 **)((u8 *)target + 0x70) + 0x28);
        if (*(s32 *)((u8 *)target + 0x14) & 0x100) {
            *(s32 *)((u8 *)obj + 0x80) = flags | 4;
        }
        if ((*(u16 *)((u8 *)obj + 0x78) == 0) && (index != -1)) {
            format_time_text(((s32 *)*(u8 **)((u8 *)target + 0x6C))[1], gTimeModeChars);
        }
        if (index == -1) {
            format_time_text(0, gTimeModeChars);
            digit = 0xE;
        } else {
            digit = gTimeModeChars[*(u16 *)((u8 *)obj + 0x78)] - 0x30;
        }
        *(s16 *)((u8 *)obj + 0x7A) = digit;
    }
}
