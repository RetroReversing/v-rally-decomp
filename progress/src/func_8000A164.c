s32 order_state_reset_frees();
s32 func_8000A100();
/* Runs the order-state reset followed by the stream-state reset. */
void func_8000A164(void) { order_state_reset_frees(); func_8000A100(); }
