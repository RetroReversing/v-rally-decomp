u64 osGetTime();
u64 __udivdi3();
extern void (*D_8009BB20)();
extern u8 *gTimeSampleState;

/* Calls the per-frame hook, then while fewer than 4 samples are stored, records the elapsed
   time (osGetTime scaled to 1/3000 units, minus the base time at +8) in the sample slot at
   +0xD0 of the current sample block. */
void func_80014090(void)
{
    u64 now;
    u64 scaled;
    u64 base;
    u8 *block;
    u8 *slot;

    D_8009BB20();
    if (*((u32 *) (gTimeSampleState + 4)) < 4)
    {
        now = osGetTime();
        block = gTimeSampleState;
        slot = (u8 *) ((*((u32 *) (block + 4)) << 3) + (u32) block);
        scaled = __udivdi3(now << 6, (u64) 0xBB8);
        base = *((u64 *) (block + 8));
        *((u64 *) (slot + 0xD0)) = scaled - base;
    }
}
