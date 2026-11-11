s32 selectCopyEntryLabel();                            /* extern */
extern void *gSelectState;
extern s32 menu_setup_record_view;
extern s32 func_80069158;
extern s32 func_800693CC;

/* Copies the current entry label, then fills the select state's three handler slots (+0x288, +0x28C,
 * +0x290) with the record-view and two other menu callbacks. Returns 0. */
s32 selectSetHandlers(void) {
    selectCopyEntryLabel();
    *(void **)((u8 *)gSelectState + 0x288) = &menu_setup_record_view;
    *(void **)((u8 *)gSelectState + 0x28C) = &func_80069158;
    *(void **)((u8 *)gSelectState + 0x290) = &func_800693CC;
    return 0;
}
