void select_reset_text(void);
s32 select_arm_if_clear(void);
void heapFreeBlock(s32 block);
extern u8 *gSelectState;
extern s32 gSelectBuffer;
extern u8 select_refresh_entry[];

/* Tears down the select screen: resets its text, points the state's handler
 * slot (+0x288) at select_refresh_entry, resets the stream, and frees the buffer. */
s32 func_80070B70(void) {
    select_reset_text();
    *(void **) (gSelectState + 0x288) = select_refresh_entry;
    select_arm_if_clear();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    return 0;
}
