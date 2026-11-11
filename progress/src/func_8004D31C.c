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

M2C_UNK streamReleaseEntry(s32);                         /* extern */
M2C_UNK list_unlink_free(void *, void **);             /* extern */
extern void **D_800A11B0;

/* Frees every block on the stream block list (node->block at +0xC, next at +4), unlinking
 * each node as it goes, then clears the list head. */
void func_8004D31C(void) {
    void *node;
    void *next;

    node = *D_800A11B0;
    if (node != NULL) {
        do {
            streamReleaseEntry(M2C_FIELD(node, s32 *, 0xC));
            next = node;
            node = M2C_FIELD(node, void **, 4);
            list_unlink_free(next, D_800A11B0);
        } while (node != NULL);
    }
    *D_800A11B0 = NULL;
}
