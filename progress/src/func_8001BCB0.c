/* Zeroes four words of scratch space, then spins forever (fatal-error halt). */ void func_8001BCB0(void) {
    s32 scratch[16];
    s32 n;
    s32 *cur;
    s32 spin;

    cur = scratch;
    n = 4;
    do {
        *cur = 0;
        n--;
        cur++;
    } while (n != 0);
    spin = 1;
    while (spin) {
    }
}
