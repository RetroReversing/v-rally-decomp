/* Builds a perspective frustum matrix from the near/far planes and the view box, scales every
   element by scale, and stores it in the 16.16 fixed-point matrix m. */
void guFrustum(long *m, float left, float right, float bottom, float top, float near, float far, float scale)
{
    float mf[4][4];
    float *row, *p;
    int i, j;

    row = &mf[0][0];
    guMtxIdentF(mf);
    mf[0][0] = 2*near/(right-left);
    mf[1][1] = 2*near/(top-bottom);
    mf[2][0] = (right+left)/(right-left);
    mf[2][1] = (top+bottom)/(top-bottom);
    mf[2][2] = -(far+near)/(far-near);
    mf[2][3] = -1;
    mf[3][2] = -2*far*near/(far-near);
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
