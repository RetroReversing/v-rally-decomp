extern u8 *g_camera;
extern s16 sSavedFlag0[], sSavedFlag1[], sSavedFlag2[], D_800A18BC[];
extern s32 D_800A1860, D_800A1864, D_800A1868, D_800A186C, D_800A1870, D_800A1874;
extern s32 gNearFlag;
void mat3_transform_vec(void *, s16 *, s32 *);
typedef struct Triple { s16 a; s16 b; s16 c; } Triple;

/* Transforms the object's two local-space box corners (picked by a camera flag)
 * into world space, then sets gNearFlag to 1 if the object at target is within
 * +/-20000 units of the first corner on X and Z, else 0. */
void checkNearPoint(u8 *obj, u8 *target)
{
    s32 worldPt[3];
    s32 origin[3];
    Triple lo, hi;
    s32 *box;
    s16 dx, dz;

    if (*(u16 *)(g_camera + 32) & 8) {
        lo = *(Triple *)sSavedFlag2;
        hi = *(Triple *)D_800A18BC;
    } else {
        lo = *(Triple *)sSavedFlag0;
        hi = *(Triple *)sSavedFlag1;
    }
    origin[0] = ((s32 *)*(void **)(obj + 0x58))[3];
    origin[1] = ((s32 *)*(void **)(obj + 0x58))[4];
    origin[2] = ((s32 *)*(void **)(obj + 0x58))[5];
    mat3_transform_vec(*(u8 **)(obj + 0x5c) + 64, (s16 *)&lo, worldPt);
    box = &D_800A1860;
    box[0] = worldPt[0] + origin[0];
    box[1] = worldPt[1] + origin[1];
    box[2] = worldPt[2] + origin[2];
    mat3_transform_vec(*(u8 **)(obj + 0x5c) + 64, (s16 *)&hi, worldPt);
    box[3] = worldPt[0] + origin[0];
    box[4] = worldPt[1] + origin[1];
    box[5] = worldPt[2] + origin[2];
    dx = box[0] - *(s32 *)(target + 20);
    lo.a = dx;
    dz = box[2] - *(s32 *)(target + 28);
    lo.c = dz;
    gNearFlag = 0;
    if (dx >= 20000) return;
    if (dz >= 20000) return;
    if (dx < -19999) return;
    if (dz < -19999) return;
    gNearFlag = 1;
}
