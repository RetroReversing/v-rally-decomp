/* identical to __osPfsSelectBank in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80090D50 in V-RALLY (matched), with its names changed by decompdecomp */

int __osContRamWrite(int a, int b, int c, char *d, int e);
void __osPfsSelectBank(char *arg0, char arg1) { char buf[32]; int i; for (i = 31; i >= 0; i--) { buf[i] = arg1; } if (__osContRamWrite(*(int *)(arg0 + 4), *(int *)(arg0 + 8), 0x400, buf, 0) == 0) { arg0[0x65] = arg1; } }
