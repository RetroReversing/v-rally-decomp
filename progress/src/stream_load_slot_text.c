s32 text_load_and_parse(u8 *name, u8 *key);
extern s32 D_800A4820;
extern u8 gStreamState[];

/* Loads and parses the text file for stream slot slot, using the key at D_800A4820. Each
 * slot is 0x2C4 bytes, starting at gStreamState+0x103AA. */
void stream_load_slot_text(s32 slot) {
    text_load_and_parse(*(s32 *) (gStreamState + 0x103AA) + (slot * 0x2C4), &D_800A4820);
}
