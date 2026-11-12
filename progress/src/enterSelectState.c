s32 order_recv_msg();
s32 streamOpenPath();
s32 select_reset_text_default();
s32 start_track_voices();
s32 voicesSetIdleParams();
s32 MusSetMasterVolume();
s32 voicesSetIdleValue();
extern s32 gRaceFlags;
extern void *gSelectState;
extern char D_800A5498[];
extern char gOrderState[];
extern char stream_state[];
extern s32 func_8005DC40;
extern s32 func_8005DD2C;

/* Entering the select state: the first time, starts the music (volumes come from the
 * stream state), then forwards the arguments and points the select state's callbacks
 * at its handlers. */
s32 enterSelectState(s32 selectArg0, s32 selectArg1) {
    void *trackVoices;

    if (!(gRaceFlags & 0x40)) {
        gRaceFlags |= 0x40;
        voicesSetIdleParams(1);
        order_recv_msg();
        trackVoices = gOrderState + 0x5558;
        streamOpenPath(trackVoices, &D_800A5498);
        MusSetMasterVolume(3, (s32) (*(f32 *)(stream_state + 0x332A) * 32767.0f));
        start_track_voices(trackVoices);
        voicesSetIdleValue((s32) (*(f32 *)(stream_state + 0x3332) * 112.0f));
    }
    select_reset_text_default(selectArg0, selectArg1);
    *(s32 * *)((char *)gSelectState + 0x288) = &func_8005DC40;
    *(s32 * *)((char *)gSelectState + 0x28C) = &func_8005DD2C;
    return 0;
}
