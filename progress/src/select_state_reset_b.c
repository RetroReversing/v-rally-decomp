typedef struct { s32 a, b; s8 c; } SelectCfg;
extern void *gSelectState;
extern s32 gSelectBuffer;
extern SelectCfg D_800A5CF0;
s32 select_set_entry_flag(s32, s32);
s32 records_restore_from_order(void);
s32 select_menu_setup(s32, s32);
s32 select_arm_if_clear(void);
s32 heapFreeBlock(s32);

/* Resets the select state: clears the flag at +0x24D, copies the 9-byte default config D_800A5CF0
 * into +0x204, and frees the block held in gSelectBuffer. Returns 0. */
s32 select_state_reset_b(void) {
    SelectCfg *dst;

    select_set_entry_flag(0, 0);
    *((s8 *)gSelectState + 0x24d) = 0;
    records_restore_from_order();
    dst = (SelectCfg *)((s8 *)gSelectState + 0x204);
    __builtin_memcpy(dst, &D_800A5CF0, 9);
    select_menu_setup(0, 0);
    select_arm_if_clear();
    if (gSelectBuffer) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    return 0;
}
