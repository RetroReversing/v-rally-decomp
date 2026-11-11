#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 strCmp();

/* Walks a table of 0x14-byte entries (name at +0, a non-zero word at +0xC marks an entry
 * that has a successor) starting at `first`, and returns the first entry whose name equals
 * `name`, or NULL if none does. */
void *find_entry_by_name(void *first, s32 name) {
    void *entry;

    entry = first;
    if (*(s32 *)((char *)entry + 0xC) == 0) {
        goto not_found;
    }
next:
    if (strCmp(name, entry) == 0) {
        goto found;
    }
    entry += 0x14;
    goto check_more;
found:
    return entry;
check_more:
    if (*(s32 *)((char *)entry + 0xC) != 0) {
        goto next;
    }
not_found:
    return NULL;
}
