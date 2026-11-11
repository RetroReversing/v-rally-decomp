s32 viewport_build_dl(s32, s32, s32, s32);
s32 func_80022668(void *, s32);
extern char gStreamState[];

/* If func_80022668 accepts the stream list at gStreamState+0x7672 (with its +8 field),
 * builds the viewport display list from the object at gStreamState+0x7CD6 (field +0x178). */
void func_800475A0(void) {
    void *list;

    list = *(void **)(gStreamState + 0x7672);
    if (func_80022668(list, *(s32 *)((char *)list + 8)) != 0) {
        viewport_build_dl(*(s32 *)((char *)*(void **)(gStreamState + 0x7CD6) + 0x178), 0, 0, 0);
    }
}
