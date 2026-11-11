s32 slot_set_selected();
s32 select_stream_char();
extern char *gSelectState;
extern char gStreamState[];

/* Counts down the countdown timer of the current slot (by 10 per call, while it is at -19 or above) and
 * refreshes the slot's display via slot_set_selected with the timer scaled to tenths of the reference. */
s32 func_8006B150(s32 arg0)
{
    char *stream;
    char *block;
    s16 timer;
    s16 newTimer;
    char *slot;

    stream = *(char **)(gStreamState + 0x32F2);
    block = stream + ((*(u8 *)(stream + *(s8 *)(gSelectState + 0x228) + 0x32) * 40) + 0x44);
    slot = (char *)(((select_stream_char(*(u8 *)(stream + 0x1F), *(u8 *)(stream + 0x21), *(u8 *)(stream + 0x23)) & 0xFF) * 2) + (u32)block);
    timer = *(s16 *)(slot + 0x1C);
    if (timer >= -0x13)
    {
        newTimer = timer - 0xA;
        *(s16 *)(slot + 0x1C) = newTimer;
        slot_set_selected(arg0, -(newTimer / 10) + 2, slot);
    }
    return 1;
}
