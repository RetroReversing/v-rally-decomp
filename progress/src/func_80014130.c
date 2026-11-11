extern void (*D_8009BB1C)(void);
extern u32 *gTimeSampleState;
u64 osGetTime(void);
u64 __udivdi3(u64, u64);

/* Per-tick timing hook: calls D_8009BB1C, then while the sample block has room (count at word 0,
 * last timestamp at words 2-3) appends the time since the last sample, scaled to (now << 6) / 3000,
 * as entry number count (8 bytes each, starting at byte 16). */
void func_80014130(void)
{
    u32 *block;
    u32 *entry;
    u64 r;

    D_8009BB1C();
    if (gTimeSampleState[0] < 4)
    {
        r = osGetTime();
        block = gTimeSampleState;
        entry = (u32 *) (block[0] * 8 + (u32) block);
        r = __udivdi3(r << 6, 3000);
        r = r - *(u64 *)(block + 2);
        *(u64 *)(entry + 4) = r;
    }
}
