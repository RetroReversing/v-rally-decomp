/* Linear interpolation in 1/128 steps: from + (to - from) * t / 128, with t in Q7 (0..128). */
s32 lerp_q7(s32 from, s32 to, s32 t) {
    return from + ((s32) (t * (to - from)) >> 7);
}
