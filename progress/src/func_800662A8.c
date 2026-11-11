s32 asset_list_teardown();
s32 records_restore_from_order();
s32 select_reset_text();
s32 func_8005C198();
extern void *gSelectState;
extern s8 gStreamPhase;
extern char gStreamState[];
extern s32 func_8006556C;
extern s32 func_80065860;

/* Ends the current stream phase: marks it done, installs the two select-screen callbacks,
 * clears the asset-list flag and tears the asset list down. Returns 1. */
s32 func_800662A8(s32 arg0, s32 arg1)
{
  char *select;
  s16 *list_flag;
  if (gSelectState)
  {
    func_8005C198();
    select_reset_text(arg0, arg1);
    gStreamPhase = 2;
    list_flag = (s16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) + 0x22);
    select = (char *) gSelectState;
    *((s32 **) (select + 0x288)) = &func_8006556C;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80065860;
    *list_flag = 0;
    asset_list_teardown(*((void **) (gStreamState + 0x32F2)));
    records_restore_from_order();
    return 1;
  }
  else
  {
    func_8005C198();
    select_reset_text(arg0, arg1);
    gStreamPhase = 2;
    list_flag = (s16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) + 0x22);
    select = (char *) gSelectState;
    *((s32 **) (select + 0x288)) = &func_8006556C;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_80065860;
    *list_flag = 0;
    asset_list_teardown(*((void **) (gStreamState + 0x32F2)));
    records_restore_from_order();
    return 1;
  }
}
