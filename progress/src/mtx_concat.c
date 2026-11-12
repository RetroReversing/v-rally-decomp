void guMtxCatF(s32, s32);
/* Concatenates two matrices with guMtxCatF; the second argument is passed first. */
void mtx_concat(s32 mtxA, s32 mtxB) { guMtxCatF(mtxB, mtxA); }
