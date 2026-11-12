extern u8 stream_state[];
extern u8 *gSelectState;
s32 select_set_active_sub(s32, u16);

/* Counts down the current stream entry's u16 counter at +0x22. When it is already zero,
 * reloads it from the selected entry's +0x14 value first. Then passes the counter to
 * select_set_active_sub and returns 1. */
s32 streamStepCountdown(s32 slot)
{
    u8 *current;
    s32 remaining;

    current = *(u8 **)(stream_state + 0x32F2);
    remaining = *(u16 *)(current + 0x22);
    if (remaining != 0)
    {
        remaining -= 1;
    }
    else
    {
        remaining = *(u16 *)(*(u8 **)(stream_state + 0x10386 + (gSelectState[0x23C] << 2)) + 0x14);
        remaining -= 1;
    }
    *(vu16 *)(current + 0x22) = remaining;
    select_set_active_sub(slot, *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x22));
    return 1;
}
