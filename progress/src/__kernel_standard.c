extern s32 D_800AFAE0;
s32 func_8009A580();
extern char gOrderState[];

/* SVID math error handler (fdlibm __kernel_standard). Packs the error record and
 * passes it to func_8009A580 (matherr). If that returns 0, sets errno to ERANGE
 * (0x22) for types 3 and 4 and to EDOM (0x21) otherwise. Returns the record's
 * result value (the last double argument). */
f64 __kernel_standard(s32 type, s32 arg1, s32 arg2, s32 arg3, f64 x, f64 y)
{
    struct {
        s32 sp10[4];
        f64 sp20;
        f64 sp28;
    } buf;

    buf.sp10[0] = type;
    buf.sp10[1] = arg1;
    buf.sp10[2] = arg2;
    buf.sp10[3] = arg3;
    buf.sp20 = x;
    buf.sp28 = y;
    if (func_8009A580(buf.sp10) == 0) {
        if ((u32)(type - 3) < 2) {
            *((s32 *)(gOrderState + 0x1290)) = 0x22;
        } else {
            *((s32 *)(gOrderState + 0x1290)) = 0x21;
        }
    }
    return buf.sp28;
}
