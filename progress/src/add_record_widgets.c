typedef void (*SpriteHook)(void *);
typedef struct { u8 p[0xE]; u16 count; } State;
typedef struct Tex3 {u16 h0,h2,type,width,height;u8 a,b;u32 c;u8 **pal,**image;u32 x,y;} Tex3;
typedef struct {u8 count,pad[3];Tex3 **tex;} Pack3;
typedef struct { u8 pad[8]; s16 x; s16 y; s16 w; s16 h; } Rect;
typedef struct { u8 pad[0xC]; s32 kind; u8 pad2[0x168]; Rect *rect; } Obj;
typedef struct { u8 pad[0xA4]; void *pack; void *obj; } Widget;
extern Pack3 *getTexturePack(s32 id, s32 extra, s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
extern Obj *find_object_by_id(int arg0);
extern u8 func_800556C4(void *arg0);
extern void func_80055738(void *);
extern u8 *gRecords;
extern Obj *g_camera;
extern void voice_update_from_cue(void *);
extern void func_8003C864(void *);
static inline u8 *record_entry(u8 idx)
{
  return gRecords + (idx * 40);
}

static inline int offset_by(s32 a, int b)
{
  return a - b;
}

/* For the current mode, adds the widgets for each record entry (count from gRecords' state)
 * into the panel at arg0, using arg1 as the base index for the pack and arg2 as the row flag. */
void add_record_widgets(s32 panel, s32 base_id, s32 row_flag)
{
  State *st = (State *)gRecords;
  u16 mode = *((u16 *) ((u8 *)st + 0x1E));
  Pack3 *pack;
  s32 width;
  u32 count;
  u32 i;
  Obj *obj;
  s32 label_x;
  Rect *rect;
  s32 x;
  s32 y;
  s32 w;
  s32 k;
  u16 h;
  Widget *widget;
  x = 5;
  if ((mode != 7) && ((mode != 0) & (mode != x)))
  {
    pack = getTexturePack(base_id + 0x4C, 0, mode);
    func_80055738(pack);
    count = st->count;
    width = pack->tex[0]->width;
    for (i = 1; i <= count; i++)
    {
      obj = find_object_by_id(offset_by(i * 2, 1));
      rect = obj->rect;
      g_camera = obj;
      x = (*rect).x;
      w = rect->w;
      y = rect->y;
      label_x = x + 0x14;
      k = offset_by(w, 0x10);
      h = offset_by(rect->h, 8);
      switch (st->count)
      {
        case 1:
          ((Widget *)sprite_create((void *)(panel), offset_by(offset_by(k, width), 0x18), 0x1B, (u16)(row_flag), voice_update_from_cue, 0))->pack = pack;
          func_800556C4(pack);
          if (record_entry(gRecords[0x32])[0x48] & 1)
          {
            widget = ((Widget *)sprite_create((void *)(panel), offset_by(w, 0x66), y + 7, (u16)(row_flag), func_8003C864, 0));
            widget->pack = pack;
            widget->obj = g_camera;
            func_800556C4(pack);
          }
          break;
        case 2:
          if ((*((u16 *) (gRecords + 0x12))) & 1)
          {
            ((Widget *)sprite_create((void *)(panel), offset_by(w, 0x12), y + 7, (u16)(row_flag), voice_update_from_cue, 0))->pack = pack;
            func_800556C4(pack);
          }
          else
          {
            if (obj->kind == 3)
            {
              label_x = x + 6;
            }
            ((Widget *)sprite_create((void *)(panel), label_x, h + 0xFFF7, (u16)(row_flag), voice_update_from_cue, 0))->pack = pack;
            func_800556C4(pack);
          }
          break;
      }
    }
  }
}
