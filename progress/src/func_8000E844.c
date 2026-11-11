extern s32 D_9B830;
extern s32 D_9B928;
extern s32 D_9B948;

/* Appends four 8-byte display list words to the list cursor *dl: a G_MOVEWORD 0xDB060000
 * with a null pointer, then three G_DL (0xDE, push) entries that call the sub-lists at
 * D_9B948, D_9B830 and D_9B928. Advances *dl past the four words. */
void func_8000E844(void **dl) {
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;

    temp_v1 = *dl;
    *dl = temp_v1 + 8;
    *(s32 *)(temp_v1 + 0) = 0xDB060000;
    *(void **)(temp_v1 + 4) = NULL;
    temp_v1_2 = *dl;
    *dl = temp_v1_2 + 8;
    *(s32 *)(temp_v1_2 + 0) = 0xDE000000;
    *(s32 **)(temp_v1_2 + 4) = &D_9B948;
    temp_v1_3 = *dl;
    *dl = temp_v1_3 + 8;
    *(s32 *)(temp_v1_3 + 0) = 0xDE000000;
    *(s32 **)(temp_v1_3 + 4) = &D_9B830;
    temp_v1_4 = *dl;
    *dl = temp_v1_4 + 8;
    *(s32 *)(temp_v1_4 + 0) = 0xDE000000;
    *(s32 **)(temp_v1_4 + 4) = &D_9B928;
}
