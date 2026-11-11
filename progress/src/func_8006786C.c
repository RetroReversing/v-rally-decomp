typedef struct
{
  u8 pad0[0x228];
  u8 unk228;
  u8 pad229[2];
  s8 unk22B;
  u8 pad22C[0x19];
  u8 unk245;
  u8 pad246[7];
  u8 unk24D;
  u8 pad24E[0x35];
  u8 unk283;
  u8 pad284[4];
  void (*unk288)(void);
  void (*unk28C)(void);
} Obj;
extern Obj *gSelectState;
extern u8 gStreamState[];
extern volatile unsigned short func_8006F4A8(u8);
extern void func_8006EE3C(u8);
extern void func_8006F0E0(u8, void *);
extern void save_race_to_pak(void);
extern void select_reset_text(s32, s32, s32, s32);
extern void select_init_screen(void);
extern void func_80066EBC(void);

/* Opens the select screen's record slot: copies the three bytes of the current state into
 * the slot table entry for the chosen car, finds or claims a record slot for it, then
 * resets the input flags and installs the screen's update and draw callbacks. */
s32 func_8006786C(void)
{
  u8 *slot_bytes;
  u8 *records;
  u8 *p;
  Obj *state;
  Obj *state2;
  u8 *new_var;
  Obj *t0;
  Obj *state_a;
  Obj *state_b;
  s8 car_id;
  s32 car;
  s32 rec_car;
  u8 i;
  u8 j;
  u8 t1;
  s32 off;
  s8 idx;
  s32 ret;
  volatile char frame_pad[8];
  func_8006F4A8(gSelectState->unk228);
  func_8006EE3C(gSelectState->unk228);
  car_id = *((s8 *) (((u8 *) gSelectState) + 0x228));
  i = 0;
  off = ((car_id * 5) * 8) + 0x44;
  slot_bytes = (*((u8 **) (gStreamState + 0x32F2))) + off;
  copy_loop:
  state = gSelectState;

  j = i & 0xFF;
  slot_bytes[j] = *((u8 *) ((((u8 *) state) + j) + 0x283));
  i++;
  if ((i & 0xFF) < 3)
  {
    goto copy_loop;
  }
  slot_bytes[3] = 0;
  func_8006F0E0(gSelectState->unk228, slot_bytes);
  save_race_to_pak();
  { extern u8 * volatile gRecords; records = gRecords; }
  state2 = gSelectState;
  slot_bytes = records;
  new_var = slot_bytes;
  i = 1;
  idx = *((s8 *) (((u8 *) state2) + 0x22B));
  t0 = state2;
  car = *((s8 *) (((u8 *) state2) + 0x228));
  t1 = *((u8 *) ((slot_bytes + idx) + 0x32));
  rec_car = car;
  j = i & 0xFF;
  search_loop:
  if ((*((u8 *) ((slot_bytes + (i & 0xFF)) + 0x32))) == car)
  {
    j = i & 0xFF;
    goto search_done;
  }

  i++;
  if ((i & 0xFF) < 4)
  {
    goto search_loop;
  }
  j = i & 0xFF;
  do
  {
    search_done:
    i = 0;

    if (j != 4)
    {
      idx = *((s8 *) (((u8 *) t0) + 0x22B));
      *((u8 *) ((slot_bytes + idx) + 0x32)) = (u8) rec_car;
      p = *((u8 **) (gStreamState + 0x32F2));
      p += j;
      p[0x32] = t1;
    }
    select_reset_text(i, 0, car, rec_car);
    {
      Obj *p0;
      Obj *p1;
      p0 = gSelectState;
      p0->unk245 = 0;
      p1 = gSelectState;
      ret = 0;
      p0->unk288 = select_init_screen;
      p0->unk28C = func_80066EBC;
      p1->unk24D = 0;
      return ret;
    }
  }
  while (0);
}
