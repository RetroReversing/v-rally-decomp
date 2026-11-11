extern s32 gOrderState;
extern s32 func_8007FBE4(s32);
extern s32 list_unlink_free(void *, void *);
extern s32 osSetIntState(s32);

/* Releases the entry at the index stored in the request: when its two counters are equal, frees its handle at +0x10 and clears it, then runs the entry update. */
void func_8007F634(void *req) {
    s32 saved;
    s32 *entry;
    u8 *table;
    saved = osSetIntState(1);
    table = (u8 *)&gOrderState + 0x5910;
    entry = (s32 *)(table + ((u16 *)((u8 *)req + 0xC))[0] * 0x5C);
    if (entry[0] == entry[1]) {
        func_8007FBE4(entry[4]);
        entry[4] = 0;
    }
    list_unlink_free(req, table + ((u16 *)((u8 *)req + 0xC))[0] * 0x5C);
    osSetIntState(saved);
}
