extern f64 D_800A6FC0;
extern f64 D_800A6FC8;

/* Converts a time in microseconds to a sample count at the rate stored at synth+0x44,
 * without the rounding to a multiple of 16 that _timeToSamples applies. */
s32 _timeToSamplesNoRound(void *synth, s32 us) {
    return (s32) (f32) (((f64) ((f32) us * (f32) *(s32 *) ((u8 *) synth + 0x44)) / D_800A6FC0) + D_800A6FC8);
}
