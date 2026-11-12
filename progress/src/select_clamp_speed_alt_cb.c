extern char stream_state[];
void clampAboveThreshold(int a, char *b);
/* Hook for league slot 0xE: clamps the speed value at stream_state+0x332E above gSpeedThreshold. hook_arg is passed through and unused. */ int select_clamp_speed_alt_cb(int hook_arg) { clampAboveThreshold(hook_arg, stream_state + 0x332E); return 0; }
