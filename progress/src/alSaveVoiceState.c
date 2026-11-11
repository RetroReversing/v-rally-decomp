extern s16 sSavedFlag0;
extern s16 sSavedVal0;
extern s16 sSavedVal1;
extern s16 sSavedFlag1;
extern s16 sSavedVal2;
extern s16 sSavedVal3;
extern s16 sSavedFlag2;
extern s16 sSavedVal4;
extern s16 sSavedVal5;
extern s16 D_800A18BC;
extern s16 sSavedVal6;
extern s16 sSavedVal7;
extern f64 sAngleScale;
extern s32 sSavedAngleX;
extern s32 sSavedAngleY;
extern f32 sSavedCosX;
extern f32 sSavedCosY;

/* Saves the voice parameters at fixed offsets of obj into the sSaved* globals,
 * clearing the flag that goes with each pair, and caches cos() of the two angle fields. */
void alSaveVoiceState(void *obj)
{
  f64 angleScale;
  s32 angleX;
  s32 angleY;
  s32 value;

  sSavedFlag0 = 0;
  sSavedVal0 = *((s32 *) (((char *) obj) + 0x90));
  value = *((s32 *) (((char *) obj) + 0xDC));
  sSavedFlag1 = 0;
  sSavedVal1 = value;
  sSavedVal2 = *((s32 *) (((char *) obj) + 0x128));
  value = *((s32 *) (((char *) obj) + 0x174));
  sSavedFlag2 = 0;
  sSavedVal3 = value;
  sSavedVal4 = *((s32 *) (((char *) obj) + 0x1C0));
  value = *((s32 *) (((char *) obj) + 0x20C));
  D_800A18BC = 0;
  sSavedVal5 = value;
  sSavedVal6 = *((s32 *) (((char *) obj) + 0x258));
  sSavedVal7 = *((s32 *) (((char *) obj) + 0x2A4));
  angleScale = sAngleScale;
  angleX = *((s32 *) (((char *) obj) + 0x2F0));
  angleY = *((s32 *) (((char *) obj) + 0x33C));
  sSavedAngleX = angleX;
  sSavedAngleY = angleY;
  sSavedCosX = __cosf((f32) (((f64) angleX) * angleScale));
  sSavedCosY = __cosf((f32) (((f64) sSavedAngleY) * angleScale));
}
