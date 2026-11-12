/* Saves value into the parameter block for codes 1 (word 0) and 6 (word 5); other codes are ignored. */
s32 alSaveParam(s32 *params, s32 code, s32 value) {
    switch (code) {
    case 1:
        params[0] = value;
        break;
    case 6:
        params[5] = value;
        break;
    }
    return 0;
}
