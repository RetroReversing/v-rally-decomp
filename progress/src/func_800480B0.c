s32 obj_mtx_visible();
s32 func_8001BE68(void *, f32, s32, f32, f32 *, f32 *, s32 *);
s32 func_8002D2C8();
s32 vec3_normalize_fixed();
s32 guMtxIdentF();

/* Computes the per-object view values for one object: its position and
 * heading are read from obj, the derived angle and limited tilt go to view. */
void func_800480B0(void *obj, void *view)
{
  s32 *new_var2;
  struct
  {
    s32 matrix[12];
    f32 translate[4];
  } mtx;
  s32 pos[4];
  int new_var3;
  char *new_var;
  f32 tilt;
  float new_var4;
  f32 tiltB;
  u32 sp78;
  f32 temp_fv1;
  f32 temp_ft0f;
  f32 temp_fv0f;
  s32 temp_ft0;
  s32 temp_fv0;
  guMtxIdentF(mtx.matrix);
  mtx.translate[0] = *((f32 *) (((char *) obj) + 0x118));
  mtx.translate[1] = *((f32 *) (((char *) obj) + 0x11C));
  mtx.translate[2] = *((f32 *) (((char *) obj) + 0x120));
  obj_mtx_visible(0, obj + 0x38, mtx.matrix);
  ;
  *((s32 *) (((char *) view) + 0x88)) = (s32) (((s32) (-(*((f32 *) (((char *) obj) - -0x108))))) & 0xFFF);
  new_var4 = (*((f32 *) (((char *) obj) + 0x124))) - (*((f32 *) (((char *) obj) + 0x118)));
  temp_ft0f = new_var4;
  new_var = ((char *) obj) + 0x12C;
  temp_fv0f = *((f32 *) new_var);
  temp_fv0f = temp_fv0f - (*((f32 *) (((char *) obj) + 0x120)));
  pos[1] = 0;
  temp_ft0 = (s32) temp_ft0f;
  temp_fv0 = (s32) temp_fv0f;
  new_var3 = 0;
  pos[new_var3] = temp_ft0;
  pos[2] = temp_fv0;
  vec3_normalize_fixed(&pos[new_var3], &pos[0]);
  {
    f32 fb = (f32) pos[2];
    func_8001BE68(obj + 0xB8, (f32) pos[new_var3], new_var3,
    fb, &tilt, &tiltB, &sp78);
  }
  tilt *= 114.0f;
  temp_fv1 = tiltB; temp_fv1 = (tiltB = temp_fv1 * 114.0f);
  if (temp_fv1 < (-500.0f))
  {
    tiltB = -500.0f;
  }
  if (tiltB > 500.0f)
  {
    tiltB = 500.0f;
  }
  *((s32 *) (((char *) view) + 0x7C)) = (s32) tiltB;
  *((s16 *) (((char *) view) + 0x10)) = (s16) (-(((func_8002D2C8(temp_fv0, temp_ft0) * 2) / 3) & 0xFFF));
}
