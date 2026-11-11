s32 flag_test_bit0();
s32 flag_clear_bit0();
extern char gOrderState[];

void func_800388FC(void) {
    void *temp_s0;

    temp_s0 = gOrderState + 0x7378;
    if (flag_test_bit0(temp_s0) != 0) {
        flag_clear_bit0(temp_s0);
    }
}
