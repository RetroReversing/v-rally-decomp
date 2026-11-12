extern u8 *gSelectState;
void select_set_entry_flag(s32 index, s8 value);

/* Resets the select-screen flags: sets the reset-pending byte, clears entry 0's flag, and clears the +0x24D byte. */
s32 select_reset_flags(void)
{
    *(u8 *)(gSelectState + 0x2BD) = 1;
    select_set_entry_flag(0, 0);
    *(u8 *)(gSelectState + 0x24D) = 0;
    return 0;
}
