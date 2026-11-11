extern s32 (*D_8009BB14)();
extern u32 *gTimeSampleState;
u64 osGetTime();
u64 __udivdi3(u64 a, u64 b);

/* Samples the OS clock into the current slot of the timing ring (gTimeSampleState)
 * when the object is active (state != 4) and the ring is not full. */
void func_800141D0(void *arg0)
{
    u32 *ring;
    u8 *slot;
    u64 now;
    u64 elapsed;

    D_8009BB14();
    if (arg0 != NULL && *(u16 *)((u8 *)arg0 + 0x48) != 4 && *gTimeSampleState < 8) {
        now = osGetTime();
        ring = gTimeSampleState;
        slot = (u8 *)(ring[0] * 8 + (u32)ring);
        elapsed = __udivdi3(now << 6, 0xBB8);
        elapsed = elapsed - *(u64 *)(ring + 2);
        *(u64 *)(slot + 0x90) = elapsed;
    }
}
