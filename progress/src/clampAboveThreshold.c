extern f64 gSpeedThreshold;

/* Replaces *value with (value - gSpeedThreshold) when it is above the threshold, otherwise 0. arg0 is unused. */
void clampAboveThreshold(s32 arg0, f32 *value) {
    f32 result;
    f64 temp_fv0;

    temp_fv0 = (f64) *value;
    if (gSpeedThreshold < temp_fv0) {
        result = (f32) (temp_fv0 - gSpeedThreshold);
    } else {
        result = 0.0f;
    }
    *value = result;
}
