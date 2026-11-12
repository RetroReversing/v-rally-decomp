s32 slotSetSelected(s32, s32);
void *list_advance(u32, void *);
s32 record_set_byte9(s32, s32, s32);
extern void *gSelectState;
extern f32 D_800A14CC;
extern f64 D_800A5480;
extern s32 gOrderState;
extern s32 stream_state;

/* Resets the select-screen state: runs a stream step over the last list entry, clears the
 * busy flag, clears the item's flag if the list is not locked, and stores the average of
 * five state bytes as a float. */
void func_8005DC40(void)
{
    ((u8 *)gSelectState)[0x245] = 1;
    slotSetSelected(7, *(u16 *)(*(void **)((u8 *)&stream_state + 0x32F2) + 0xE) - 1);
    ((u8 *)gSelectState)[0x245] = 0;
    if (((u8 *)gSelectState)[0x248] == 0)
    {
        record_set_byte9(*(s32 *)((u8 *)&stream_state + 0x325A), 9, 0);
        ((u8 *)list_advance(5, *(void **)((u8 *)gSelectState + 0xC)))[0x41] = 0;
    }
    *(s16 *)((u8 *)gSelectState + 0x220) = 0;
    D_800A14CC = (f32) ((f64) (((u8 *)&gOrderState)[0x2544] + ((u8 *)&gOrderState)[0x2545] + ((u8 *)&gOrderState)[0x2546] + ((u8 *)&gOrderState)[0x2547] + ((u8 *)&gOrderState)[0x2548]) * D_800A5480);
}
