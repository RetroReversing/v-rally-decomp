extern f64 D_800A6FD0;
extern f64 D_800A6FD8;

/* Converts a time in microseconds to a sample count at the rate stored at synth+0x44,
 * rounded to a multiple of 16 samples. */
s32 _timeToSamples(void *synth, s32 us) {
    return (s32) (f32) (((f64) ((f32) us * (f32) *(s32 *) ((u8 *) synth + 0x44)) / D_800A6FD0) + D_800A6FD8) & ~0xF;
}
