s32 alFilterNew(void *a0, void *fn2, void *fn3, s32 n4);
extern void *alSavePull;
extern void *alSaveParam;

/* Sets up a save effect: attaches the alSavePull/alSaveParam filter, then clears word 0x14 and sets word 0x18 to 1. */ void alSaveNew(void *save) {
    alFilterNew(save, &alSavePull, &alSaveParam, 3);
    *(s32 *)((s8 *)save + 0x14) = 0;
    *(s32 *)((s8 *)save + 0x18) = 1;
}
