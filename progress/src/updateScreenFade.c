extern u16 gFadeTimer;
extern u16 gFadeLevel;
extern u16 gFadeStep;
extern s32 gFadeDirection;
void func_8000F1D4(s32, void *);

/* Steps the screen fade. gFadeDirection is the fade mode: bit 1 fades in (level rises to 0xFF),
 * bit 0 fades out (level falls to 0). Each step redraws the overlay; when the level reaches
 * its end, the mode clears and the timer is reset to the step size. */
void updateScreenFade(s32 ctx)
{
  s32 mode;
  u16 level;
  u16 *timer;

  timer = &gFadeTimer;
  mode = gFadeDirection;
  if (mode != 0) {
    *timer = *timer - 1;
    if (mode & 1) {
      level = gFadeLevel - gFadeStep;
      gFadeLevel = level;
      if ((s16) level < 0) {
        gFadeDirection = 0;
        gFadeLevel = 0;
        *timer = gFadeStep;
      }
      func_8000F1D4(ctx, timer);
    } else if (mode & 2) {
      level = gFadeLevel + gFadeStep;
      gFadeLevel = level;
      if ((s16) level >= 0x100) {
        gFadeDirection = 0;
        gFadeLevel = 0xFF;
        *timer = gFadeStep;
      }
      func_8000F1D4(ctx, timer);
    }
  }
}
