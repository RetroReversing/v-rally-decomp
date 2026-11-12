extern void *D_800A2500;
/* Return a consumed envelope param to the synth free list. */ void alParamFree(void **param) { void **freeHead = (void **)((char *)D_800A2500 + 0x2c); *param = *freeHead; *freeHead = param; }
