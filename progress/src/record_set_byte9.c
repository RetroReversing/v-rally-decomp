char *getRecordValueFromRange(int a, int b);

/* Sets byte 9 of the record found by getRecordValueFromRange(first, second & 0xFFFF). */
void record_set_byte9(int first, int second, char value) {
    getRecordValueFromRange(first, second & 0xFFFF)[9] = value;
}
