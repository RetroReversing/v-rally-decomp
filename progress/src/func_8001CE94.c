extern s32 gShadeMode;
extern s32 gGameState;
extern s32 stream_state;

/* Fills the three shade words in the shade table from obj. In shade mode 2, when the
 * stream's current entry has the same mode value, all three use the fixed value 0x82. */
void func_8001CE94(void *obj)
{
  register s32 value;
  if ((gShadeMode == 2) && (((value = (*((u16 *) (((char *) (*((void **) (((char *) (&stream_state)) + 0x32F2)))) + 0xE)))) == gShadeMode)))
  {
    value = 0x82;
    *((s16 *) (((char *) (&gGameState)) + 0x6BE6)) = value;
    *((s16 *) (((char *) (&gGameState)) + 0x6BE8)) = value;
  }
  else
  {
    *((s16 *) (((char *) (&gGameState)) + 0x6BE6)) = (s16) (*((s32 *) (((char *) obj) + 0x90)));
    *((s16 *) (((char *) (&gGameState)) + 0x6BE8)) = (s16) (*((s32 *) (0xDC + ((char *) obj))));
    value = *((s32 *) (((char *) obj) + 0x128));
  }
  *((s16 *) (((char *) (&gGameState)) + 0x6BEA)) = (s16) value;
}
