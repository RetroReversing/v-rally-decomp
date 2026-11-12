extern int gEntryPoolSlot; extern char stream_state[];
/* Hands out the next 0x18-byte entry from the current slot's pool cursor and advances it. */
int entry_pool_alloc(void) { int slot = gEntryPoolSlot; int *cursor = (int *)(stream_state + 0x3302) + slot; int entry = *cursor; *cursor = entry + 0x18; return entry; }
