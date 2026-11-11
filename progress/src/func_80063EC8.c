s32 selectCopyEntryLabel(s32, s32);
s32 func_8005C198();
s32 heapFreeBlock(s32);
extern char *gSelectState;
extern s32 gSelectBuffer;
extern char gStreamState[];
extern char setup_stage_results[];
extern char func_8006425C[];
extern char func_80064504[];

/* Resets the select and stream state, frees the cached block if there is one, and
   installs the select-state callback table. */
s32 func_80063EC8(s32 arg0, s32 arg1) {
    *(s8 *)(gSelectState + 0x245) = 0;
    *(s16 *)(*(char **)(gStreamState + 0x32F2) + 0x1E) = 0;
    func_8005C198();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    selectCopyEntryLabel(arg0, arg1);
    *(char **)(gSelectState + 0x288) = setup_stage_results;
    *(char **)(gSelectState + 0x28C) = func_80064504;
    *(char **)(gSelectState + 0x290) = func_8006425C;
    return 0;
}
