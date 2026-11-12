extern char char_class_tbl[];

s32 ctype_toupper(s32 c) {
    s32 ch;

    ch = c;
    if (*(char_class_tbl + (ch & 0xFF)) & 4) {
        ch -= 0x20;
    }
    return ch;
}
