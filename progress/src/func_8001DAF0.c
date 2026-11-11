extern s32 D_8009E230;
extern s32 gShadeMode;
extern char D_800A47C4[], D_800A47CC[], D_800A47D4[], D_800A47DC[], D_800A47E4[], D_800A47EC[], D_800A47F4[], D_800A4800[];
void text_load_and_parse(void *a0, void *a1);

/* Applies the shade mode's setting to the object's +0x4C block. Each mode picks its own
 * table; mode 3 also sets D_8009E230. Then always applies the final table. */
void func_8001DAF0(u8 *obj)
{
    text_load_and_parse(obj + 0x4C, D_800A47C4);
    D_8009E230 = 0;
    switch (gShadeMode) {
    case 0:
        text_load_and_parse(obj + 0x4C, D_800A47CC);
        break;
    case 1:
        text_load_and_parse(obj + 0x4C, D_800A47D4);
        break;
    case 2:
        text_load_and_parse(obj + 0x4C, D_800A47DC);
        break;
    case 3:
        text_load_and_parse(obj + 0x4C, D_800A47E4);
        D_8009E230 = 0xD;
        break;
    case 4:
        text_load_and_parse(obj + 0x4C, D_800A47EC);
        break;
    case 5:
        text_load_and_parse(obj + 0x4C, D_800A47F4);
        break;
    }
    text_load_and_parse(obj + 0x4C, D_800A4800);
}
