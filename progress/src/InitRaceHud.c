typedef struct 
{
  s32 w[177];
} Block635;
extern u8 stream_state[];
extern u8 gOrderState[];
extern u8 *gSelectState;
extern u16 D_800D061E;
extern Block635 *gSlotTableB;
void select_clear_slots(void);
void func_8005BB5C(void);
void func_80063328(void);
void func_8005937C(s32, s32);
void list_set_flag2_at_index(s32);
void text_obj_set_disabled(u32);
void func_80061740(Block635);

/* Resets the race HUD: clears the event's position fields, primes the per-slot
 * entries for the current event's record count, then refreshes the slot table
 * and the row pointer used by the HUD. */
void InitRaceHud(void)
{
  Block635 slots;
  s32 i;
  s32 j;
  u8 *mgr;
  u8 *event;
  int new_var;
  short new_var2;
  u8 *row;
  select_clear_slots();
  func_8005BB5C();
  func_80063328();
  event = *((u8 **) (stream_state + 0x32F2));
  mgr = *((u8 **) (stream_state + 0x325A));
  *((s16 *) (event + 0x20)) = 0;
  *((s16 *) (event + 0x22)) = 0;
  new_var = (new_var2 = 0);
  if ((*((s16 *) (mgr + 2))) == 1)
  {
    i = new_var2;
    if (D_800D061E > new_var2)
    {
      j = new_var2;
      do
      {
#ifdef PORT
        func_8005937C(i + 6, *((u16 *) (((u8 *) gSlotTableB) + j + 0x14)));
#else
        func_8005937C(i + 6, *((u16 *) ((j + (int)gSlotTableB) + 0x14)));
#endif
        i += 1;
        j += 0x2C4;
      }
      while (i < D_800D061E);
    }
    list_set_flag2_at_index(0);
    text_obj_set_disabled(19);
    text_obj_set_disabled(20);
    text_obj_set_disabled(21);
    text_obj_set_disabled(22);
  }
  else
  {
    i = new_var2;
    if (D_800D061E > new_var)
    {
      j = 0;
      do
      {
#ifdef PORT
        func_8005937C(i + 15, *((u16 *) (((u8 *) gSlotTableB) + j + 0x14)));
#else
        func_8005937C(i + 15, *((u16 *) ((j + (int)gSlotTableB) + 0x14)));
#endif
        i += 1;
        j += 0x2C4;
      }
      while (i < D_800D061E);
    }
  }
  slots = *gSlotTableB;
  func_80061740(slots);
  row = (*((u8 **) ((*((u8 **) (stream_state + 0x325A))) + 16))) + ((*((s16 *) ((*((u8 **) (stream_state + 0x325A))) + 2))) * 20);
  row[14] = row[13] + gSelectState[0x23B];
  *((s32 *) (gOrderState + 0x5550)) = 0;
}