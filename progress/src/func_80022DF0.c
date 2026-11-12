/* Clears the state block's counter at word 5 and the 11 entries of each of its three tables
 * (words 7, 0x12 and 0x1D onwards), then sets word 0x28 to -1 (no entry). */
void func_80022DF0(s32 *state) {
    unsigned int i;

    state[5] = 0;
    for (i = 0; i < 11; i++) {
        state[7 + i] = 0;
        state[0x12 + i] = 0;
        state[0x1D + i] = 0;
    }
    state[0x28] = -1;
}
