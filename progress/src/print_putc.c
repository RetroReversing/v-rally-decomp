s32 print_write_char(s32);

/* Writes one character to the debug print output. A newline is preceded by a carriage return.
 * Returns the character. */
s32 print_putc(s32 c) {
    if (c == 0xA) {
        print_write_char(0xD);
    }
    print_write_char(c);
    return c;
}
