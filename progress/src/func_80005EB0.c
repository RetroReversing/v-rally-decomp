extern int D_800AFB3C;
extern int gStreamMain;

/* Swaps the saved stream-main value (D_800AFB3C) with the current gStreamMain. */
void func_80005EB0(void)
{
    s32 saved;

    saved = D_800AFB3C;
    D_800AFB3C = (s32) gStreamMain;
    gStreamMain = saved;
}
