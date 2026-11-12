s32 asset_list_teardown();
s32 records_restore_from_order();
s32 select_reset_text();
s32 select_arm_if_clear();
extern void *gSelectState;
extern s8 gStreamPhase;
extern char stream_state[];
extern s32 league_season_setup;
extern s32 func_80065860;

/* Ends the current stream phase: marks it done, installs the two select-screen callbacks,
 * clears the asset-list flag and tears the asset list down. Returns 1. */
s32 func_800662A8(s32 arg0, s32 arg1)
{
  char *select;
  s16 *list_flag;
  if (gSelectState)
  {
    select_arm_if_clear();
    select_reset_text(arg0, arg1);
    gStreamPhase = 2;
    list_flag = (s16 *) (((char *) (*((void **) (stream_state + 0x32F2)))) + 0x22);
    select = (char *) gSelectState;
    *((s32 **) (select + 0x288)) = &league_season_setup;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80065860;
    *list_flag = 0;
    asset_list_teardown(*((void **) (stream_state + 0x32F2)));
    records_restore_from_order();
    return 1;
  }
  else
  {
    select_arm_if_clear();
    select_reset_text(arg0, arg1);
    gStreamPhase = 2;
    list_flag = (s16 *) (((char *) (*((void **) (stream_state + 0x32F2)))) + 0x22);
    select = (char *) gSelectState;
    *((s32 **) (select + 0x288)) = &league_season_setup;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80065860;
    *list_flag = 0;
    asset_list_teardown(*((void **) (stream_state + 0x32F2)));
    records_restore_from_order();
    return 1;
  }
}
