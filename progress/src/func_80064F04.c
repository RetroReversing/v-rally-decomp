s32 select_reset_text(s32, s32);
s32 select_arm_if_clear();
s32 func_80062334();
s32 heapFreeBlock(s32);
extern void *gSelectState;
extern s32 gSelectBuffer;
extern s32 func_80064E48;
extern s32 hud_draw_counter_text;

/* Frees the block held in gSelectBuffer if there is one, runs select_reset_text with the
   argument, points the two select-state hooks at func_80064E48 and hud_draw_counter_text,
   and then calls func_80062334. Returns 0. */
s32 func_80064F04(s32 arg0, s32 arg1)
{
    select_arm_if_clear();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    select_reset_text(arg0, arg1);
    *(s32 **)((s8 *)gSelectState + 0x288) = &func_80064E48;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &hud_draw_counter_text;
    func_80062334();
    return 0;
}
