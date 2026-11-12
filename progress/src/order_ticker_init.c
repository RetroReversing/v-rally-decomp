extern char gGameState[];
extern char gOrderState[];
extern void *gOrderPrevHook;
s32 pool_alloc_records(s32 count);
void func_80009E7C(void);

/* Sets up the double-buffered record ticker at gGameState+0x6BA8: two pools of
 * 350 records are allocated, and this module's tick callback is chained in front
 * of the previous one, which is kept at gOrderState+0x11F4. */
void order_ticker_init(void) {
    int count;
    s32 *ticker = (s32 *)(gGameState + 0x6BA8);
    s32 second;
    s32 first;
#ifdef PORT
    void *prev_callback;
#else
    s32 prev_callback;
#endif
    unsigned short unused;

    count = 0x15E;
    *ticker = pool_alloc_records(count);
    second = pool_alloc_records(count);
    first = ticker[0];
    prev_callback = *(&gOrderPrevHook);
    do {
        ticker[1] = second;
        ticker[4] = 0;
        unused = 5;
        ticker[3] = second;
        ticker[5] = count;
        gOrderPrevHook = func_80009E7C;
    } while (0);
    ticker[2] = first;
    do {
    } while (0);
#ifdef PORT
    *(void **)(gOrderState + 0x11F4) = prev_callback;
#else
    *(s32 *)(gOrderState + 0x11F4) = prev_callback;
#endif
}
