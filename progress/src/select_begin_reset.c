/* Marks a select-screen reset as pending, then runs the select reset. */
extern s8 gSelectResetPending;
extern s32 select_reset_all(s32, s32);

void select_begin_reset(void) {
    gSelectResetPending = 1;
    select_reset_all(0, 0);
}
