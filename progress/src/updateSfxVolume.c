extern int gSoundState;
extern float kSfxMaxVolume;
s32 voiceKeyIsFree();
s32 voice_alloc_request();
s32 voiceSetVolumeByKey();

/* Sets the volume of the sound at gSoundState+0x1C8 from its distance: full volume at 0, silent at 9e6.
 * Distance is clamped to 9e6. Only runs when the sound's voice key is free. */
void updateSfxVolume(s32 unused0, s32 unused1, s32 unused2, s32 *distance)
{
  f32 volume;
  if (voiceKeyIsFree(gSoundState + 0x1C8) != 0)
  {
    volume = (f32)(f64)(u32)*distance;
    if (volume > 9e6f) volume = 9e6f;
    voice_alloc_request(gSoundState + 0x1C8);
    voiceSetVolumeByKey(gSoundState + 0x1C8, (s32)(kSfxMaxVolume * (1.0f - (volume * 1.1111111e-7f))));
  }
}
