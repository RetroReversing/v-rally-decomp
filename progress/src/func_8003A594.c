extern u32 D_800AFA6C;
extern f32 gSpeedAccum;
extern s32 gRaceFlags;
extern char gOrderState[];
s32 func_80038A8C(s32, s32, s32);
s32 start_track_voices(void *);
s32 voicesSetIdleParams(s32);
s32 voicesSetIdleValue(s32);

/* Sets the per-channel gains of a voice object from the state code arg1 (0 =
   silent/stop, 1..9 = fade or play stages). arg2 selects the cue to start. */
void func_8003A594(void *voice, s16 state, s32 arg2)
{
    *(u8 *)((char *)voice + 0x90) = 0xFF;
    *(u8 *)((char *)voice + 0x91) = 0xFF;
    *(u8 *)((char *)voice + 0x92) = 0xFF;
    *(u8 *)((char *)voice + 0x93) = 0xFF;
    if (state == 0) {
        *(s32 *)((char *)voice + 0x80) |= 4;
        voicesSetIdleParams(1);
        return;
    }
    *(s32 *)((char *)voice + 0x80) &= ~4;
    if (state >= 0xA) {
        return;
    }
    *(u8 *)((char *)voice + 0x90) = 0xFF;
    *(u8 *)((char *)voice + 0x91) = 0;
    *(u8 *)((char *)voice + 0x92) = 0;
    if (!((D_800AFA6C >> 3) & 1)) {
        return;
    }
    if (state < 5) {
        *(s32 *)((char *)voice + 0x80) |= 4;
        if (arg2 == 0) {
            return;
        }
        if ((D_800AFA6C & 0xF) != 0xF) {
            return;
        }
        func_80038A8C(0x17, state, arg2);
        return;
    }
    if (arg2 == 0) {
        return;
    }
    if ((D_800AFA6C & 0xF) != 0xF) {
        return;
    }
    func_80038A8C(0x16, state, arg2);
    if (gRaceFlags & 0x10) {
        return;
    }
    gRaceFlags |= 0x10;
    voicesSetIdleParams(1);
    start_track_voices(gOrderState + 0x8830);
    voicesSetIdleValue((s32)(gSpeedAccum * 80.0f));
}
