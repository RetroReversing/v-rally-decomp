s32 voice_alloc_request(s32);
s32 voiceSetVolumeByKey(s32, s32);
extern s32 gSoundState;

/* Requests a voice for the sound state's entry at +0x1A4 and sets its volume to 0x30. */
void func_80038ED4(void) {
    voice_alloc_request(gSoundState + 0x1A4);
    voiceSetVolumeByKey(gSoundState + 0x1A4, 0x30);
}
