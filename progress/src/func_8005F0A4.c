extern float gSpeedAccum;
void clampAboveThreshold(int unused, float *value);
void voicesSetIdleValue(int value);

/* Clamps gSpeedAccum against the threshold, then sends it to the voices scaled by 112. Returns 0. */
int func_8005F0A4(int arg0) { float *p = &gSpeedAccum; clampAboveThreshold(arg0, p); voicesSetIdleValue((int)(*p * 112.0f)); return 0; }
