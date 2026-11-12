typedef struct 
{
  u8 pad[0x184];
  void *assets[4];
  u8 p[0x8e];
  s16 slide;
  u8 q[4];
  s8 selected;
  u8 r;
  s8 type;
  u8 t[0x21];
  u8 alpha;
  u8 hidden;
  u8 active;
} Obj;
typedef struct 
{
  u8 p[4];
  void **node;
} Asset;
extern Obj *gSelectState;
extern u8 *gRecords;
extern void *D_800D05D8;
struct N { int p0; struct N *next; int p8; int key; };
extern struct N *find_object_by_id(int);
extern void func_8004C370(s32, void *);
extern void draw_select_entry(void *, s32);
void draw_palette_sprite(void *, s16, s16, void *);
extern void func_8004CEB4(void *, void *, void *, s32, s32, s32, s32, s32, s32);

/* Draws the four-slot strip for the active menu object: slides it into view,
 * places each slot that has an asset (the first two get a sliding x), draws
 * the slot icon and its label, and draws the label for the slot the cursor
 * is on. The strip is skipped while the object is hidden. */
void func_8005BCD4(void)
{
  struct 
  {
    s32 rec[16];
    u8 aa[4];
    u8 bb[4];
    u8 cc[4];
    u8 q[4];
    u8 pad[8];
    u8 text[10];
    u8 col[5];
    u8 p;
    f32 f;
    f32 g;
    s16 z;
    u8 pad2[14];
    s16 xy[4];
  } ds;
  Obj *menu;
  struct N *hud_list;
  u8 i;
  u8 saved_sel;
  s8 k;
  s8 j;
  menu = gSelectState;
  if (menu->hidden)
  {
    return;
  }
  ds.col[0] = menu->alpha;
  ds.col[2] = (ds.col[1] = 0xdc);
  ds.col[3] = 0x80;
  ds.z = 0;
  ds.col[4] = 0xff;
  ds.g = (ds.f = 1.0f);
  if (menu->slide < 0xc0)
  {
    menu->slide += 16;
  }
  for (j = 0; j < 4; j++)
  {
    ds.rec[12 + j] = 1;
    ds.aa[j] = 30;
    ds.bb[j] = 50;
    ds.cc[j] = 142;
  }

  ds.q[0] = (ds.q[1] = 210);
  ds.q[2] = (ds.q[3] = 50);
  hud_list = find_object_by_id(1);
  for (i = 0; i < (*((u16 *) (gRecords + 14))); i++)
  {
    register Obj *obj;
    obj = gSelectState;
    if (!obj->assets[i])
    {
      continue;
    }
    if (i < 2)
    {
      register u16 slide_x;
      slide_x = (u16) obj->slide;
      ds.xy[1] = (22 * (i & 1)) + 0x1a8;
      ds.rec[5] = (ds.rec[4] = (i & 2) * 400);
      ds.rec[7] = (ds.rec[6] = ds.rec[4] + 256);
      ds.rec[8] = ((i & 1) * 22) + 0x1aa;
      ds.rec[10] = (ds.rec[9] = ((i & 1) * 22) + 0x1be);
      ds.rec[11] = ((i & 1) * 22) + 0x1aa;
      ds.xy[0] = slide_x;
    }
    else
    {
      ds.xy[0] = 400;
      ds.xy[1] = ((i & 1) * 22) + 0x1a8;
    }
    func_8004C370(*((s32 *) (((u8 *) hud_list) + 0x178)), ds.rec);
    ds.xy[2] = (*((u16 *) (((u8 *) (*((Asset *) gSelectState->assets[i])->node)) + 6))) * ds.f;
    ds.xy[3] = (*((u16 *) (8 + ((u8 *) (*((Asset *) gSelectState->assets[i])->node))))) * ds.g;
    *((s16 *) (ds.text + 4)) = (i) ? (0x128) : (0x126);
    *((s16 *) (ds.text + 6)) = ((i & 2) * 256) + 42;
    *((s16 *) (ds.text + 8)) = ((i & 1) * 22) + 0x1ae;
    draw_select_entry(ds.text, 0);
    menu = gSelectState;
    saved_sel = 255;
    if (menu->active && (i == menu->selected))
    {
      saved_sel = i;
      for (j = 3; j >= 0; j--)
      {
        register u8 *game;
        register s8 jv;
        game = gRecords;
        jv = j;
        #ifdef PORT
        if (*((u8 *)game + jv + 0x32) == menu->type)
#else
        if (*((u8 *)((s32) game + (s32) jv + 0x32)) == menu->type)
#endif
        {
          break;
        }
      }

      i = j;
    }
    if (gSelectState->assets[i])
    {
      func_8004CEB4(D_800D05D8, *((Asset *) gSelectState->assets[i])->node, ds.xy, 0, ds.col[4], ds.col[4], ds.col[4], ds.col[4], 0);
    }
    if ((ds.xy[0] - 64) >= 0)
    {
      register u8 *game2;
      register u8 car_idx;
      game2 = gRecords;
      #ifdef PORT
      car_idx = *((u8 *)game2 + i + 0x32);
#else
      car_idx = *((u8 *)((s32) game2 + (s32) i + 0x32));
#endif
      draw_palette_sprite((void *)(ds.text), (s16)(ds.xy[0] - 48), (s16)(*((s16 *) (ds.text + 8))), (void *)(game2 + ((car_idx * 40) + 68)));
    }
    if (gSelectState->active && (saved_sel == gSelectState->selected))
    {
      i = saved_sel;
    }
  }

}
