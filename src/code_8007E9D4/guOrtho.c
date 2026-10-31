#include "snapshot31_manual_verified.h"

void guMtxIdentF(void *);
void guMtxF2L(void *, void *);
void guOrtho(void *mf, float l, float r, float b, float t, float n, float f, float scale) {
    float ortho[4][4];
    float *p = &ortho[0][0];
    int i, j;
    guMtxIdentF(p);
    ortho[0][0] = 2/(r-l);
    ortho[1][1] = 2/(t-b);
    ortho[2][2] = -2/(f-n);
    ortho[3][0] = -(r+l)/(r-l);
    ortho[3][1] = -(t+b)/(t-b);
    ortho[3][2] = -(f+n)/(f-n);
    ortho[3][3] = 1;
    for (i=0; i<4; i++, p+=4) {
        j = 0;
        while (j < 4) {
            p[j] *= scale;
            j++;
        }
    }
    guMtxF2L(ortho, mf);
}