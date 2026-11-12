char *getRecordValueFromRange(int a, int b);

/* Sets the byte at offset 0xA of the record found for the given range and value. */
void setRecordFlag(int rangeStart, int value, char flag) {
    getRecordValueFromRange(rangeStart, value & 0xFFFF)[0xA] = flag;
}
