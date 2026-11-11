s32 strCmp();
extern s32 D_8009B9E0;
extern s32 D_8009B9E4;

/* Looks up name in the table at D_8009B9E0, which has 3-word entries (name pointer, link, ...)
 * and ends when an entry's second word is 0. Returns the matching entry, or NULL. */
s32 *func_80010344(s32 name) {
    s32 *entry;

    entry = &D_8009B9E0;
    if (D_8009B9E4 == 0) {
        goto block_6;
    }
loop_1:
    if (strCmp(name, *entry) == 0) {
        goto block_3;
    }
    entry += 3;
    goto block_5;
block_3:
    return entry;
block_5:
    if (entry[1] != 0) {
        goto loop_1;
    }
block_6:
    return NULL;
}
