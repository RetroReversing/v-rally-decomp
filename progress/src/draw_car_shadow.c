#define CMD(a,b) {u32 *g=p; p+=2; g[0]=(a);g[1]=(b);}
void *gfx_get_dl(s32);
s32 gfx_set_dl(s32, void *);
s32 gfx_push_mtx(s32, s32);
s32 gfx_set_quad_pos(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 gfx_append_quad(s32, s32);
s32 gfx_set_quad_colors_shared_alpha(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 obj_mtx_visible(s32, void *, void *);
s32 mtx_pool_alloc();
s32 guMtxIdentF(void *);
extern u8 *g_camera;

/* Draws the car's ground shadow: a quad at the car's footprint (shape size from
 * the car's shape data), built as an RSP display list for gfx context gfx_ctx. */
void draw_car_shadow(s32 gfx_ctx)
{
  f32 mtx[4][4];
  f32 pos[3];
  f32 pos_x;
  s32 mtx_id;
  s32 col;
  u8 *shape;
  shape = *((u8 **) (g_camera + 0x178));
  guMtxIdentF(mtx);
  mtx_id = mtx_pool_alloc();
  mtx[3][0] = *((f32 *) (g_camera + 0x118));
  mtx[3][1] = *((f32 *) (g_camera + 0x11C));
  mtx[3][2] = *((f32 *) (g_camera + 0x120));
  obj_mtx_visible(mtx_id, g_camera + 0x38, mtx);
  {
    u32 *p = gfx_get_dl(gfx_ctx);
    CMD(0xE7000000, 0);
    CMD(0xE3000A01, 0x100000);
    CMD(0xE200001C, 0x504240);
    CMD(0xFCFFFFFF, 0xFFFE793C);
    CMD(0xD9FFF9FF, 0);
    CMD(0xD9FFFFFF, 0x200004);
    gfx_set_dl(gfx_ctx, p);
  }
  gfx_push_mtx(gfx_ctx, mtx_id);
  col = gfx_append_quad(gfx_ctx, 0) & 0xFFFF;
  pos[0] = pos_x = *((f32 *) (g_camera + 0x148));
  pos[2] = *((f32 *) (g_camera + 0x150));
  gfx_set_quad_pos(gfx_ctx, col,
    (s16) (-*((s16 *) (shape + 0xC)) - pos_x),
    (s16) (-*((u16 *) (shape + 0xE))),
    (s16) (-200.0f - pos[2]),
    (s16) (*((s16 *) (shape + 0xC)) - pos[0]),
    (s16) (-*((u16 *) (shape + 0xE))),
    (s16) (-200.0f - pos[2]),
    (s16) (*((s16 *) (shape + 0xC)) + pos[0]),
    (s16) (*((u16 *) (shape + 0xE))),
    (s16) (pos[2] + -200.0f),
    (s16) (-*((s16 *) (shape + 0xC)) + pos[0]),
    (s16) (*((u16 *) (shape + 0xE))),
    (s16) (pos[2] + -200.0f));
  gfx_set_quad_colors_shared_alpha(gfx_ctx, col, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80);
}
