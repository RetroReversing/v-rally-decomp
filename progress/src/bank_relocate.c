/* A bank entry: a pointer to its item list and the item count. */
typedef struct Entry { void *items; u16 count; u16 pad06; } Entry;

/* Adds base to each word that is not already a pointer (top bit clear). */
s32 rebase_words(u32 *words, s32 count, u32 base);
void entry_list_release(void *list);
extern u32 rebase_base_addr;

/* Relocates a bank: its entries pointer, then every entry's items pointer.
 * Afterwards each entry's item list is released in turn. */
void *bank_relocate(Entry *bank) {
    s32 i;
    Entry *entry;
    Entry *self;
    s32 zero;

    zero = 0;
    rebase_words((u32 *)bank, 1, rebase_base_addr);
    entry = (Entry *)bank->items;
    rebase_words((u32 *)entry, bank->count, rebase_base_addr);
    i = zero;
    self = bank;
    if ((s32)bank->count > zero) {
        do {
            entry_list_release(entry);
            i += 1;
            entry += 1;
        } while (i < (s32)self->count);
    }
    return bank;
}
