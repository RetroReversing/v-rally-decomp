extern unsigned char D_800C792F;
void update_camera(void *);
extern s32 D_8009BA30;
extern s32 gPadFlags;
extern char stream_state[];

/* Per-frame update of one car. Unless pad flag 0x2 is held, the car's timer at 0x60
 * advances by the step in D_800C792F (capped at 0x800). Once it reaches 0x321 the
 * field at 0x6A counts down; when it runs out, the car's sub-object at 0x6C is marked
 * done and D_8009BA30 is cleared. Then the shared car update runs. */
void func_80012184(void *arg0)
{
  s32 timer;
  s16 counter;
  int new_var;
  f32 one;
  u8 *obj;
  u8 *sub;
  s32 arg1;

  obj = *((u8 **) (0x7CD6 + stream_state));
  one = 1.0f;
  arg1 = gPadFlags;
  D_8009BA30 = 1;
  *((f32 *) (obj + 0x114)) = one;
  if ((arg1 & 2) == 0)
  {
    timer = *((s32 *) (((u8 *) arg0) + 0x60));
    *((s32 *) (((u8 *) arg0) + 0x30)) = 6;
    if (timer < 0x800)
    {
      *((s32 *) (((u8 *) arg0) + 0x60)) = timer + (D_800C792F * 12);
    }
    if ((*((s32 *) (((u8 *) arg0) + 0x60))) >= 0x321)
    {
      new_var = 0x6A;
#ifdef PORT
      counter = *((s16 *) (((u8 *) arg0) + new_var));
#else
      counter = *((s16 *) (new_var + (int)arg0));
#endif
      if (counter >= 0xA61)
      {
        *((s16 *) (((u8 *) arg0) + new_var)) = counter - (D_800C792F * 30);
      }
      else
      {
        sub = *((u8 **) (((u8 *) arg0) + 0x6C));
        D_8009BA30 = 0;
        *((s32 *) (sub + 8)) = 1;
      }
    }
  }
  update_camera(arg0);
}
