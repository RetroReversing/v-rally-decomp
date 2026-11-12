/* Case-folds a path character: lowercases A-Z and maps '\' to '/'. Returns the converted character. */
u8 str_fold_path_char(s32 ch) {
    u8 c;

    if ((u8)(ch - 0x41) < 0x1B) {
        return (u8)(ch + 0x20);
    }
    c = ch;
    if (c == 0x5C) {
        return 0x2F;
    }
    return c;
}
