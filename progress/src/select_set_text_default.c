void selectStateSetDefaults(void);
void selectSetText(s32);

/* Resets the select-screen defaults, then sets the select text to the given id. */
void select_set_text_default(s32 textId) {
    selectStateSetDefaults();
    selectSetText(textId);
}
