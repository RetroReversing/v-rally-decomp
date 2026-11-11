s32 updateCameraView();
void *named_entry_lookup(void **, u8 *);
s32 func_80022668();
void *find_object_by_id();
f32 sqrtf(f32);
extern char D_800A3FF0[];
extern char gOrderState[];
extern char *gRecords;
extern char *g_camera;
typedef struct Cb { char pad[0x10]; char *arg; void (*fn)(char *); } Cb;
#define FIELD_F(p, o) (*(f32 *)((char *)(p) + (o)))
#define FIELD_S32(p, o) (*(s32 *)((char *)(p) + (o)))
#define FIELD_PTR(p, o) (*(char **)((char *)(p) + (o)))

/* For each camera pair in the record table, look up the camera and its partner
 * object, run the camera's callback, and store the camera-to-target distance in
 * the camera's slot 0x194 (zero while the camera is flagged). Camera 1 also
 * refreshes the distance from every other object to its target. */
void func_80010468(void)
{
  u8 n_records;
  u8 rec_idx;
  char *cam_partner;
  Cb *cb;
  char *obj_node;
  char *other;
  char *cam_target;
  char *cam;
  f32 dx, dy, dz;
  f32 x2, y2, z2;

  n_records = gRecords[0xF];
  for (rec_idx = 1; rec_idx <= n_records; rec_idx++)
  {
    g_camera = find_object_by_id(((rec_idx - 1) * 2) | 1);
    cam_partner = find_object_by_id((rec_idx - 1) * 2 + 2);
    cb = named_entry_lookup((void **)(g_camera + 0x28), (u8 *)(D_800A3FF0));
    if (cb == NULL)
      continue;
    cb->fn(cb->arg);
    updateCameraView(cam_partner);
    func_80022668(cb->arg, FIELD_S32(cb->arg, 8));
    cam_target = g_camera + 0x38;
    x2 = (FIELD_F(g_camera, 0x124) - FIELD_F(cam_target, 0xE0)) * (FIELD_F(g_camera, 0x124) - FIELD_F(cam_target, 0xE0));
    y2 = (FIELD_F(g_camera, 0x128) - FIELD_F(cam_target, 0xE4)) * (FIELD_F(g_camera, 0x128) - FIELD_F(cam_target, 0xE4));
    z2 = (FIELD_F(g_camera, 0x12C) - FIELD_F(cam_target, 0xE8)) * (FIELD_F(g_camera, 0x12C) - FIELD_F(cam_target, 0xE8));
    if (FIELD_S32(g_camera, 0x20) & 0x880000)
      FIELD_S32(cam_partner, 0x194) = 0;
    else
      FIELD_S32(cam_partner, 0x194) = sqrtf(x2 + y2 + z2);
    cam = g_camera;
    FIELD_S32(cam, 0x194) = FIELD_S32(cam_partner, 0x194);
    obj_node = FIELD_PTR(cam, 0x24);
    FIELD_S32(FIELD_PTR(obj_node, 0x68), 0x1C) = FIELD_S32(cam_partner, 0x194);
    if (rec_idx == 1)
    {
      for (obj_node = *(char **)FIELD_PTR(gOrderState, 0x73F0); obj_node != NULL; obj_node = FIELD_PTR(obj_node, 4))
      {
        if (obj_node != FIELD_PTR(cam, 0x24))
        {
          other = FIELD_PTR(obj_node, 0x5C);
          dx = (f32)FIELD_S32(other, 0x54) - FIELD_F(cam_target, 0xE0);
          x2 = dx * dx;
          dy = (f32)FIELD_S32(other, 0x58) - FIELD_F(cam_target, 0xE4);
          y2 = dy * dy;
          z2 = ((f32)FIELD_S32(other, 0x5C) - FIELD_F(cam_target, 0xE8)) * ((f32)FIELD_S32(other, 0x5C) - FIELD_F(cam_target, 0xE8));
          FIELD_S32(FIELD_PTR(obj_node, 0x68), 0x1C) = sqrtf(x2 + y2 + z2);
        }
      }
    }
  }
}
