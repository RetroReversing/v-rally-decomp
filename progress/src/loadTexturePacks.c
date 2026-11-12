extern unsigned short gTexPackCount;
extern char *D_800D0658;
s32 getTexturePack();
s32 resolve_path();
s32 appendString();
extern s8 *gSelectState;
extern char aTexPackDir[];
extern char aTexPackExt[];

/* Enters the texture directory, then loads the texture pack for each of the
 * gTexPackCount entries: the entry's 5-character name, with the pack extension
 * appended, is passed to getTexturePack and the result is stored in the select state. */
void loadTexturePacks(void) {
    char name[16];
    u32 i;
    u8 k;
    char *entry;

    resolve_path(aTexPackDir);
    i = 0;
    if (gTexPackCount != 0) {
        do {
            entry = (char *) D_800D0658 + ((i & 0xFF) * 0x2C4);
            k = 0;
            do {
                name[k] = entry[k];
                k++;
            } while (k < 5);
            name[k] = 0;
            appendString(name, aTexPackExt);
            *(s32 *)(((i & 0xFF) * 4) + gSelectState + 0x194) = getTexturePack(name, 0);
            i++;
        } while ((i & 0xFF) < (u16) gTexPackCount);
    }
}
