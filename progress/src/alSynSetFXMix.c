void *__allocParam();

/* Queues a mix update on the voice's effect: a VRALParam of type 0x10 carrying mix & 0xFF, timed at the
 * synth clock (+0x1C) plus the effect's time offset (+0xD8), and sent to the effect's handler as type 3. */
void alSynSetFXMix(void *synth, void *voice, s32 mix)
{
  s32 time;
  void *offs;
  VRALParam *evt;
  void *handler_obj;
  void *voice_s0;
  void *synth_s1;
  s32 mix_s2;
  voice_s0 = voice;
  synth_s1 = synth;
  mix_s2 = mix;
  if (*((void **) (((char *) voice_s0) + 8)) != NULL)
  {
    evt = __allocParam();
    if (evt != NULL)
    {
      time = *((s32 *) (((char *) synth_s1) + 0x1C));
      offs = *((void **) (((char *) *((void **) (((char *) voice_s0) + 8))) + 0xD8));
      evt->type = 0x10;
      evt->value = mix_s2 & 0xFF;
      evt->next = NULL;
      time += (s32) offs;
      evt->time = time;
      handler_obj = *((void **) (((char *) *((void **) (((char *) voice_s0) + 8))) + 0xC));
      (*((s32 (**)(void *, s32, void *)) (((char *) handler_obj) + 8)))(handler_obj, 3, evt);
    }
  }
}
