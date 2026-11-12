extern char D_800AFA5C;
extern char *gSelectState;
extern char D_800A13C0[];
extern char D_800A5268[];
void strCpy(char *a, char *b);
void selectSetText(char *text);

/* Selects item `item` of the select list. Copies the item's name into the select state.
 * When use_fixed_text is set, shows the fixed text at D_800A5268 and sets flag 0x29E.
 * Otherwise shows the text pointed to by the state's pointer at 0x1F4. Then sets flag
 * 0x29D and calls selectSetText. */
void selectSetItem(char item, int use_fixed_text) {
    char *text;

    D_800AFA5C = item;
    strCpy(gSelectState + 0x2AD, D_800A13C0 + (item & 0xFF) * 0x24);
    if (use_fixed_text & 0xFF) {
        text = D_800A5268;
        gSelectState[0x29E] = 1;
    } else {
        text = *(char **)(gSelectState + 0x1F4);
    }
    gSelectState[0x29D] = 1;
    selectSetText(text);
}
