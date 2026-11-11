u64 osGetTime(void);
u64 __udivdi3(u64, u64);
extern char *gTimeSampleState;

/* Records a time sample: while fewer than four samples are stored, writes the elapsed time since the
 * base value at +8 (scaled from osGetTime to a 3000-unit tick count) into the next sample slot. */
void func_80013F3C(void)
{
    char *state;
    char *slotBase;
    u32 idx;
    u64 t;
    u64 r;

    if (*(u32 *)(gTimeSampleState + 4) < 4) {
        t = osGetTime();
        state = gTimeSampleState;
        idx = *(u32 *)(state + 4);
        slotBase = (char *) (idx * 8);
        slotBase = state + (u32) slotBase;
        r = __udivdi3(t << 6, 3000);
        r = r - *(u64 *)(state + 8);
        *(u64 *)(slotBase + 0xD0) = r;
    }
}
