typedef struct Obj356
{
#ifdef PORT
  void *x;
#else
  s32 x;
#endif
  u16 mode;
  s8 b6;
  s8 b7;
  u32 n;
  s32 c;
  void *p;
  void *q;
  f32 f18;
  f32 f1c;
  f32 f20;
  f32 f24;
  f32 f28;
  f32 f2c;
  void *cb;
  void *cb2;
  f32 x38;
  f32 x3c;
  f32 x40;
} Obj356;
typedef struct
{
  char pad[0x118];
  f32 x;
  f32 y;
  f32 z;
} N356;
typedef struct
{
  char pad[0xE];
  u16 hE;
  char pad2[0xE];
  u16 h1E;
} R356;
extern s8 gStreamLastValue;
extern u8 g_dark_mode[];
#define g_dark_mode g_dark_mode[0]
extern s32 gShadeMode;
extern Obj356 *g_ent_list;
extern N356 *g_camera;
extern R356 *gRecords;
void *getTexturePack(void *, s32);
void func_80035B04(void *);
void func_80036260(void *);
void func_80036C48(void *, Obj356 *);
N356 *find_object_by_id(s32);
void *poolAlloc(s32, s32);
void update_part_scroll(void);
void track_draw_visible_tris(void);
void smoke_update_particles(void);
void func_8003678C(void);

/* Allocates and sets up the per-mode state object (g_ent_list) for the
 * current game state arg0; mode picks the layout and the work buffers. */
void ent_list_setup(char *arg0)
{
  N356 *ref_node;
  u32 count;
  u16 h1e;

  g_ent_list = poolAlloc(1, 0x44);
  g_ent_list->mode = gShadeMode;
  ref_node = find_object_by_id(1);
  g_ent_list->f18 = ref_node->x;
  g_ent_list->f18 = ref_node->y;
  g_ent_list->f20 = ref_node->z;
  g_ent_list->f24 = ref_node->x;
  g_ent_list->f24 = ref_node->y;
  g_ent_list->f2c = ref_node->z;
  g_camera = ref_node;
  gStreamLastValue = 0;
  switch (g_ent_list->mode)
  {
    case 0:
      g_ent_list->x = 0;
      g_ent_list->p = 0;
      g_ent_list->q = 0;
      if (g_dark_mode == 0)
      {
        g_ent_list->x38 = *(s32 *) (arg0 + 0x420);
        g_ent_list->x3c = (f32) -*(s32 *) (arg0 + 0x46C) * 0.1f;
        g_ent_list->x40 = *(s32 *) (arg0 + 0x4B8);
        func_80036C48(arg0, g_ent_list);
      }
      break;
    case 3:
      count = *(s32 *) (arg0 + 0xDC) - 50;
      g_ent_list->n = count;
      if ((u32) (g_dark_mode - 1) < 2 || (h1e = gRecords->h1E) == 5 || (h1e != 0 && h1e < 5))
        g_ent_list->n = g_ent_list->n / 3;
      else if (g_dark_mode == 3)
        g_ent_list->n = count >> 2;
      g_ent_list->b7 = *(s32 *) (arg0 + 0x128);
      g_ent_list->cb = smoke_update_particles;
      g_ent_list->x = 0;
      g_ent_list->cb2 = func_8003678C;
      g_ent_list->p = poolAlloc(1, g_ent_list->n * 20);
      if (gRecords->hE == 2)
      {
        g_ent_list->q = poolAlloc(1, g_ent_list->n * 20);
        func_80036260(g_ent_list->p);
        func_80036260(g_ent_list->q);
      }
      else
      {
        g_ent_list->q = 0;
        func_80036260(g_ent_list->p);
      }
      break;
    case 4:
      {
      u32 c4 = *(u32 *) (arg0 + 0x174);
      g_ent_list->n = c4;
      if ((u32) (g_dark_mode - 1) < 2)
        g_ent_list->n = c4 >> 1;
      else if (g_dark_mode == 3)
        g_ent_list->n = c4 >> 2;
      }
      g_ent_list->c = *(s32 *) (arg0 + 0x1C0);
      g_ent_list->b6 = *(s32 *) (arg0 + 0x20C);
      g_ent_list->b7 = *(s32 *) (arg0 + 0x258);
#ifdef PORT
      g_ent_list->x = getTexturePack(arg0 + 0x260, 0);
#else
      g_ent_list->x = (s32) getTexturePack(arg0 + 0x260, 0);
#endif
      g_ent_list->cb = update_part_scroll;
      g_ent_list->cb2 = track_draw_visible_tris;
      g_ent_list->p = poolAlloc(1, g_ent_list->n * 8);
      if (gRecords->hE == 2)
      {
        g_ent_list->q = poolAlloc(1, g_ent_list->n * 8);
        func_80035B04(g_ent_list->p);
        func_80035B04(g_ent_list->q);
      }
      else
      {
        g_ent_list->q = 0;
        func_80035B04(g_ent_list->p);
      }
      break;
    default:
      g_ent_list->x = 0;
      g_ent_list->p = 0;
      g_ent_list->q = 0;
      break;
  }
}
