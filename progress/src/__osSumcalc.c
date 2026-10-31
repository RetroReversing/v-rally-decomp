/* identical to __osSumcalc in hm64-decomp (matched), with its names changed by decompdecomp */
u16 __osSumcalc(u8* ptr, int length) {
    int i;
    u32 sum = 0;
    u8* tmp = ptr;

    for (i = 0; i < length; i++) {
        sum += *tmp++;
#if BUILD_VERSION < VERSION_J
        sum = sum & 0xFFFF;
#endif
    }

#if BUILD_VERSION >= VERSION_J
    return sum & 0xFFFF;
#else
    return sum;
#endif
}
