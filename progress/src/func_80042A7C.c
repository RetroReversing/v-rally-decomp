s32 named_entry_set_value(void **list, u8 *name, s32 value);
extern u8 D_800A4DD4[];

/* If the object's flag at +0x24 is set, sets the named entry at +0x28 to value. */
void func_80042A7C(void *obj, s32 value) {
    if (*(s32 *)((u8 *)obj + 0x24) != 0) {
        named_entry_set_value((void **)((u8 *)obj + 0x28), D_800A4DD4, value);
    }
}
