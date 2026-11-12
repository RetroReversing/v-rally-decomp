extern void *gSelectState;
extern s32 finish_race_results;
extern s32 best_times_select_update;
s32 select_copy_entry_label(void);

/* Copies the entry label, then points the select-screen state at the race-results and best-times callbacks. */
s32 select_setup_callbacks(void) {
    select_copy_entry_label();
    *(s32 **)((s8 *)gSelectState + 0x288) = &finish_race_results;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &best_times_select_update;
    return 0;
}
