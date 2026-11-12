/* Zeroes the first halfword of each 0x24-byte record in the table, for count records. */
void records_clear_heads(char *records, int count) {
    int left = count;
    int was_left;
    char *rec = records;
    was_left = left;
    goto loop_2;
block_1:
    *(short *)rec = 0;
    rec += 0x24;
    was_left = left;
loop_2:
    left -= 1;
    if (was_left != 0) goto block_1;
    return;
}
