extern void *gSelectState;
extern s32 gSelectBuffer;
extern s32 func_80071B3C;
extern s32 func_80071E08;
extern s32 func_80072364;

s32 selectCopyEntryLabel(s32, s32);
s32 func_8005C198();
s32 heapFreeBlock(s32);

/* Select-screen state entry: frees the block held in gSelectBuffer, clears the
 * select flag at +0x245, fills the slot name for arg1, then installs the three
 * state handlers (+0x288, +0x28C, +0x290) in gSelectState. */
s32 select_setup_handlers(s32 arg0, s32 arg1) {
    func_8005C198();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    ((s8 *)gSelectState)[0x245] = 0;
    selectCopyEntryLabel(arg0, arg1);
    *(s32 **)((s8 *)gSelectState + 0x288) = &func_80071B3C;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &func_80072364;
    *(s32 **)((s8 *)gSelectState + 0x290) = &func_80071E08;
    return 0;
}
