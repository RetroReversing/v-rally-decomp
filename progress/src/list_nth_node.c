/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

/* Walks n links of a list (next pointer at +4) from *head and returns the node reached.
   Stops early at the last node, so the result is never NULL unless the list is empty. */
void *list_nth_node(void **head, s32 n) {
    void *node = *head;
    s32 i = n;

    while (i != 0 && node != NULL) {
        void *next = *(void **)((char *)node + 4);

        if (next == NULL) {
            break;
        }
        node = next;
        i--;
    }
    return node;
}
