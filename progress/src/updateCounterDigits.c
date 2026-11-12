s32 getCounterValue(s32);
void format_to_buffer(u8 *, void *, s32);
extern u8 D_800A4B3C[];

/* Shows the counter's value (clamped at 0) on its digit sprites. The object
   is the ones digit; its children at +0x8C are the tens and hundreds digits.
   Leading-zero digits are hidden (flag bit 4 in +0x80). */
void updateCounterDigits(void *counter) {
    u8 *obj = counter;
    u8 digits[4];
    s32 src;
    s32 value;
    u8 *tens;
    u8 *hundreds;

    src = *(s32 *)(*(u8 **)(obj + 0xA8) + 0x24);
    if (src != 0) {
        if (*(u16 *)(obj + 0x78) == 0) {
            value = getCounterValue(src);
            value &= ~value >> 31;
            format_to_buffer(digits, D_800A4B3C, value & 0xFFFF);
            tens = *(u8 **)(obj + 0x8C);
            *(s16 *)(obj + 0x7A) = digits[0] - 0x30;
            hundreds = *(u8 **)(tens + 0x8C);
            if (digits[1] != 0) {
                *(s32 *)(tens + 0x80) &= -5;
                *(s16 *)(obj + 0x7A) = digits[1] - 0x30;
                *(s16 *)(tens + 0x7A) = digits[0] - 0x30;
                if (digits[2] != 0) {
                    *(s32 *)(hundreds + 0x80) &= -5;
                    *(s16 *)(obj + 0x7A) = digits[2] - 0x30;
                    *(s16 *)(tens + 0x7A) = digits[1] - 0x30;
                    *(s16 *)(hundreds + 0x7A) = digits[0] - 0x30;
                    return;
                }
            } else {
                *(s32 *)(tens + 0x80) |= 4;
            }
            *(s32 *)(hundreds + 0x80) |= 4;
        }
    }
}
