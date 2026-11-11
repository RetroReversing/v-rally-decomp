char *findRecordByRange(int a, int b);

/* Finds the record covering index `index` in range set `range`, and stores `value` in
 * the first word of that index's 12-byte entry (entries start at record+8, first index at record+0xD). */
void func_8008A178(int range, int index, int value) {
    int idx = index & 0xFFFF;
    char *rec = findRecordByRange(range, idx);
    *(int *)(*(int *)(rec + 8) + (idx - *(unsigned char *)(rec + 0xD)) * 0xC) = value;
}
