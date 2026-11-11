typedef long Mtx_t[4][4];

typedef union {
    Mtx_t m;
    long long int force_structure_alignment;
} Mtx;

/* Converts a float 4x4 matrix to the N64 fixed-point Mtx format. Each 16.16
 * value is split: the integer halves go to m[0][*] and the fraction halves to
 * m[2][*], packed two per 32-bit word. */
void guMtxF2L(float mf[4][4], Mtx *m)
{
    int row, pair;
    int fix1, fix2;
    int *intPart, *fracPart;

    intPart = (int *) &m->m[0][0];
    fracPart = (int *) &m->m[2][0];

    for (row = 0; row < 4; row++)
    for (pair = 0; pair < 2; pair++) {
        fix1 = (long)((mf[row][pair * 2]) * (float)0x00010000);
        fix2 = (long)((mf[row][pair * 2 + 1]) * (float)0x00010000);
        *(intPart++) = (fix1 & 0xffff0000) | ((fix2 >> 16) & 0xffff);
        *(fracPart++) = ((fix1 << 16) & 0xffff0000) | (fix2 & 0xffff);
    }
}
