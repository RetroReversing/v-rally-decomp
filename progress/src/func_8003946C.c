typedef void (*SpriteHook)(void *);
#define H(p,o) (*(s16 *)((u8*)(p)+(o)))
#define U(p,o) (*(u16 *)((u8*)(p)+(o)))
#define W(p,o) (*(s32 *)((u8*)(p)+(o)))
#define B(p,o) (*((u8*)(p)+(o)))
#define A(p,o) (*(u8 **)((u8*)(p)+(o)))
typedef struct { u8 pad0[6]; u16 w; } Img;
typedef struct { u8 pad0[4]; Img **imgs; } Spr;
typedef struct {
  u8 pad0[0xc];
  s16 xc;
  s16 xe;
  u8 pad10[0x7a - 0x10];
  s16 x7a;
  u8 pad7c[0x9c - 0x7c];
  s16 x9c;
  s16 x9e;
  s32 flags;
  Spr *spr;
  u8 *owner;
} Obj;
extern u8 *gRecords;
extern u8 *g_camera;
extern u8 *find_object_by_id(s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
extern Spr *getTexturePack(void *, s32);
extern void updateStreamRate(void *);

/* Creates the race-list sprite objects, unless the race stage (gRecords+0x1E) is 7.
   With one player it adds one sprite for the current record row. With two players it adds
   one sprite per active row, using camera indices 1, 3, 5, ... */
void func_8003946C(void *parent, u8 *spr_data, s32 spr_id)
{
  u8 *records = gRecords;
  u8 *cam;
  u8 *cam_info;
  u8 *cam1;
  Spr *spr;
  Obj *obj;
  s32 x;
  s32 y;
  s32 z;
  s32 sum;
  s32 x_off;
  s32 cam_index;
  u32 row_index;
  char *rec_row;
  char *lrow;
  if (U(records, 0x1e) != 7)
  {
    if (U(records, 0xe) == 1)
    {
      rec_row = (char *) records;
      rec_row += B(records, 0x32) * 40;
      if (rec_row[0x48] & 2)
      {
        cam1 = find_object_by_id(1);
        x = H(A(cam1, 0x178), 0xc);
        y = H(A(cam1, 0x178), 0xe);
        g_camera = cam1;
        obj = ((Obj *)sprite_create(parent, 0, 0, (u16)((u16) spr_id), updateStreamRate, 1));
        obj->x9c = x - 63;
        obj->x9e = y - 42;
        spr = getTexturePack(spr_data + 0x4c, 0);
        obj->spr = spr;
        obj->xc = -(spr->imgs[0]->w >> 1);
        obj->xe = -3;
        obj->flags |= 0x20;
        obj->owner = g_camera;
      }
    }
    else
    {
      row_index = 1;
      if (U(records, 0xe) == 2)
      {
        cam_index = 1;
        do
        {
          lrow = (char *) gRecords;
          lrow += B(((u8 *) gRecords) + row_index, 0x31) * 40;
          if (lrow[0x48] & 2)
          {
            cam = find_object_by_id(cam_index);
            cam_info = A(cam, 0x178);
            x_off = 0;
            g_camera = cam;
            x = H(cam_info, 0xc);
            z = H(cam_info, 8);
            sum = H(cam_info, 0xa) + H(cam_info, 0xe);
            if (!(U(gRecords, 0x12) & 1))
            {
              x -= 16;
              x_off = (-(W(cam, 0xc) == 1)) & 20;
            }
            obj = ((Obj *)sprite_create(parent, 0, 0, (u16)((u16) spr_id), updateStreamRate, 1));
            obj->spr = getTexturePack(spr_data + 0x4c, 0);
            obj->x9c = (u16)(z + x) - 35 + x_off;
            obj->x9e = sum - 32;
            obj->xc = -(obj->spr->imgs[0]->w >> 1);
            obj->xe = -2;
            obj->flags |= 0x20;
            obj->owner = g_camera;
            obj->x7a = 1;
          }
          row_index++;
          cam_index += 2;
        }
        while (U(records, 0xe) >= row_index);
      }
    }
  }
}
