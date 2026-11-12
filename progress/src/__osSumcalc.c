/* Returns the 16-bit byte sum of length bytes starting at data (used for header checksums). */
u16 __osSumcalc(u8* data, int length) {
    int i;
    u32 sum = 0;
    u8* tmp = data;

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
