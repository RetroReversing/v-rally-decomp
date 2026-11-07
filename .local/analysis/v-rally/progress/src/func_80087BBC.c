/* identical to func_8008D4DC in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80087BBC in V-RALLY (matched), with its names changed by decompdecomp */

unsigned char *func_80087BBC(char *arg0, unsigned char *arg1) { unsigned int hi = *arg1++; unsigned int lo = *arg1; *(short *)(arg0 + 0xAC) = 0; *(short *)(arg0 + 0xAA) = lo | (hi << 8); return arg1 + 1; }
