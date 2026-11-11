extern int gRandomState;

/* Advances the random state by eight steps of a shift register: each step shifts left
 * and sets the low bit when the top bits match one of the two feedback patterns. Returns
 * arg0 scaled by the new state as a fraction of 2^32. */
s32 randomScaled(s32 arg0) {
    s32 shifted;
    s32 masked;
    s32 feedback;
    s32 i;

    i = 0;
    do {
        shifted = gRandomState * 2;
        masked = gRandomState & 0x48000000;
        feedback = (masked == 0x48000000) | (masked == 0x08000000);
        gRandomState = shifted;
        i += 1;
        if (feedback != 0) {
            gRandomState = (s32) (shifted | 1);
        }
    } while (i < 8);
    return (s32) ((f32) arg0 * ((f32) gRandomState * 0.000015258789f * 0.000015258789f));
}
