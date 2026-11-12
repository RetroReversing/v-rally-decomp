#define sp60 rect.x
#define sp62 rect.y
#define sp64 rect.w
#define sp66 rect.h
void *view_get_ctx_id(void *);
void *gfx_get_dl(void *);
s32 gfx_set_dl(void *, void *);
s32 gfx_push_mtx(void *, s32);
s32 vertex_record_set_xy(void *, s32, s16, s16);
s32 func_80006984(void *, s32, s32, s32, s32);
u16 gfx_add_quad_tris(void *);
s32 func_80008770(void *, void *, s32, s16 *);
s32 func_80008C58(void *, s32, s32, s32);
s32 mtx_pool_alloc();
s32 guMtxF2L(void *, s32);
s32 guMtxIdent(void *);
s32 guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
extern void *gSceneSlot0;
extern s32 D_800A0310;
extern s16 D_800A0370[];
extern s16 D_800A0372;
extern s16 D_800A0374;
extern s16 D_800A0376;
extern char stream_state[];

/* Builds the display list for a strip of rectangles: sets up an ortho projection
 * from the screen size (screen+0xC/0xE), then draws the strip in rows of the
 * height taken from the tex descriptor (+0x8 total, +0xC row size, +0x6 width),
 * and finally emits the bounds rectangle taken from gSceneSlot0. */
void draw_rect_strips(void *screen, void *tex)
{
  f32 ortho[4][4];
  struct 
  {
    s16 x;
    s16 y;
    u16 w;
    u16 h;
    s32 extra[2];
  } rect;
  f32 row_scale;
  s32 y;
  s32 proj_mtx_l;
  u32 v_base_hi;
  u32 v_base_b;
  int v_base;
  u32 v_base_c;
  s32 v_base_d;
  u16 h_total;
  u16 row_count;
  u16 strip_h;
  void *out;
  void *out2;
  void *bounds;
  void *ident;
  void *gfx;
  u32 cmd;
  u32 v_base_e;
  struct Packet
  {
    u32 w0;
    #ifdef PORT
    uintptr_t w1;
#else
    u32 w1;
#endif

  } *cursor;
  struct Packet *pkt;
  ident = stream_state + 0x80D2;
  guMtxIdent(ident);
  gfx = view_get_ctx_id(screen);
  cursor = gfx_get_dl(gfx);
  pkt = cursor++;
  cmd = 0xDA380003;
  pkt->w0 = 0xDE000000;
  #ifdef PORT
  pkt->w1 = (uintptr_t) (&D_800A0310);
#else
  pkt->w1 = (u32) (&D_800A0310);
#endif

  cursor->w0 = cmd;
  #ifdef PORT
  cursor->w1 = (uintptr_t) ident;
#else
  cursor->w1 = (u32) ident;
#endif

  cursor++;
  gfx_set_dl(gfx, cursor);
  y = 0;
  proj_mtx_l = mtx_pool_alloc();
  guOrthoF(ortho, 0, (f32) (*((s16 *) (((char *) screen) + 0xC))), (f32) (*((s16 *) (((char *) screen) + 0xE))), 0, -1.0f, 10.0f, 1.0f);
  guMtxF2L(ortho, proj_mtx_l);
  gfx_push_mtx(gfx, proj_mtx_l);
  out = *((void **) (((char *) gfx) + 0x14));
  #ifdef PORT
  *((void **) (((char *) gfx) + 0x14)) = (void *) ((char *) out + sizeof(struct Packet));
#else
  *((void **) (((char *) gfx) + 0x14)) = (void *) (out + 8);
#endif

  #ifdef PORT
  ((struct Packet *) out)->w0
#else
  *((s32 *) (((char *) out) + 0))
#endif
 = (0xED000000 | ((((s32) (((f32) D_800A0370[0]) * 4.0f)) & 0xFFF) << 12)) | (((s32) (((f32) D_800A0372) * 4.0f)) & 0xFFF);
  #ifdef PORT
  ((struct Packet *) out)->w1
#else
  *((s32 *) (((char *) out) + 4))
#endif
 = (s32) (((((s32) (((f32) ((D_800A0370[0] + D_800A0374) - 1)) * 4.0f)) & 0xFFF) << 0xC) | (((s32) (((f32) ((D_800A0372 + D_800A0376) - 1)) * 4.0f)) & 0xFFF));
  row_count = *((u16 *) (((char *) tex) + 8));
  row_scale = ((f32) (*((s16 *) (((char *) screen) + 0xE)))) / ((f32) row_count);
  if (row_count != 0)
  {
    do
    {
      sp60 = 0;
      sp62 = y;
      sp64 = *((u16 *) (((char *) tex) + 6));
      h_total = *((u16 *) (((char *) tex) + 8));
      strip_h = *((u16 *) (((char *) tex) + 0xC));
      if (y < (h_total - strip_h))
      {
        sp66 = strip_h;
      
      func_80008770(gfx, tex, 0, &sp60);}
      else
      {
        sp66 = h_total - y;
      
      func_80008770(gfx, tex, 0, &sp60);}
      v_base = gfx_add_quad_tris(gfx) & 0xFFFF;
      v_base_d = v_base & 0xFFFF;
      v_base_b = (s32) (((f32) y) * row_scale);
      vertex_record_set_xy(gfx, v_base_d, 0, (s16) v_base_b);
      v_base_c = (u16) (v_base + 1);
      vertex_record_set_xy(gfx, v_base_c, *((s16 *) (((char *) screen) + 0xC)), (s16) v_base_b);
      v_base_e = (u16) (v_base + 2);
      vertex_record_set_xy(gfx, v_base_e, *((s16 *) (((char *) screen) + 0xC)), (s16) ((s32) (((f32) (((s16) sp66) + y)) * row_scale)));
      ;
      v_base_hi = (u16)(v_base + 3);
      vertex_record_set_xy(gfx, v_base_hi, 0, (s16) ((s32) (((f32) (((s16) sp66) + y)) * row_scale)));
      func_80008C58(gfx, v_base_d, 0, 0);
      func_80008C58(gfx, v_base_c, (sp64 - 1) & 0xFFFF, 0);
      func_80008C58(gfx, v_base_e, (sp64 - 1) & 0xFFFF, (sp66 - 1) & 0xFFFF);
      func_80008C58(gfx, v_base_hi, 0, (sp66 - 1) & 0xFFFF);
      func_80006984(gfx, v_base_d, 0xFF, 0xFF, 0xFF);
      func_80006984(gfx, v_base_c, 0xFF, 0xFF, 0xFF);
      func_80006984(gfx, v_base_e, 0xFF, 0xFF, 0xFF);
      func_80006984(gfx, v_base_hi, 0xFF, 0xFF, 0xFF);
      y += *((u16 *) (((char *) tex) + 0xC));
    }
    while (y < ((s32) (*((u16 *) (((char *) tex) + 8)))));
  }
  bounds = gSceneSlot0;
  out2 = *((void **) (((char *) gfx) + 0x14));
  #ifdef PORT
  *((void **) (((char *) gfx) + 0x14)) = (void *) ((char *) out2 + sizeof(struct Packet));
#else
  *((void **) (((char *) gfx) + 0x14)) = (void *) (out2 + 8);
#endif

  #ifdef PORT
  ((struct Packet *) out2)->w0
#else
  *((s32 *) (((char *) out2) + 0))
#endif
 = (0xED000000 | ((((s32) (((f32) (*((s16 *) (((char *) bounds) + 0)))) * 4.0f)) & 0xFFF) << 12)) | (((s32) (((f32) (*((s16 *) (((char *) bounds) + 2)))) * 4.0f)) & 0xFFF);
  #ifdef PORT
  ((struct Packet *) out2)->w1
#else
  *((s32 *) (((char *) out2) + 4))
#endif
 = (s32) (((((s32) (((f32) (((*((s16 *) (((char *) bounds) + 0))) + (*((s16 *) (((char *) bounds) + 4)))) - 1)) * 4.0f)) & 0xFFF) << 0xC) | (((s32) (((f32) (((*((s16 *) (((char *) bounds) + 2))) + (*((s16 *) (((char *) bounds) + 6)))) - 1)) * 4.0f)) & 0xFFF));
}
