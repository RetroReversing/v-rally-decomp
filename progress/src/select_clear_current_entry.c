/* Copies the byte at +0x4C of the current select entry into +0x4D, then clears the entry pointer. */
extern char *gSelectState;

void select_clear_current_entry(void)
{
    char *entry;

    entry = *(char **)(gSelectState + 0x1F0);
    *(u8 *)(entry + 0x4D) = *(u8 *)(entry + 0x4C);
    *(char **)(gSelectState + 0x1F0) = NULL;
}
