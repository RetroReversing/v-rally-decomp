void list_unlink_free(void *node, void **pool);
extern u8 D_800C02AA[];

/* Frees every node in the list whose head is stored at D_800C02AA+0x5A7E.
 * The pool pointer is at +0x10 of that object; each node's next link is at +4. */
void func_80059FB4(void) {
    void *node;
    void *cursor;

    node = **(void ***) (*(u8 **) (D_800C02AA + 0x5A7E) + 0x10);
    if (node != NULL) {
        do {
            cursor = node;
            node = *(void **) ((u8 *) cursor + 4);
            list_unlink_free(cursor, *(void ***) (*(u8 **) (D_800C02AA + 0x5A7E) + 0x10));
        } while (node != NULL);
    }
}
