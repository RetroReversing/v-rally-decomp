extern char gGameState[];
void itemListRunHandlers(char *a);

/* Runs the item list handlers for the item system state block at gGameState + 0x6BD0. */
void itemUpdateAll(void) { itemListRunHandlers(gGameState + 0x6BD0); }
