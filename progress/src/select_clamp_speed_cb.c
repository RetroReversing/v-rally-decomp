extern char stream_state[];
void clampAboveThreshold(int a, char *b);
/* League hook callback: clamps the speed value at stream_state+0x333A. The argument is unused. */ int select_clamp_speed_cb(int unused) { clampAboveThreshold(unused, stream_state + 0x333A); return 0; }
