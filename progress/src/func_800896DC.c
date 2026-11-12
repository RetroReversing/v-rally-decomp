/* Fills count bytes at dst with value (memset). The unused pad keeps the original stack frame. */
void func_800896DC(signed char *dst, signed char value, int count) {
    int pad[2];
    int i = count - 1;
    if (count != 0) {
        do {
            *dst = value;
            dst++;
            i--;
        } while (i != -1);
    }
    (void)&pad;
}
