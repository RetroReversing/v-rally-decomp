/* Relocates a table of pointer-like words: every second word whose top bit is clear gets base added. Words with the top bit set are left as they are. */ void rebase_words(u32 *words, s32 count, s32 base) {
    char unused[8];
    s32 i;
    u32 *p;
    u32 value;

    p = words;
    i = 0;
    if (count > 0) {
        do {
            value = *p;
            i += 1;
            if (value <= 0x7FFFFFFFU) {
                *p = value + base;
            }
            p += 2;
        } while (i < count);
    }
}
