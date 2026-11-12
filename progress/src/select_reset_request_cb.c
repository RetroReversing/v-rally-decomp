void select_arm_reset_state(void);

/* League select callback: arms the select reset state, then reports success. */
s32 select_reset_request_cb(void) {
    select_arm_reset_state();
    return 0;
}
