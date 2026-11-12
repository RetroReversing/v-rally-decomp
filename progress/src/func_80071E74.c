extern char *gSelectState;
void select_set_entry_flag(int index, int value);

/* Marks the select state as needing an entry reset, clears entry 0's flag and the
 * pending flag at +0x24D. Same body as select_reset_entries. */
int func_80071E74(void)
{
    *(char *)(gSelectState + 0x2BD) = 1;
    select_set_entry_flag(0, 0);
    *(char *)(gSelectState + 0x24D) = 0;
    return 0;
}
