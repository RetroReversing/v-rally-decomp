void *gfx_get_dl(s32);
s32 gfx_set_dl(s32, void *);
s32 gfx_push_mtx(s32, s32);
s32 gfx_set_quad_pos(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 gfx_append_quad(s32, s32);
s32 gfx_set_quad_color(s32, s32, u8, u8, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 obj_mtx_visible(s32, void *, void *);
s32 mtx_pool_alloc();
f32 func_8001BE68(void *, f32, f32, f32, f32 *, f32 *, f32 *);
s32 smoke_update_particles(s16 *, s32);
s32 guMtxIdentF(void *);
extern s32 D_8009F5F8;
extern void *g_camera;
extern void *g_ent_list;

/* Projects each 0x14-byte entry of the sprite list in 'recs' into screen space
 * with the current camera matrix, and emits a display-list quad for every
 * entry that lands in front of the camera. Entries that fail the test get
 * their y set to the off-screen marker 1001. */
void func_8003678C(s16 *recs, s32 dl, u8 mode)
{
  s32 off_screen_y;
  f32 mtx[16];
  f32 screen_pos[4];
  volatile f32 scale[4];
  f32 obj_x;
  f32 obj_y;
  f32 temp_fv0;
  s16 rec_y;
  s32 tex;
  s32 mtx_slot;
  s32 tex_raw;
  char *new_var;
  s32 count;
  s32 drawn_any;
  void *dl_cmd;

  guMtxIdentF(&mtx);
  drawn_any = 0;
  mtx_slot = mtx_pool_alloc();
  mtx[12] = *((f32 *) (((char *) g_camera) + 0x118));
  mtx[13] = *((f32 *) (((char *) g_camera) + 0x11C));
  mtx[14] = *((f32 *) (((char *) g_camera) + 0x120));
  obj_mtx_visible(mtx_slot, g_camera + 0x38, &mtx);
  smoke_update_particles(recs, mode & 0xFF);
  dl_cmd = gfx_get_dl(dl);
  *((s32 *) (((char *) dl_cmd) + 0)) = 0xDE000000;
  *((s32 **) (((char *) dl_cmd) + 4)) = &D_8009F5F8;
  gfx_set_dl(dl, dl_cmd + 8);
  count = *((s32 *) (((char *) g_ent_list) + 8));
  new_var = ((char *) recs) + 15;
  if ((count--) != 0)
  {
    off_screen_y = 0x3E9;
    do
    {
      rec_y = *((s16 *) (((char *) recs) + 2));
      if ((((((((rec_y != 0) && ((temp_fv0 = func_8001BE68(g_camera + 0xB8, (f32) (*recs), (f32) rec_y, (f32) (*((s16 *) (((char *) recs) + 4))), &screen_pos[0], &screen_pos[1], &screen_pos[2]), screen_pos[0] < 1.0f))) && (screen_pos[0] > (-1.0f))) && (screen_pos[1] < 1.0f)) && (screen_pos[1] > (-1.0f))) && (screen_pos[2] < 1.0f)) && (screen_pos[2] > (-1.0f))) && (((f64) temp_fv0) >= 0.0))
      {
        if (!(drawn_any & 0xFF))
        {
          drawn_any = 1;
          gfx_push_mtx(dl, mtx_slot);
        }
        tex_raw = gfx_append_quad(dl, 0);
        obj_x = *((f32 *) (((char *) g_camera) + 0x148));
        scale[0] = obj_x;
        obj_y = *((f32 *) (((char *) g_camera) + 0x150));
        scale[2] = obj_y;
        tex = tex_raw & 0xFFFF;
        gfx_set_quad_pos(dl, tex, (s16) ((s32) (((f32) (*recs)) - obj_x)), *((s16 *) (((char *) recs) + 2)), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) recs) + 4)))) - obj_y))), (s32) ((s16) ((s32) ((((f32) (*recs)) - scale[0]) + 2.0f))), (s32) ((s16) (((u16) (*((s16 *) (((char *) recs) + 2)))) + 2)), (s32) ((s16) ((s32) ((((f32) (*((s16 *) (((char *) recs) + 4)))) - scale[2]) + 2.0f))), (s32) ((s16) ((s32) ((((f32) (*((s16 *) (((char *) recs) + 6)))) + scale[0]) + 1.0f))), (s32) ((s16) ((*((u16 *) (((char *) recs) + 8))) + 1)), (s32) ((s16) ((s32) ((((f32) (*((s16 *) (((char *) recs) + 10)))) + scale[2]) + 1.0f))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) recs) + 6)))) + scale[0]))), (s32) ((s16) (*((u16 *) (((char *) recs) + 8)))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) recs) + 10)))) + scale[2]))));
        gfx_set_quad_color(dl, tex, *((u8 *) (((char *) recs) + 13)), *((u8 *) (((char *) recs) + 14)), (s32) (*((u8 *) (((char *) recs) + 15))), (s32) (*((u8 *) (((char *) recs) + 13))), (s32) (*((u8 *) (((char *) recs) + 14))), (s32) (*((u8 *) (((char *) recs) + 15))), (s32) (*((u8 *) (((char *) recs) + 16))), (s32) (*((u8 *) (((char *) recs) + 17))), (s32) (*((u8 *) (((char *) recs) + 18))), (s32) (*((u8 *) (((char *) recs) + 13))), (s32) (*((u8 *) (((char *) recs) + 17))), (s32) (*((u8 *) (((char *) recs) + 18))));
      }
      else
      {
        *((s16 *) (((char *) recs) + 2)) = (s16) off_screen_y;
      }
      recs += 0xA;
    }
    while ((count--) != 0);
  }
}
