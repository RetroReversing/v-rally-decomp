extern int g_pos_bias;

/* For count entries spaced two words apart, adds g_pos_bias to each word that is
 * non-negative as a signed value. */
void add_pos_bias_words(u32 *words, s32 count) {
    char pad[8];
    s32 i;
    u32 *p;
    u32 v;

    p = words;
    i = 0;
    if (count > 0) {
        do {
            v = *p;
            i++;
            if (v <= 0x7FFFFFFFU) *p = v + g_pos_bias;
            p += 2;
        } while (i < count);
    }
}
