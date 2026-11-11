extern char gStreamState[];
void func_800553B0(void) { int i = 0; do { ((int *)(gStreamState + 0x3902))[i & 0xFFFF] = 0; i++; } while ((unsigned)(i & 0xFFFF) < 0x800); }
