s32 func_8000A188(s32, s32, s32, s32, s32);
s32 func_80022668(s32, s32);
extern char gStreamState[];

/* Finds entry number (arg1 & 0xFFFF) in the list at gStreamState+0x7672 and, if there is one,
   fills its background-layer header from owner with func_8000A188. */
void func_80047C2C(s32 owner, s32 index) {
    s32 entry;

    entry = func_80022668(*(s32 *)(gStreamState + 0x7672), index & 0xFFFF);
    if (entry != 0) {
        func_8000A188(owner, entry, 0, 0, 0);
    }
}
