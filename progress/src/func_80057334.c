extern void *gSelectState;
extern char D_800A51A8[];
extern char D_800A51B0[];
extern char D_800A51B8[];
extern char D_800A51BC[];
extern char D_800A51C0[];
extern char D_800A51C8[];
extern char D_800A51D0[];
extern char D_800A51D8[];
extern char D_800A51DC[];
extern char D_800A51E4[];
extern char D_800A51EC[];
extern int D_800ADF80;
s32 view_get_ctx_id();
void func_8000C22C(void *, s32, s32, s32, u8);
s32 func_8000C244();

/* Picks the menu label for option `index` (0-9) and shows it in the select view. */
void func_80057334(s16 x, s16 y, s32 index) {
    s32 *label;

    label = &D_800A51A8;
    if (index != 0) {
        goto block_2;
    }
    label = &D_800A51B0;
    goto block_20;
block_2:
    if (index != 1) {
        goto block_4;
    }
    label = &D_800A51B8;
    goto block_20;
block_4:
    if (index != 2) {
        goto block_6;
    }
    label = &D_800A51BC;
    goto block_20;
block_6:
    if (index != 3) {
        goto block_8;
    }
    label = &D_800A51C0;
    goto block_20;
block_8:
    if (index != 4) {
        goto block_10;
    }
    label = &D_800A51C8;
    goto block_20;
block_10:
    if (index != 5) {
        goto block_12;
    }
    label = &D_800A51D0;
    goto block_20;
block_12:
    if (index != 6) {
        goto block_14;
    }
    label = &D_800A51D8;
    goto block_20;
block_14:
    if (index != 7) {
        goto block_16;
    }
    label = &D_800A51DC;
    goto block_20;
block_16:
    if (index != 8) {
        goto block_18;
    }
    label = &D_800A51E4;
    goto block_20;
block_18:
    if (index != 9) {
        goto block_20;
    }
    label = &D_800A51EC;
block_20:
    func_8000C22C((void *)(*(s32 *)((char *)gSelectState + 0xE4)), (s32)(0xFF), (s32)(0), (s32)(0), (u8)(0xFF));
    func_8000C244(*(s32 *)((char *)gSelectState + 0xE4), view_get_ctx_id(D_800ADF80), x, y, label, 0);
    return;
}
