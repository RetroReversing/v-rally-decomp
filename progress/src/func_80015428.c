extern int g_pos_bias;

/* Adds g_pos_bias to each of the first count ints in values. */
void func_80015428(int *values, int count) {
    int i;
    int pad[2];

    i = 0;
    if (count > 0) {
        do {
            *values += g_pos_bias;
            values++;
            i++;
        } while (i < count);
    }
    (void)&pad;
}
