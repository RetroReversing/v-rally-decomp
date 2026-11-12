extern unsigned char D_800B6819;
extern int gLeague;
extern void *gRecords;
s32 func_80057B40();void *select_get_entry(u32);
void select_propagate_values(s32, u32, u32);
s32 hud_setup_stage_results();
#ifdef PORT
void func_80061F34(void *, char *);
#else
void func_80061F34(void *, s32);
#endif
s32 stream_state_update();
s32 record_set_byte9();
s32 setRecordSlotValue();
s32 league_set_hook_entry();
extern s8 D_8009E260;
extern s8 D_800A14D6;
extern s8 D_800A14D7;
extern s8 D_800A14D8;
extern u8 gStreamPhase;
extern char gOrderState[];
extern char stream_state[];
extern s32 stage_stub_return_true;
void func_800416EC();
static inline u16 *inline_fn()
{
  return (u16 *) (gRecords + 0x1E);
}

/* Scans the order-state table for a nonzero entry, updates the league/select hooks for that result, then advances the stored stage records when the stream is still in phase 0. */ void func_80071B3C(void)
{
  s32 pad[2];
  char *new_var;
  char *rec;
#ifdef PORT
  char *slot_base;
#else
  s32 slot_base;
#endif
  s32 hit_flag;
  s32 scan_start;
  s32 scan_count;
  s32 hit;
  s32 var_v0_2;
  int slot_idx;
  u16 phase_val;
  u16 phase_key;
  u16 saved_stage_e;
  int is_phase0;
  char *slot_ptr;
  u32 temp_a0;
  u32 scan_i;
  u8 saved_flag_21;
  void *new_var4;
  void *new_var7;
  u8 saved_flag_23;
  void *temp_v0;
  u16 *new_var5;
  hit = 0;
  if (D_800B6819 != 0)
  {
    scan_count = 4;
    scan_start = 8;
    goto scan;
    found:
    hit = 1;

    goto scanned;
  }
  else
  {
    scan_count = 8;
    scan_start = 0;
  }
  scan:
  temp_a0 = scan_count & 0xFFFF;

  scan_i = 0;
  if (temp_a0 != 0)
  {
    var_v0_2 = scan_start & 0xFFFF;
    new_var = ((char *) gOrderState) + 0x7DC0;
    do
    {
      if (((u16 *) new_var)[var_v0_2 + scan_i] != 0)
      {
        new_var += (s32) 0x7DC0;
        goto found;
      }
      scan_i++;
    }
    while (scan_i < temp_a0);
  }
  scanned:
  ;

  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  hit_flag = hit;
  ;
  slot_idx = 3;
  ;
  ;
  ;
  if (!(hit_flag & 0xff))
  {
    if (hit)
    {
      record_set_byte9((s32) gLeague, 0x28, 0);
      temp_v0 = select_get_entry(slot_idx);
      ((s8 *) temp_v0)[0xF] = 0x50;
      ((s8 *) temp_v0)[0x10] = 0x50;
      ((s8 *) temp_v0)[0x11] = 0x50;
    }
    else
    {
      record_set_byte9((s32) gLeague, 0x28, 0);
      temp_v0 = select_get_entry(slot_idx);
      ((s8 *) temp_v0)[0xF] = 0x50;
      ((s8 *) temp_v0)[0x10] = 0x50;
      ((s8 *) temp_v0)[0x11] = 0x50;
    }
  }
  else
  {
    record_set_byte9((s32) gLeague, 0x28, 1, hit);
  }
  slot_ptr = (stream_state + 0x10386) + ((*((u16 *) (gRecords + 0x1E))) * 4);
  #ifdef PORT
  slot_base = *((char **) slot_ptr);
#else
  slot_base = *((s32 *) slot_ptr);
#endif
  new_var4 = gRecords;
  rec = (char *) (((((u32) (*((u16 *) (gRecords + 0x20)))) * 0x2C4) + slot_base) + ((*((u16 *) (gRecords + 0x22))) << 6));
  *((u8 *) (gRecords + 0x2E)) = *((u8 *) (rec + 0x37));
  func_80061F34(new_var4, slot_base);
  setRecordSlotValue((s32) gLeague, 4, 0x14);
  league_set_hook_entry((s32) gLeague, 4, 0x10000, (&stage_stub_return_true));
  stream_state_update();
  if ((*((u16 *) (gRecords + 0xE))) < 2U)
  {
    record_set_byte9((s32) gLeague, 0x27, 0);
    ((s8 *) select_get_entry(2))[0x41] = 0;
    select_propagate_values(2, 1, 5);
  }
  hud_setup_stage_results();
  if (((s32) gStreamPhase) < slot_idx)
  {
    if (is_phase0 = gStreamPhase == 0)
    {
      if (gStreamPhase == 0)
      {
        D_8009E260 = 4;
        saved_stage_e = *((u16 *) (gRecords + 0xE));
        ;
        saved_flag_21 = *((u8 *) (gRecords + 0x21));
        saved_flag_23 = *((u8 *) (gRecords + 0x23));
        new_var7 = gRecords;
        *((u16 *) (gRecords + 0xE)) = 1U;
        if ((*((s32 *) (gRecords + 0x20))) == 0x20001)
        {
          *((u16 *) (gRecords + 0x20)) = 1U;
          *((u16 *) (gRecords + 0x22)) = 2U;
        }
        else
          if ((*((s32 *) (new_var7 + 0x20))) == 0x40000)
        {
          new_var5 = (u16 *) (gRecords + 0x20);
          *inline_fn() = 4U;
          *new_var5 = 0U;
          *((u16 *) (gRecords + 0x22)) = 1U;
        }
        else
          if ((*((s32 *) (gRecords + 0x20))) == 0x50001)
        {
          *((u16 *) (gRecords + 0x20)) = 0xAU;
          *((u16 *) (gRecords + 0x22)) = 0U;
        }
        phase_key = *((u16 *) (gRecords + 0x20));
        phase_val = *((u16 *) (gRecords + 0x22));
        D_800A14D6 = (s8) (*((u16 *) (gRecords + 0x1E)));
        D_800A14D7 = (s8) phase_key;
        D_800A14D8 = (s8) phase_val;
        func_800416EC();
        D_8009E260 = 1;
        *((u16 *) (gRecords + 0x1E)) = 5U;
        *((u16 *) (gRecords + 0x20)) = (u16) saved_flag_21;
        *((u16 *) (gRecords + 0x22)) = (u16) saved_flag_23;
        *((u16 *) (gRecords + 0xE)) = saved_stage_e;
      }
    }
  }
  func_80057B40(0x2A, 3, 0, 0);
}
