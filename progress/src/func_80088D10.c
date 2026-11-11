typedef struct S_func_80088D10_arg0
{
  u8 p0[8];
  s32 elapsed;
  u8 p1[0x30];
  s32 start_time;
  u8 p2[0x10];
  s32 end_time;
  f32 rate_a;
  f32 rate_b;
  f32 rate_c;
  s32 scale;
  u8 p3[0x53];
  u8 interval;
  u8 base_a;
  u8 base_b;
  u8 base_c;
  u8 phase;
  u8 out;
  u8 timer;
  u8 limit_a;
  u8 limit_b;
  u8 limit_c;
  u8 p4[4];
  u8 saved_out;
} S_func_80088D10_arg0;

/* Steps a four-phase ramp on the state at arg0. The timer counts down one tick per call,
 * and when it reaches zero the phase advances and the output value (out) is recomputed:
 * phase 1 ramps up from base_a, phase 2 ramps from base_b, phase 3 holds, and phase 4 ramps
 * back down to 0 from saved_out. Once elapsed passes end_time, phase 4 starts. */
void func_80088D10(S_func_80088D10_arg0 *arg0)
{
  u8 phase;
  int progress;
  f32 amount;
  f32 rate;
  f32 progress_f;
  if ((((u32) arg0->elapsed) >= ((u32) arg0->end_time)) && (arg0->phase < 4U))
  {
    arg0->phase = 4;
    arg0->timer = 1;
    arg0->saved_out = arg0->out;
  }
  arg0->timer--;
  if (arg0->timer)
  {
    return;
  }
  phase = arg0->phase;
  arg0->timer = arg0->interval;
  if (1)
  {
    switch (phase)
    {
      case 1:
        progress = (s32) (((((u32) (arg0->elapsed - arg0->start_time)) >> 8) * ((u32) arg0->scale)) >> 10);
        if (progress < arg0->limit_a)
      {
        progress_f = (f32) progress;
        rate = arg0->rate_a;
        arg0->out = arg0->base_a + ((s32) (rate * progress_f));
      }
      else
      {
        arg0->phase = phase + 1;
        arg0->out = arg0->base_b;
      }
        break;

      case 2:
        progress = (s32) ((((((u32) (arg0->elapsed - arg0->start_time)) >> 8) - arg0->limit_a) * ((u32) arg0->scale)) >> 10);
        if (progress < arg0->limit_b)
      {
        ;
        arg0->out = arg0->base_b + ((s32) (arg0->rate_b * ((f32) progress)));
      }
      else
      {
        arg0->phase = phase + 1;
        arg0->out = arg0->base_c;
      }
        break;

      case 3:
        break;

      case 4:
        progress = (s32) (((((u32) (arg0->elapsed - arg0->end_time)) >> 8) * ((u32) arg0->scale)) >> 10);
        if (progress < arg0->limit_c)
      {
        ;
        amount = arg0->rate_c * (f32)progress;
        arg0->out = arg0->saved_out - (s32)(amount * (f32)arg0->saved_out);
      }
      else
      {
        arg0->phase = phase + 1;
        arg0->out = 0;
      }
        break;

    }

  }
}
