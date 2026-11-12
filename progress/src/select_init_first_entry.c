extern char *gSelectState;
void select_set_entry_flag(int index, int value);

/* Marks selection entry 0 as set and raises the gSelectState+0x24D flag. */
int select_init_first_entry(void) {
    select_set_entry_flag(0, 1);
    *(char *)(gSelectState + 0x24D) = 1;
    return 0;
}
