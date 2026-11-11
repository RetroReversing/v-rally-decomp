extern char si_assert_fn[];
extern char si_assert_file[];

void func_800914E0(char *, char *, s32);
s32 si_busy(void);

/* Reads one 32-bit word from a physical address through the uncached segment, once the
 * serial interface is idle. Returns 0 and stores the word in *out, or -1 if the SI is busy.
 * The address must be word aligned and out must not be NULL (checked with the assert calls). */
s32 si_read_word(s32 addr, s32 *out) {
    s32 val;

    if (addr & 3) {
        func_800914E0(si_assert_fn, si_assert_file, 0x33);
    }
    if (out == NULL) {
        func_800914E0(si_assert_fn, si_assert_file, 0x34);
    }
    if (si_busy() != 0) {
        return -1;
    }
    val = *(s32 *)(addr | 0xA0000000);
    *out = val;
    return 0;
}
