extern int gStreamMain;
extern int D_800AFB3C;
s32 streamFreeObject();

/* Frees the two stream objects (gStreamMain and D_800AFB3C) if the main one is set.
 * Clears both globals and returns 1 when something was freed, 0 otherwise. */
s32 func_80005DEC(void) {
    s32 freed;

    freed = 0;
    if (gStreamMain != 0) {
        streamFreeObject(gStreamMain);
        gStreamMain = 0;
        streamFreeObject(D_800AFB3C);
        freed = 1;
        D_800AFB3C = 0;
    }
    return freed;
}
