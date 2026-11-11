void *__allocParam();

/* Queues a pan change for a voice. If the voice has a handler and a parameter block can be
 * allocated, the block gets type 0xC, the pan value (low byte), a time of the synth's time
 * (+0x1C) plus the voice object's +0xD8 field, and no next link. The voice's object at +0xC
 * then gets it through its handler (msg 3). */
void alSynSetPan(void *synth, void *voice, s32 pan)
{
  s32 (*handler)(void *, s32, void *);
  s32 time;
  s32 panValue;
  void *param;
  void *obj;
  void *voicePtr;
  void *synthPtr;

  voicePtr = voice;
  handler = *((s32 (**)(void *, s32, void *)) (((char *) voicePtr) + 8));
  synthPtr = synth;
  panValue = pan;
  if (handler != NULL)
  {
    param = __allocParam();
    if (param != NULL)
    {
      handler = *((s32 (**)(void *, s32, void *)) (((char *) voicePtr) + 8));
      time = *((s32 *) (((char *) synthPtr) + 0x1C));
      obj = *((void **) (((char *) handler) + 0xD8));
      handler = (s32 (*)(void *, s32, void *)) 0xC;
      *((s16 *) (((char *) param) + 8)) = 0xC;
      do
      {
        handler = (s32 (*)(void *, s32, void *)) (panValue & 0xFF);
        do { *((s32 (**)(void *, s32, void *)) (((char *) param) + 0xC)) = handler; *((s32 *) (((char *) param) + 0)) = 0; } while (0);
        time += obj;
        *((s32 *) (((char *) param) + 4)) = time;
      }
      while (0);
      handler = *((s32 (**)(void *, s32, void *)) (((char *) voicePtr) + 8));
      obj = *((void **) (((char *) handler) + 0xC));
      handler = *((s32 (**)(void *, s32, void *)) (((char *) obj) + 8));
      handler(obj, 3, param);
    }
  }
}
