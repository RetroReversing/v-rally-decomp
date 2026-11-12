char *findRecordByRange(int a, int b);

/* Returns the value of the record covering key, adjusted by 12 per unit past that record's start. */
int getRecordValueFromRange(int table, int key) {
    int offset = key & 0xFFFF;
    char *rec = findRecordByRange(table, offset);
    return *(int *)(rec + 8) + (offset - *(unsigned char *)(rec + 0xD)) * 0xC;
}
