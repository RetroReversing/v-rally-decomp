typedef struct 
{
  u8 pad[0xA];
} Data10;
typedef struct 
{
  u8 pad[0x20];
  s32 state;
} State4;
typedef struct 
{
  u8 pad[0x4];
  State4 *p4;
} Obj10;
typedef struct 
{
  u8 pad[0x10];
  Obj10 *p10;
} Root;
typedef struct 
{
  u8 pad[0x288];
  void (*f288)(void);
  void (*f28c)(void);
} Config;
typedef struct 
{
  s32 a;
  s32 b;
  s16 c;
  s8 d;
} Params;
extern s32 gRaceFlags;
extern Config *gSelectState;
extern Params D_800A5450;
extern Params D_800A545C;
extern Params D_800A5468;
extern Params D_800A5474;
extern u8 gOrderState[];
extern Root *gLeague;
extern s32 gSelectStep;
void stub_noop_80084AF4(void);
void func_80084AD8(void);
s32 pad_port_disconnected(s32);
void select_reset_text_default(s32, s32);
void func_8002FB64(void);
void select_begin_reset(void);
s32 cont_port_is_connected(s32, s32);
void order_set_timeout(void);
void func_8005E6AC(void);
void select_touch_first_entry(void);

/* Picks the attract/league state for the menu: sets the league state code, copies the
 * matching parameter block into the config and installs the menu callbacks. The
 * state depends on the save-slot checks: state 1 when no slot is valid, 2 when the
 * flag bit is set, 3 when the count is zero, otherwise a slot scan decides between
 * the normal state (5) and the plain callback. */
s32 func_8005D96C(s32 setup_a, s32 setup_b)
{
  s32 slot;
  s32 i;
  u32 flags;
  s32 all_ok;
  u32 n_slots;
  void (*fn)(void);
  u8 temp;
  Root *root;
  stub_noop_80084AF4();
  func_80084AD8();
  if ((pad_port_disconnected(0) == 0) || ((temp = gOrderState[0x7D50]) == 0))
  {
    ;
    gLeague->p10->p4->state = 1;
    ;
    __builtin_memcpy(((u8 *) gSelectState) + 0x1f8, &D_800A5450, 11);
    select_reset_text_default(setup_a, setup_b);
    fn = order_set_timeout;
    gSelectState->f288 = fn;
    gSelectState->f28c = func_8005E6AC;
    goto done;
  }
  if ((short) (flags = gRaceFlags & 0x8000))
  {
    ;
    gLeague->p10->p4->state = 2;
    ;
    __builtin_memcpy(((u8 *) gSelectState) + 0x1f8, &D_800A545C, 10);
    select_reset_text_default(setup_a, setup_b);
    return 0;
  }
  all_ok = 1;
  if (gSelectStep == 0)
  {
    gLeague->p10->p4->state = 3;
    ;
    __builtin_memcpy(((u8 *) gSelectState) + 0x1f8, &D_800A5468, 11);
    select_reset_text_default(setup_a, setup_b);
    return 0;
  }
  i = 0;
  if (flags < temp)
  {
    n_slots = temp;
    do
    {
      slot = i & 255;
      if (pad_port_disconnected(slot))
      {
        all_ok &= -(cont_port_is_connected(slot, 2) != 0);
      }
      i++;
    }
    while ((i & 255) < n_slots);
  }
  if ((all_ok & 255) != 0)
  {
    stub_noop_80084AF4();
    func_80084AD8();
    func_8002FB64();
    gLeague->p10->p4->state = 5;
    root = gSelectState;
    __builtin_memcpy(((u8 *) root) + 0x1f8, &D_800A5474, 9);
    select_reset_text_default(setup_a, setup_b);
    select_begin_reset();
  }
  else
  {
    select_reset_text_default(setup_a, setup_b);
    gSelectState->f28c = select_touch_first_entry;
  }
done:
  return 0;
}
