/* Counts the leading bits of value that equal its top bit (the run of leading 1s if value is
   negative, else of leading 0s) and stores the count in *count. */
void func_8002D7E4(s32 value, s32 *count) {
    s32 run;
    u32 mask;

    run = 0;
    mask = 0x80000000;
    if (value < 0) {
loop_1:
        if (mask & value) {
            mask = mask >> 1;
            run += 1;
            if (mask == 0) {

            } else {
                goto loop_1;
            }
        }
    } else {
loop_4:
        if (!(value & mask)) {
            mask = mask >> 1;
            run += 1;
            if (mask != 0) {
                goto loop_4;
            }
        }
    }
    *count = run;
}
