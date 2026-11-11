#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif

/* Walks the node list starting at *list (each node's next pointer is at +4) and
 * calls each node's callback (at +0x14) with its data pointer (at +0x10). */
void RunNodeCallbacks(void **list) {
    void *node;

    if (list != NULL) {
        node = *list;
        if (node != NULL) {
            do {
                M2C_FIELD(node, M2C_UNK (**)(s32), 0x14)(M2C_FIELD(node, s32 *, 0x10));
                node = M2C_FIELD(node, void **, 4);
            } while (node != NULL);
        }
    }
}
