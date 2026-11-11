/* Advance pointer past delimiters: space (0x20), tab (0x09), and comma (0x2C) */
/**
 * Skips delimiter characters in a buffer.
 * Returns a pointer to the first non‑delimiter byte or `end`.
 */
s8 *skip_delimiters(s8 *ptr, u32 end) {
    s8 *var_a0 = ptr;
    s8 temp_a2;
    while (((((temp_a2 = *var_a0) == 0x20) | (temp_a2 == 9)) != 0 || temp_a2 == 0x2C) && (u32)var_a0 < end) {
        var_a0 += 1;
    }
    return var_a0;
}
