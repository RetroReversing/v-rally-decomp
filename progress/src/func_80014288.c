u64 osGetTime();
u64 __udivdi3(u64,u64);
extern s32 (*D_8009BB18)();
extern char *gTimeSampleState;
static inline char *inline_fn(char *arg0){return arg0;}

/* Per-frame timing sample: calls the frame hook, then while fewer than 8 samples are stored, records
 * the current time (osGetTime ticks scaled by 64 and divided by 3000) and the elapsed time since the
 * last sample. Samples are 8-byte records after a 4-byte count. */
void func_80014288(void)
{
    char *state;
    u32 index;
    char *entry;
    u64 ret;
    u32 count, count2;

    D_8009BB18();
    if (*(u32 *)gTimeSampleState < 8) {
        ret = osGetTime();
        state = gTimeSampleState;
        count = *(u32 *)state;
        index = count;
        *(u32 *)state = index + 1;
        index = (u32)inline_fn(state + index * 8);
        ret = __udivdi3(ret << 6, 0xBB8);
        entry = (char *)index + 0x50;
        *(u64 *)entry = ret - *(u64 *)(state + 8);
        ret = osGetTime();
        state = gTimeSampleState;
        count2 = *(u32 *)state;
        index = count2;
        index = (u32)(state + index * ((unsigned long long)8));
        ret = __udivdi3(ret << 6, 0xBB8);
        *(u64 *)((char *)index + 0x10) = ret - *(u64 *)(state + 8);
    }
}
