extern u8 gStreamState[];
extern void *gSelectState;
extern s32 gSelectBuffer;
extern void func_80071B3C(void);
extern void func_80071E08(void);
extern void func_80072364(void);
extern s32 select_copy_entry_state(s32, s32);
extern s32 select_set_active_sub(s32, u16);
extern s32 selectCopyEntryLabel(s32);
extern s32 func_8005C198(void);
extern s32 heapFreeBlock(s32);

/* Enters the stream-driven state: marks the current stream as state 5 with no pending
 * value, and when the lead track is type 3 installs this state's callbacks on the select
 * state; otherwise it just sets the flag and updates the stream entry. */
s32 func_80071A48(s32 index) {
    *(s16 *)(*(u8 **)(gStreamState + 0x32F2) + 0x1E) = 5;
    *(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0x22) = 0;
    if (!(*(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0x2C) & 0x200)) {
        if (*(s16 *)(*(u8 **)(gStreamState + 0x325A) + 2) == 3) {
            *(s8 *)((u8 *)gSelectState + 0x245) = 0;
            selectCopyEntryLabel(index);
            *(void **)((u8 *)gSelectState + 0x288) = func_80071B3C;
            *(void **)((u8 *)gSelectState + 0x290) = func_80071E08;
            *(void **)((u8 *)gSelectState + 0x28C) = func_80072364;
            func_8005C198();
            if (gSelectBuffer != 0) {
                heapFreeBlock(gSelectBuffer);
                gSelectBuffer = 0;
                return 0;
            }
            return 0;
        }
        goto block_5;
    }
block_5:
    *(s8 *)((u8 *)gSelectState + 0x245) = 1;
    select_copy_entry_state(index, 0x21);
    select_set_active_sub(index, *(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0x22));
    return 0;
}
