void copyString(void *a, s32 b, s32 c);

/* Finds the list node whose 8-byte name key matches arg1's name. The key is copied
 * into a zeroed 8-byte buffer first. Returns the node, or NULL if none matches. */
void *func_80080570(void **list, s32 name)
{
    char key[8];
    char *p;
    char *node;
    s32 k0;
    s32 k1;

    p = key;
    do {
        *p = 0;
        p++;
    } while (p < key + 8);
    copyString(key, name, 8);
    k0 = *(s32 *)key;
    k1 = *(s32 *)(key + 4);
    if (list != NULL) {
        node = *list;
        while (node != NULL) {
            if (k0 == *(s32 *)(node + 0xC) && k1 == *(s32 *)(node + 0x10)) {
                return node;
            }
            node = *(char **)(node + 4);
        }
    }
    return NULL;
}
