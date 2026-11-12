extern int gOrderSlot;
extern int D_800ADF90[];

/* Returns the current offset for the active order slot and advances it by 0x60 (one record). */
int func_80009E54(void)
{
    int slot = gOrderSlot;
    int *p = &D_800ADF90[slot];
    int old = *p;
    *p = old + 0x60;
    return old;
}
