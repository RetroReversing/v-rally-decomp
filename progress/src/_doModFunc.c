extern f64 D_800A7208;
extern f64 D_800A7210;
extern f64 D_800A7218;

/* Advances a modulator by arg1 steps. The phase at +0x14 grows by the rate at +0x10 per
 * step. When it passes the limit D_800A7208 it is wrapped down by D_800A7210, and the
 * wrapped value is stored back. Returns the depth at +0x1C times the phase's absolute value
 * minus D_800A7218. */
f32 _doModFunc(void *mod, s32 steps)
{
  f32 magnitude;
  f64 limit;
  f32 phase;
  f64 phaseD;
  phase = (*((f32 *) (((char *) mod) + 0x14))) + ((*((f32 *) (((char *) mod) + 0x10))) * ((f32) steps));
  phaseD = (f64) phase;
  limit = D_800A7208;
  *((f32 *) (((char *) mod) + 0x14)) = phase;
  if (limit < phaseD)
  {
    phase = (f32) (phaseD - D_800A7210);
  }
  magnitude = phase;
  *((f32 *) (((char *) mod) + 0x14)) = phase;
  if (phase < 0.0f)
  {
    magnitude = -phase;
  }
  phase = ((f64) magnitude) - D_800A7218;
  return (*((f32 *) (((char *) mod) + 0x1C))) * ((f32) phase);
}
