extern u8 D_800AFA5C;
extern void *gLeague;
extern s32 gSoundState;
s32 voice_alloc_request(s32);
s32 voiceSetVolumeByKey(s32, s32);

/* Requests a voice at gSoundState+0x1B0 and sets its volume to 0x30 when D_800AFA5C is set or gLeague's s16 at +2 is nonzero. */
void func_80038F0C(void)
{
    if ((D_800AFA5C != 0) || (((s16 *) gLeague)[1] != 0)) {
        voice_alloc_request(gSoundState + 0x1B0);
        voiceSetVolumeByKey(gSoundState + 0x1B0, 0x30);
    }
}
