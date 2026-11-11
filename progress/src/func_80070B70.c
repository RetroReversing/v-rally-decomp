void select_reset_text(void);
s32 func_8005C198(void);
void heapFreeBlock(s32 block);
extern u8 *gSelectState;
extern s32 gSelectBuffer;
extern u8 func_80070A34[];

/* Tears down the select screen: resets its text, points the state's handler
 * slot (+0x288) at func_80070A34, resets the stream, and frees the buffer. */
s32 func_80070B70(void) {
    select_reset_text();
    *(void **) (gSelectState + 0x288) = func_80070A34;
    func_8005C198();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    return 0;
}
