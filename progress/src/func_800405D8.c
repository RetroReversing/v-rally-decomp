s32 view_set_rect();
s32 view_gfx_setup();
void *list_find_node(void **, u8 *);
s32 func_8003FD0C();
void *find_object_by_id();
extern s32 gSceneSlot0;
extern s32 gSelectState;
extern char D_800A4C18[];
extern void *gRecords;
extern void *g_camera;
static inline char *inline_fn()
{
  return (char *) gRecords;
}

/* Makes the object with id (record id at gRecords+0xE, doubled and | 1) the current camera: sets up the
 * view from its 0x178 field and the scene slot, and if the record's state at +0x1E is not 7, calls the
 * object's 0x14 callback with its 0x10 argument. */
void func_800405D8(void)
{
  void *camObj;
  void *handler;
  char *recPtr;
  camObj = find_object_by_id(((*((u16 *) (inline_fn() + 0xE))) * 2) | 1);
  { s32 arg = *((s32 *) (((char *) camObj) + 0x178));
  g_camera = camObj;
  view_gfx_setup(arg);
  }
  view_set_rect(*((s32 *) (((char *) camObj) + 0x178)), gSceneSlot0);
  if (gSelectState == 0)
  {
    func_8003FD0C(0);
  }
  if ((*((u16 *) (recPtr = ((char *) gRecords) + 0x1E))) != 7)
  {
    g_camera = camObj;
    handler = list_find_node((void **)(((char *) camObj) + 0x28), (u8 *)(D_800A4C18));
    if (handler != NULL)
    {
      (*((s32 (**)(s32)) (((char *) handler) + 0x14)))(*((s32 *) (((char *) handler) + 0x10)));
    }
  }
}
