s32 func_80022ED8(void *);
s32 obj_reset_records(s32);
s32 func_80042D20();
s32 func_800494D4(s32);
s32 func_8004E218(void *);
s32 func_8004F3C4();
s32 car_slot_reset();
s32 initCarSlot(s32, void *, s32);
s32 func_80050AB8(s32);
s32 func_800804C4(s32, s32 *);
s32 func_800857A0(s32);
extern s32 gPadFlags;
extern s8 D_800A1210;
extern s32 gCarEntries;
extern s32 gSlotTable;
extern s32 D_800A73E0;
extern s32 gOrderState;
extern s32 gStreamState;
extern s32 func_8004E18C;

/* Runs one slot of the object table. A slot's chain (slot 1 also takes the
 * next entry) is ticked and drawn; if the slot is idle it is armed: its state
 * is set to 3, its flags are cleared, and its handlers are started. */
void func_8004E224(s32 arg0)
{
  s32 temp_a2;
  char *new_var2;
  s32 temp_s1;
  s32 slotBase;
  s32 slot;
  s32 neg1;
  char *new_var;
  union
  {
    u32 i;
    void *p;
  } state;
  void *temp_v0;
  void *cfgp;
  slotBase = gCarEntries;
  slot = arg0 & 0xFF;
  state.p = *(*((void ***)(((char *)(&gOrderState)) + 0x73F0)));
  if (slot == 1)
  {
    state.p = *((void **)(((char *)state.p) + 4));
    if ((*((u16 *)(((char *)(*((void **)(((char *)(&gStreamState)) + 0x32F2)))) + 0x1A))) == slot)
    {
      state.p = *((void **)(((char *)state.p) + 4));
    }
  }
  if ((*((s32 *)(((char *)(*((void **)(((char *)state.p) + 0x6C)))) + 0x34))) != 0)
  {
    state.i = 0;
    loop_5:
    func_800857A0(state.i & 0xFF);

    state.i += 1;
    if (state.i < 4U)
    {
      goto loop_5;
    }
  }
  else
  {
    if (!((*((s32 *)(((char *)state.p) + 0x14))) & 0x80))
    {
      func_80022ED8(state.p);
    }
    obj_reset_records(*(*((s32 **)(((char *)state.p) + 0x38))));
    if ((*((s32 *)(((char *)(*((void **)(((char *)state.p) + 0x6C)))) + 0x34))) == 0)
    {
      *((s32 *)(((char *)state.p) + 0x14)) = (s32)((*((s32 *)(((char *)state.p) + 0x14))) & (~0x10));
    }
    if ((*((u16 *)(((char *)(*((void **)(((char *)(&gStreamState)) + 0x32F2)))) + 0x1A))) == 1)
    {
      void *next = *((void **)(((char *)state.p) + 4));
      if (!((*((s32 *)(((char *)next) + 0x14))) & 0x80))
      {
        func_80022ED8(next);
      }
      obj_reset_records(*(*((s32 **)(((char *)next) + 0x38))));
      if ((*((s32 *)(((char *)(*((void **)(((char *)next) + 0x6C)))) + 0x34))) == 0)
      {
        *((s32 *)(((char *)next) + 0x14)) = (s32)((*((s32 *)(((char *)next) + 0x14))) & (~0x10));
      }
      state.p = *((void **)(((char *)next) + 0));
    }
    D_800A1210 = 0;
    func_8004F3C4();
    if ((*((u8 *)(((char *)(&D_800A73E0)) + 0x6C01))) != 0)
    {
      temp_s1 = arg0 & 0xFF;
      new_var2 = ((char *)(slotBase + (temp_s1 * 0x44))) + 8;
      if ((*((u16 *)new_var2)) & 0x200)
      {
        initCarSlot(gCarEntries, state.p, temp_s1);
        func_8004E218(state.p);
        func_80050AB8(temp_s1);
        state.i = 0;
      }
      else
      {
        goto block_25;
      }
    }
    else
    {
      temp_a2 = arg0 & 0xFF;
      temp_v0 = slotBase + (temp_a2 * 0x44);
      *((s16 *)(((char *)temp_v0) + 0xA)) = 3;
      new_var = (char *)(&gStreamState);
      neg1 = *((u16 *)(((char *)temp_v0) + 8));
      cfgp = *((void **)(new_var + 0x32F2));
      *((s16 *)(((char *)temp_v0) + 0xC)) = 0;
      neg1 &= 0xFDFF;
      *((u16 *)(((char *)temp_v0) + 8)) = (u16)neg1;
      neg1 = -1;
      *((s32 *)(((char *)(*((void **)(((char *)state.p) + 0x44)))) + 0x28)) = neg1;
      *((s32 *)(((char *)(*((void **)(((char *)state.p) + 0x70)))) + 0x28)) = neg1;
      if ((*((u16 *)(((char *)cfgp) + 0x1A))) == 1)
      {
        state.p = *((void **)(((char *)state.p) + 4));
        car_slot_reset(gSlotTable, (void **)state.p, temp_a2);
        state.p = *((void **)state.p);
      }
      if ((*((u16 *)(((char *)(*((void **)(new_var + 0x32F2)))) + 0xE))) == 1)
      {
        func_800804C4(neg1 = *((s32 *)(((char *)(&gOrderState)) + 0x72FC)), &func_8004E18C);
      }
      *((s32 *)(((char *)state.p) + 0x14)) = (s32)((*((s32 *)(((char *)state.p) + 0x14))) | 0x10);
      block_25:
      state.i = 0;
    }
    do
    {
      func_800857A0(state.i & 0xFF);
      state.i += 1;
    }
    while (state.i < 4U);
    func_80042D20();
    if (gPadFlags & 0x4000)
    {
      func_800494D4(arg0 & 0xFF);
    }
  }
}
