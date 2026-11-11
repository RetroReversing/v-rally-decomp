void *__allocParam();

/* Queues a pitch update on the voice's effect: a VRALParam of type 7 carrying the float pitch, timed at the
 * synth clock (+0x1C) plus the effect's time offset (+0xD8), and sent to the effect's handler as type 3. */
void alSynSetPitch(void *synth, void *voice, f32 pitch)
{
  void *handler_obj;
  VRALParam *evt;
  s32 time;
  if ((*((void **) (((char *) voice) + 8))) != NULL)
  {
    evt = __allocParam(synth, voice);
    if (evt != NULL)
    {
      time = (s32) ((*((s32 *) (((char *) synth) + 0x1C))) + (*((s32 *) (((char *) (*((void **) (((char *) voice) + 8)))) + 0xD8))));
      evt->type = 7;
      *((f32 *) (((char *) evt) + 0xC)) = pitch;
      evt->next = NULL;
      evt->time = time;
      handler_obj = *((void **) (((char *) (*((void **) (((char *) voice) + 8)))) + 0xC));
      (*((s32 (**)(void *, s32, void *)) (((char *) handler_obj) + 8)))(handler_obj, 3, evt);
    }
  }
}
