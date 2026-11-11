void *view_get_ctx_id(s32);
s32 draw_shaded_bar(s32, void *, void *, u8, u8, u8, u8, u8, u8);

/* Appends a G_SETENVCOLOR display list command (0xFB, env colour white) to the view's
 * display list, then draws the shaded bar with the given parameters. */
void func_8004CEB4(s32 viewId, void *pos, void *size, u8 r, u8 g, u8 b, u8 a, u8 p7, u8 p8)
{
  void *view;
  s32 *dl;
  view = view_get_ctx_id(viewId);
  dl = *((s32 **) (((char *) view) + 0x14));
  *((s32 **) (((char *) view) + 0x14)) = dl + 2;
  dl[0] = 0xFB000000;
  dl[1] = -1;
  draw_shaded_bar(viewId, pos, size, r, g, b, a, p7, p8);
}
