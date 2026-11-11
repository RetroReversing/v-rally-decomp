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

s32 nameNodeFind();                                 /* extern */
s32 nameSlotAlloc(M2C_UNK);                         /* extern */

/* Returns the node or the child already holding `name`. If there is none, appends a new
 * child slot (count at 0x10, child table at 0x14) with `name` copied in and returns it. */
s32 nameNodeFindOrAdd(void *node, M2C_UNK name) {
    s32 found;

    found = nameNodeFind(node, name);
    if (found == 0) {
        M2C_FIELD(node, s32 *, 0x10) = (s32) (M2C_FIELD(node, s32 *, 0x10) + 1);
        M2C_FIELD(((M2C_FIELD(node, s32 *, 0x10) * 4) + node), s32 *, 0x14) = nameSlotAlloc(name);
        found = M2C_FIELD(((M2C_FIELD(node, s32 *, 0x10) * 4) + node), s32 *, 0x14);
    }
    return found;
}
