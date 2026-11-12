s32 text_load_and_parse(u8 *name, u8 *key);
/* Loads and parses a text file without key filtering. */
void text_load_file(u8 *name) { text_load_and_parse(name, NULL); }
