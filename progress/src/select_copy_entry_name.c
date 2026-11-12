u8 *strCpy(u8 *dst, u8 *src);
extern u8 *gSelectState;

/* Copies the name string of the entry at arg0 into the select state's name buffer (+0x1F8). */
#ifdef PORT
void select_copy_entry_name(u8 *entry) {
    strCpy(gSelectState + 0x1F8, entry + 0x4C);
}
#else
void select_copy_entry_name(s32 entry) {
    strCpy(gSelectState + 0x1F8, (u8 *)entry + 0x4C);
}
#endif
