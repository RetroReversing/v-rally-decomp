extern char *gRecords; extern int gRaceState;
void func_80043124(char *arg0) { *(short *)(gRecords + 0x36) = 0; { int v = *(int *)(arg0 + 0x14); gRaceState = 1; *(int *)(arg0 + 0x14) = v & ~0x200; } }
