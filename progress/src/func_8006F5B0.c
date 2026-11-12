s32 glyph_record_reset(s32);

/* Calls glyph_record_reset for indices 0 to 3. */
void func_8006F5B0(void) {
    u32 i;

    i = 0;
    do {
        glyph_record_reset(i & 0xFF);
        i += 1;
    } while (i < 4U);
}
