s32 str_icmp_gt(u8 *str, u8 *other);

/* One pass of a bubble sort over the name list. The count is at index 0x1F and
 * the names start at index 0x20. Walks back from the last name, swapping each
 * adjacent pair, and ends the pass at the first pair str_icmp_gt reports as greater. */
void func_800826DC(s32 *list) {
    s32 i;
    s32 stopped;
    s32 a;
    s32 b;
    s32 flag;

    i = list[0x1F];
    stopped = 0;
    flag = (i < 2) ^ 1;
    if (flag) {
        do {
            if (str_icmp_gt((u8 *)list[i + 0x20], (u8 *)list[i + 0x1F]) != 0) {
                stopped = 1;
            } else {
                a = list[i + 0x1F];
                b = list[i + 0x20];
                list[i + 0x20] = a;
                list[i + 0x1F] = b;
            }
            i--;
        } while ((i >= 2) & (stopped == 0));
    }
}
