#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif
void *select_get_entry(u32);

/* Stores three bytes into the select-list entry at index: arg1 at +0xF, arg2 at
 * +0x10 and arg3 at +0x11. */
void SetSelectEntryBytes(s32 index, s8 b0, s8 b1, s8 b2) {
    void *entry;

    entry = select_get_entry(index);
    M2C_FIELD(entry, s8 *, 0xF) = b0;
    M2C_FIELD(entry, s8 *, 0x10) = b1;
    M2C_FIELD(entry, s8 *, 0x11) = b2;
}
