void *select_get_entry(u32);
s32 select_copy_entry_state(s32, s32);
s32 select_set_active_sub(s32, u8);
s32 UpdateSelectedEntry(u8, void *);
s32 select_load_texture_pack();
extern void *gSelectState;
extern char stream_state[];

/* Sets up the select screen's selection for the player's current record: stores the
 * record's index, looks up how many entries share its class, then starts the screen's
 * display routines. */
s32 func_8007AAFC(s32 arg0) {
    char *records;
    char *entry;
    char *record;
    char *var_v1;
    char *state;
    s32 var_a0;
    u8 car;
    u8 slot;
    u8 class_id;

    *((u8 *)gSelectState + 0x2BC) = 4;
    *((u8 *)gSelectState + 0x245) = 1;
    state = gSelectState;
    records = *(char **)(stream_state + 0x32F2);
    entry = records + *((s8 *)state + 0x228);
    record = records + *(u8 *)(entry + 0x32) * 0x28;
    slot = *(u8 *)(record + 0x4F);
    car = slot;
    class_id = *(u8 *)(*(char **)(stream_state + 0x103AA) + car * 0x2C4 + 0x15);
    if (class_id == *(u8 *)(state + 0x238)) {
        var_v1 = *(char **)((char *)select_get_entry((u8)(class_id)) + 0x28);
        var_a0 = 0;
        if (*(u8 *)(var_v1 + 0x22) != car) {
            do {
                var_v1 = *(char **)var_v1;
                var_a0 += 1;
            } while (*(u8 *)(var_v1 + 0x22) != car);
        }
        *((u8 *)gSelectState + 0x239) = var_a0;
        *((u8 *)gSelectState + 0x237) = slot;
    } else {
        *(state + 0x239) = 0;
        UpdateSelectedEntry(class_id, state);
    }
    select_load_texture_pack();
    *((u8 *)gSelectState + 0x2BD) = 1;
    entry = *(char **)(stream_state + 0x325A);
    select_copy_entry_state(arg0, *(u8 *)(*(char **)(entry + 0x10) + *(s16 *)(entry + 2) * 0x14 + 0xD) + 4);
    select_set_active_sub(arg0, *((u8 *)gSelectState + 0x239));
    return 0;
}
