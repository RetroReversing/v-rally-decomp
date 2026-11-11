extern char gStreamState[];
int poolAlloc(int a, int b);
int func_80081D50(int arg0) { int t = poolAlloc(arg0, *(int *)(gStreamState + 0x30C2)); *(int *)(gStreamState + 0x30EA) = t; *(int *)(gStreamState + 0x30EE) = t; return 0; }
