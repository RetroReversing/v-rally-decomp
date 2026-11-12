extern void *gSceneSlot2;
extern void *g_camera;
s32 obj_get_owner();
s32 view_gfx_setup();
s32 gfx_clear_zbuffer_rect();
void *find_object_by_id();
s32 func_800489D8();

/* Makes object 0 the active camera, sets up its view in the display list at +0x178, then
 * clears the z-buffer rectangle of that list. The rectangle size comes from obj_get_owner. */
void func_80048ADC(void)
{
  void *cam;
  void *gfx;
  s32 v;

  cam = find_object_by_id(0);
  gfx = *(void **) ((char *) cam + 0x178);
  g_camera = cam;
  view_gfx_setup(gfx);
  v = obj_get_owner(gSceneSlot2);
  gfx = *(void **) ((char *) g_camera + 0x178);
  gfx_clear_zbuffer_rect(gfx, v, (char *) gfx + 8);
  func_800489D8();
}
