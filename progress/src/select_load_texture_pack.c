#ifdef PORT
extern char *D_800D0658;
#else
extern int D_800D0658;
#endif
extern void *gSelectState;
extern char D_800A5F9C[];
extern char D_800A5FAC[];
s32 getTexturePack();
s32 func_8007A794();
s32 resolve_path();
s32 appendString();

/* Takes the first 5 characters of the currently selected entry's name (entries are 0x2C4 bytes,
 * the selection index is at gSelectState+0x237), appends the suffix D_800A5FAC to it and stores the
 * texture pack id that results in gSelectState+0x1E4. */
void select_load_texture_pack(void)
{
    char name[16];
    char *namePtr;
    u8 i;
    char *entry;

    func_8007A794();
    resolve_path(D_800A5F9C);
    entry = (char *)(D_800D0658 + *((u8 *)((char *)gSelectState + 0x237)) * 0x2C4);
    i = 0;
    do
    {
        name[i] = entry[i];
        i++;
    } while (i < 5);
    namePtr = name;
    namePtr[i] = 0;
    appendString(namePtr, D_800A5FAC);
    *((s32 *)((char *)gSelectState + 0x1E4)) = getTexturePack(namePtr, 0);
}