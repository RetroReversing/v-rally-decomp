typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Obj { u8 pad[0x118]; Vec3 pos; u8 pad2[0x178 - 0x124]; void *p178; } Obj;
typedef struct Mgr { u8 pad[0xE]; u16 mode; } Mgr;
typedef struct Race {
  u8 pad[4];
  u16 type;
  u8 pad6[6];
  s32 ids[3];
  Vec3 pos[2];
  s32 x30;
  void (*fn)(s32, s32, u8);
} Race;
extern Mgr *gRecords;
extern u8 gStreamLastValue;
extern u8 g_dark_mode;
extern Obj *g_camera;
extern Race *g_ent_list;
s32 view_get_ctx_id(void *);
void func_800376C8(s32, Obj *);
Obj *find_object_by_id(s32);

/* Per-frame camera update, once per view for gRecords->mode views (mode 2 is skipped). Points g_camera at
 * each view's camera object. For race entities of type 3 or 4 it also runs the entity callback and
 * copies the camera position into the entity's pos array. */
void func_800354F4(void)
{
  u16 mode;
  u8 i;
  u8 count;
  s32 k;
  s32 j;
  s32 r;
  Obj *obj;

  mode = gRecords->mode;
  if (mode == 2)
    return;
  count = mode;
  for (i = 1; i <= count; i++)
  {
    if (gStreamLastValue != 0)
      continue;
    switch (g_ent_list->type)
    {
      case 0:
        if (g_dark_mode == 0)
        {
          k = (i - 1) * 2;
          obj = find_object_by_id(k + 3);
          g_camera = obj;
          r = view_get_ctx_id(obj->p178);
          func_800376C8(r, find_object_by_id(k + 2));
        }
        break;
      case 3:
      case 4:
        j = i - 1;
        obj = find_object_by_id(j * 2 + 2);
        g_camera = obj;
        r = view_get_ctx_id(obj->p178);
        g_ent_list->fn(*(s32 *)((u8 *)g_ent_list - -(i * 4) + 0xC), r, i - 1);
        g_ent_list->pos[j].x = g_camera->pos.x;
        g_ent_list->pos[j].y = g_camera->pos.y;
        g_ent_list->pos[j].z = g_camera->pos.z;
        break;
    }
  }
}
