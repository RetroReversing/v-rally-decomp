s32 select_reset_text();
s32 func_8006F0E0();
s32 save_race_to_pak();
extern void *gSelectState;
extern char gStreamState[];
extern s32 setup_stage_results;
extern s32 func_8006425C;
extern s32 func_80064504;
extern s32 init_stage_screen;
extern s32 func_80066384;
extern s32 func_80066470;
extern s32 func_80071B3C;
extern s32 func_80071E08;
extern s32 func_80072364;
static inline void *inline_fn(char *arg0)
{
  return *((void **) arg0);
}

s32 func_8006B534(s32 arg0, s32 arg1)
{
  u16 temp_a0;
  func_8006F0E0(*((u8 *) (((char *) (inline_fn(gStreamState + 0x32F2) + (*((s8 *) (((char *) gSelectState) + 0x228))))) + 0x32)));
  save_race_to_pak();
  select_reset_text(arg0, arg1);
  temp_a0 = *((u16 *) (((char *) inline_fn(gStreamState + 0x32F2)) + 0x1E));
  if ((temp_a0 != 0) & (temp_a0 < 5U))
  {
    *((s32 **) (((char *) gSelectState) + 0x288)) = &init_stage_screen;
    *((s32 **) (((char *) gSelectState) + 0x290)) = &func_80066470;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80066384;
  }
  else
    if (temp_a0 == 0)
  {
    *((s32 **) (((char *) gSelectState) + 0x288)) = &setup_stage_results;
    *((s32 **) (((char *) gSelectState) + 0x290)) = &func_8006425C;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80064504;
  }
  else
    if (temp_a0 == 5)
  {
    *((s32 **) (((char *) gSelectState) + 0x288)) = &func_80071B3C;
    *((s32 **) (((char *) gSelectState) + 0x290)) = &func_80071E08;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80072364;
  }
  *((s8 *) (((char *) gSelectState) + 0x22B)) = -1;
  return 1;
}
