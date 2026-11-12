extern u8 *gSoundState;
extern u8 gEngineVoice;
extern u8 D_800C35C9;
extern u8 D_800C35CA;
extern u8 D_800C35CB;
extern u8 D_800C35CC;
extern u8 D_800C35CD;
extern u8 D_800C35CE;
extern u8 D_800C35CF;
s32 voicesSetParamsByKey(void *, s32);
s32 func_80089980(void);

/* Resets the sound state: clears each of the 39 slots (12 bytes apart) through
 * voicesSetParamsByKey, sets the eight flag bytes gEngineVoice..CF (0xFF, except D_800C35C9 = 0),
 * then calls func_80089980. */
void soundResetState(void)
{
  u8 slot;
  int slotOffset;

  for (slot = 0; slot < 0x27; slot++)
  {
    slotOffset = slot * 12;
    voicesSetParamsByKey((void *) (gSoundState + slotOffset), 0);
  }

  gEngineVoice = 0xFF;
  D_800C35C9 = 0;
  D_800C35CA = 0xFF;
  D_800C35CB = 0xFF;
  D_800C35CC = 0xFF;
  D_800C35CD = 0xFF;
  D_800C35CE = 0xFF;
  D_800C35CF = 0xFF;
  func_80089980();
}
