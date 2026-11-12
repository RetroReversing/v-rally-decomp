s32 angle_atan2_thunk();
extern f64 D_800A48E0;
extern f64 D_800A48E8;
extern f64 D_800A48F0;
extern f64 D_800A48F8;

/* Returns a steering-style offset for obj: the two angle differences (each taken
 * modulo 4096 and wrapped to the short way round) blended by weights that depend
 * on the distance in obj->0x58, then subtracted from the value at obj->0x58+8. */
s32 func_8001FD14(void *obj)
{
  f64 new_var;
  s32 angA;
  s32 angB;
  s32 t;
  s32 v1;
  s32 v0;
  f32 dist;
  f32 __repair_fv1_1;
  f32 wA;
  f32 wB;

  wA = 100.0f;
  wB = 0.0f;
  angA = angle_atan2_thunk(*((s16 *) (((char *) (*((void **) (((char *) obj) + 0x5C)))) + 0x50)), *((s16 *) (((char *) (*((void **) (((char *) obj) + 0x5C)))) + 0x44)));
  angB = angle_atan2_thunk(*((s32 *) (((char *) (*((void **) (((char *) obj) + 0x58)))) + 0x28)), *((s32 *) (((char *) (*((void **) (((char *) obj) + 0x58)))) + 0x20)));
  dist = (f32) (*((s32 *) (*((void **) (((char *) obj) + 0x58)))));
  if (dist < 2400.0f)
  {
    if (!(dist < 1200.0f))
    {
      t = (s32) dist;
      if (t < 0)
      {
        t = -t;
      }
      __repair_fv1_1 = (f32) (0x960 - t);
      wA = (f32) ((((f64) (__repair_fv1_1 * 0.00083333335f)) * D_800A48E0) + D_800A48E8);
      wB = (f32) (D_800A48F0 - ((f64) wA));
    }
  }
  else
  {
    wA = 25.0f;
    wB = 75.0f;
  }
  v1 = -0x400;
  v1 = angA < v1;
  if (v1 && (angB >= 0x401))
  {
    angA += 0x1000;
  }
  if ((angB < (-0x400)) && (angA >= 0x401))
  {
    angB += 0x1000;
  }
  angA = (s32) (((f64) ((wA * ((f32) angA)) + (wB * ((f32) angB)))) * D_800A48F8);
  v0 = *((s32 *) (((char *) (*((void **) (((char *) obj) + 0x58)))) + 8));
  return v0 - angA;
}
