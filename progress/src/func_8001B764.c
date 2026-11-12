/* Lower-cases the ASCII letters of the NUL-terminated string in place. */
void func_8001B764(unsigned char *str) {
    unsigned int c;

    while ((c = *str) != 0) {
        if (c - 0x41 < 0x1A) {
            *str = c + 0x20;
        }
        str++;
    }
}
