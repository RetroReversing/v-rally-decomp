s32 order_recv_msg();
s32 streamOpenPath();
s32 selectStateReset();
s32 selectSetItem();
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

/* Select-screen setup. The first call (bit 0x40 of gRaceFlags clear) starts the menu
   music and sets the master volume from the stream's volume value. Every call then
   resets the select state's list pointer and installs its two callbacks. */
s32 select_menu_setup(void) {
    void *musicTrack;

    if (!(gRaceFlags & 0x40)) {
        gRaceFlags |= 0x40;
        voicesSetIdleParams(1);
        order_recv_msg();
        musicTrack = gOrderState + 0x5558;
        streamOpenPath(musicTrack, &D_800A5498);
        MusSetMasterVolume(3, (s32) (*(f32 *)(stream_state + 0x332A) * 32767.0f));
        start_track_voices(musicTrack);
        voicesSetIdleValue(0x70);
    }
    selectStateReset(1);
    *(void * *)((char *)gSelectState + 0x1F4) = (void *) (gSelectState + 0x204);
    selectSetItem(0, 0);
    *(s32 * *)((char *)gSelectState + 0x288) = &func_8005DC40;
    *(s32 * *)((char *)gSelectState + 0x28C) = &func_8005DD2C;
    return 0;
}
