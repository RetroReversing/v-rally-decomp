extern unsigned int g_select_flags;

/* Returns 1 when bit 0x4000 of g_select_flags is set, 0 otherwise. */
int select_flag_4000_set(void) {
    int result = 0;
    if (g_select_flags & 0x4000) {
        result = 1;
    }
    return result;
}
