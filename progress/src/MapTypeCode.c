/* Maps a type code to its value: 5 -> 4, 6 -> 3, 7 -> 7, 8 -> 11; codes 0-4 and any other code
 * return 0. Case labels follow the original jump table (jtbl_800A4958). */
s32 MapTypeCode(u16 type) {
    switch (type) {
    case 5:
        return 4;
    case 6:
        return 3;
    case 7:
        return 7;
    case 8:
        return 11;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    default:
        return 0;
    }
}
