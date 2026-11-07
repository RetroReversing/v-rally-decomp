void osWritebackDCacheAll(void) {
    unsigned int p = 0x80000000U;
    unsigned int end = p + 0x2000U - 0x10U;
    do {
        p += 0x10U;
    } while (p - 0x10U < end);
}
