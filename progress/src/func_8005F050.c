extern float gSpeedAccum;
void rampFloatToOne(int a, float *b);
void voicesSetIdleValue(int a);

/* Clamps the ratio in gSpeedAccum to 0..1 (rampFloatToOne), then passes it to voicesSetIdleValue scaled to 0..112. Returns 0. The first argument is unused. */
int func_8005F050(int unused) {
    float *ratio = &gSpeedAccum;
    rampFloatToOne(unused, ratio);
    voicesSetIdleValue((int)(*ratio * 112.0f));
    return 0;
}
