extern char *gSelectState;
void select_set_entry_flag(int a, int b);

/* Sets selection entry 0's flag, then marks two selection-state bytes as set. Returns 0. */
int select_init_flags(void) {
    select_set_entry_flag(0, 1);
    *(char *)(gSelectState + 0x24D) = 1;
    *(char *)(gSelectState + 0x2BD) = 1;
    return 0;
}
