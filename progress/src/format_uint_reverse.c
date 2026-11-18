extern u8 *gDigitChars;
extern u8 gOrderState[];

/* Writes value in radix digits backwards, ending just below the buffer end at gOrderState+0x87A0, and returns the first digit's address. */ /* Writes value in radix digits backwards, ending just below the buffer end at gOrderState+0x87A0, and returns the first digit's address. */ u8 *format_uint_reverse(u32 value, u32 radix) {
    u8 *cursor;
    u32 remaining;
    u32 quot;
    u32 digit;

    remaining = value;
    cursor = gOrderState + 0x87A0;
    do {
        quot = remaining / radix;
        digit = remaining % radix;
        cursor--;
        *cursor = gDigitChars[digit];
        remaining = quot;
    } while (quot != 0);
    return cursor;
}
