/* Returns bit 0 of the flags word pointed to by flags. */
s32 flag_test_bit0(s32 *flags) {
    return *flags & 1;
}
