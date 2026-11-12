s32 select_reset_text();
s32 glyph_record_pack();
s32 save_race_to_pak();
extern void *gSelectState;
extern char stream_state[];
extern s32 setup_stage_results;
extern s32 func_8006425C;
extern s32 func_80064504;
extern s32 init_stage_screen;
extern s32 func_80066384;
extern s32 select_shutdown_pending_stub;
extern s32 func_80071B3C;
extern s32 func_80071E08;
extern s32 func_80072364;
static inline void *inline_fn(char *arg0)
{
  return *((void **) arg0);
}

/* Saves the current race, resets the select text, then points the select state's three handler slots at the screen set for the stream result code (0, 1-4, or 5). */ s32 select_pick_next_state(s32 arg0, s32 arg1)
{
  u16 resultCode;
  glyph_record_pack(*((u8 *) (((char *) (inline_fn(stream_state + 0x32F2) + (*((s8 *) (((char *) gSelectState) + 0x228))))) + 0x32)));
  save_race_to_pak();
  select_reset_text(arg0, arg1);
  resultCode = *((u16 *) (((char *) inline_fn(stream_state + 0x32F2)) + 0x1E));
  if ((resultCode != 0) & (resultCode < 5U))
  {
    *((s32 **) (((char *) gSelectState) + 0x288)) = &init_stage_screen;
    *((s32 **) (((char *) gSelectState) + 0x290)) = &select_shutdown_pending_stub;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80066384;
  }
  else
    if (resultCode == 0)
  {
    *((s32 **) (((char *) gSelectState) + 0x288)) = &setup_stage_results;
    *((s32 **) (((char *) gSelectState) + 0x290)) = &func_8006425C;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80064504;
  }
  else
    if (resultCode == 5)
  {
    *((s32 **) (((char *) gSelectState) + 0x288)) = &func_80071B3C;
    *((s32 **) (((char *) gSelectState) + 0x290)) = &func_80071E08;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80072364;
  }
  *((s8 *) (((char *) gSelectState) + 0x22B)) = -1;
  return 1;
}
