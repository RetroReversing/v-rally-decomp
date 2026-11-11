s32 StreamAllocNodes();
s32 resetTransform();
extern char gOrderState[];
extern char gStreamState[];
extern s32 streamFlipBuffer;

/* Sets up the stream state in gStreamState: two 64-node pools with their list heads and counters,
 * then pushes streamFlipBuffer onto the callback slot, keeping the previous slot value in the
 * chain at 0x32E6. */
void func_8000A068(void) {
    s32 *prevCallback;
    s32 pool;

    *(s32 *)(gStreamState + 0x32FA) = StreamAllocNodes(0x40);
    pool = StreamAllocNodes(0x40);
    *(s32 *)(gStreamState + 0x32FE) = pool;
    *(s32 *)(gStreamState + 0x330A) = 0;
    *(s32 *)(gStreamState + 0x330E) = 0x40;
    *(s32 *)(gStreamState + 0x3306) = pool;
    *(s32 *)(gStreamState + 0x3302) = (s32) *(s32 *)(gStreamState + 0x32FA);
    resetTransform(gOrderState + 0x20, *(s32 *)(gStreamState + 0x32FA));
    prevCallback = *(s32 * *)(gStreamState + 0x7DA6);
    *(s32 * *)(gStreamState + 0x7DA6) = &streamFlipBuffer;
    *(s32 * *)(gStreamState + 0x32E6) = prevCallback;
}
