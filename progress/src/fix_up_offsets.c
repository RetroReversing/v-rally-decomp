/* Adds delta to each nonzero word in the first count words; zero entries are left alone. */
void fix_up_offsets(s32 *words, s32 delta, s32 count) {
    s32 pad[2];
    s32 i = 0, value;

    if (count > 0) {
        do {
            value = *words;
            i++;
            if (value) {
                *words = value + delta;
            }
            words++;
        } while (i < count);
    }
    (void)&pad;
}
