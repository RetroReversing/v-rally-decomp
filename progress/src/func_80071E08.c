s32 select_arm_if_clear(void);
s32 select_shutdown_pending(void);
s32 asset_list_teardown(void);

/* Tears down the asset list and the two subsystems it depends on. */
void func_80071E08(void)
{
    select_arm_if_clear();
    select_shutdown_pending();
    asset_list_teardown();
}
