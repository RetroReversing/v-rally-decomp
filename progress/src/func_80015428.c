extern int g_pos_bias;
void func_80015428(int *arg0, int arg1) {
    int i;
    int pad[2];

    i = 0;
    if (arg1 > 0) {
        do {
            *arg0 += g_pos_bias;
            arg0++;
            i++;
        } while (i < arg1);
    }
    (void)&pad;
}
