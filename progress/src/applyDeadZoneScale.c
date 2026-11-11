/* Clamps input to a limit derived from arg2 and arg4 with a 0x46 dead zone on each side,
 * then scales the result by arg1 (>> 10). */
s32 applyDeadZoneScale(s32 input, s32 scale, s32 arg2, s32 arg3, s32 arg4) {
    s32 negInput;
    s32 limited;

    limited = (s32) (-arg2 * arg4) >> 9;
    if (input < limited) {
        goto block_2;
    }
    negInput = -input;
    goto block_4;
block_2:
    limited = input - 0x46;
    goto block_6;
block_4:
    if (limited >= negInput) {
        goto block_6;
    }
    limited = negInput + 0x46;
block_6:
    return (s32) (limited * scale) >> 0xA;
}
