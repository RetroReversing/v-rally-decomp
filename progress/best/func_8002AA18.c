s32 func_8002AA18(s8 *a, s8 *b) {
    while (*a == *b && *a != 0 && *(u8 *)b != 0) {
        a++;
        b++;
    }
    if (*a == 0) {
        return *b != 0;
    }
    return 1;
}
