/* Entry in a named list: next link, name pointer at +0xC, id at +0x10, two values after it. */
typedef struct NamedEntry { struct NamedEntry *next; u8 pad04[8]; u8 *name; s32 id; s32 value; s32 value2; } NamedEntry;

void *list_find_node(void **list, u8 *name);
void *poolAllocNode(void **pool, s32 size);
s32 poolAllocHeadNode(void);

/* Returns the id of the entry called name. Unless force_new is set, an existing entry with
 * that name is reused. Otherwise a new entry is allocated from the pool, given a fresh id, and
 * linked to name. */
s32 named_entry_find_or_add(void **pool, s32 arg1, s32 arg2, u8 *name, s32 force_new) {
    NamedEntry *entry;
    void *found;

    if (force_new == 0) {
        found = list_find_node(pool, name);
        if (found != NULL) {
            return ((NamedEntry *)found)->id;
        }
    }
    entry = poolAllocNode(pool, 0x1C);
    entry->id = poolAllocHeadNode();
    entry->value = arg1;
    entry->value2 = arg2;
    entry->name = name;
    return entry->id;
}
