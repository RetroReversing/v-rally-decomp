typedef struct 
{
  u32 w0;
#ifdef PORT
  uintptr_t w1;
#else
  u32 w1;
#endif
} Gfx;
typedef struct Obj
{
  s32 x;
  s32 y;
  s32 z;
  s16 v0[3];
  s16 v2[3];
  s16 v1[3];
  s16 pad;
  s32 flags;
} Obj;
typedef struct Xform
{
  f32 mat[4][4];
  u16 origin[3];
  s32 offset[3];
} Xform;
typedef struct Size
{
  u8 pad[6];
  u16 w;
  u16 h;
} Size;
#ifdef PORT
int abs(int);
#endif
Gfx *gfx_get_dl(void *);
void gfx_set_dl(void *, Gfx *);
void gfx_push_mtx(void *, s32);
void gfx_set_quad_pos(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80006EF8(void *, s32);
void gfx_set_quad_color(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void texture_build_dl(void *, void *, s32);
void gfx_set_quad_uv(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 obj_mtx_visible(s32, void *, Xform *);
s32 mtx_pool_alloc(void);
void guMtxIdentF(void *);
extern u8 D_8009EB00[];
extern u8 D_8009EB40[];
extern s32 gShadeMode;
extern f64 D_800A4A60;
extern u8 stream_state[];

/* Draws a run of track objects. Objects with flags bit 0 set are drawn in
 * chains: the first in-range object sets up the display list (texture/palette
 * commands) and starts a run, following objects in the run are kept when they
 * lie within a small distance of the previous one, and each kept object emits
 * its textured quad. Walks `count + 1` objects from `obj` and returns nothing. */
void func_8002F270(void *ctx, Obj *obj, s32 count, Size *size, void *gfx_ctx)
{
  u8 loaded;
  Xform tr;
  s16 delta[3];
  u8 setup;
  s32 first;
  s32 result;
  
  s32 dist;
  s32 dist_x;
  s16 dx;
  s16 dy;
  s16 dz;
  u8 *cam;
  Gfx *g;
  u16 id;
  f64 limit;
  loaded = 0;
  result = 0;
  *((u16 *) (((u8 *) gfx_ctx) + 0x78)) = 0;
  guMtxIdentF(tr.mat);
  first = 1;
  setup = 0;
  if (count--)
  {
    limit = D_800A4A60;
    do
    {
      if (obj->flags & 1)
      {
        if (!loaded)
        {
          texture_build_dl(gfx_ctx, size, 0);
          loaded = 1;
        }
        if (first)
        {
          first = 0;
          if (!setup)
          {
            setup = first + 1;
            g = gfx_get_dl(gfx_ctx);
            
            if (gShadeMode == 5)
            {
              Gfx *_g = g++;
              _g->w0 = 0xDE000000;
              #ifdef PORT
              _g->w1 = (uintptr_t) D_8009EB40;
#else
              _g->w1 = (u32) D_8009EB40;
#endif
            }
            else
            {
              Gfx *_g = g++;
              _g->w0 = 0xDE000000;
              #ifdef PORT
              _g->w1 = (uintptr_t) D_8009EB00;
#else
              _g->w1 = (u32) D_8009EB00;
#endif
            }
            {
              Gfx *_g = g++;
              _g->w0 = 0xDE000000;
#ifdef PORT
              _g->w1 = (uintptr_t) D_8009EB00;
#else
              _g->w1 = (u32) D_8009EB00;
#endif
            }
            {
              Gfx *_g = g++;
              _g->w0 = 0xFA000000;
              _g->w1 = ((stream_state[0x6C27] << 24) | (stream_state[0x6C27] << 16)) | (stream_state[0x6C27] << 8);
            }
            {
              Gfx *_g = g++;
              _g->w0 = 0xFB000000;
              _g->w1 = (((stream_state[0x6C26] << 24) | (stream_state[0x6C26] << 16)) | (stream_state[0x6C26] << 8)) | stream_state[0x6C28];
            }
            gfx_set_dl(gfx_ctx, g);
          }
          dist = mtx_pool_alloc();
          tr.mat[3][0] = obj->x;
          tr.mat[3][1] = obj->y;
          tr.mat[3][2] = obj->z;
          tr.origin[0] = obj->x;
          tr.origin[1] = obj->y;
          tr.origin[2] = obj->z;
          tr.offset[0] = 0;
          tr.offset[1] = 0;
          tr.offset[2] = 0;
          cam = *((u8 **) (stream_state + 0x7CD6));
          dist_x = (*((f32 *) (cam + 0x118))) - ((f32) obj->x);
          if (__builtin_abs(dist_x) <= 6000)
          {
            s32 dz2 = (*((f32 *) (cam + 0x120))) - ((f32) obj->z);
            if (__builtin_abs(dz2) < 6001)
            {
              result = obj_mtx_visible(dist, cam + 0x38, &tr);
              if (result == 1)
              {
                gfx_push_mtx(gfx_ctx, dist);
              }
            }
            else
            {
              result = 0;
            }
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          dx = obj->x - tr.origin[0];
          delta[0] = dx;
          dy = obj->y - tr.origin[1];
          delta[1] = dy;
          dz = obj->z - tr.origin[2];
          delta[2] = dz;
          if (((((f64) abs(dx)) < limit) && (((f64) abs(dy)) < limit)) && (((f64) abs(dz)) < limit))
          {
            s32 e = obj->y;
            e = e - (*((s32 *) ((*((u8 **) (((u8 *) ctx) + 0x5C))) + 0x58)));
            e = __builtin_abs(e);
            if (e < 160)
            {
              tr.offset[0] = dx;
              tr.offset[1] = dy;
              tr.offset[2] = dz;
              goto draw;
            }
          }
          obj--;
          count++;
          first = 1;
          result = 0;
        }
        draw:
        if (result == 1)
        {
          id = func_80006EF8(gfx_ctx, 0);
          gfx_set_quad_pos(gfx_ctx, id, (s16) tr.offset[0], (s16) tr.offset[1], (s16) tr.offset[2], (s16) (obj->v0[0] + tr.offset[0]), (s16) (obj->v0[1] + tr.offset[1]), (s16) (obj->v0[2] + tr.offset[2]), (s16) (obj->v1[0] + tr.offset[0]), (s16) (obj->v1[1] + tr.offset[1]), (s16) (obj->v1[2] + tr.offset[2]), (s16) (obj->v2[0] + tr.offset[0]), (s16) (obj->v2[1] + tr.offset[1]), (s16) (obj->v2[2] + tr.offset[2]));
          gfx_set_quad_color(gfx_ctx, id, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
          gfx_set_quad_uv(gfx_ctx, id, 0, 0, size->w, 0, size->w, size->h, 0, size->h);
        }
        else
        {
          first = 1;
        }

      }
      obj++;
    }
    while (count--);
  }
}
