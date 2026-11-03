typedef struct 
{
  u32 w0;
  u32 w1;
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
Gfx *func_80006008(void *);
void func_80006014(void *, Gfx *);
void func_800061FC(void *, s32);
void func_800068C0(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80006EF8(void *, s32);
void func_800071EC(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_800075BC(void *, void *, s32);
void func_80008B28(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80010BFC(s32, void *, Xform *);
s32 func_8001BD1C(void);
void guMtxIdentF(void *);
extern u8 D_8009EB00[];
extern u8 D_8009EB40[];
extern s32 D_8009FF30;
extern f64 D_800A4A60;
extern u8 D_800C02AE[];
void func_8002F270(void *arg0, Obj *obj, s32 count, Size *size, void *arg4)
{
  u8 loaded;
  Xform tr;
  s16 delta[3];
  u8 setup;
  s32 first;
  s32 result;
  
  s32 d;
  s32 d2;
  s16 dx;
  s16 dy;
  s16 dz;
  u8 *cam;
  Gfx *g;
  u16 id;
  f64 lim;
  loaded = 0;
  result = 0;
  *((u16 *) (((u8 *) arg4) + 0x78)) = 0;
  guMtxIdentF(tr.mat);
  first = 1;
  setup = 0;
  if (count--)
  {
    lim = D_800A4A60;
    do
    {
      if (obj->flags & 1)
      {
        if (!loaded)
        {
          func_800075BC(arg4, size, 0);
          loaded = 1;
        }
        if (first)
        {
          first = 0;
          if (!setup)
          {
            setup = first + 1;
            g = func_80006008(arg4);
            
            if (D_8009FF30 == 5)
            {
              Gfx *_g = g++;
              _g->w0 = 0xDE000000;
              _g->w1 = (u32) D_8009EB40;
            }
            else
            {
              Gfx *_g = g++;
              _g->w0 = 0xDE000000;
              _g->w1 = (u32) D_8009EB00;
            }
            {
              Gfx *_g = g++;
              _g->w0 = 0xDE000000;
              _g->w1 = (u32) D_8009EB00;
            }
            {
              Gfx *_g = g++;
              _g->w0 = 0xFA000000;
              _g->w1 = ((D_800C02AE[0x6C27] << 24) | (D_800C02AE[0x6C27] << 16)) | (D_800C02AE[0x6C27] << 8);
            }
            {
              Gfx *_g = g++;
              _g->w0 = 0xFB000000;
              _g->w1 = (((D_800C02AE[0x6C26] << 24) | (D_800C02AE[0x6C26] << 16)) | (D_800C02AE[0x6C26] << 8)) | D_800C02AE[0x6C28];
            }
            func_80006014(arg4, g);
          }
          d = func_8001BD1C();
          tr.mat[3][0] = obj->x;
          tr.mat[3][1] = obj->y;
          tr.mat[3][2] = obj->z;
          tr.origin[0] = obj->x;
          tr.origin[1] = obj->y;
          tr.origin[2] = obj->z;
          tr.offset[0] = 0;
          tr.offset[1] = 0;
          tr.offset[2] = 0;
          cam = *((u8 **) (D_800C02AE + 0x7CD6));
          d2 = (*((f32 *) (cam + 0x118))) - ((f32) obj->x);
          if (d2 < 0)
          {
            d2 = -d2;
          }
          result = 0;
          if (d2 <= 6000)
          {
            s32 dz2 = (*((f32 *) (cam + 0x120))) - ((f32) obj->z);
            if (dz2 < 0)
            {
              dz2 = -dz2;
            }
            if (dz2 < 6001)
            {
              result = func_80010BFC(d, cam + 0x38, &tr);
              if (result == 1)
              {
                func_800061FC(arg4, d);
              }
            }
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
          if (((((f64) abs(dx)) < lim) && (((f64) abs(dy)) < lim)) && (((f64) abs(dz)) < lim))
          {
            d = obj->y;
            d = d - (*((s32 *) ((*((u8 **) (((u8 *) arg0) + 0x5C))) + 0x58)));
            if (d < 0)
            {
              d = -d;
            }
            if (d < 160)
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
          id = func_80006EF8(arg4, 0);
          func_800068C0(arg4, id, (s16) tr.offset[0], (s16) tr.offset[1], (s16) tr.offset[2], (s16) (obj->v0[0] + tr.offset[0]), (s16) (obj->v0[1] + tr.offset[1]), (s16) (obj->v0[2] + tr.offset[2]), (s16) (obj->v1[0] + tr.offset[0]), (s16) (obj->v1[1] + tr.offset[1]), (s16) (obj->v1[2] + tr.offset[2]), (s16) (obj->v2[0] + tr.offset[0]), (s16) (obj->v2[1] + tr.offset[1]), (s16) (obj->v2[2] + tr.offset[2]));
          func_800071EC(arg4, id, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
          func_80008B28(arg4, id, 0, 0, size->w, 0, size->w, size->h, 0, size->h);
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

