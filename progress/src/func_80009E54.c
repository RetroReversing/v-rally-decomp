extern int gOrderSlot;
extern int D_800ADF90[];

int func_80009E54(void) {
    int i = gOrderSlot;
    int *p = &D_800ADF90[i];
    int old = *p;
    *p = old + 0x60;
    return old;
}
