void add_pos_bias_words(void *words, s32 count);

/* Applies position bias to a single 2-word header record at `record` and returns it. */
void *func_800523EC(void *record) {
    add_pos_bias_words(record, 1);
    return record;
}
