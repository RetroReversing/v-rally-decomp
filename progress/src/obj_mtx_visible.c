extern u8 stream_state[];
extern f64 D_800A4008;
void guMtxCatF(void *, void *, void *);
void guMtxF2L(void *, s32);
void transposeMatrix4x4(void *, void *);
void vec3_transform_mtx3(void *, s32, s32, s32, void *, void *, void *);

/* Builds object obj's world matrix (its local matrix times parent_mtx), picks its
 * scale from the render config (0.5 or 1.0, times 1.328 in one mode, times the
 * object's own scale), and returns 1 when the object's three test values are all
 * under the limit (visible). When out_mtx is set, the fixed-point matrix is written there. */
s32 obj_mtx_visible(s32 out_mtx, u8 *obj, u8 *parent_mtx)
{
  s32 fixed_mtx[0x10];
  u8 *cfg;
  f64 lim;
  s32 v;
  guMtxCatF(obj + 0x40, obj, obj + 0x80);
  guMtxCatF(parent_mtx, obj + 0x80, obj + 0x80);
  cfg = *((u8 **) (&stream_state[0x32F2]));
  *((s32 *) (obj + 0x108)) = 0;
  if (((*((u16 *) (cfg + 0xE))) != 1) && ((*((u16 *) (cfg + 0x12))) != 1))
  {
    *((f32 *) (obj + 0x104)) = 0.5f;
  }
  else
  {
    *((f32 *) (obj + 0x104)) = 1.0f;
  }
  if ((*((u16 *) (&stream_state[0x32A8]))) == 1)
  {
    *((f32 *) (obj + 0x104)) = (*((f32 *) (obj + 0x104))) * 1.328f;
  }
  *((f32 *) (obj + 0x104)) = (*((f32 *) (obj + 0x104))) * (*((f32 *) (obj + 0xDC)));
  *((s32 *) (obj + 0x10C)) = 0;
  transposeMatrix4x4(obj + 0x80, fixed_mtx);
  vec3_transform_mtx3(fixed_mtx, *((s32 *) (obj + 0x104)), *((s32 *) (obj + 0x108)), *((s32 *) (obj + 0x10C)), obj + 0x110, obj + 0x114, obj + 0x118);
  lim = D_800A4008;
  if ((f64) __builtin_abs((s32) (*((f32 *) (obj + 0xB0)))) < lim) {
  if ((f64) __builtin_abs((s32) (*((f32 *) (obj + 0xB4)))) < lim) {
  if ((f64) __builtin_abs((s32) (*((f32 *) (obj + 0xB8)))) < lim) {
  if (out_mtx != 0)
  {
    guMtxF2L(obj + 0x80, out_mtx);
  }
  return 1; } } }
  return 0;
}
