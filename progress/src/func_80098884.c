extern u8 *gDigitChars;
extern u8 gOrderState[];

u8 *func_80098884(u32 arg0, u32 arg1) {
    u8 *out;
    u32 n;
    u32 q;
    u32 r;

    n = arg0;
    out = gOrderState + 0x87A0;
    do {
        q = n / arg1;
        r = n % arg1;
        out--;
        *out = gDigitChars[r];
        n = q;
    } while (q != 0);
    return out;
}
