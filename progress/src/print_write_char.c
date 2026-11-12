/* Sends one character to the debug output port and returns it. */
extern void print_send_byte(s32 c);

s32 print_write_char(s32 c) {
    print_send_byte(c);
    return c;
}
