/* Returns the first ']' at or after start, or end if none is found before end. */
char *str_find_close_bracket(char *start, char *end) {
    while ((*start != 0x5D) & (start < end)) {
        start++;
    }
    return start;
}
