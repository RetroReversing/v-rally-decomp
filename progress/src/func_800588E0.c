extern char D_800A5248[];
void text_load_and_parse(int a, char *b);
void func_8005BB5C(void);

/* Loads and parses text for the given name, then updates the selection display. */
void func_800588E0(int name) { text_load_and_parse(name, D_800A5248); func_8005BB5C(); }
