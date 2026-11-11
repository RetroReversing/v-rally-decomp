typedef struct 
{
  s16 pad0;
  s16 index;
  u8 pad4[0xA];
  void *ptr;
} T3508;
typedef struct 
{
  u8 pad0[0x204];
  u32 x204;
  u32 x208;
  s16 x20c;
  s8 x20e;
  u8 pad210[0x40];
  u8 x24f;
  u8 pad250[0x38];
  void (*f288)(void);
  void (*f28c)(void);
  void (*f290)(void);
} Obj;
typedef struct 
{
  u8 pad0[0x10];
  Obj *obj;
} Node;
extern u8 gOrderState[];
extern u8 gStreamState[];
extern u8 D_800A5CE4[] __attribute__((aligned(4)));
extern u8 D_800A5D18[] __attribute__((aligned(4)));
extern u8 D_800A5D24[] __attribute__((aligned(4)));
extern Obj *gSelectState;
extern s8 gStreamPhase;
extern volatile short asset_list_teardown(void);
extern void records_restore_from_order();
extern void select_reset_text(s32, s32);
extern void func_8005C198(s32, s32);
extern void buildLinkPacket(void);
extern void func_8006F424(void);
extern void save_race_to_pak(void);
extern void InitSelectHandlers(s32, s32);
extern void func_80070C34(void);
extern void best_times_select_update(void);
extern void func_80071B3C(void);
extern void func_80071E08(void);
extern void func_80072364(void);

/* Selects the next state of the current menu node: the first branch runs the
 * start-up sequence, the second the select update, and the default branch the
 * idle reset. Stores the resulting state into the node's object. */
s32 func_80072090(s32 a0, s32 a1)
{
  s32 mode = (gOrderState[0x7FC9]) ? (4) : (8);
  T3508 *p = *((T3508 **) (gStreamState + 0x325A));
  Node *n = (Node *) (((u8 *) p->ptr) + (((s32) p->index) * 20));
  s32 state;
  if ((*((s32 *) (gOrderState + 0x8030))) != 3)
  {
    func_8005C198(*((s32 *) (gOrderState + 0x8030)), mode);
    __builtin_memcpy(&gSelectState->x204, D_800A5D18, 11);
    select_reset_text(a0, a1);
    state = 4;
    gStreamPhase = 0;
    gSelectState->f288 = func_80071B3C;
    gSelectState->f290 = func_80071E08;
    gSelectState->f28c = func_80072364;
    asset_list_teardown();
  }
  else
    if (gSelectState->x24f != mode)
  {
    __builtin_memcpy(&gSelectState->x204, (u32 *) D_800A5CE4, 9);
    select_reset_text(a0, a1);
    state = 3;
    *((s32 *) (gOrderState + 0x8030)) = 5;
    gSelectState->f288 = func_80070C34;
    gSelectState->f28c = best_times_select_update;
  }
  else
  {
    records_restore_from_order();
    state = 0;
    __builtin_memcpy(&gSelectState->x204, D_800A5D24, 10);
    InitSelectHandlers(0, 0);
    *((s32 *) (gOrderState + 0x8030)) = 5;
    gOrderState[0x7FCA] = 0;
    func_8006F424();
    buildLinkPacket();
    save_race_to_pak();
  }
  *((s32 *) (((u8 *) (*((void **) (((u8 *) n) + 4)))) + 0x14)) = state;
  return 0;
}
