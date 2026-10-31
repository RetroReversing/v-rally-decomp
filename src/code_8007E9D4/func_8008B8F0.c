#include "snapshot31_manual_verified.h"

void func_8008B8F0(long *m, float l, float r, float b, float t, float n, float f, float scale)
{
    float mf[4][4];
    float *row, *p;
    int i, j;

    row = &mf[0][0];
    guMtxIdentF(mf);
    mf[0][0] = 2*n/(r-l);
    mf[1][1] = 2*n/(t-b);
    mf[2][0] = (r+l)/(r-l);
    mf[2][1] = (t+b)/(t-b);
    mf[2][2] = -(f+n)/(f-n);
    mf[2][3] = -1;
    mf[3][2] = -2*f*n/(f-n);
    mf[3][3] = 0;

    for (i=0; i<4; i++) {
        j = 0;
        p = row;
        do {
            *p++ *= scale;
            j++;
        } while (j < 4);
        row += 4;
    }
    guMtxF2L(mf, m);
}