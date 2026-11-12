extern s8 gSelectResetFlag;
void select_arm_reset_state(void);
void select_reset_text_default(s32, s32);

/* Clears the select reset flag, then runs the two select-state teardown steps. */
s32 select_clear_reset_flag(void) {
    select_arm_reset_state();
    gSelectResetFlag = 0;
    select_reset_text_default(0, 0);
    return 0;
}
