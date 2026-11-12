typedef struct 
{
  u8 b[0x500];
} Blob;
extern Blob stream_state;
extern u8 *gRecords;
extern u8 *gLeague;
#ifdef PORT
extern u8 *gSlotTableB[];
#else
extern s32 gSlotTableB[];
#endif
extern u8 D_8009E260;
extern u8 D_800A14D6;
extern u8 D_800A14D7;
extern u8 D_800A14D8;
extern u8 gStreamPhase;
extern void *gSelectState;
extern s32 func_80064504;
extern s32 stage_stub_return_true;
extern void func_800416EC();
extern s32 func_80057B40(s32, s32, s32, s32);
void *select_get_entry(u32);
void select_propagate_values(s32, u32, u32);
extern s32 hud_setup_stage_results(void);
void func_80061F34(void *, void *);
extern s32 stream_state_update(void);
s32 record_set_byte9(void *, s32, s32);
s32 setRecordSlotValue(void *, s32, s32);
s32 league_set_hook_entry(void *, s32, s32, void *);

/* Sets up the results screen for the stage just finished: fills the HUD and league menus,
 * then, for the result code in gStreamPhase, rewrites the record fields and saves the code
 * values, and finally restores the record fields and closes the screen. */
void setup_stage_results(void)
{
  s32 new_var;
  u8 *p = (u8 *) stream_state.b;
  u8 *a0;
  s32 t;
  s32 i;
  u16 s2;
  u8 s0;
  u8 s1;
  {
    u8 *first = gRecords;
    t = *((u16 *) (first + 0x1e));
    i = *((u16 *) (first + 0x20));
#ifdef PORT
    {
      u8 *tp = gSlotTableB[(u16) t];
      u8 *base = tp + (6 * (118 * i));
      s32 offset = (*((u16 *) (first + 0x22))) << 6;
      *(first + 0x2e) = *((u8 *) ((base + offset) + 0x37));
      func_80061F34(first, tp);
    }
#else
    t = ((s32 *) gSlotTableB)[(u16) t];
    {
      s32 base = (6 * (118 * i)) + t;
      s32 offset = (*((u16 *) (first + 0x22))) << 6;
      *(first + 0x2e) = *((u8 *) ((base + offset) + 0x37));
    }
    func_80061F34(first, (void *)t);
#endif
  }
  {
    u8 *menu = gLeague;
    if (gStreamPhase)
    {
      *((void **) (((u8 *) gSelectState) + 0x28c)) = &func_80064504;
      setRecordSlotValue(menu, 3, 0x14);
    }
    else
    {
      *((void **) (((u8 *) gSelectState) + 0x28c)) = &func_80064504;
      setRecordSlotValue(menu, 3, 0x14);
    }
  }
  league_set_hook_entry(gLeague, 3, 0x10000, &stage_stub_return_true);
  stream_state_update();
  if ((*((u16 *) (gRecords + 0xe))) < 2)
  {
    record_set_byte9(gLeague, 0x1a, 0);
    *((s8 *) (((u8 *) select_get_entry(2)) + 0x41)) = 0;
    select_propagate_values(2, 1, 4);
  }
  hud_setup_stage_results();
  if ((s16) gStreamPhase >= 3)
  {
    goto done;
  }
  switch (gStreamPhase)
  {
    case 0:
      switch ((s8) gStreamPhase)
    {
      case 0:
      {
        a0 = gRecords;
        D_8009E260 = 4;
        s2 = *((volatile u16 *) (a0 + 0xe));
        new_var = *((volatile s32 *) (a0 + 0x20));
        t = new_var;
        s0 = *(a0 + 0x21);
        s1 = *(a0 + 0x23);
        *((u16 *) (a0 + 0xe)) = 1;
        if (new_var == 0x10003)
        {
          *((u16 *) (a0 + 0x1e)) = 5;
          *((u16 *) (a0 + 0x20)) = 1;
          *((u16 *) (a0 + 0x22)) = 2;
        }
        else
          if (new_var == 0x60004)
        {
          *((u16 *) (a0 + 0x1e)) = 5;
          *((u16 *) (a0 + 0x20)) = 6;
          *((u16 *) (a0 + 0x22)) = 0;
        }
        else
          if (new_var == 0x20001)
        {
          shared:
          *((u16 *) (a0 + 0x1e)) = 5;
          *((u16 *) (a0 + 0x20)) = 1;
          *((u16 *) (a0 + 0x22)) = 2;
        }
        else
          if (t == 0x40000)
        {
          *((u16 *) (a0 + 0x1e)) = 4;
          *((u16 *) (a0 + 0x20)) = 1;
          *((u16 *) (a0 + 0x20)) = 0;
          *((u16 *) (a0 + 0x22)) = 1;
        }
        else
          if (t == 0x50001)
        {
          *((u16 *) (a0 + 0x1e)) = 5;
          *((u16 *) (a0 + 0x20)) = 10;
          *((u16 *) (a0 + 0x22)) = 0;
        }
        {
          u16 c;
          u16 r;
          u16 s;
          u8 *snap = gRecords;
          c = *((u16 *) (snap + 0x1e));
          r = *((u16 *) (snap + 0x20));
          s = *((u16 *) (snap + 0x22));
          D_800A14D6 = c;
          D_800A14D7 = r;
          D_800A14D8 = s;
        }
        func_800416EC();
        {
          u8 *restore = gRecords;
          D_8009E260 = 1;
          *((u16 *) (restore + 0x20)) = s0;
          *((u16 *) (restore + 0x1e)) = 0;
          *((u16 *) (restore + 0x22)) = s1;
          *((u16 *) (restore + 0xe)) = s2;
        }
      }
        break;

    }

      break;

    case 1:

    case 2:
      break;

  }

  done:
  func_80057B40(0x1c, 2, 0, 0);

}
