/* Maps a type code (0-8) to its value (4, 3, 7 or 11); returns 0 for any other code. */
s32 MapTypeCode(u16 type) {
    switch (type) {
    case 0:
        return 7;
    case 1:
        return 11;
    case 2:
        return 7;
    case 3:
        return 11;
    case 4:
        return 4;
    case 5:
        return 3;
    case 6:
        return 7;
    case 7:
        return 11;
    case 8:
        return 11;
    default:
        return 0;
    }
}
