s32 view_get_ctx_id();
s32 func_8002EE00();
s32 func_8002F270();
void *find_object_by_id();
extern u16 D_800B0558;
extern u32 D_800AFA8C;
extern u8 D_800B6818;
extern void *gCarList;
extern void *gRecords;
extern void *D_800C6ED0;
extern void *g_camera;

/* Per-frame pass over the car list: for each active camera slot, finds the
 * car that camera follows (or walks the whole list for the other cases) and
 * runs the two per-car update calls on it. Does nothing once the record's
 * state byte at 0xE is 2. */
void func_8002F7D8(void)
{
  char *link;
  u8 slot_count;
  s32 cam_idx;
  s32 flag;
  s32 ctx_id;
  s32 src;
  void *car;
  void *model;
  void *cam;
  char *rec;
  s32 limit;
  s32 prev;
  s32 v0;
  if ((*((u16 *) (((char *) gRecords) + 0xE))) == 2)
  {
    return;
  }
  limit = 0x14;
  if (D_800B0558 != 0)
  {
    do
    {
      limit = 0xA;
    }
    while (0);
  }
  v0 = D_800AFA8C;
  D_800AFA8C = 0;
  v0 = limit < ((u32) v0);
  D_800B0558 = v0;
  slot_count = *((u8 *) (((char *) gRecords) + 0xF));
  cam_idx = 1;
  if (slot_count == 0)
  {
    return;
  }
  flag = v0 & 0xFF;
  do
  {
    cam = find_object_by_id((cam_idx & 0xFF) << 1);
    src = *((s32 *) (((char *) cam) + 0x178));
    g_camera = cam;
    ctx_id = view_get_ctx_id(src);
    rec = gRecords;
    if ((((*((u16 *) (rec + 0x1E))) == 0) && ((*((u16 *) (rec + 0x1A))) != 0)) || (((*((u16 *) (rec + 0x1E))) == 5) && (D_800B6818 == 0)))
    {
      car = *((void **) gCarList);
      v0 = *((s32 *) (((char *) g_camera) + 0x24));
      #ifdef PORT
      cam = *((void **) (((char *) g_camera) + 0x24));
#else
      cam = (void *) v0;
#endif
      while (car != cam)
      {
        car = *((void **) (((char *) car) + 4));
      }

      model = *(*((void ***) (((char *) car) + 0x38)));
      func_8002EE00(car, *((s32 *) (((char *) model) + 0x10)), *((u16 *) (((char *) model) + 0x16)), ctx_id, model, flag);
      func_8002F270(car, *((s32 *) (((char *) model) + 0)), *((u16 *) (((char *) model) + 0x14)), *(*((s32 **) (((char *) D_800C6ED0) + 4))), ctx_id);
    }
    else
    {
      car = *((void **) gCarList);
      while (car != NULL)
      {
        link = ((char *) car) + 0x38;
        model = *(*((void ***) link));
        func_8002EE00(car, *((s32 *) (((char *) model) + 0x10)), *((u16 *) (((char *) model) + 0x16)), ctx_id, model, flag);
        func_8002F270(car, *((s32 *) (((char *) model) + 0)), *((u16 *) (((char *) model) + 0x14)), *(*((s32 **) (((char *) D_800C6ED0) + 4))), ctx_id);
        car = *((void **) (((char *) car) + 4));
      }

    }
    cam_idx += 1;
  }
  while (((u8) cam_idx) <= slot_count);
}
