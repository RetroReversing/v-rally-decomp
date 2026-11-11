/* Appends a G_TRI1 command for vertices v0, v1, v2 (each masked to 5 bits) to the
 * display list whose write pointer is at ctx+0x14, then advances that pointer by 8. */
void gfx_add_tri1(void *ctx, s32 v0, s32 v1, s32 v2)
{
  void *dl;
  dl = *((void **) (((s8 *) ctx) + 0x14));
  *((s32 *) (((s8 *) dl) + 0)) = (s32) (((((v0 & 0x1F) << 0x11) | ((v1 & 0x1F) << 9)) | ((v2 & 0x1F) * 2)) | 0x05000000);
  *((s32 *) (((s8 *) dl) + 4)) = 0;
  dl = (*((void **) (((s8 *) ctx) + 0x14))) + 8;
  *((void **) (((s8 *) ctx) + 0x14)) = (void *) dl;
}
