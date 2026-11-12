s32 select_arm_if_clear(void);
s32 select_request_reset(s32, s32);
s32 select_reset_all(s32, s32);
extern s8 gStreamPhase;

/* Restarts the stream: resets the two subsystems, marks the stream phase as
 * active (1), then runs the second reset. Always returns 1. */
s32 func_8006632C(s32 arg0, s32 arg1) {
    select_arm_if_clear();
    select_reset_all(arg0, arg1);
    gStreamPhase = 1;
    select_request_reset(0, 0);
    return 1;
}
