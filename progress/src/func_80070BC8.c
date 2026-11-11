s32 select_reset_text(void);
s32 func_8005C198(void);
s32 func_80062334(void);
s32 heapFreeBlock(s32);
extern char *gSelectState;
extern s32 gSelectBuffer;
extern s32 func_80070630;
extern s32 func_80070750;

/* Resets the select screen: clears its text, re-points its two callbacks at the
 * default handlers, and frees the select buffer if one is allocated. */
s32 func_80070BC8(void)
{
    select_reset_text();
    *(s32 **)(gSelectState + 0x288) = &func_80070630;
    *(s32 **)(gSelectState + 0x28C) = &func_80070750;
    func_8005C198();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    func_80062334();
    return 0;
}
