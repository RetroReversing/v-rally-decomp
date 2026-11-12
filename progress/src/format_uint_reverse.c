extern u8 *gDigitChars;
extern u8 gOrderState[];

/* Writes value in radix digits backwards, ending just below the buffer end at gOrderState+0x87A0, and returns the first digit's address. */ u8 *format_uint_reverse(u32 value, u32 radix) {
    u8 *cursor;
    u32 rest;
    u32 quotient;
    u32 digit;

    rest = value;
    cursor = gOrderState + 0x87A0;
    do {
        quotient = rest / radix;
        digit = rest % radix;
        cursor--;
        *cursor = gDigitChars[digit];
        rest = quotient;
    } while (quotient != 0);
    return cursor;
}
