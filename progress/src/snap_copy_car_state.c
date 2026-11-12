extern char gSnapTable[]; extern int gSnapIndex;

/* Copies four words from the object at arg0 (offsets 0x90, 0xDC, 0x128, 0x174) into the current gSnapTable entry (24 bytes each). */
void snap_copy_car_state(char *arg0) { int o = gSnapIndex * 0x18; *(int *)(gSnapTable + o) = *(int *)(arg0 + 0x90); *(int *)(gSnapTable + 4 + o) = *(int *)(arg0 + 0xDC); *(int *)(gSnapTable + 8 + o) = *(int *)(arg0 + 0x128); *(int *)(gSnapTable + 0xC + o) = *(int *)(arg0 + 0x174); }
