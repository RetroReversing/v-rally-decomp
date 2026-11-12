void *select_get_entry(u32 index); void strCpy(char *dst, char *src); void select_set_text_default(char *text);
/* Copy the label of select entry entry_index into the select text buffer. */
int select_copy_entry_label(int unused, int entry_index) { char label[16]; strCpy(label, (char *)select_get_entry(entry_index) + 48); select_set_text_default(label); return 0; }
