s32 streamObjDestroy(s32);
s32 scene_teardown();
s32 func_80005DEC();
extern s32 D_8009B6E0;
extern s32 gPrevVideoHandler;
extern s32 stream_state;

/* Per-frame scene step: stores gPrevVideoHandler into the stream state at +0x7E12, releases the
 * pending handle D_8009B6E0 if set, then runs func_80005DEC. If that reports done (low byte
 * non-zero), tears the scene down. Returns the low byte of the result. */
s32 func_8000DAA8(void)
{
    s32 done;

    *(s32 *)((s8 *)&stream_state + 0x7E12) = (s32) gPrevVideoHandler;
    if (D_8009B6E0 != 0)
    {
        streamObjDestroy(D_8009B6E0);
        D_8009B6E0 = 0;
    }
    done = func_80005DEC();
    if (done & 0xFF)
    {
        done = scene_teardown();
    }
    return done & 0xFF;
}
