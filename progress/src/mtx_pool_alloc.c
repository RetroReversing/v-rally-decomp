extern int D_800B7038; extern char gOrderState[];
int mtx_pool_alloc(void) { int i = D_800B7038; int *p = (int *)(gOrderState + 0x87E0) + i; int old = *p; *p = old + 0x40; return old; }
