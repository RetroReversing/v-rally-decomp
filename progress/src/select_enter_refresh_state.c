extern void *gSelectState;
extern s8 gSelectMode;
extern void select_refresh_entry(void);
s32 select_copy_entry_label();

/* Enters the select refresh state: copies the entry label, sets the select mode to 2, and points the state callback slot at select_refresh_entry. */
s32 select_enter_refresh_state(void)
{
    select_copy_entry_label();
    gSelectMode = 2;
    *(void **)((u8 *)gSelectState + 0x288) = select_refresh_entry;
    return 0;
}
