extern u8 gOrderState[];
extern u8 stream_state[];
extern s32 setNodeFlags(void);
extern s32 clearNodeFlags(void);
extern s32 updateObjectFlagsFromMask(void);
extern s32 func_80080514(s32, s32 (*)(void), s32);

/* Chooses the play-flag callback for the current stream's list, based on the stream's
 * mode and state: setting or clearing the flags, or returning early for mode 2 tracks. */
void func_8004F3C4(void) {
    s32 mode;
    u8 *stream;
    stream = *(u8 **)(stream_state + 0x32F2);
    mode = *(u16 *)(stream + 0x1E);
    if (mode == 0) {
        if (*(u16 *)(stream + 0x1A) == 0) {
            func_80080514(*(s32 *)(gOrderState + 0x73F0), updateObjectFlagsFromMask, 0x40); } else {
            func_80080514(*(s32 *)(gOrderState + 0x73F0), setNodeFlags, 0x40);
        }
    } else if (mode == 5 && *(u8 *)(gOrderState + 0x7FC8) == 0) {
        func_80080514(*(s32 *)(gOrderState + 0x73F0), setNodeFlags, 0x40);
    } else {
        u8 *stream2 = *(u8 **)(stream_state + 0x32F2);
        if (*(u16 *)(stream2 + 0xE) == 2) {
            u16 trackType = *(u16 *)(stream2 + 0x1E);
            if ((trackType != 0 && trackType < 5) || trackType == 5) {
                func_80080514(*(s32 *)(gOrderState + 0x73F0), updateObjectFlagsFromMask, 0x40);
                return;
            }
        }
        func_80080514(*(s32 *)(gOrderState + 0x73F0), clearNodeFlags, 0x40);
    }
}
