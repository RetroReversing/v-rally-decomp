/* Copies the translation column (words 5..7) of a 3x3 matrix into the order state globals. */
extern s32 D_800B618C;
extern s32 D_800B6190;
extern s32 D_800B6194;

void order_state_store_translation(s32 *mtx) {
    s32 v;
    v = mtx[5];
    D_800B618C = v;
    v = mtx[6];
    D_800B6190 = v;
    v = mtx[7]; D_800B6194 = v; }
